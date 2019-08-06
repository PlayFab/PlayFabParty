#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace ExperimentationModels
    {
        // Experimentation Enums
        enum class ExperimentState
        {
            ExperimentStateNew,
            ExperimentStateStarted,
            ExperimentStateStopped,
            ExperimentStateDeleted
        };

        inline void ToJsonEnum(const ExperimentState input, Json::Value& output)
        {
            if (input == ExperimentState::ExperimentStateNew) output = Json::Value("New");
            if (input == ExperimentState::ExperimentStateStarted) output = Json::Value("Started");
            if (input == ExperimentState::ExperimentStateStopped) output = Json::Value("Stopped");
            if (input == ExperimentState::ExperimentStateDeleted) output = Json::Value("Deleted");
        }
        inline void FromJsonEnum(const Json::Value& input, ExperimentState& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "New") output = ExperimentState::ExperimentStateNew;
            if (inputStr == "Started") output = ExperimentState::ExperimentStateStarted;
            if (inputStr == "Stopped") output = ExperimentState::ExperimentStateStopped;
            if (inputStr == "Deleted") output = ExperimentState::ExperimentStateDeleted;
        }

        enum class ExperimentType
        {
            ExperimentTypeActive,
            ExperimentTypeSnapshot
        };

        inline void ToJsonEnum(const ExperimentType input, Json::Value& output)
        {
            if (input == ExperimentType::ExperimentTypeActive) output = Json::Value("Active");
            if (input == ExperimentType::ExperimentTypeSnapshot) output = Json::Value("Snapshot");
        }
        inline void FromJsonEnum(const Json::Value& input, ExperimentType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Active") output = ExperimentType::ExperimentTypeActive;
            if (inputStr == "Snapshot") output = ExperimentType::ExperimentTypeSnapshot;
        }

        // Experimentation Classes
        struct Variable : public PlayFabBaseModel
        {
            std::string Name;
            std::string Value;

            Variable() :
                PlayFabBaseModel(),
                Name(),
                Value()
            {}

            Variable(const Variable& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value)
            {}

            ~Variable() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct Variant : public PlayFabBaseModel
        {
            std::string Description;
            std::string Id;
            bool IsControl;
            std::string Name;
            std::list<Variable> Variables;
            Uint32 Weight;

            Variant() :
                PlayFabBaseModel(),
                Description(),
                Id(),
                IsControl(),
                Name(),
                Variables(),
                Weight()
            {}

            Variant(const Variant& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Id(src.Id),
                IsControl(src.IsControl),
                Name(src.Name),
                Variables(src.Variables),
                Weight(src.Weight)
            {}

            ~Variant() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilP(input["IsControl"], IsControl);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["Variables"], Variables);
                FromJsonUtilP(input["Weight"], Weight);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_IsControl; ToJsonUtilP(IsControl, each_IsControl); output["IsControl"] = each_IsControl;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Variables; ToJsonUtilO(Variables, each_Variables); output["Variables"] = each_Variables;
                Json::Value each_Weight; ToJsonUtilP(Weight, each_Weight); output["Weight"] = each_Weight;
                return output;
            }
        };

        struct CreateExperimentRequest : public PlayFabRequestCommon
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Name;
            Uint32 PopulationPercentage;
            std::string SegmentId;
            time_t StartDate;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            CreateExperimentRequest() :
                PlayFabRequestCommon(),
                Description(),
                Duration(),
                pfExperimentType(),
                Name(),
                PopulationPercentage(),
                SegmentId(),
                StartDate(),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            CreateExperimentRequest(const CreateExperimentRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Name(src.Name),
                PopulationPercentage(src.PopulationPercentage),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            ~CreateExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["Duration"], Duration);
                FromJsonUtilE(input["ExperimentType"], pfExperimentType);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["PopulationPercentage"], PopulationPercentage);
                FromJsonUtilS(input["SegmentId"], SegmentId);
                FromJsonUtilT(input["StartDate"], StartDate);
                FromJsonUtilS(input["TitlePlayerAccountTestIds"], TitlePlayerAccountTestIds);
                FromJsonUtilO(input["Variants"], Variants);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_Duration; ToJsonUtilP(Duration, each_Duration); output["Duration"] = each_Duration;
                Json::Value each_pfExperimentType; ToJsonUtilE(pfExperimentType, each_pfExperimentType); output["ExperimentType"] = each_pfExperimentType;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_PopulationPercentage; ToJsonUtilP(PopulationPercentage, each_PopulationPercentage); output["PopulationPercentage"] = each_PopulationPercentage;
                Json::Value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output["SegmentId"] = each_SegmentId;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_TitlePlayerAccountTestIds; ToJsonUtilS(TitlePlayerAccountTestIds, each_TitlePlayerAccountTestIds); output["TitlePlayerAccountTestIds"] = each_TitlePlayerAccountTestIds;
                Json::Value each_Variants; ToJsonUtilO(Variants, each_Variants); output["Variants"] = each_Variants;
                return output;
            }
        };

        struct CreateExperimentResult : public PlayFabResultCommon
        {
            std::string ExperimentId;

            CreateExperimentResult() :
                PlayFabResultCommon(),
                ExperimentId()
            {}

            CreateExperimentResult(const CreateExperimentResult& src) :
                PlayFabResultCommon(),
                ExperimentId(src.ExperimentId)
            {}

            ~CreateExperimentResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                return output;
            }
        };

        struct DeleteExperimentRequest : public PlayFabRequestCommon
        {
            std::string ExperimentId;

            DeleteExperimentRequest() :
                PlayFabRequestCommon(),
                ExperimentId()
            {}

            DeleteExperimentRequest(const DeleteExperimentRequest& src) :
                PlayFabRequestCommon(),
                ExperimentId(src.ExperimentId)
            {}

            ~DeleteExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                return output;
            }
        };

        struct EmptyResponse : public PlayFabResultCommon
        {

            EmptyResponse() :
                PlayFabResultCommon()
            {}

            EmptyResponse(const EmptyResponse&) :
                PlayFabResultCommon()
            {}

            ~EmptyResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            ~EntityKey() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct Experiment : public PlayFabBaseModel
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Id;
            std::string Name;
            Uint32 PopulationPercentage;
            std::string SegmentId;
            time_t StartDate;
            Boxed<ExperimentState> State;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            Experiment() :
                PlayFabBaseModel(),
                Description(),
                Duration(),
                pfExperimentType(),
                Id(),
                Name(),
                PopulationPercentage(),
                SegmentId(),
                StartDate(),
                State(),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            Experiment(const Experiment& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Id(src.Id),
                Name(src.Name),
                PopulationPercentage(src.PopulationPercentage),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                State(src.State),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            ~Experiment() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["Duration"], Duration);
                FromJsonUtilE(input["ExperimentType"], pfExperimentType);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["PopulationPercentage"], PopulationPercentage);
                FromJsonUtilS(input["SegmentId"], SegmentId);
                FromJsonUtilT(input["StartDate"], StartDate);
                FromJsonUtilE(input["State"], State);
                FromJsonUtilS(input["TitlePlayerAccountTestIds"], TitlePlayerAccountTestIds);
                FromJsonUtilO(input["Variants"], Variants);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_Duration; ToJsonUtilP(Duration, each_Duration); output["Duration"] = each_Duration;
                Json::Value each_pfExperimentType; ToJsonUtilE(pfExperimentType, each_pfExperimentType); output["ExperimentType"] = each_pfExperimentType;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_PopulationPercentage; ToJsonUtilP(PopulationPercentage, each_PopulationPercentage); output["PopulationPercentage"] = each_PopulationPercentage;
                Json::Value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output["SegmentId"] = each_SegmentId;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_State; ToJsonUtilE(State, each_State); output["State"] = each_State;
                Json::Value each_TitlePlayerAccountTestIds; ToJsonUtilS(TitlePlayerAccountTestIds, each_TitlePlayerAccountTestIds); output["TitlePlayerAccountTestIds"] = each_TitlePlayerAccountTestIds;
                Json::Value each_Variants; ToJsonUtilO(Variants, each_Variants); output["Variants"] = each_Variants;
                return output;
            }
        };

        struct GetExperimentsRequest : public PlayFabRequestCommon
        {

            GetExperimentsRequest() :
                PlayFabRequestCommon()
            {}

            GetExperimentsRequest(const GetExperimentsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetExperimentsRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetExperimentsResult : public PlayFabResultCommon
        {
            std::list<Experiment> Experiments;

            GetExperimentsResult() :
                PlayFabResultCommon(),
                Experiments()
            {}

            GetExperimentsResult(const GetExperimentsResult& src) :
                PlayFabResultCommon(),
                Experiments(src.Experiments)
            {}

            ~GetExperimentsResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Experiments"], Experiments);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Experiments; ToJsonUtilO(Experiments, each_Experiments); output["Experiments"] = each_Experiments;
                return output;
            }
        };

        struct GetLatestScorecardForExperimentRequest : public PlayFabRequestCommon
        {
            std::string ExperimentId;

            GetLatestScorecardForExperimentRequest() :
                PlayFabRequestCommon(),
                ExperimentId()
            {}

            GetLatestScorecardForExperimentRequest(const GetLatestScorecardForExperimentRequest& src) :
                PlayFabRequestCommon(),
                ExperimentId(src.ExperimentId)
            {}

            ~GetLatestScorecardForExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                return output;
            }
        };

        struct MetricData : public PlayFabBaseModel
        {
            std::string AnalysisTemplate;
            float Average;
            double ConfidenceIntervalEnd;
            double ConfidenceIntervalStart;
            Int32 Count;
            float DeltaAbsoluteChange;
            float DeltaRelativeChange;
            std::string InternalName;
            std::string Movement;
            std::string Name;
            float PMove;
            float PValue;
            float PValueThreshold;
            std::string StatSigLevel;
            float StdDev;
            std::string Type;

            MetricData() :
                PlayFabBaseModel(),
                AnalysisTemplate(),
                Average(),
                ConfidenceIntervalEnd(),
                ConfidenceIntervalStart(),
                Count(),
                DeltaAbsoluteChange(),
                DeltaRelativeChange(),
                InternalName(),
                Movement(),
                Name(),
                PMove(),
                PValue(),
                PValueThreshold(),
                StatSigLevel(),
                StdDev(),
                Type()
            {}

            MetricData(const MetricData& src) :
                PlayFabBaseModel(),
                AnalysisTemplate(src.AnalysisTemplate),
                Average(src.Average),
                ConfidenceIntervalEnd(src.ConfidenceIntervalEnd),
                ConfidenceIntervalStart(src.ConfidenceIntervalStart),
                Count(src.Count),
                DeltaAbsoluteChange(src.DeltaAbsoluteChange),
                DeltaRelativeChange(src.DeltaRelativeChange),
                InternalName(src.InternalName),
                Movement(src.Movement),
                Name(src.Name),
                PMove(src.PMove),
                PValue(src.PValue),
                PValueThreshold(src.PValueThreshold),
                StatSigLevel(src.StatSigLevel),
                StdDev(src.StdDev),
                Type(src.Type)
            {}

            ~MetricData() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AnalysisTemplate"], AnalysisTemplate);
                FromJsonUtilP(input["Average"], Average);
                FromJsonUtilP(input["ConfidenceIntervalEnd"], ConfidenceIntervalEnd);
                FromJsonUtilP(input["ConfidenceIntervalStart"], ConfidenceIntervalStart);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilP(input["DeltaAbsoluteChange"], DeltaAbsoluteChange);
                FromJsonUtilP(input["DeltaRelativeChange"], DeltaRelativeChange);
                FromJsonUtilS(input["InternalName"], InternalName);
                FromJsonUtilS(input["Movement"], Movement);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["PMove"], PMove);
                FromJsonUtilP(input["PValue"], PValue);
                FromJsonUtilP(input["PValueThreshold"], PValueThreshold);
                FromJsonUtilS(input["StatSigLevel"], StatSigLevel);
                FromJsonUtilP(input["StdDev"], StdDev);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AnalysisTemplate; ToJsonUtilS(AnalysisTemplate, each_AnalysisTemplate); output["AnalysisTemplate"] = each_AnalysisTemplate;
                Json::Value each_Average; ToJsonUtilP(Average, each_Average); output["Average"] = each_Average;
                Json::Value each_ConfidenceIntervalEnd; ToJsonUtilP(ConfidenceIntervalEnd, each_ConfidenceIntervalEnd); output["ConfidenceIntervalEnd"] = each_ConfidenceIntervalEnd;
                Json::Value each_ConfidenceIntervalStart; ToJsonUtilP(ConfidenceIntervalStart, each_ConfidenceIntervalStart); output["ConfidenceIntervalStart"] = each_ConfidenceIntervalStart;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_DeltaAbsoluteChange; ToJsonUtilP(DeltaAbsoluteChange, each_DeltaAbsoluteChange); output["DeltaAbsoluteChange"] = each_DeltaAbsoluteChange;
                Json::Value each_DeltaRelativeChange; ToJsonUtilP(DeltaRelativeChange, each_DeltaRelativeChange); output["DeltaRelativeChange"] = each_DeltaRelativeChange;
                Json::Value each_InternalName; ToJsonUtilS(InternalName, each_InternalName); output["InternalName"] = each_InternalName;
                Json::Value each_Movement; ToJsonUtilS(Movement, each_Movement); output["Movement"] = each_Movement;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_PMove; ToJsonUtilP(PMove, each_PMove); output["PMove"] = each_PMove;
                Json::Value each_PValue; ToJsonUtilP(PValue, each_PValue); output["PValue"] = each_PValue;
                Json::Value each_PValueThreshold; ToJsonUtilP(PValueThreshold, each_PValueThreshold); output["PValueThreshold"] = each_PValueThreshold;
                Json::Value each_StatSigLevel; ToJsonUtilS(StatSigLevel, each_StatSigLevel); output["StatSigLevel"] = each_StatSigLevel;
                Json::Value each_StdDev; ToJsonUtilP(StdDev, each_StdDev); output["StdDev"] = each_StdDev;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct ScorecardDataRow : public PlayFabBaseModel
        {
            std::map<std::string, MetricData> MetricDataRows;
            std::string VariantName;

            ScorecardDataRow() :
                PlayFabBaseModel(),
                MetricDataRows(),
                VariantName()
            {}

            ScorecardDataRow(const ScorecardDataRow& src) :
                PlayFabBaseModel(),
                MetricDataRows(src.MetricDataRows),
                VariantName(src.VariantName)
            {}

            ~ScorecardDataRow() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["MetricDataRows"], MetricDataRows);
                FromJsonUtilS(input["VariantName"], VariantName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MetricDataRows; ToJsonUtilO(MetricDataRows, each_MetricDataRows); output["MetricDataRows"] = each_MetricDataRows;
                Json::Value each_VariantName; ToJsonUtilS(VariantName, each_VariantName); output["VariantName"] = each_VariantName;
                return output;
            }
        };

        struct Scorecard : public PlayFabBaseModel
        {
            std::string DateGenerated;
            std::string Duration;
            std::string ExperimentId;
            std::string ExperimentName;
            std::list<ScorecardDataRow> ScorecardDataRows;

            Scorecard() :
                PlayFabBaseModel(),
                DateGenerated(),
                Duration(),
                ExperimentId(),
                ExperimentName(),
                ScorecardDataRows()
            {}

            Scorecard(const Scorecard& src) :
                PlayFabBaseModel(),
                DateGenerated(src.DateGenerated),
                Duration(src.Duration),
                ExperimentId(src.ExperimentId),
                ExperimentName(src.ExperimentName),
                ScorecardDataRows(src.ScorecardDataRows)
            {}

            ~Scorecard() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["DateGenerated"], DateGenerated);
                FromJsonUtilS(input["Duration"], Duration);
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
                FromJsonUtilS(input["ExperimentName"], ExperimentName);
                FromJsonUtilO(input["ScorecardDataRows"], ScorecardDataRows);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DateGenerated; ToJsonUtilS(DateGenerated, each_DateGenerated); output["DateGenerated"] = each_DateGenerated;
                Json::Value each_Duration; ToJsonUtilS(Duration, each_Duration); output["Duration"] = each_Duration;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                Json::Value each_ExperimentName; ToJsonUtilS(ExperimentName, each_ExperimentName); output["ExperimentName"] = each_ExperimentName;
                Json::Value each_ScorecardDataRows; ToJsonUtilO(ScorecardDataRows, each_ScorecardDataRows); output["ScorecardDataRows"] = each_ScorecardDataRows;
                return output;
            }
        };

        struct GetLatestScorecardForExperimentResult : public PlayFabResultCommon
        {
            Boxed<Scorecard> pfScorecard;

            GetLatestScorecardForExperimentResult() :
                PlayFabResultCommon(),
                pfScorecard()
            {}

            GetLatestScorecardForExperimentResult(const GetLatestScorecardForExperimentResult& src) :
                PlayFabResultCommon(),
                pfScorecard(src.pfScorecard)
            {}

            ~GetLatestScorecardForExperimentResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Scorecard"], pfScorecard);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfScorecard; ToJsonUtilO(pfScorecard, each_pfScorecard); output["Scorecard"] = each_pfScorecard;
                return output;
            }
        };

        struct GetLatestScorecardsForTitleRequest : public PlayFabRequestCommon
        {

            GetLatestScorecardsForTitleRequest() :
                PlayFabRequestCommon()
            {}

            GetLatestScorecardsForTitleRequest(const GetLatestScorecardsForTitleRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetLatestScorecardsForTitleRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetLatestScorecardsForTitleResult : public PlayFabResultCommon
        {
            std::list<Scorecard> Scorecards;

            GetLatestScorecardsForTitleResult() :
                PlayFabResultCommon(),
                Scorecards()
            {}

            GetLatestScorecardsForTitleResult(const GetLatestScorecardsForTitleResult& src) :
                PlayFabResultCommon(),
                Scorecards(src.Scorecards)
            {}

            ~GetLatestScorecardsForTitleResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Scorecards"], Scorecards);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Scorecards; ToJsonUtilO(Scorecards, each_Scorecards); output["Scorecards"] = each_Scorecards;
                return output;
            }
        };

        struct GetTreatmentAssignmentRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            GetTreatmentAssignmentRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetTreatmentAssignmentRequest(const GetTreatmentAssignmentRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetTreatmentAssignmentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct TreatmentAssignment : public PlayFabBaseModel
        {
            std::list<Variable> Variables;
            std::list<std::string> Variants;

            TreatmentAssignment() :
                PlayFabBaseModel(),
                Variables(),
                Variants()
            {}

            TreatmentAssignment(const TreatmentAssignment& src) :
                PlayFabBaseModel(),
                Variables(src.Variables),
                Variants(src.Variants)
            {}

            ~TreatmentAssignment() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Variables"], Variables);
                FromJsonUtilS(input["Variants"], Variants);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Variables; ToJsonUtilO(Variables, each_Variables); output["Variables"] = each_Variables;
                Json::Value each_Variants; ToJsonUtilS(Variants, each_Variants); output["Variants"] = each_Variants;
                return output;
            }
        };

        struct GetTreatmentAssignmentResult : public PlayFabResultCommon
        {
            Boxed<TreatmentAssignment> pfTreatmentAssignment;

            GetTreatmentAssignmentResult() :
                PlayFabResultCommon(),
                pfTreatmentAssignment()
            {}

            GetTreatmentAssignmentResult(const GetTreatmentAssignmentResult& src) :
                PlayFabResultCommon(),
                pfTreatmentAssignment(src.pfTreatmentAssignment)
            {}

            ~GetTreatmentAssignmentResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["TreatmentAssignment"], pfTreatmentAssignment);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfTreatmentAssignment; ToJsonUtilO(pfTreatmentAssignment, each_pfTreatmentAssignment); output["TreatmentAssignment"] = each_pfTreatmentAssignment;
                return output;
            }
        };

        struct StartExperimentRequest : public PlayFabRequestCommon
        {
            std::string ExperimentId;

            StartExperimentRequest() :
                PlayFabRequestCommon(),
                ExperimentId()
            {}

            StartExperimentRequest(const StartExperimentRequest& src) :
                PlayFabRequestCommon(),
                ExperimentId(src.ExperimentId)
            {}

            ~StartExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                return output;
            }
        };

        struct StopExperimentRequest : public PlayFabRequestCommon
        {
            std::string ExperimentId;

            StopExperimentRequest() :
                PlayFabRequestCommon(),
                ExperimentId()
            {}

            StopExperimentRequest(const StopExperimentRequest& src) :
                PlayFabRequestCommon(),
                ExperimentId(src.ExperimentId)
            {}

            ~StopExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ExperimentId"], ExperimentId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExperimentId; ToJsonUtilS(ExperimentId, each_ExperimentId); output["ExperimentId"] = each_ExperimentId;
                return output;
            }
        };

        struct UpdateExperimentRequest : public PlayFabRequestCommon
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Id;
            std::string Name;
            Uint32 PopulationPercentage;
            std::string SegmentId;
            time_t StartDate;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            UpdateExperimentRequest() :
                PlayFabRequestCommon(),
                Description(),
                Duration(),
                pfExperimentType(),
                Id(),
                Name(),
                PopulationPercentage(),
                SegmentId(),
                StartDate(),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            UpdateExperimentRequest(const UpdateExperimentRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Id(src.Id),
                Name(src.Name),
                PopulationPercentage(src.PopulationPercentage),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            ~UpdateExperimentRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilP(input["Duration"], Duration);
                FromJsonUtilE(input["ExperimentType"], pfExperimentType);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["PopulationPercentage"], PopulationPercentage);
                FromJsonUtilS(input["SegmentId"], SegmentId);
                FromJsonUtilT(input["StartDate"], StartDate);
                FromJsonUtilS(input["TitlePlayerAccountTestIds"], TitlePlayerAccountTestIds);
                FromJsonUtilO(input["Variants"], Variants);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_Duration; ToJsonUtilP(Duration, each_Duration); output["Duration"] = each_Duration;
                Json::Value each_pfExperimentType; ToJsonUtilE(pfExperimentType, each_pfExperimentType); output["ExperimentType"] = each_pfExperimentType;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_PopulationPercentage; ToJsonUtilP(PopulationPercentage, each_PopulationPercentage); output["PopulationPercentage"] = each_PopulationPercentage;
                Json::Value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output["SegmentId"] = each_SegmentId;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_TitlePlayerAccountTestIds; ToJsonUtilS(TitlePlayerAccountTestIds, each_TitlePlayerAccountTestIds); output["TitlePlayerAccountTestIds"] = each_TitlePlayerAccountTestIds;
                Json::Value each_Variants; ToJsonUtilO(Variants, each_Variants); output["Variants"] = each_Variants;
                return output;
            }
        };

    }
}

#endif
