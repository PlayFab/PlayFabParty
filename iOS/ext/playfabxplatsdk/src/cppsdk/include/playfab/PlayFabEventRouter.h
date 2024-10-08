#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEventPipeline.h>

#include <unordered_map>

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

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;

        virtual void Update() = 0;
    protected:
        std::unordered_map<EventPipelineKey, std::shared_ptr<IPlayFabEventPipeline>> pipelines;

        std::shared_ptr<PlayFabApiSettings> apiSettings;
        std::shared_ptr<PlayFabAuthenticationContext> authenticationContext;
    };

    /// <summary>
    /// Default implementation of event router
    /// </summary>
    class PlayFabEventRouter : public IPlayFabEventRouter
    {
    public:
        PlayFabEventRouter(bool threadedEventPipeline);

        PlayFabEventRouter(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext, bool threadedEventPipeline);
        PlayFabEventRouter(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext, bool threadedEventPipeline);

        virtual void RouteEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request) const override;

        /// <summary>
        /// Updates underlying PlayFabEventPipeline
        /// This function must be called every game tick if threadedEventPipeline is set to false
        /// </summary>
        virtual void Update() override;
    private:
    };
}

#endif
