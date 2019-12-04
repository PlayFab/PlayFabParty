#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabAuthenticationDataModels.h>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationAPI
    {
    public:
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

#endif
