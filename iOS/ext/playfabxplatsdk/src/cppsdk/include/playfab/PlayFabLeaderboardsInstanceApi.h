#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabLeaderboardsDataModels.h>
#include <memory>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
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
        void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

        // ------------ Generated result handlers
        void OnCreateStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnDeleteStatisticsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardAroundEntityResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetLeaderboardForEntitiesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnGetStatisticDefinitionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnIncrementStatisticVersionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        void OnUpdateStatisticsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    private:
        std::shared_ptr<PlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    };
}

#endif
#endif
