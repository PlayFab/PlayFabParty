#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabEconomyDataModels.h>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Economy APIs
    /// </summary>
    class PlayFabEconomyAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AddVirtualCurrencies(EconomyModels::AddVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::AddVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeInventoryItems(EconomyModels::ConsumeInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::ConsumeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBundle(EconomyModels::CreateBundleRequest& request, ProcessApiCallback<EconomyModels::CreateBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateCurrency(EconomyModels::CreateCurrencyRequest& request, ProcessApiCallback<EconomyModels::CreateCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateDraftUgcItem(EconomyModels::CreateDraftItemRequest& request, ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateReview(EconomyModels::CreateOrUpdateReviewRequest& request, ProcessApiCallback<EconomyModels::CreateOrUpdateReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateStore(EconomyModels::CreateStoreRequest& request, ProcessApiCallback<EconomyModels::CreateStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSubscription(EconomyModels::CreateSubscriptionRequest& request, ProcessApiCallback<EconomyModels::CreateSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUgcUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBundleByFriendlyId(EconomyModels::DeleteBundleByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBundleById(EconomyModels::DeleteBundleByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteItem(EconomyModels::DeleteItemRequest& request, ProcessApiCallback<EconomyModels::DeleteItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStoreByFriendlyId(EconomyModels::DeleteStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStoreById(EconomyModels::DeleteStoreByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSubscriptionByFriendlyId(EconomyModels::DeleteSubscriptionByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSubscriptionById(EconomyModels::DeleteSubscriptionByIdRequest& request, ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteUgcItem(EconomyModels::DeleteItemRequest& request, ProcessApiCallback<EconomyModels::DeleteItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleByFriendlyId(EconomyModels::GetBundleByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleById(EconomyModels::GetBundleByIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleByMarketplaceOfferId(EconomyModels::GetBundleByMarketplaceOfferIdRequest& request, ProcessApiCallback<EconomyModels::GetBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, ProcessApiCallback<EconomyModels::GetCatalogConfigResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCurrencyById(EconomyModels::GetCurrencyByIdRequest& request, ProcessApiCallback<EconomyModels::GetCurrencyByIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItem(EconomyModels::GetDraftItemRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftUgcItem(EconomyModels::GetDraftItemRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftUgcItems(EconomyModels::GetDraftItemsRequest& request, ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::GetInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviews(EconomyModels::GetReviewsRequest& request, ProcessApiCallback<EconomyModels::GetReviewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviewSummary(EconomyModels::ReviewSummaryRequest& request, ProcessApiCallback<EconomyModels::ReviewSummaryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMyReview(EconomyModels::GetMyReviewRequest& request, ProcessApiCallback<EconomyModels::GetMyReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishedItem(EconomyModels::GetPublishedItemRequest& request, ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishedUgcItem(EconomyModels::GetPublishedItemRequest& request, ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishStatus(EconomyModels::PublishStatusRequest& request, ProcessApiCallback<EconomyModels::PublishStatusResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreByFriendlyId(EconomyModels::GetStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreById(EconomyModels::GetStoreByIdRequest& request, ProcessApiCallback<EconomyModels::GetStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionByFriendlyId(EconomyModels::GetSubscriptionByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionById(EconomyModels::GetSubscriptionByIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionByMarketplaceOfferId(EconomyModels::GetSubscriptionByMarketplaceOfferIdRequest& request, ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUgcItemModerationState(EconomyModels::GetUgcItemModerationStateRequest& request, ProcessApiCallback<EconomyModels::GetUgcItemModerationStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUgcPublishStatus(EconomyModels::PublishStatusRequest& request, ProcessApiCallback<EconomyModels::PublishStatusResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetVirtualCurrencies(EconomyModels::GetVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::GetVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantInventoryItems(EconomyModels::GrantInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::GrantInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishItem(EconomyModels::PublishItemRequest& request, ProcessApiCallback<EconomyModels::PublishItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishUgcItem(EconomyModels::PublishItemRequest& request, ProcessApiCallback<EconomyModels::PublishItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItemByFriendlyId(EconomyModels::PurchaseItemByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItemById(EconomyModels::PurchaseItemByIdRequest& request, ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportReview(EconomyModels::ReportReviewRequest& request, ProcessApiCallback<EconomyModels::ReportReviewResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportUgcItem(EconomyModels::ReportItemRequest& request, ProcessApiCallback<EconomyModels::ReportItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void Search(EconomyModels::CatalogSearchRequest& request, ProcessApiCallback<EconomyModels::CatalogSearchResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchBundles(EconomyModels::SearchBundlesRequest& request, ProcessApiCallback<EconomyModels::SearchBundlesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchForItemsContainingItemByFriendlyId(EconomyModels::SearchForItemsContainingItemByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchForItemsContainingItemById(EconomyModels::SearchForItemsContainingItemByIdRequest& request, ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchInStoreByFriendlyId(EconomyModels::SearchInStoreByFriendlyIdRequest& request, ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchInStoreById(EconomyModels::SearchInStoreByIdRequest& request, ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchStores(EconomyModels::SearchStoresRequest& request, ProcessApiCallback<EconomyModels::SearchStoresResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchSubscriptions(EconomyModels::SearchSubscriptionsRequest& request, ProcessApiCallback<EconomyModels::SearchSubscriptionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetInventoryItems(EconomyModels::SetInventoryItemsRequest& request, ProcessApiCallback<EconomyModels::SetInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetUgcItemModerationState(EconomyModels::SetUgcItemModerationStateRequest& request, ProcessApiCallback<EconomyModels::SetUgcItemModerationStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetVirtualCurrencies(EconomyModels::SetVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::SetVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubmitHelpfulnessVote(EconomyModels::HelpfulnessVoteRequest& request, ProcessApiCallback<EconomyModels::HelpfulnessVoteResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractVirtualCurrencies(EconomyModels::SubtractVirtualCurrenciesRequest& request, ProcessApiCallback<EconomyModels::SubtractVirtualCurrenciesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void TakedownReviews(EconomyModels::TakedownReviewsRequest& request, ProcessApiCallback<EconomyModels::TakedownReviewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBundle(EconomyModels::UpdateBundleRequest& request, ProcessApiCallback<EconomyModels::UpdateBundleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, ProcessApiCallback<EconomyModels::UpdateCatalogConfigResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCurrency(EconomyModels::UpdateCurrencyRequest& request, ProcessApiCallback<EconomyModels::UpdateCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftUgcItem(EconomyModels::UpdateDraftItemRequest& request, ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateInventoryItemsProperties(EconomyModels::UpdateInventoryItemsPropertiesRequest& request, ProcessApiCallback<EconomyModels::UpdateInventoryPropertiesItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStore(EconomyModels::UpdateStoreRequest& request, ProcessApiCallback<EconomyModels::UpdateStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSubscription(EconomyModels::UpdateSubscriptionRequest& request, ProcessApiCallback<EconomyModels::UpdateSubscriptionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEconomyAPI(); // Private constructor, static class should never have an instance
        PlayFabEconomyAPI(const PlayFabEconomyAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAddVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnConsumeInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateBundleResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateCurrencyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateOrUpdateReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateStoreResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateSubscriptionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateUgcUploadUrlsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnCreateUploadUrlsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteBundleByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteBundleByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteSubscriptionByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteSubscriptionByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetBundleByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetBundleByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetBundleByMarketplaceOfferIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetCatalogConfigResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetCurrencyByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetDraftItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetDraftUgcItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetItemReviewsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetItemReviewSummaryResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetMyReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetPublishedItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetPublishedUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetPublishStatusResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetSubscriptionByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetSubscriptionByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetSubscriptionByMarketplaceOfferIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetUgcItemModerationStateResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetUgcPublishStatusResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGrantInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnPublishItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnPublishUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnPurchaseItemByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnPurchaseItemByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnReportReviewResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnReportUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchBundlesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchForItemsContainingItemByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchForItemsContainingItemByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchInStoreByFriendlyIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchInStoreByIdResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchStoresResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSearchSubscriptionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSetInventoryItemsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSetUgcItemModerationStateResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSetVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSubmitHelpfulnessVoteResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnSubtractVirtualCurrenciesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnTakedownReviewsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateBundleResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateCatalogConfigResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateCurrencyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateDraftItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateDraftUgcItemResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateInventoryItemsPropertiesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateStoreResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateSubscriptionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
