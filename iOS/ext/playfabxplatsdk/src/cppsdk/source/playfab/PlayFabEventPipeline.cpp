#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <chrono>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabEventPipeline.h>
#include <playfab/PlayFabEventsApi.h>

namespace PlayFabInternal
{
    // BUMBLELION: A default buffer size of 12K allows for about 3 large Party events to queue before dropping new
    // events. This is a custom size chosen for Party - it should not be integrated back into the public SDK.
    static const int defaultBufferSize = 12288;
    static const int defaultMaxItemsInBatch = 5;
    static const int defaultMaxBatchWaitTimeInSeconds = 3;
    static const int defaultMaxBatchesInFlight = 16;
    static const int defaultReadBufferWaitTimeInMs = 10;

    PlayFabEventPipelineSettings::PlayFabEventPipelineSettings() :
        bufferSize(defaultBufferSize),
        maximalNumberOfItemsInBatch(defaultMaxItemsInBatch),
        maximalBatchWaitTime(defaultMaxBatchWaitTimeInSeconds),
        maximalNumberOfBatchesInFlight(defaultMaxBatchesInFlight),
        readBufferWaitTime(defaultReadBufferWaitTimeInMs),
        authenticationContext(nullptr),
        emitType(PlayFabEventPipelineType::PlayFabPlayStream),
        // BUMBLELION: enable manual pumping of event pipeline
        useBackgroundThread(true)
    {
    }

    PlayFabEventPipelineSettings::PlayFabEventPipelineSettings(PlayFabEventPipelineType type, bool useBackgroundThread) :
        bufferSize(defaultBufferSize),
        maximalNumberOfItemsInBatch(defaultMaxItemsInBatch),
        maximalBatchWaitTime(defaultMaxBatchWaitTimeInSeconds),
        maximalNumberOfBatchesInFlight(defaultMaxBatchesInFlight),
        readBufferWaitTime(defaultReadBufferWaitTimeInMs),
        authenticationContext(nullptr),
        emitType(type),
        // BUMBLELION: enable manual pumping of event pipeline
        useBackgroundThread(useBackgroundThread)
    {
    }

    PlayFabEventPipeline::PlayFabEventPipeline(std::shared_ptr<PlayFabEventPipelineSettings> settings) :
        batchCounter(0),
        buffer(settings->bufferSize),
        isWorkerThreadRunning(false)
    {
        this->settings = std::move(settings);
        this->batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        this->batchesInFlight.reserve(this->settings->maximalNumberOfBatchesInFlight);
        if (this->settings->useBackgroundThread)
        {
            this->Start();
        }
    }

    PlayFabEventPipeline::~PlayFabEventPipeline()
    {
        // BUMBLELION: the stop functionality was refactored into its own function so that when tokens expire we can
        // prevent the pipeline from enqueuing a bunch of requests which we know will fail
        Stop();
    }

    void PlayFabEventPipeline::Start()
    {
        // start worker thread
        this->isWorkerThreadRunning = true;
        if (!this->workerThread.joinable())
        {
            this->workerThread = std::thread(&PlayFabEventPipeline::WorkerThread, this);
        }
    }

    // BUMBLELION: the stop functionality was refactored into its own function so that when tokens expire we can
    // prevent the pipeline from enqueuing a bunch of requests which we know will fail
    void PlayFabEventPipeline::Stop()
    {
        // stop worker thread
        this->isWorkerThreadRunning = false;
        if (this->workerThread.joinable())
        {
            this->workerThread.join();
        }
    }

    void PlayFabEventPipeline::Update()
    {
        if (this->settings->useBackgroundThread)
        {
            throw std::runtime_error("You should not call Update() when PlayFabEventPipelineSettings::useBackgroundThread == true");
        }

        bool hasMoreWorkToProcess;
        do
        {
            hasMoreWorkToProcess = DoWork();
        } while (hasMoreWorkToProcess);
    }

    std::shared_ptr<PlayFabEventPipelineSettings> PlayFabEventPipeline::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabEventPipeline::IntakeEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request)
    {
        try
        {
            using Result = PlayFabEventBuffer::EventProducingResult;
            EmitEventResult emitResult;

            // put event into buffer
            switch (this->buffer.TryPut(request))
            {
                case Result::Success:
                    return;

                case Result::Overflow:
                {
                    emitResult = EmitEventResult::Overflow;
                    LOG_PIPELINE("Buffer overflow");
                }
                break;

                case Result::Disabled:
                {
                    emitResult = EmitEventResult::Disabled;
                }
                break;

                default:
                {
                    emitResult = EmitEventResult::NotSupported;
                    LOG_PIPELINE("TryPut returned an unknown type of result");
                }
                break;
            }

            // pipeline failed to intake the event, create a response
            const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(request);
            auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
            playFabEmitEventResponse->emitEventResult = emitResult;

            // call an emit event callback
            CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::IntakeEvent method");
        }
    }

    void PlayFabEventPipeline::SetExceptionCallback(ExceptionCallback ex)
    {
        { // LOCK userCallbackMutex
            std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
            userExceptionCallback = ex;
        } // UNLOCK userCallbackMutex
    }

    void PlayFabEventPipeline::WorkerThread()
    {
        while (this->isWorkerThreadRunning)
        {
            bool hasMoreWorkToProcess = DoWork();
            if (!hasMoreWorkToProcess)
            {
                // give some time for batches in flight to deflate
                std::this_thread::sleep_for(std::chrono::milliseconds(this->settings->readBufferWaitTime));
            }
        }
    }

    bool PlayFabEventPipeline::DoWork()
    {
        using clock = std::chrono::steady_clock;
        using Result = PlayFabEventBuffer::EventConsumingResult;
        std::shared_ptr<const IPlayFabEmitEventRequest> request;

        try
        {
            // Process events in the loop
            if (this->batchesInFlight.size() >= this->settings->maximalNumberOfBatchesInFlight)
            {
                // do not take new events from buffer if batches currently in flight are at the maximum allowed number
                // and are not sent out (or received an error) yet
                return false;
            }

            // BUMBLELION: Don't try taking a request until we get an entity token. We'd rather not lose events
            // that were generated before an entity token was created (i.e. before a user was created).
            if (PlayFabSettings::entityToken.empty() &&
                (settings->authenticationContext == nullptr || settings->authenticationContext->entityToken.empty()))
            {
                return false;
            }

            switch (this->buffer.TryTake(request))
            {
                case Result::Success:
                {
                    // add an event to batch
                    this->batch.push_back(std::move(request));

                    // if batch is full
                    if (this->batch.size() >= this->settings->maximalNumberOfItemsInBatch)
                    {
                        this->SendBatch();
                    }
                    else if (this->batch.size() == 1)
                    {
                        // if it is the first event in an incomplete batch then set the batch creation moment
                        momentBatchStarted = clock::now();
                    }

                    return true;
                }

                case Result::Disabled:
                case Result::Empty:
                default:
                    break;
            }

            // if batch was started
            if (this->batch.size() > 0)
            {
                // check if the batch wait time expired
                std::chrono::seconds batchAge = std::chrono::duration_cast<std::chrono::seconds>(clock::now() - momentBatchStarted);
                if (batchAge.count() >= (int32_t)this->settings->maximalBatchWaitTime)
                {
                    // batch wait time expired, send incomplete batch
                    this->SendBatch();
                    return true;
                }
            }

            return false;
        }
        catch (const std::exception& ex)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WorkerThread method");
            this->isWorkerThreadRunning = false;

            { // LOCK userCallbackMutex
                std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
                if (userExceptionCallback)
                {
                    userExceptionCallback(ex);
                }
            } // UNLOCK userCallbackMutex

            return false;
        }
        catch(...)
        {
            LOG_PIPELINE("A non std::exception was caught in PlayFabEventPipeline::WorkerThread method");
            return false;
        }
    }

    void PlayFabEventPipeline::SendBatch()
    {
        // create a WriteEvents API request to send the batch
        EventsModels::WriteEventsRequest batchReq;
        if (this->settings->authenticationContext != nullptr)
        {
            batchReq.authenticationContext = this->settings->authenticationContext;
        }

        for (const auto& eventEmitRequest : this->batch)
        {
            const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
            batchReq.Events.push_back(playFabEmitRequest->event->eventContents);
        }

        uintptr_t batchId = this->batchCounter.fetch_add(1);
        // add batch to flight tracking map
        void* customData = reinterpret_cast<void*>(batchId); // used to track batches across asynchronous Events API
        this->batchesInFlight[customData] = std::move(this->batch);

        this->batch.clear(); // batch vector will be reused
        this->batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        if(this->settings->emitType == PlayFabEventPipelineType::PlayFabPlayStream)
        {
            // call Events API to send the batch
            PlayFabEventsAPI::WriteEvents(
                batchReq,
                std::bind(&PlayFabEventPipeline::WriteEventsApiCallback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PlayFabEventPipeline::WriteEventsApiErrorCallback, this, std::placeholders::_1, std::placeholders::_2),
                customData);
        }
        else
        {
            // call Events API to send the batch, bypassing Playstream
            PlayFabEventsAPI::WriteTelemetryEvents(
                batchReq,
                std::bind(&PlayFabEventPipeline::WriteEventsApiCallback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PlayFabEventPipeline::WriteEventsApiErrorCallback, this, std::placeholders::_1, std::placeholders::_2),
                customData);
        }
    }

    void PlayFabEventPipeline::WriteEventsApiCallback(const EventsModels::WriteEventsResponse& result, void* customData)
    {
        try
        {
            // batch was successfully sent out, find it in the batch tracking map using customData pointer as a key
            auto foundBatchIterator = this->batchesInFlight.find(customData);
            if (foundBatchIterator == this->batchesInFlight.end())
            {
                LOG_PIPELINE("Untracked batch was returned to EventsAPI.WriteEvents callback"); // normally this never happens
            }
            else
            {
                auto requestBatchPtr = std::shared_ptr<const std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(new std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>(std::move(foundBatchIterator->second)));

                // call individual emit event callbacks
                for (const auto& eventEmitRequest : *requestBatchPtr)
                {
                    const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
                    auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
                    playFabEmitEventResponse->emitEventResult = EmitEventResult::Success;
                    auto playFabError = std::shared_ptr<PlayFabError>(new PlayFabError());
                    playFabError->HttpCode = 200;
                    playFabError->ErrorCode = PlayFabErrorCode::PlayFabErrorSuccess;
                    playFabEmitEventResponse->playFabError = playFabError;
                    playFabEmitEventResponse->writeEventsResponse = std::shared_ptr<EventsModels::WriteEventsResponse>(new EventsModels::WriteEventsResponse(result));
                    playFabEmitEventResponse->batch = requestBatchPtr;
                    playFabEmitEventResponse->batchNumber = static_cast<size_t>(reinterpret_cast<uintptr_t>(customData));

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }

                // remove the batch from tracking map
                this->batchesInFlight.erase(foundBatchIterator->first);
            }
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WriteEventsApiCallback method");
        }
    }

    void PlayFabEventPipeline::WriteEventsApiErrorCallback(const PlayFabError& error, void* customData)
    {
        try
        {
            // batch wasn't sent out due to an error, find it in the batch tracking map using customData pointer as a key
            auto foundBatchIterator = this->batchesInFlight.find(customData);
            if (foundBatchIterator == this->batchesInFlight.end())
            {
                LOG_PIPELINE("Untracked batch was returned to EventsAPI.WriteEvents callback"); // normally this never happens
            }
            else
            {
                auto requestBatchPtr = std::shared_ptr<const std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(new std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>(std::move(foundBatchIterator->second)));

                // call individual emit event callbacks
                for (const auto& eventEmitRequest : *requestBatchPtr)
                {
                    const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
                    auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
                    playFabEmitEventResponse->emitEventResult = EmitEventResult::Success;
                    playFabEmitEventResponse->playFabError = std::shared_ptr<PlayFabError>(new PlayFabError(error));
                    playFabEmitEventResponse->batch = requestBatchPtr;
                    playFabEmitEventResponse->batchNumber = static_cast<size_t>(reinterpret_cast<uintptr_t>(customData));

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }

                // remove the batch from tracking map
                this->batchesInFlight.erase(foundBatchIterator->first);
            }
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WriteEventsApiErrorCallback method");
        }
    }

    void PlayFabEventPipeline::CallbackRequest(std::shared_ptr<const IPlayFabEmitEventRequest> request, std::shared_ptr<const IPlayFabEmitEventResponse> response)
    {
        const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(request);

        if(playFabEmitRequest->callback != nullptr)
        {
            playFabEmitRequest->callback(playFabEmitRequest->event, std::move(response));
        }

        if(playFabEmitRequest->stdCallback != nullptr)
        {
            playFabEmitRequest->stdCallback(playFabEmitRequest->event, std::move(response));
        }
    }
}

#endif
