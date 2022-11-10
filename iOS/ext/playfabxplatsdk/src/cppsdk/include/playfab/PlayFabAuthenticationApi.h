#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAuthenticationDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFabInternal
{
    class CallRequestContainerBase;
    class CallRequestContainer;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationAPI
    {
    public:
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Authentication.Update();
        /// </summary>
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void ActivateKey(AuthenticationModels::ActivateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::ActivateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateKey(AuthenticationModels::CreateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::CreateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeactivateKey(AuthenticationModels::DeactivateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::DeactivateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteKey(AuthenticationModels::DeleteAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::DeleteAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetKeys(AuthenticationModels::GetAPIKeysRequest& request, const ProcessApiCallback<AuthenticationModels::GetAPIKeysResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAuthenticationAPI(); // Private constructor, static class should never have an instance
        PlayFabAuthenticationAPI(const PlayFabAuthenticationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnActivateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeactivateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetKeysResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnValidateEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif // #if !defined(DISABLE_PLAYFABENTITY_API)
