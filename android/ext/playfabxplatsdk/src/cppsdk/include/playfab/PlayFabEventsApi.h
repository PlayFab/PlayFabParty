#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFabInternal
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Events APIs
    /// </summary>
    class PlayFabEventsAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Events.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void DeleteEventSamplingRatio(EventsModels::DeleteEventSamplingRatioRequest& request, const ProcessApiCallback<EventsModels::DeleteEventSamplingRatioResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEventSamplingRatio(EventsModels::GetEventSamplingRatioRequest& request, const ProcessApiCallback<EventsModels::GetEventSamplingRatioResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEventSamplingRatios(EventsModels::GetEventSamplingRatiosRequest& request, const ProcessApiCallback<EventsModels::GetEventSamplingRatiosResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetEventSamplingRatio(EventsModels::SetEventSamplingRatioRequest& request, const ProcessApiCallback<EventsModels::SetEventSamplingRatioResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTelemetryEvents(EventsModels::WriteEventsRequest& request, const ProcessApiCallback<EventsModels::WriteEventsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEventsAPI(); // Private constructor, static class should never have an instance
        PlayFabEventsAPI(const PlayFabEventsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnDeleteEventSamplingRatioResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEventSamplingRatioResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEventSamplingRatiosResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetEventSamplingRatioResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnWriteEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnWriteTelemetryEventsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
