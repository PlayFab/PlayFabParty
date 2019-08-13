#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabEconomyDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Economy APIs
    /// </summary>
    class PlayFabEconomyInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabEconomyInstanceAPI();
        explicit PlayFabEconomyInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabEconomyInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabEconomyInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabEconomyInstanceAPI();
        PlayFabEconomyInstanceAPI(const PlayFabEconomyInstanceAPI& source) = delete; // disable copy
        PlayFabEconomyInstanceAPI(PlayFabEconomyInstanceAPI&&) = delete; // disable move
        PlayFabEconomyInstanceAPI& operator=(const PlayFabEconomyInstanceAPI& source) = delete; // disable assignment
        PlayFabEconomyInstanceAPI& operator=(PlayFabEconomyInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AddVirtualCurrencies(EconomyModels::AddVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::AddVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeInventoryItems(EconomyModels::ConsumeInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::ConsumeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateBundle(EconomyModels::CreateBundleRequest& request, ProcessApiCallback<EconomyModels::CreateBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateCurrency(EconomyModels::CreateCurrencyRequest& request, ProcessApiCallback<EconomyModels::CreateCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftUgcItem(EconomyModels::CreateDraftItemRequest& request, ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateReview(EconomyModels::CreateOrUpdateReviewRequest& request, ProcessApiCallback<EconomyModels::CreateOrUpdateReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateStore(EconomyModels::CreateStoreRequest& request, ProcessApiCallback<EconomyModels::CreateStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateSubscription(EconomyModels::CreateSubscriptionRequest& request, ProcessApiCallback<EconomyModels::CreateSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUgcUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteBundleByFriendlyId(EconomyModels::DeleteBundleByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteBundleById(EconomyModels::DeleteBundleByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteItem(EconomyModels::DeleteItemRequest& request, ProcessApiCallback<EconomyModels::DeleteItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStoreByFriendlyId(EconomyModels::DeleteStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStoreById(EconomyModels::DeleteStoreByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSubscriptionByFriendlyId(EconomyModels::DeleteSubscriptionByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSubscriptionById(EconomyModels::DeleteSubscriptionByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteUgcItem(EconomyModels::DeleteItemRequest& request, ProcessApiCallback<EconomyModels::DeleteItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleByFriendlyId(EconomyModels::GetBundleByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleById(EconomyModels::GetBundleByIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleByMarketplaceOfferId(EconomyModels::GetBundleByMarketplaceOfferIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, ProcessApiCallback<EconomyModels::GetCatalogConfigResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCurrencyById(EconomyModels::GetCurrencyByIdRequest& request, ProcessApiCallback<EconomyModels::GetCurrencyByIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItem(EconomyModels::GetDraftItemRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftUgcItem(EconomyModels::GetDraftItemRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftUgcItems(EconomyModels::GetDraftItemsRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::GetInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviews(EconomyModels::GetReviewsRequest& request, ProcessApiCallback<EconomyModels::GetReviewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviewSummary(EconomyModels::ReviewSummaryRequest& request, ProcessApiCallback<EconomyModels::ReviewSummaryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMyReview(EconomyModels::GetMyReviewRequest& request, ProcessApiCallback<EconomyModels::GetMyReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishedItem(EconomyModels::GetPublishedItemRequest& request, ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishedUgcItem(EconomyModels::GetPublishedItemRequest& request, ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishStatus(EconomyModels::PublishStatusRequest& request, ProcessApiCallback<EconomyModels::PublishStatusResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStoreByFriendlyId(EconomyModels::GetStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStoreById(EconomyModels::GetStoreByIdRequest& request, ProcessApiCallback<EconomyModels::GetStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionByFriendlyId(EconomyModels::GetSubscriptionByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionById(EconomyModels::GetSubscriptionByIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionByMarketplaceOfferId(EconomyModels::GetSubscriptionByMarketplaceOfferIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUgcItemModerationState(EconomyModels::GetUgcItemModerationStateRequest& request, ProcessApiCallback<EconomyModels::GetUgcItemModerationStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUgcPublishStatus(EconomyModels::PublishStatusRequest& request, ProcessApiCallback<EconomyModels::PublishStatusResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetVirtualCurrencies(EconomyModels::GetVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::GetVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantInventoryItems(EconomyModels::GrantInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::GrantInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishItem(EconomyModels::PublishItemRequest& request, ProcessApiCallback<EconomyModels::PublishItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishUgcItem(EconomyModels::PublishItemRequest& request, ProcessApiCallback<EconomyModels::PublishItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseItemByFriendlyId(EconomyModels::PurchaseItemByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseItemById(EconomyModels::PurchaseItemByIdRequest& request, ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportReview(EconomyModels::ReportReviewRequest& request, ProcessApiCallback<EconomyModels::ReportReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportUgcItem(EconomyModels::ReportItemRequest& request, ProcessApiCallback<EconomyModels::ReportItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void Search(EconomyModels::CatalogSearchRequest& request, ProcessApiCallback<EconomyModels::CatalogSearchResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchBundles(EconomyModels::SearchBundlesRequest& request, ProcessApiCallback<EconomyModels::SearchBundlesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchForItemsContainingItemByFriendlyId(EconomyModels::SearchForItemsContainingItemByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchForItemsContainingItemById(EconomyModels::SearchForItemsContainingItemByIdRequest& request, ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchInStoreByFriendlyId(EconomyModels::SearchInStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchInStoreById(EconomyModels::SearchInStoreByIdRequest& request, ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchStores(EconomyModels::SearchStoresRequest& request, ProcessApiCallback<EconomyModels::SearchStoresResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchSubscriptions(EconomyModels::SearchSubscriptionsRequest& request, ProcessApiCallback<EconomyModels::SearchSubscriptionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetInventoryItems(EconomyModels::SetInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::SetInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetUgcItemModerationState(EconomyModels::SetUgcItemModerationStateRequest& request, ProcessApiCallback<EconomyModels::SetUgcItemModerationStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetVirtualCurrencies(EconomyModels::SetVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::SetVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubmitHelpfulnessVote(EconomyModels::HelpfulnessVoteRequest& request, ProcessApiCallback<EconomyModels::HelpfulnessVoteResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractVirtualCurrencies(EconomyModels::SubtractVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::SubtractVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void TakedownReviews(EconomyModels::TakedownReviewsRequest& request, ProcessApiCallback<EconomyModels::TakedownReviewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateBundle(EconomyModels::UpdateBundleRequest& request, ProcessApiCallback<EconomyModels::UpdateBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, ProcessApiCallback<EconomyModels::UpdateCatalogConfigResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCurrency(EconomyModels::UpdateCurrencyRequest& request, ProcessApiCallback<EconomyModels::UpdateCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftUgcItem(EconomyModels::UpdateDraftItemRequest& request, ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateInventoryItemsProperties(EconomyModels::UpdateInventoryItemsPropertiesRequest& request, ProcessApiCallback<EconomyModels::UpdateInventoryPropertiesItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStore(EconomyModels::UpdateStoreRequest& request, ProcessApiCallback<EconomyModels::UpdateStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateSubscription(EconomyModels::UpdateSubscriptionRequest& request, ProcessApiCallback<EconomyModels::UpdateSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAddVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnConsumeInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateBundleResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateCurrencyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateOrUpdateReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateStoreResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateSubscriptionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateUgcUploadUrlsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnCreateUploadUrlsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteBundleByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteBundleByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteSubscriptionByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteSubscriptionByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetBundleByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetBundleByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetBundleByMarketplaceOfferIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCatalogConfigResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetCurrencyByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetDraftItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetDraftUgcItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetItemReviewsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetItemReviewSummaryResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetMyReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPublishedItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPublishedUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetPublishStatusResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetSubscriptionByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetSubscriptionByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetSubscriptionByMarketplaceOfferIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUgcItemModerationStateResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetUgcPublishStatusResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGrantInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnPublishItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnPublishUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnPurchaseItemByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnPurchaseItemByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnReportReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnReportUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchBundlesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchForItemsContainingItemByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchForItemsContainingItemByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchInStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchInStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchStoresResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSearchSubscriptionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSetInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSetUgcItemModerationStateResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSetVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSubmitHelpfulnessVoteResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnSubtractVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnTakedownReviewsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateBundleResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCatalogConfigResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateCurrencyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateInventoryItemsPropertiesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateStoreResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateSubscriptionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
