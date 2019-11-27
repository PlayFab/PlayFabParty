#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabCloudScriptDataModels.h>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all CloudScript APIs
    /// </summary>
    class PlayFabCloudScriptAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, const ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteFunction(CloudScriptModels::ExecuteFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::ExecuteFunctionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListFunctions(CloudScriptModels::ListFunctionsRequest& request, const ProcessApiCallback<CloudScriptModels::ListFunctionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterHttpFunction(CloudScriptModels::RegisterHttpFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnregisterFunction(CloudScriptModels::UnregisterFunctionRequest& request, const ProcessApiCallback<CloudScriptModels::EmptyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabCloudScriptAPI(); // Private constructor, static class should never have an instance
        PlayFabCloudScriptAPI(const PlayFabCloudScriptAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnExecuteFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnListFunctionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnRegisterHttpFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUnregisterFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
