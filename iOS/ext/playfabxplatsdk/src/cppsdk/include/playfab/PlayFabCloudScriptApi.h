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
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteFunction(CloudScriptModels::ExecuteFunctionRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteFunctionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListFunctions(CloudScriptModels::ListFunctionsRequest& request, ProcessApiCallback<CloudScriptModels::ListFunctionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterHttpFunction(CloudScriptModels::RegisterHttpFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnregisterFunction(CloudScriptModels::UnregisterFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabCloudScriptAPI(); // Private constructor, static class should never have an instance
        PlayFabCloudScriptAPI(const PlayFabCloudScriptAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnExecuteFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnListFunctionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnRegisterHttpFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUnregisterFunctionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
