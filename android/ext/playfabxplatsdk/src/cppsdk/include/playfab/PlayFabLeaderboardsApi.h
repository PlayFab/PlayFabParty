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
        static void CreateStatisticDefinition(LeaderboardsModels::CreateStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatisticDefinition(LeaderboardsModels::DeleteStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStatistics(LeaderboardsModels::DeleteStatisticsRequest& request, ProcessApiCallback<LeaderboardsModels::DeleteStatisticsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(LeaderboardsModels::GetEntityLeaderboardRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundEntity(LeaderboardsModels::GetLeaderboardAroundEntityRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForEntities(LeaderboardsModels::GetLeaderboardForEntitiesRequest& request, ProcessApiCallback<LeaderboardsModels::GetEntityLeaderboardResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinition(LeaderboardsModels::GetStatisticDefinitionRequest& request, ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStatisticDefinitions(LeaderboardsModels::GetStatisticDefinitionsRequest& request, ProcessApiCallback<LeaderboardsModels::GetStatisticDefinitionsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementStatisticVersion(LeaderboardsModels::IncrementStatisticVersionRequest& request, ProcessApiCallback<LeaderboardsModels::IncrementStatisticVersionResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStatistics(LeaderboardsModels::UpdateStatisticsRequest& request, ProcessApiCallback<LeaderboardsModels::UpdateStatisticsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabLeaderboardsAPI(); // Private constructor, static class should never have an instance
        PlayFabLeaderboardsAPI(const PlayFabLeaderboardsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnDeleteStatisticsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetLeaderboardResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetLeaderboardAroundEntityResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetLeaderboardForEntitiesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetStatisticDefinitionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnGetStatisticDefinitionsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnIncrementStatisticVersionResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);
        static void OnUpdateStatisticsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
