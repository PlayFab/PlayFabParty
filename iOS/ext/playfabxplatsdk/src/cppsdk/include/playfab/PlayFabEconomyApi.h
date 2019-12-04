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
        static void AddVirtualCurrencies(EconomyModels::AddVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::AddVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeInventoryItems(EconomyModels::ConsumeInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::ConsumeInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CraftRecipeByFriendlyId(EconomyModels::CraftRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::CraftRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CraftRecipeById(EconomyModels::CraftRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::CraftRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateBundle(EconomyModels::CreateBundleRequest& request, const ProcessApiCallback<EconomyModels::CreateBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateCurrency(EconomyModels::CreateCurrencyRequest& request, const ProcessApiCallback<EconomyModels::CreateCurrencyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateDraftUgcItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateOrUpdateReview(EconomyModels::CreateOrUpdateReviewRequest& request, const ProcessApiCallback<EconomyModels::CreateOrUpdateReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRecipe(EconomyModels::CreateRecipeRequest& request, const ProcessApiCallback<EconomyModels::CreateRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateStore(EconomyModels::CreateStoreRequest& request, const ProcessApiCallback<EconomyModels::CreateStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSubscription(EconomyModels::CreateSubscriptionRequest& request, const ProcessApiCallback<EconomyModels::CreateSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUgcUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBundleByFriendlyId(EconomyModels::DeleteBundleByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteBundleById(EconomyModels::DeleteBundleByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRecipeByFriendlyId(EconomyModels::DeleteRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRecipeById(EconomyModels::DeleteRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStoreByFriendlyId(EconomyModels::DeleteStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStoreById(EconomyModels::DeleteStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSubscriptionByFriendlyId(EconomyModels::DeleteSubscriptionByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSubscriptionById(EconomyModels::DeleteSubscriptionByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteUgcItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleByFriendlyId(EconomyModels::GetBundleByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleById(EconomyModels::GetBundleByIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetBundleByMarketplaceOfferId(EconomyModels::GetBundleByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCurrencyById(EconomyModels::GetCurrencyByIdRequest& request, const ProcessApiCallback<EconomyModels::GetCurrencyByIdResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftUgcItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDraftUgcItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviews(EconomyModels::GetReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetReviewsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetItemReviewSummary(EconomyModels::ReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::ReviewSummaryResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMyReview(EconomyModels::GetMyReviewRequest& request, const ProcessApiCallback<EconomyModels::GetMyReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishedItem(EconomyModels::GetPublishedItemRequest& request, const ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishedUgcItem(EconomyModels::GetPublishedItemRequest& request, const ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublishStatus(EconomyModels::PublishStatusRequest& request, const ProcessApiCallback<EconomyModels::PublishStatusResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRecipeByFriendlyId(EconomyModels::GetRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRecipeById(EconomyModels::GetRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRecipeByMarketplaceOfferId(EconomyModels::GetRecipeByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreByFriendlyId(EconomyModels::GetStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreById(EconomyModels::GetStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::GetStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionByFriendlyId(EconomyModels::GetSubscriptionByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionById(EconomyModels::GetSubscriptionByIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSubscriptionByMarketplaceOfferId(EconomyModels::GetSubscriptionByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUgcItemModerationState(EconomyModels::GetUgcItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetUgcItemModerationStateResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUgcPublishStatus(EconomyModels::PublishStatusRequest& request, const ProcessApiCallback<EconomyModels::PublishStatusResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetVirtualCurrencies(EconomyModels::GetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::GetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantInventoryItems(EconomyModels::GrantInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GrantInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishItem(EconomyModels::PublishItemRequest& request, const ProcessApiCallback<EconomyModels::PublishItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PublishUgcItem(EconomyModels::PublishItemRequest& request, const ProcessApiCallback<EconomyModels::PublishItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItemByFriendlyId(EconomyModels::PurchaseItemByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItemById(EconomyModels::PurchaseItemByIdRequest& request, const ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportReview(EconomyModels::ReportReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportUgcItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void Search(EconomyModels::CatalogSearchRequest& request, const ProcessApiCallback<EconomyModels::CatalogSearchResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchBundles(EconomyModels::SearchBundlesRequest& request, const ProcessApiCallback<EconomyModels::SearchBundlesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchForItemsContainingItemByFriendlyId(EconomyModels::SearchForItemsContainingItemByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchForItemsContainingItemById(EconomyModels::SearchForItemsContainingItemByIdRequest& request, const ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchInStoreByFriendlyId(EconomyModels::SearchInStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchInStoreById(EconomyModels::SearchInStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchRecipes(EconomyModels::SearchRecipesRequest& request, const ProcessApiCallback<EconomyModels::SearchRecipesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchStores(EconomyModels::SearchStoresRequest& request, const ProcessApiCallback<EconomyModels::SearchStoresResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SearchSubscriptions(EconomyModels::SearchSubscriptionsRequest& request, const ProcessApiCallback<EconomyModels::SearchSubscriptionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetInventoryItems(EconomyModels::SetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::SetInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetUgcItemModerationState(EconomyModels::SetUgcItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetUgcItemModerationStateResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetVirtualCurrencies(EconomyModels::SetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubmitHelpfulnessVote(EconomyModels::HelpfulnessVoteRequest& request, const ProcessApiCallback<EconomyModels::HelpfulnessVoteResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractVirtualCurrencies(EconomyModels::SubtractVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SubtractVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void TakedownReviews(EconomyModels::TakedownReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownReviewsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBundle(EconomyModels::UpdateBundleRequest& request, const ProcessApiCallback<EconomyModels::UpdateBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCurrency(EconomyModels::UpdateCurrencyRequest& request, const ProcessApiCallback<EconomyModels::UpdateCurrencyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateDraftUgcItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateInventoryItemsProperties(EconomyModels::UpdateInventoryItemsPropertiesRequest& request, const ProcessApiCallback<EconomyModels::UpdateInventoryPropertiesItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRecipe(EconomyModels::UpdateRecipeRequest& request, const ProcessApiCallback<EconomyModels::UpdateRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStore(EconomyModels::UpdateStoreRequest& request, const ProcessApiCallback<EconomyModels::UpdateStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSubscription(EconomyModels::UpdateSubscriptionRequest& request, const ProcessApiCallback<EconomyModels::UpdateSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEconomyAPI(); // Private constructor, static class should never have an instance
        PlayFabEconomyAPI(const PlayFabEconomyAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAddVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnConsumeInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCraftRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCraftRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateOrUpdateReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateUgcUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetBundleByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetCurrencyByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetDraftUgcItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetMyReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetPublishedItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetPublishedUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetRecipeByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetSubscriptionByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetUgcPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGrantInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPublishItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPublishUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPurchaseItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnPurchaseItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnReportUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchBundlesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchForItemsContainingItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchForItemsContainingItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchInStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchInStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchRecipesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchStoresResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSearchSubscriptionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSubmitHelpfulnessVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnSubtractVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnTakedownReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateInventoryItemsPropertiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
