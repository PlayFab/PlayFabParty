#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEvent.h>
#include <playfab/PlayFabEventPipeline.h>

namespace PlayFabInternal
{
    /// <summary>
    /// The enumeration of all built-in event pipelines
    /// </summary>
    enum class EventPipelineKey
    {
        PlayFabPlayStream, // PlayFab (PlayStream) event pipeline
        PlayFabTelemetry // PlayFab event pipeline, bypasses PlayStream
    };

    /// <summary>
    /// Interface for any event router
    /// </summary>
    class IPlayFabEventRouter
    {
    public:
        virtual ~IPlayFabEventRouter() {}
        virtual void RouteEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request) const = 0; // Route an event to pipelines. This method must be thread-safe.
        const std::unordered_map<EventPipelineKey, std::shared_ptr<IPlayFabEventPipeline>>& GetPipelines() const;

        // BUMBLELION: enable manual pumping of event pipeline
        virtual void Update() = 0;

    protected:
        std::unordered_map<EventPipelineKey, std::shared_ptr<IPlayFabEventPipeline>> pipelines;
    };

    /// <summary>
    /// Default implementation of event router
    /// </summary>
    class PlayFabEventRouter: public IPlayFabEventRouter
    {
    public:
        // BUMBLELION: enable manual pumping of event pipeline
        PlayFabEventRouter(bool threadedEventPipeline);
        virtual void RouteEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request) const override;

        // BUMBLELION: enable manual pumping of event pipeline
        void Update() override;

    private:
    };
}

#endif
