#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabAuthenticationDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFabInternal
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabAuthenticationInstanceAPI();
        PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings);
        PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabAuthenticationInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabAuthenticationInstanceAPI() = default;
        PlayFabAuthenticationInstanceAPI(const PlayFabAuthenticationInstanceAPI& source) = delete; // disable copy
        PlayFabAuthenticationInstanceAPI(PlayFabAuthenticationInstanceAPI&&) = delete; // disable move
        PlayFabAuthenticationInstanceAPI& operator=(const PlayFabAuthenticationInstanceAPI& source) = delete; // disable assignment
        PlayFabAuthenticationInstanceAPI& operator=(PlayFabAuthenticationInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Authentication.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void ActivateKey(AuthenticationModels::ActivateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::ActivateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateKey(AuthenticationModels::CreateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::CreateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeactivateKey(AuthenticationModels::DeactivateAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::DeactivateAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteKey(AuthenticationModels::DeleteAPIKeyRequest& request, const ProcessApiCallback<AuthenticationModels::DeleteAPIKeyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetKeys(AuthenticationModels::GetAPIKeysRequest& request, const ProcessApiCallback<AuthenticationModels::GetAPIKeysResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, const ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnActivateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeactivateKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteKeyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetKeysResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnValidateEntityTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
