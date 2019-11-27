#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCloudScriptInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

namespace PlayFabInternal
{
    using namespace CloudScriptModels;

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI()
    {
    }

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    PlayFabCloudScriptInstanceAPI::PlayFabCloudScriptInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->settings = std::move(apiSettings);
        this->authContext = std::move(authenticationContext);
    }

    PlayFabCloudScriptInstanceAPI::~PlayFabCloudScriptInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabCloudScriptInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabCloudScriptInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabCloudScriptInstanceAPI::GetAuthenticationContext() const
    {
        return this->authContext;
    }

    void PlayFabCloudScriptInstanceAPI::SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        this->authContext = std::move(authenticationContext);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabCloudScriptInstanceAPI::GetOrCreateAuthenticationContext()
    {
        if (this->authContext == nullptr)
        {
            this->authContext = std::make_shared<PlayFabAuthenticationContext>();
        }
        
        return this->authContext;
    }

    size_t PlayFabCloudScriptInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabCloudScriptInstanceAPI::ForgetAllCredentials()
    {
        if (this->authContext == nullptr)
            return;

        this->authContext->ForgetAllCredentials();
    }

    // PlayFabCloudScript instance APIs

    void PlayFabCloudScriptInstanceAPI::ExecuteEntityCloudScript(
        ExecuteEntityCloudScriptRequest& request,
        const ProcessApiCallback<ExecuteCloudScriptResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        auto authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/CloudScript/ExecuteEntityCloudScript",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ExecuteCloudScriptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabCloudScriptInstanceAPI::ExecuteFunction(
        ExecuteFunctionRequest& request,
        const ProcessApiCallback<ExecuteFunctionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        auto authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/CloudScript/ExecuteFunction",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnExecuteFunctionResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteFunctionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnExecuteFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ExecuteFunctionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ExecuteFunctionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabCloudScriptInstanceAPI::ListFunctions(
        ListFunctionsRequest& request,
        const ProcessApiCallback<ListFunctionsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        auto authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/CloudScript/ListFunctions",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnListFunctionsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListFunctionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnListFunctionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ListFunctionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListFunctionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabCloudScriptInstanceAPI::RegisterHttpFunction(
        RegisterHttpFunctionRequest& request,
        const ProcessApiCallback<EmptyResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        auto authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/CloudScript/RegisterHttpFunction",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnRegisterHttpFunctionResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnRegisterHttpFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabCloudScriptInstanceAPI::UnregisterFunction(
        UnregisterFunctionRequest& request,
        const ProcessApiCallback<EmptyResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        auto authenticationContext = request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext() : request.authenticationContext;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->GetOrCreateAuthenticationContext()->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/CloudScript/UnregisterFunction",
            headers,
            jsonAsString,
            std::bind(&PlayFabCloudScriptInstanceAPI::OnUnregisterFunctionResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            this->settings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(authenticationContext, this->settings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabCloudScriptInstanceAPI::OnUnregisterFunctionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabCloudScriptInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
    {
        if (container.errorWrapper.HttpCode == 200)
        {
            resultCommon.FromJson(container.errorWrapper.Data);
            resultCommon.Request = container.errorWrapper.Request;
            return true;
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            if (container.errorCallback != nullptr)
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            return false;
        }
    }
}

#endif

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#pragma warning (default: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
