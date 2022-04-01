#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabLeaderboardsDataModels.h>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Leaderboards APIs
    /// </summary>
    class PlayFabLeaderboardsAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, const ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, const ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, const ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStatisticDefinition(LeaderboardsModels::UpdateStatisticDefinitionRequest& request, const ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, const ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabLeaderboardsAPI(); // Private constructor, static class should never have an instance
        PlayFabLeaderboardsAPI(const PlayFabLeaderboardsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardAroundEntityResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLeaderboardForEntitiesResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetStatisticDefinitionsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnIncrementStatisticVersionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateStatisticDefinitionResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateStatisticsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
