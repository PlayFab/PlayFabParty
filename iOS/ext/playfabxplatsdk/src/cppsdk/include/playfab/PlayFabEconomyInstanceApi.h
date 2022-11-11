#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabEconomyDataModels.h>
#include <playfab/PlayFabError.h>

namespace PlayFabInternal
{
    class CallRequestContainerBase;
    class CallRequestContainer;
    class PlayFabApiSettings;
    class PlayFabAuthenticationContext;

    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Economy APIs
    /// </summary>
    class PlayFabEconomyInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;

    public:
        PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);
        PlayFabEconomyInstanceAPI(const std::shared_ptr<PlayFabApiSettings>& apiSettings, const std::shared_ptr<PlayFabAuthenticationContext>& authenticationContext);

        ~PlayFabEconomyInstanceAPI() = default;
        PlayFabEconomyInstanceAPI(const PlayFabEconomyInstanceAPI& source) = delete; // disable copy
        PlayFabEconomyInstanceAPI(PlayFabEconomyInstanceAPI&&) = delete; // disable move
        PlayFabEconomyInstanceAPI& operator=(const PlayFabEconomyInstanceAPI& source) = delete; // disable assignment
        PlayFabEconomyInstanceAPI& operator=(PlayFabEconomyInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        /// <summary>
        /// Calls the Update function on your implementation of the IHttpPlugin to check for responses to HTTP requests.
        /// All api's (Client, Server, Admin etc.) share the same IHttpPlugin. 
        /// This means that you only need to call Update() on one API to retrieve the responses for all APIs.
        /// Additional calls to Update (on any API) during the same tick are unlikely to retrieve additional responses.
        /// Call Update when your game ticks as follows:
        ///     Economy.Update();
        /// </summary>
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void AcceptTrade(EconomyModels::AcceptTradeRequest& request, const ProcessApiCallback<EconomyModels::AcceptTradeResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void AddVirtualCurrencies(EconomyModels::AddVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::AddVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CancelTrade(EconomyModels::CancelTradeRequest& request, const ProcessApiCallback<EconomyModels::CancelTradeResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ConsumeInventoryItems(EconomyModels::ConsumeInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::ConsumeInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateDraftItem(EconomyModels::CreateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::CreateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void CreateUploadUrls(EconomyModels::CreateUploadUrlsRequest& request, const ProcessApiCallback<EconomyModels::CreateUploadUrlsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteEntityItemReviews(EconomyModels::DeleteEntityItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::DeleteEntityItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteItem(EconomyModels::DeleteItemRequest& request, const ProcessApiCallback<EconomyModels::DeleteItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetAccessTokens(EconomyModels::GetAccessTokensRequest& request, const ProcessApiCallback<EconomyModels::GetAccessTokensResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetCatalogConfig(EconomyModels::GetCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::GetCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItem(EconomyModels::GetDraftItemRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetDraftItems(EconomyModels::GetDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityDraftItems(EconomyModels::GetEntityDraftItemsRequest& request, const ProcessApiCallback<EconomyModels::GetEntityDraftItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetEntityItemReview(EconomyModels::GetEntityItemReviewRequest& request, const ProcessApiCallback<EconomyModels::GetEntityItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetInventoryItems(EconomyModels::GetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GetInventoryItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItem(EconomyModels::GetItemRequest& request, const ProcessApiCallback<EconomyModels::GetItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemModerationState(EconomyModels::GetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::GetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemPublishStatus(EconomyModels::GetItemPublishStatusRequest& request, const ProcessApiCallback<EconomyModels::GetItemPublishStatusResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviews(EconomyModels::GetItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetItemReviewSummary(EconomyModels::GetItemReviewSummaryRequest& request, const ProcessApiCallback<EconomyModels::GetItemReviewSummaryResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetMarketplaceAccessToken(EconomyModels::GetMarketplaceAccessTokenRequest& request, const ProcessApiCallback<EconomyModels::GetMarketplaceAccessTokenResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetReceiptIssuerCertificateAsJwk(EconomyModels::GetIssuerKeyRequest& request, const ProcessApiCallback<EconomyModels::GetReceiptIssuerCertificateAsJwkResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetReceiptIssuerCertificateAsPem(EconomyModels::GetIssuerKeyRequest& request, const ProcessApiCallback<EconomyModels::GetReceiptIssuerCertificateAsPemCertResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetReceiptIssuerCertificates(EconomyModels::GetReceiptIssuerCertificatesRequest& request, const ProcessApiCallback<EconomyModels::GetReceiptIssuerCertificatesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTrade(EconomyModels::GetTradeRequest& request, const ProcessApiCallback<EconomyModels::GetTradeResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetTrades(EconomyModels::GetTradesRequest& request, const ProcessApiCallback<EconomyModels::GetTradesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetVirtualCurrencies(EconomyModels::GetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::GetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GrantInventoryItems(EconomyModels::GrantInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::GrantInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void OpenTrade(EconomyModels::OpenTradeRequest& request, const ProcessApiCallback<EconomyModels::OpenTradeResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void PublishDraftItem(EconomyModels::PublishDraftItemRequest& request, const ProcessApiCallback<EconomyModels::PublishDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void Redeem(EconomyModels::RedeemMarketplaceAssetsRequest& request, const ProcessApiCallback<EconomyModels::RedeemMarketplaceAssetsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RedeemInAppPurchase(EconomyModels::RedeemInAppPurchaseRequest& request, const ProcessApiCallback<EconomyModels::RedeemInAppPurchaseResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void RefreshSubscriptions(EconomyModels::RefreshSubscriptionsRequest& request, const ProcessApiCallback<EconomyModels::RefreshSubscriptionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportItem(EconomyModels::ReportItemRequest& request, const ProcessApiCallback<EconomyModels::ReportItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReportItemReview(EconomyModels::ReportItemReviewRequest& request, const ProcessApiCallback<EconomyModels::ReportItemReviewResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void ReviewItem(EconomyModels::ReviewItemRequest& request, const ProcessApiCallback<EconomyModels::ReviewItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchItems(EconomyModels::SearchItemsRequest& request, const ProcessApiCallback<EconomyModels::SearchItemsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SearchTrades(EconomyModels::SearchTradesRequest& request, const ProcessApiCallback<EconomyModels::SearchTradesResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetInventoryItems(EconomyModels::SetInventoryItemsRequest& request, const ProcessApiCallback<EconomyModels::SetInventoryItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetItemModerationState(EconomyModels::SetItemModerationStateRequest& request, const ProcessApiCallback<EconomyModels::SetItemModerationStateResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SetVirtualCurrencies(EconomyModels::SetVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SetVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubmitItemReviewVote(EconomyModels::SubmitItemReviewVoteRequest& request, const ProcessApiCallback<EconomyModels::SubmitItemReviewVoteResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void SubtractVirtualCurrencies(EconomyModels::SubtractVirtualCurrenciesRequest& request, const ProcessApiCallback<EconomyModels::SubtractVirtualCurrenciesResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void TakedownItemReviews(EconomyModels::TakedownItemReviewsRequest& request, const ProcessApiCallback<EconomyModels::TakedownItemReviewsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateCatalogConfig(EconomyModels::UpdateCatalogConfigRequest& request, const ProcessApiCallback<EconomyModels::UpdateCatalogConfigResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateDraftItem(EconomyModels::UpdateDraftItemRequest& request, const ProcessApiCallback<EconomyModels::UpdateDraftItemResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateInventoryItemsProperties(EconomyModels::UpdateInventoryItemsPropertiesRequest& request, const ProcessApiCallback<EconomyModels::UpdateInventoryPropertiesItemsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnAcceptTradeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnAddVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCancelTradeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnConsumeInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnCreateUploadUrlsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteEntityItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetAccessTokensResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetEntityDraftItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetEntityItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemPublishStatusResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetItemReviewSummaryResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetMarketplaceAccessTokenResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetReceiptIssuerCertificateAsJwkResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetReceiptIssuerCertificateAsPemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetReceiptIssuerCertificatesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetTradeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetTradesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGrantInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnOpenTradeResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnPublishDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRedeemInAppPurchaseResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnRefreshSubscriptionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReportItemReviewResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnReviewItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSearchTradesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetInventoryItemsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetItemModerationStateResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSetVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubmitItemReviewVoteResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnSubtractVirtualCurrenciesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnTakedownItemReviewsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateCatalogConfigResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateDraftItemResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateInventoryItemsPropertiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
