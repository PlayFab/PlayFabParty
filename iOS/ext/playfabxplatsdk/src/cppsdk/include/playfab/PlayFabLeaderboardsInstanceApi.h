#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabLeaderboardsDataModels.h>
#include <memory>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Leaderboards APIs
    /// </summary>
    class PlayFabLeaderboardsInstanceAPI
    {
    private:
        std::shared_ptr<PlayFabApiSettings> settings;
        std::shared_ptr<PlayFabAuthenticationContext> authContext;

    public:
        PlayFabLeaderboardsInstanceAPI();
        explicit PlayFabLeaderboardsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings);
        explicit PlayFabLeaderboardsInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        PlayFabLeaderboardsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        ~PlayFabLeaderboardsInstanceAPI();
        PlayFabLeaderboardsInstanceAPI(const PlayFabLeaderboardsInstanceAPI& source) = delete; // disable copy
        PlayFabLeaderboardsInstanceAPI(PlayFabLeaderboardsInstanceAPI&&) = delete; // disable move
        PlayFabLeaderboardsInstanceAPI& operator=(const PlayFabLeaderboardsInstanceAPI& source) = delete; // disable assignment
        PlayFabLeaderboardsInstanceAPI& operator=(PlayFabLeaderboardsInstanceAPI&& other) = delete; // disable move assignment

        std::shared_ptr<PlayFabApiSettings> GetSettings() const;
        void SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings);
        std::shared_ptr<PlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext);
        size_t Update();
        void ForgetAllCredentials();

        // ------------ Generated API calls
        void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatisticDefinition(LeaderboardsModels::UpdateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCreateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnDeleteStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardAroundEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetLeaderboardForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnGetStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnIncrementStatisticVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        void OnUpdateStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
