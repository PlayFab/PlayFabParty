#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabEconomyDataModels.h>
#include <memory>

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
        void AddVirtualCurrencies(EconomyModels::AddVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::AddVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeInventoryItems(EconomyModels::ConsumeInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::ConsumeInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CraftRecipeByFriendlyId(EconomyModels::CraftRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::CraftRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CraftRecipeById(EconomyModels::CraftRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::CraftRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateBundle(EconomyModels::CreateBundleRequest& request, const ProcessApiCallback<EconomyModels::CreateBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateCurrency(EconomyModels::CreateCurrencyRequest& request, const ProcessApiCallback<EconomyModels::CreateCurrencyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftUgcItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateOrUpdateReview(EconomyModels::CreateOrUpdateReviewRequest& request, const ProcessApiCallback<EconomyModels::CreateOrUpdateReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateRecipe(EconomyModels::CreateRecipeRequest& request, const ProcessApiCallback<EconomyModels::CreateRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateStore(EconomyModels::CreateStoreRequest& request, const ProcessApiCallback<EconomyModels::CreateStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateSubscription(EconomyModels::CreateSubscriptionRequest& request, const ProcessApiCallback<EconomyModels::CreateSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUgcUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteBundleByFriendlyId(EconomyModels::DeleteBundleByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteBundleById(EconomyModels::DeleteBundleByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteRecipeByFriendlyId(EconomyModels::DeleteRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteRecipeById(EconomyModels::DeleteRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStoreByFriendlyId(EconomyModels::DeleteStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStoreById(EconomyModels::DeleteStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSubscriptionByFriendlyId(EconomyModels::DeleteSubscriptionByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteSubscriptionById(EconomyModels::DeleteSubscriptionByIdRequest& request, const ProcessApiCallback<EconomyModels::DeleteSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteUgcItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleByFriendlyId(EconomyModels::GetBundleByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleById(EconomyModels::GetBundleByIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetBundleByMarketplaceOfferId(EconomyModels::GetBundleByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCurrencyById(EconomyModels::GetCurrencyByIdRequest& request, const ProcessApiCallback<EconomyModels::GetCurrencyByIdResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftUgcItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftUgcItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviews(EconomyModels::GetReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetReviewsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviewSummary(EconomyModels::ReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::ReviewSummaryResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMyReview(EconomyModels::GetMyReviewRequest& request, const ProcessApiCallback<EconomyModels::GetMyReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishedItem(EconomyModels::GetPublishedItemRequest& request, const ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishedUgcItem(EconomyModels::GetPublishedItemRequest& request, const ProcessApiCallback<EconomyModels::GetPublishedItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetPublishStatus(EconomyModels::PublishStatusRequest& request, const ProcessApiCallback<EconomyModels::PublishStatusResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetRecipeByFriendlyId(EconomyModels::GetRecipeByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetRecipeById(EconomyModels::GetRecipeByIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetRecipeByMarketplaceOfferId(EconomyModels::GetRecipeByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStoreByFriendlyId(EconomyModels::GetStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStoreById(EconomyModels::GetStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::GetStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionByFriendlyId(EconomyModels::GetSubscriptionByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionById(EconomyModels::GetSubscriptionByIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetSubscriptionByMarketplaceOfferId(EconomyModels::GetSubscriptionByMarketplaceOfferIdRequest& request, const ProcessApiCallback<EconomyModels::GetSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUgcItemModerationState(EconomyModels::GetUgcItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetUgcItemModerationStateResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetUgcPublishStatus(EconomyModels::PublishStatusRequest& request, const ProcessApiCallback<EconomyModels::PublishStatusResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetVirtualCurrencies(EconomyModels::GetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::GetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantInventoryItems(EconomyModels::GrantInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GrantInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishItem(EconomyModels::PublishItemRequest& request, const ProcessApiCallback<EconomyModels::PublishItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishUgcItem(EconomyModels::PublishItemRequest& request, const ProcessApiCallback<EconomyModels::PublishItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseItemByFriendlyId(EconomyModels::PurchaseItemByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PurchaseItemById(EconomyModels::PurchaseItemByIdRequest& request, const ProcessApiCallback<EconomyModels::PurchaseItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportReview(EconomyModels::ReportReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportReviewResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportUgcItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void Search(EconomyModels::CatalogSearchRequest& request, const ProcessApiCallback<EconomyModels::CatalogSearchResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchBundles(EconomyModels::SearchBundlesRequest& request, const ProcessApiCallback<EconomyModels::SearchBundlesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchForItemsContainingItemByFriendlyId(EconomyModels::SearchForItemsContainingItemByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchForItemsContainingItemById(EconomyModels::SearchForItemsContainingItemByIdRequest& request, const ProcessApiCallback<EconomyModels::SearchForItemsContainingItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchInStoreByFriendlyId(EconomyModels::SearchInStoreByFriendlyIdRequest& request, const ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchInStoreById(EconomyModels::SearchInStoreByIdRequest& request, const ProcessApiCallback<EconomyModels::SearchInStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchRecipes(EconomyModels::SearchRecipesRequest& request, const ProcessApiCallback<EconomyModels::SearchRecipesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchStores(EconomyModels::SearchStoresRequest& request, const ProcessApiCallback<EconomyModels::SearchStoresResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchSubscriptions(EconomyModels::SearchSubscriptionsRequest& request, const ProcessApiCallback<EconomyModels::SearchSubscriptionsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetInventoryItems(EconomyModels::SetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::SetInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetUgcItemModerationState(EconomyModels::SetUgcItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetUgcItemModerationStateResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetVirtualCurrencies(EconomyModels::SetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubmitHelpfulnessVote(EconomyModels::HelpfulnessVoteRequest& request, const ProcessApiCallback<EconomyModels::HelpfulnessVoteResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractVirtualCurrencies(EconomyModels::SubtractVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SubtractVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void TakedownReviews(EconomyModels::TakedownReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownReviewsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateBundle(EconomyModels::UpdateBundleRequest& request, const ProcessApiCallback<EconomyModels::UpdateBundleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCurrency(EconomyModels::UpdateCurrencyRequest& request, const ProcessApiCallback<EconomyModels::UpdateCurrencyResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftUgcItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateInventoryItemsProperties(EconomyModels::UpdateInventoryItemsPropertiesRequest& request, const ProcessApiCallback<EconomyModels::UpdateInventoryPropertiesItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateRecipe(EconomyModels::UpdateRecipeRequest& request, const ProcessApiCallback<EconomyModels::UpdateRecipeResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStore(EconomyModels::UpdateStoreRequest& request, const ProcessApiCallback<EconomyModels::UpdateStoreResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateSubscription(EconomyModels::UpdateSubscriptionRequest& request, const ProcessApiCallback<EconomyModels::UpdateSubscriptionResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAddVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnConsumeInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCraftRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCraftRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateOrUpdateReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateUgcUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetBundleByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetBundleByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetBundleByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetCurrencyByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftUgcItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetMyReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetPublishedItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetPublishedUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetRecipeByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetRecipeByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetRecipeByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetSubscriptionByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetSubscriptionByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetSubscriptionByMarketplaceOfferIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetUgcPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGrantInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPublishItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPublishUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPurchaseItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPurchaseItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchBundlesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchForItemsContainingItemByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchForItemsContainingItemByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchInStoreByFriendlyIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchInStoreByIdResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchRecipesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchStoresResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchSubscriptionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetUgcItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubmitHelpfulnessVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubtractVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnTakedownReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateBundleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateCurrencyResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateDraftUgcItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateInventoryItemsPropertiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateRecipeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStoreResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateSubscriptionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
