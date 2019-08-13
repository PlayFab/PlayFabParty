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
        static void ActivateKey(AuthenticationModels::ActivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::ActivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateKey(AuthenticationModels::CreateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::CreateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeactivateKey(AuthenticationModels::DeactivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeactivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteKey(AuthenticationModels::DeleteAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeleteAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetKeys(AuthenticationModels::GetAPIKeysRequest& request, ProcessApiCallback<AuthenticationModels::GetAPIKeysResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAuthenticationAPI(); // Private constructor, static class should never have an instance
        PlayFabAuthenticationAPI(const PlayFabAuthenticationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnActivateKeyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateKeyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeactivateKeyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteKeyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetEntityTokenResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetKeysResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnValidateEntityTokenResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
