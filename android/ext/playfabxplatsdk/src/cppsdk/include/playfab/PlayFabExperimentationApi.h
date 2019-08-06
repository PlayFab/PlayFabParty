#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabExperimentationDataModels.h>

namespace PlayFabInternal
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Experimentation APIs
    /// </summary>
    class PlayFabExperimentationAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void CreateExperiment(ExperimentationModels::CreateExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::CreateExperimentResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteExperiment(ExperimentationModels::DeleteExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetExperiments(ExperimentationModels::GetExperimentsRequest& request, const ProcessApiCallback<ExperimentationModels::GetExperimentsResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLatestScorecardForExperiment(ExperimentationModels::GetLatestScorecardForExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::GetLatestScorecardForExperimentResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLatestScorecardsForTitle(ExperimentationModels::GetLatestScorecardsForTitleRequest& request, const ProcessApiCallback<ExperimentationModels::GetLatestScorecardsForTitleResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTreatmentAssignment(ExperimentationModels::GetTreatmentAssignmentRequest& request, const ProcessApiCallback<ExperimentationModels::GetTreatmentAssignmentResult> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartExperiment(ExperimentationModels::StartExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StopExperiment(ExperimentationModels::StopExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateExperiment(ExperimentationModels::UpdateExperimentRequest& request, const ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, const ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabExperimentationAPI(); // Private constructor, static class should never have an instance
        PlayFabExperimentationAPI(const PlayFabExperimentationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnCreateExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnDeleteExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetExperimentsResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLatestScorecardForExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetLatestScorecardsForTitleResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnGetTreatmentAssignmentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnStartExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnStopExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);
        static void OnUpdateExperimentResult(int httpCode, const std::string& result, const std::shared_ptr<CallRequestContainerBase>& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container);
    };
}

#endif
