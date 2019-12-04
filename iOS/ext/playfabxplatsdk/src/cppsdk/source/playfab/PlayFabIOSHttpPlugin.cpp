#include <stdafx.h>

#include <playfab/PlayFabIOSHttpPlugin.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabIOSPostRequestCPP.h>

#include <stdexcept>
#include <vector>

namespace PlayFabInternal
{
    PlayFabIOSHttpPlugin::PlayFabIOSHttpPlugin()
    {
        activeRequestCount = 0;
        threadRunning = true;
        workerThread = std::thread(&PlayFabIOSHttpPlugin::WorkerThread, this);
    };

    PlayFabIOSHttpPlugin::~PlayFabIOSHttpPlugin()
    {
        threadRunning = false;
        try
        {
            workerThread.join();
        }
        catch (...)
        {
        }
    }

    void PlayFabIOSHttpPlugin::WorkerThread()
    {
        size_t queueSize;

        while (this->threadRunning)
        {
            std::unique_ptr<CallRequestContainerBase> requestContainer = nullptr;

            { // LOCK httpRequestMutex
                std::unique_lock<std::mutex> lock(this->httpRequestMutex);

                queueSize = this->pendingRequests.size();
                if (queueSize != 0)
                {
                    requestContainer = std::move(this->pendingRequests[0]);
                    this->pendingRequests.pop_front();
                }
            } // UNLOCK httpRequestMutex

            if (queueSize == 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                continue;
            }

            if (requestContainer != nullptr)
            {
                CallRequestContainer* requestContainerPtr = dynamic_cast<CallRequestContainer*>(requestContainer.get());
                if (requestContainerPtr != nullptr)
                {
                    requestContainer.release();
                    ExecuteRequest(std::unique_ptr<CallRequestContainer>(requestContainerPtr));
                }
            }
        }
    }

    void PlayFabIOSHttpPlugin::HandleCallback(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;
        reqContainer.finished = true;
        if (PlayFabSettings::threadedCallbacks)
        {
            HandleResults(std::move(requestContainer));
        }
        else
        {
            { // LOCK httpRequestMutex
                std::unique_lock<std::mutex> lock(httpRequestMutex);
                pendingResults.push_back(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(requestContainer.release())));
            } // UNLOCK httpRequestMutex
        }
    }

    void PlayFabIOSHttpPlugin::MakePostRequest(std::unique_ptr<CallRequestContainerBase> requestContainer)
    {
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            pendingRequests.push_back(std::move(requestContainer));
            activeRequestCount++;
        } // UNLOCK httpRequestMutex
    }

    void PlayFabIOSHttpPlugin::ExecuteRequest(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;

        std::string url = GetUrl(reqContainer);
        std::string requestBody = std::move(reqContainer.GetRequestBody());
        
        PlayFabIOSPostRequestCPP::prepare(url, requestBody);
        PlayFabIOSPostRequestCPP::SetPlayFabPredefinedHeaders();
        auto headers = reqContainer.GetRequestHeaders();
        if(headers.size() > 0)
        {
            for (auto const &obj : headers)
            {
                if (obj.first.length() != 0 && obj.second.length() != 0) // no empty keys or values in headers
                {
                    std::string headerK = obj.first;
                    std::string headerV = obj.second;
                    PlayFabIOSPostRequestCPP::AddContainerHeaders(headerK, headerV);
                }
            }
        }
		Int32 httpStatusCode = 0;
		bool bResult = false;

        //pass in the reqComtainer just to store the return status and response data
        bResult = PlayFabIOSPostRequestCPP::open(reqContainer, httpStatusCode);
            
        if (bResult)
        {
            ProcessResponse(reqContainer, httpStatusCode);
        }
     
         
        HandleCallback(std::move(requestContainer));
    }

    std::string PlayFabIOSHttpPlugin::GetUrl(CallRequestContainer& reqContainer) const
    {
        return PlayFabSettings::GetUrl(reqContainer.GetUrl(), PlayFabSettings::requestGetParams);
    }

    void PlayFabIOSHttpPlugin::SetPredefinedHeaders(CallRequestContainer& requestContainer, void* hRequest)
    {
  
    }

    bool PlayFabIOSHttpPlugin::GetBinaryPayload(CallRequestContainer& reqContainer, void* payload, int32_t payloadSize) const
    {
        return false;
    }

    void PlayFabIOSHttpPlugin::ProcessResponse(CallRequestContainer& reqContainer, const int httpCode)
    {
        Json::CharReaderBuilder jsonReaderFactory;
        std::unique_ptr<Json::CharReader> jsonReader(jsonReaderFactory.newCharReader());
        JSONCPP_STRING jsonParseErrors;
        const bool parsedSuccessfully = jsonReader->parse(reqContainer.responseString.c_str(), reqContainer.responseString.c_str() + reqContainer.responseString.length(), &reqContainer.responseJson, &jsonParseErrors);

        if (parsedSuccessfully)
        {
            // fully successful response
            reqContainer.errorWrapper.HttpCode = reqContainer.responseJson.get("code", Json::Value::null).asInt();
            reqContainer.errorWrapper.HttpStatus = reqContainer.responseJson.get("status", Json::Value::null).asString();
            reqContainer.errorWrapper.Data = reqContainer.responseJson.get("data", Json::Value::null);
            reqContainer.errorWrapper.ErrorName = reqContainer.responseJson.get("error", Json::Value::null).asString();
            reqContainer.errorWrapper.ErrorMessage = reqContainer.responseJson.get("errorMessage", Json::Value::null).asString();
            reqContainer.errorWrapper.ErrorDetails = reqContainer.responseJson.get("errorDetails", Json::Value::null);
        }
        else
        {
            reqContainer.errorWrapper.HttpCode = httpCode;
            reqContainer.errorWrapper.HttpStatus = reqContainer.responseString;
            reqContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorPartialFailure;
            reqContainer.errorWrapper.ErrorName = "Failed to parse PlayFab response";
            reqContainer.errorWrapper.ErrorMessage = jsonParseErrors;
        }
    }

    void PlayFabIOSHttpPlugin::SetErrorInfo(CallRequestContainer& requestContainer, const std::string& errorMessage, const int httpCode) const
    {
        requestContainer.errorWrapper.HttpCode = httpCode;
        requestContainer.errorWrapper.HttpStatus = errorMessage;
        requestContainer.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorUnknownError;
        requestContainer.errorWrapper.ErrorName = errorMessage;
    }

    void PlayFabIOSHttpPlugin::HandleResults(std::unique_ptr<CallRequestContainer> requestContainer)
    {
        CallRequestContainer& reqContainer = *requestContainer;
        auto callback = reqContainer.GetCallback();
        if (callback != nullptr)
        {
            callback(
                reqContainer.responseJson.get("code", Json::Value::null).asInt(),
                reqContainer.responseString,
                std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(requestContainer.release())));
        }
    }

    size_t PlayFabIOSHttpPlugin::Update()
    {
        if (PlayFabSettings::threadedCallbacks)
        {
            throw std::runtime_error("You should not call Update() when PlayFabSettings::threadedCallbacks == true");
        }

        std::unique_ptr<CallRequestContainerBase> requestContainer = nullptr;
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            if (pendingResults.empty())
            {
                return activeRequestCount;
            }

            requestContainer = std::move(this->pendingResults[0]);
            this->pendingResults.pop_front();
            activeRequestCount--;
        } // UNLOCK httpRequestMutex

        HandleResults(std::unique_ptr<CallRequestContainer>(static_cast<CallRequestContainer*>(requestContainer.release())));

        // activeRequestCount can be altered by HandleResults, so we have to re-lock and return an updated value
        { // LOCK httpRequestMutex
            std::unique_lock<std::mutex> lock(httpRequestMutex);
            return activeRequestCount;
        }
    }
}
