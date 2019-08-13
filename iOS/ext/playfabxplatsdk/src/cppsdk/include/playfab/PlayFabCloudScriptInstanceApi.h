#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabCloudScriptDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all CloudScript APIs
    /// </summary>
    class PlayFabCloudScriptInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabCloudScriptInstanceAPI();
        explicit PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabCloudScriptInstanceAPI();
        PlayFabCloudScriptInstanceAPI(const PlayFabCloudScriptInstanceAPI& source) = delete; // disable copy
        PlayFabCloudScriptInstanceAPI(PlayFabCloudScriptInstanceAPI&&) = delete; // disable move
        PlayFabCloudScriptInstanceAPI& operator=(const PlayFabCloudScriptInstanceAPI& source) = delete; // disable assignment
        PlayFabCloudScriptInstanceAPI& operator=(PlayFabCloudScriptInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ExecuteFunction(CloudScriptModels::ExecuteFunctionRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteFunctionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ListFunctions(CloudScriptModels::ListFunctionsRequest& request, ProcessApiCallback<CloudScriptModels::ListFunctionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RegisterHttpFunction(CloudScriptModels::RegisterHttpFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UnregisterFunction(CloudScriptModels::UnregisterFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnExecuteEntityCloudScriptResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnExecuteFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnListFunctionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnRegisterHttpFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUnregisterFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
