#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEconomyApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#pragma warning (disable: 4100) // formal parameters are part of a public interface
#endif // defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

namespace PlayFabInternal
{
    using namespace EconomyModels;

    size_t PlayFabEconomyAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabEconomyAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabEconomy APIs

    void PlayFabEconomyAPI::AddVirtualCurrencies(
        AddVirtualCurrenciesRequest& request,
        const ProcessApiCallback<AddVirtualCurrenciesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/AddVirtualCurrencies",
            headers,
            jsonAsString,
            OnAddVirtualCurrenciesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddVirtualCurrenciesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnAddVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        AddVirtualCurrenciesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddVirtualCurrenciesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::ConsumeInventoryItems(
        ConsumeInventoryItemsRequest& request,
        const ProcessApiCallback<ConsumeInventoryItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/ConsumeInventoryItems",
            headers,
            jsonAsString,
            OnConsumeInventoryItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnConsumeInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ConsumeInventoryItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ConsumeInventoryItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CraftRecipeByFriendlyId(
        CraftRecipeByFriendlyIdRequest& request,
        const ProcessApiCallback<CraftRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CraftRecipeByFriendlyId",
            headers,
            jsonAsString,
            OnCraftRecipeByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CraftRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCraftRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CraftRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CraftRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CraftRecipeById(
        CraftRecipeByIdRequest& request,
        const ProcessApiCallback<CraftRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CraftRecipeById",
            headers,
            jsonAsString,
            OnCraftRecipeByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CraftRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCraftRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CraftRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CraftRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateBundle(
        CreateBundleRequest& request,
        const ProcessApiCallback<CreateBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateBundle",
            headers,
            jsonAsString,
            OnCreateBundleResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateCurrency(
        CreateCurrencyRequest& request,
        const ProcessApiCallback<CreateCurrencyResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateCurrency",
            headers,
            jsonAsString,
            OnCreateCurrencyResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateDraftItem(
        CreateDraftItemRequest& request,
        const ProcessApiCallback<CreateDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateDraftItem",
            headers,
            jsonAsString,
            OnCreateDraftItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateDraftUgcItem(
        CreateDraftItemRequest& request,
        const ProcessApiCallback<CreateDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/CreateDraftUgcItem",
            headers,
            jsonAsString,
            OnCreateDraftUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateOrUpdateReview(
        CreateOrUpdateReviewRequest& request,
        const ProcessApiCallback<CreateOrUpdateReviewResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateOrUpdateReview",
            headers,
            jsonAsString,
            OnCreateOrUpdateReviewResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateOrUpdateReviewResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateOrUpdateReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateOrUpdateReviewResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateOrUpdateReviewResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateRecipe(
        CreateRecipeRequest& request,
        const ProcessApiCallback<CreateRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateRecipe",
            headers,
            jsonAsString,
            OnCreateRecipeResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateStore(
        CreateStoreRequest& request,
        const ProcessApiCallback<CreateStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateStore",
            headers,
            jsonAsString,
            OnCreateStoreResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateSubscription(
        CreateSubscriptionRequest& request,
        const ProcessApiCallback<CreateSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateSubscription",
            headers,
            jsonAsString,
            OnCreateSubscriptionResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateUgcUploadUrls(
        CreateUploadUrlsRequest& request,
        const ProcessApiCallback<CreateUploadUrlsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/CreateUgcUploadUrls",
            headers,
            jsonAsString,
            OnCreateUgcUploadUrlsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateUploadUrlsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateUgcUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateUploadUrlsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateUploadUrlsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::CreateUploadUrls(
        CreateUploadUrlsRequest& request,
        const ProcessApiCallback<CreateUploadUrlsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/CreateUploadUrls",
            headers,
            jsonAsString,
            OnCreateUploadUrlsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateUploadUrlsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CreateUploadUrlsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateUploadUrlsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteBundleByFriendlyId(
        DeleteBundleByFriendlyIdRequest& request,
        const ProcessApiCallback<DeleteBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteBundleByFriendlyId",
            headers,
            jsonAsString,
            OnDeleteBundleByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteBundleById(
        DeleteBundleByIdRequest& request,
        const ProcessApiCallback<DeleteBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteBundleById",
            headers,
            jsonAsString,
            OnDeleteBundleByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteItem(
        DeleteItemRequest& request,
        const ProcessApiCallback<DeleteItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteItem",
            headers,
            jsonAsString,
            OnDeleteItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteRecipeByFriendlyId(
        DeleteRecipeByFriendlyIdRequest& request,
        const ProcessApiCallback<DeleteRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteRecipeByFriendlyId",
            headers,
            jsonAsString,
            OnDeleteRecipeByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteRecipeById(
        DeleteRecipeByIdRequest& request,
        const ProcessApiCallback<DeleteRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteRecipeById",
            headers,
            jsonAsString,
            OnDeleteRecipeByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteStoreByFriendlyId(
        DeleteStoreByFriendlyIdRequest& request,
        const ProcessApiCallback<DeleteStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteStoreByFriendlyId",
            headers,
            jsonAsString,
            OnDeleteStoreByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteStoreById(
        DeleteStoreByIdRequest& request,
        const ProcessApiCallback<DeleteStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteStoreById",
            headers,
            jsonAsString,
            OnDeleteStoreByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteSubscriptionByFriendlyId(
        DeleteSubscriptionByFriendlyIdRequest& request,
        const ProcessApiCallback<DeleteSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteSubscriptionByFriendlyId",
            headers,
            jsonAsString,
            OnDeleteSubscriptionByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteSubscriptionById(
        DeleteSubscriptionByIdRequest& request,
        const ProcessApiCallback<DeleteSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/DeleteSubscriptionById",
            headers,
            jsonAsString,
            OnDeleteSubscriptionByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::DeleteUgcItem(
        DeleteItemRequest& request,
        const ProcessApiCallback<DeleteItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/DeleteUgcItem",
            headers,
            jsonAsString,
            OnDeleteUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnDeleteUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        DeleteItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetBundleByFriendlyId(
        GetBundleByFriendlyIdRequest& request,
        const ProcessApiCallback<GetBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetBundleByFriendlyId",
            headers,
            jsonAsString,
            OnGetBundleByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetBundleById(
        GetBundleByIdRequest& request,
        const ProcessApiCallback<GetBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetBundleById",
            headers,
            jsonAsString,
            OnGetBundleByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetBundleByMarketplaceOfferId(
        GetBundleByMarketplaceOfferIdRequest& request,
        const ProcessApiCallback<GetBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetBundleByMarketplaceOfferId",
            headers,
            jsonAsString,
            OnGetBundleByMarketplaceOfferIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetBundleByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetCatalogConfig(
        GetCatalogConfigRequest& request,
        const ProcessApiCallback<GetCatalogConfigResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetCatalogConfig",
            headers,
            jsonAsString,
            OnGetCatalogConfigResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogConfigResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetCatalogConfigResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCatalogConfigResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetCurrencyById(
        GetCurrencyByIdRequest& request,
        const ProcessApiCallback<GetCurrencyByIdResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetCurrencyById",
            headers,
            jsonAsString,
            OnGetCurrencyByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCurrencyByIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetCurrencyByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetCurrencyByIdResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCurrencyByIdResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetDraftItem(
        GetDraftItemRequest& request,
        const ProcessApiCallback<GetDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetDraftItem",
            headers,
            jsonAsString,
            OnGetDraftItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetDraftItems(
        GetDraftItemsRequest& request,
        const ProcessApiCallback<GetDraftItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetDraftItems",
            headers,
            jsonAsString,
            OnGetDraftItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetDraftItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetDraftItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetDraftUgcItem(
        GetDraftItemRequest& request,
        const ProcessApiCallback<GetDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/GetDraftUgcItem",
            headers,
            jsonAsString,
            OnGetDraftUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetDraftUgcItems(
        GetDraftItemsRequest& request,
        const ProcessApiCallback<GetDraftItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/GetDraftUgcItems",
            headers,
            jsonAsString,
            OnGetDraftUgcItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDraftItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetDraftUgcItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetDraftItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetDraftItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetInventoryItems(
        GetInventoryItemsRequest& request,
        const ProcessApiCallback<GetInventoryItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/GetInventoryItems",
            headers,
            jsonAsString,
            OnGetInventoryItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetInventoryItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetInventoryItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetItemReviews(
        GetReviewsRequest& request,
        const ProcessApiCallback<GetReviewsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetItemReviews",
            headers,
            jsonAsString,
            OnGetItemReviewsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetReviewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetReviewsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetReviewsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetItemReviewSummary(
        ReviewSummaryRequest& request,
        const ProcessApiCallback<ReviewSummaryResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetItemReviewSummary",
            headers,
            jsonAsString,
            OnGetItemReviewSummaryResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReviewSummaryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ReviewSummaryResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ReviewSummaryResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetMyReview(
        GetMyReviewRequest& request,
        const ProcessApiCallback<GetMyReviewResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetMyReview",
            headers,
            jsonAsString,
            OnGetMyReviewResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMyReviewResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetMyReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetMyReviewResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetMyReviewResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetPublishedItem(
        GetPublishedItemRequest& request,
        const ProcessApiCallback<GetPublishedItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetPublishedItem",
            headers,
            jsonAsString,
            OnGetPublishedItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublishedItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetPublishedItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetPublishedItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPublishedItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetPublishedUgcItem(
        GetPublishedItemRequest& request,
        const ProcessApiCallback<GetPublishedItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/GetPublishedUgcItem",
            headers,
            jsonAsString,
            OnGetPublishedUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublishedItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetPublishedUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetPublishedItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPublishedItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetPublishStatus(
        PublishStatusRequest& request,
        const ProcessApiCallback<PublishStatusResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetPublishStatus",
            headers,
            jsonAsString,
            OnGetPublishStatusResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PublishStatusResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PublishStatusResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PublishStatusResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetRecipeByFriendlyId(
        GetRecipeByFriendlyIdRequest& request,
        const ProcessApiCallback<GetRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetRecipeByFriendlyId",
            headers,
            jsonAsString,
            OnGetRecipeByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetRecipeById(
        GetRecipeByIdRequest& request,
        const ProcessApiCallback<GetRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetRecipeById",
            headers,
            jsonAsString,
            OnGetRecipeByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetRecipeByMarketplaceOfferId(
        GetRecipeByMarketplaceOfferIdRequest& request,
        const ProcessApiCallback<GetRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetRecipeByMarketplaceOfferId",
            headers,
            jsonAsString,
            OnGetRecipeByMarketplaceOfferIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetRecipeByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetStoreByFriendlyId(
        GetStoreByFriendlyIdRequest& request,
        const ProcessApiCallback<GetStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetStoreByFriendlyId",
            headers,
            jsonAsString,
            OnGetStoreByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetStoreById(
        GetStoreByIdRequest& request,
        const ProcessApiCallback<GetStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetStoreById",
            headers,
            jsonAsString,
            OnGetStoreByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetSubscriptionByFriendlyId(
        GetSubscriptionByFriendlyIdRequest& request,
        const ProcessApiCallback<GetSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetSubscriptionByFriendlyId",
            headers,
            jsonAsString,
            OnGetSubscriptionByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetSubscriptionById(
        GetSubscriptionByIdRequest& request,
        const ProcessApiCallback<GetSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetSubscriptionById",
            headers,
            jsonAsString,
            OnGetSubscriptionByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetSubscriptionByMarketplaceOfferId(
        GetSubscriptionByMarketplaceOfferIdRequest& request,
        const ProcessApiCallback<GetSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/GetSubscriptionByMarketplaceOfferId",
            headers,
            jsonAsString,
            OnGetSubscriptionByMarketplaceOfferIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetSubscriptionByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetUgcItemModerationState(
        GetUgcItemModerationStateRequest& request,
        const ProcessApiCallback<GetUgcItemModerationStateResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/GetUgcItemModerationState",
            headers,
            jsonAsString,
            OnGetUgcItemModerationStateResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUgcItemModerationStateResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetUgcItemModerationStateResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUgcItemModerationStateResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetUgcPublishStatus(
        PublishStatusRequest& request,
        const ProcessApiCallback<PublishStatusResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/GetUgcPublishStatus",
            headers,
            jsonAsString,
            OnGetUgcPublishStatusResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PublishStatusResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetUgcPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PublishStatusResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PublishStatusResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GetVirtualCurrencies(
        GetVirtualCurrenciesRequest& request,
        const ProcessApiCallback<GetVirtualCurrenciesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/GetVirtualCurrencies",
            headers,
            jsonAsString,
            OnGetVirtualCurrenciesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetVirtualCurrenciesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetVirtualCurrenciesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetVirtualCurrenciesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::GrantInventoryItems(
        GrantInventoryItemsRequest& request,
        const ProcessApiCallback<GrantInventoryItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/GrantInventoryItems",
            headers,
            jsonAsString,
            OnGrantInventoryItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnGrantInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GrantInventoryItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GrantInventoryItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::PublishItem(
        PublishItemRequest& request,
        const ProcessApiCallback<PublishItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/PublishItem",
            headers,
            jsonAsString,
            OnPublishItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PublishItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnPublishItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PublishItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PublishItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::PublishUgcItem(
        PublishItemRequest& request,
        const ProcessApiCallback<PublishItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/PublishUgcItem",
            headers,
            jsonAsString,
            OnPublishUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PublishItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnPublishUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PublishItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PublishItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::PurchaseItemByFriendlyId(
        PurchaseItemByFriendlyIdRequest& request,
        const ProcessApiCallback<PurchaseItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/PurchaseItemByFriendlyId",
            headers,
            jsonAsString,
            OnPurchaseItemByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnPurchaseItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PurchaseItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PurchaseItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::PurchaseItemById(
        PurchaseItemByIdRequest& request,
        const ProcessApiCallback<PurchaseItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/PurchaseItemById",
            headers,
            jsonAsString,
            OnPurchaseItemByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnPurchaseItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PurchaseItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PurchaseItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::ReportReview(
        ReportReviewRequest& request,
        const ProcessApiCallback<ReportReviewResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/ReportReview",
            headers,
            jsonAsString,
            OnReportReviewResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportReviewResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnReportReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ReportReviewResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ReportReviewResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::ReportUgcItem(
        ReportItemRequest& request,
        const ProcessApiCallback<ReportItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/ReportUgcItem",
            headers,
            jsonAsString,
            OnReportUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnReportUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ReportItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ReportItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::Search(
        CatalogSearchRequest& request,
        const ProcessApiCallback<CatalogSearchResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/Search",
            headers,
            jsonAsString,
            OnSearchResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CatalogSearchResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        CatalogSearchResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CatalogSearchResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchBundles(
        SearchBundlesRequest& request,
        const ProcessApiCallback<SearchBundlesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchBundles",
            headers,
            jsonAsString,
            OnSearchBundlesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchBundlesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchBundlesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchBundlesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchBundlesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchForItemsContainingItemByFriendlyId(
        SearchForItemsContainingItemByFriendlyIdRequest& request,
        const ProcessApiCallback<SearchForItemsContainingItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchForItemsContainingItemByFriendlyId",
            headers,
            jsonAsString,
            OnSearchForItemsContainingItemByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchForItemsContainingItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchForItemsContainingItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchForItemsContainingItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchForItemsContainingItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchForItemsContainingItemById(
        SearchForItemsContainingItemByIdRequest& request,
        const ProcessApiCallback<SearchForItemsContainingItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchForItemsContainingItemById",
            headers,
            jsonAsString,
            OnSearchForItemsContainingItemByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchForItemsContainingItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchForItemsContainingItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchForItemsContainingItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchForItemsContainingItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchInStoreByFriendlyId(
        SearchInStoreByFriendlyIdRequest& request,
        const ProcessApiCallback<SearchInStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchInStoreByFriendlyId",
            headers,
            jsonAsString,
            OnSearchInStoreByFriendlyIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchInStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchInStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchInStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchInStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchInStoreById(
        SearchInStoreByIdRequest& request,
        const ProcessApiCallback<SearchInStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchInStoreById",
            headers,
            jsonAsString,
            OnSearchInStoreByIdResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchInStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchInStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchInStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchInStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchRecipes(
        SearchRecipesRequest& request,
        const ProcessApiCallback<SearchRecipesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchRecipes",
            headers,
            jsonAsString,
            OnSearchRecipesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchRecipesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchRecipesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchRecipesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchRecipesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchStores(
        SearchStoresRequest& request,
        const ProcessApiCallback<SearchStoresResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchStores",
            headers,
            jsonAsString,
            OnSearchStoresResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchStoresResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchStoresResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchStoresResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchStoresResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SearchSubscriptions(
        SearchSubscriptionsRequest& request,
        const ProcessApiCallback<SearchSubscriptionsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SearchSubscriptions",
            headers,
            jsonAsString,
            OnSearchSubscriptionsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SearchSubscriptionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSearchSubscriptionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SearchSubscriptionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SearchSubscriptionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SetInventoryItems(
        SetInventoryItemsRequest& request,
        const ProcessApiCallback<SetInventoryItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/SetInventoryItems",
            headers,
            jsonAsString,
            OnSetInventoryItemsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetInventoryItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetInventoryItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SetUgcItemModerationState(
        SetUgcItemModerationStateRequest& request,
        const ProcessApiCallback<SetUgcItemModerationStateResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/SetUgcItemModerationState",
            headers,
            jsonAsString,
            OnSetUgcItemModerationStateResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetUgcItemModerationStateResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetUgcItemModerationStateResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetUgcItemModerationStateResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SetVirtualCurrencies(
        SetVirtualCurrenciesRequest& request,
        const ProcessApiCallback<SetVirtualCurrenciesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/SetVirtualCurrencies",
            headers,
            jsonAsString,
            OnSetVirtualCurrenciesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetVirtualCurrenciesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetVirtualCurrenciesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetVirtualCurrenciesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SubmitHelpfulnessVote(
        HelpfulnessVoteRequest& request,
        const ProcessApiCallback<HelpfulnessVoteResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/SubmitHelpfulnessVote",
            headers,
            jsonAsString,
            OnSubmitHelpfulnessVoteResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<HelpfulnessVoteResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSubmitHelpfulnessVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        HelpfulnessVoteResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<HelpfulnessVoteResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::SubtractVirtualCurrencies(
        SubtractVirtualCurrenciesRequest& request,
        const ProcessApiCallback<SubtractVirtualCurrenciesResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/SubtractVirtualCurrencies",
            headers,
            jsonAsString,
            OnSubtractVirtualCurrenciesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SubtractVirtualCurrenciesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnSubtractVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SubtractVirtualCurrenciesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SubtractVirtualCurrenciesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::TakedownReviews(
        TakedownReviewsRequest& request,
        const ProcessApiCallback<TakedownReviewsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/TakedownReviews",
            headers,
            jsonAsString,
            OnTakedownReviewsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<TakedownReviewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnTakedownReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        TakedownReviewsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<TakedownReviewsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateBundle(
        UpdateBundleRequest& request,
        const ProcessApiCallback<UpdateBundleResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateBundle",
            headers,
            jsonAsString,
            OnUpdateBundleResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBundleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateBundleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateBundleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateCatalogConfig(
        UpdateCatalogConfigRequest& request,
        const ProcessApiCallback<UpdateCatalogConfigResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateCatalogConfig",
            headers,
            jsonAsString,
            OnUpdateCatalogConfigResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogConfigResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateCatalogConfigResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogConfigResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateCurrency(
        UpdateCurrencyRequest& request,
        const ProcessApiCallback<UpdateCurrencyResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateCurrency",
            headers,
            jsonAsString,
            OnUpdateCurrencyResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateDraftItem(
        UpdateDraftItemRequest& request,
        const ProcessApiCallback<UpdateDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateDraftItem",
            headers,
            jsonAsString,
            OnUpdateDraftItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateDraftUgcItem(
        UpdateDraftItemRequest& request,
        const ProcessApiCallback<UpdateDraftItemResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/UserGeneratedContent/UpdateDraftUgcItem",
            headers,
            jsonAsString,
            OnUpdateDraftUgcItemResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateDraftItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateDraftItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateDraftItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateInventoryItemsProperties(
        UpdateInventoryItemsPropertiesRequest& request,
        const ProcessApiCallback<UpdateInventoryPropertiesItemsResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Inventory/UpdateInventoryItemsProperties",
            headers,
            jsonAsString,
            OnUpdateInventoryItemsPropertiesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateInventoryPropertiesItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateInventoryItemsPropertiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateInventoryPropertiesItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateInventoryPropertiesItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateRecipe(
        UpdateRecipeRequest& request,
        const ProcessApiCallback<UpdateRecipeResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateRecipe",
            headers,
            jsonAsString,
            OnUpdateRecipeResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateRecipeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateRecipeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateRecipeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateStore(
        UpdateStoreRequest& request,
        const ProcessApiCallback<UpdateStoreResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateStore",
            headers,
            jsonAsString,
            OnUpdateStoreResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabEconomyAPI::UpdateSubscription(
        UpdateSubscriptionRequest& request,
        const ProcessApiCallback<UpdateSubscriptionResult> callback,
        const ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();
        std::string jsonAsString = requestJson.toStyledString();

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Catalog/UpdateSubscription",
            headers,
            jsonAsString,
            OnUpdateSubscriptionResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSubscriptionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings(request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEconomyAPI::OnUpdateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UpdateSubscriptionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateSubscriptionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabEconomyAPI::ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
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
