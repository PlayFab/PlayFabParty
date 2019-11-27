#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace LeaderboardsModels
    {
        // Leaderboards Enums
        enum class LeaderboardSortDirection
        {
            LeaderboardSortDirectionDescending,
            LeaderboardSortDirectionAscending
        };

        inline void ToJsonEnum(const LeaderboardSortDirection input, Json::Value& output)
        {
            if (input == LeaderboardSortDirection::LeaderboardSortDirectionDescending) output = Json::Value("Descending");
            if (input == LeaderboardSortDirection::LeaderboardSortDirectionAscending) output = Json::Value("Ascending");
        }
        inline void FromJsonEnum(const Json::Value& input, LeaderboardSortDirection& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Descending") output = LeaderboardSortDirection::LeaderboardSortDirectionDescending;
            if (inputStr == "Ascending") output = LeaderboardSortDirection::LeaderboardSortDirectionAscending;
        }

        enum class StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void ToJsonEnum(const StatisticAggregationMethod input, Json::Value& output)
        {
            if (input == StatisticAggregationMethod::StatisticAggregationMethodLast) output = Json::Value("Last");
            if (input == StatisticAggregationMethod::StatisticAggregationMethodMin) output = Json::Value("Min");
            if (input == StatisticAggregationMethod::StatisticAggregationMethodMax) output = Json::Value("Max");
            if (input == StatisticAggregationMethod::StatisticAggregationMethodSum) output = Json::Value("Sum");
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticAggregationMethod& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Last") output = StatisticAggregationMethod::StatisticAggregationMethodLast;
            if (inputStr == "Min") output = StatisticAggregationMethod::StatisticAggregationMethodMin;
            if (inputStr == "Max") output = StatisticAggregationMethod::StatisticAggregationMethodMax;
            if (inputStr == "Sum") output = StatisticAggregationMethod::StatisticAggregationMethodSum;
        }

        // Leaderboards Classes
        struct LeaderboardDefinition : public PlayFabBaseModel
        {
            std::list<std::string> ChildLeaderboardNames;
            Boxed<Uint32> DynamicChildLeaderboardMaxSize;
            bool ProvisionLeaderboard;
            Boxed<LeaderboardSortDirection> SortDirection;

            LeaderboardDefinition() :
                PlayFabBaseModel(),
                ChildLeaderboardNames(),
                DynamicChildLeaderboardMaxSize(),
                ProvisionLeaderboard(),
                SortDirection()
            {}

            LeaderboardDefinition(const LeaderboardDefinition& src) :
                PlayFabBaseModel(),
                ChildLeaderboardNames(src.ChildLeaderboardNames),
                DynamicChildLeaderboardMaxSize(src.DynamicChildLeaderboardMaxSize),
                ProvisionLeaderboard(src.ProvisionLeaderboard),
                SortDirection(src.SortDirection)
            {}

            ~LeaderboardDefinition() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildLeaderboardNames"], ChildLeaderboardNames);
                FromJsonUtilP(input["DynamicChildLeaderboardMaxSize"], DynamicChildLeaderboardMaxSize);
                FromJsonUtilP(input["ProvisionLeaderboard"], ProvisionLeaderboard);
                FromJsonUtilE(input["SortDirection"], SortDirection);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildLeaderboardNames; ToJsonUtilS(ChildLeaderboardNames, each_ChildLeaderboardNames); output["ChildLeaderboardNames"] = each_ChildLeaderboardNames;
                Json::Value each_DynamicChildLeaderboardMaxSize; ToJsonUtilP(DynamicChildLeaderboardMaxSize, each_DynamicChildLeaderboardMaxSize); output["DynamicChildLeaderboardMaxSize"] = each_DynamicChildLeaderboardMaxSize;
                Json::Value each_ProvisionLeaderboard; ToJsonUtilP(ProvisionLeaderboard, each_ProvisionLeaderboard); output["ProvisionLeaderboard"] = each_ProvisionLeaderboard;
                Json::Value each_SortDirection; ToJsonUtilE(SortDirection, each_SortDirection); output["SortDirection"] = each_SortDirection;
                return output;
            }
        };

        struct CreateStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            Boxed<LeaderboardDefinition> pfLeaderboardDefinition;
            std::string Name;

            CreateStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                pfLeaderboardDefinition(),
                Name()
            {}

            CreateStatisticDefinitionRequest(const CreateStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                pfLeaderboardDefinition(src.pfLeaderboardDefinition),
                Name(src.Name)
            {}

            ~CreateStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilO(input["LeaderboardDefinition"], pfLeaderboardDefinition);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_pfLeaderboardDefinition; ToJsonUtilO(pfLeaderboardDefinition, each_pfLeaderboardDefinition); output["LeaderboardDefinition"] = each_pfLeaderboardDefinition;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct DeleteStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            std::string Name;

            DeleteStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                Name()
            {}

            DeleteStatisticDefinitionRequest(const DeleteStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                Name(src.Name)
            {}

            ~DeleteStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
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

        struct StatisticDelete : public PlayFabBaseModel
        {
            std::string ChildName;
            std::string Name;
            Boxed<Uint32> Version;

            StatisticDelete() :
                PlayFabBaseModel(),
                ChildName(),
                Name(),
                Version()
            {}

            StatisticDelete(const StatisticDelete& src) :
                PlayFabBaseModel(),
                ChildName(src.ChildName),
                Name(src.Name),
                Version(src.Version)
            {}

            ~StatisticDelete() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct DeleteStatisticsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<Int32> ExpectedProfileVersion;
            std::list<StatisticDelete> Statistics;

            DeleteStatisticsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ExpectedProfileVersion(),
                Statistics()
            {}

            DeleteStatisticsRequest(const DeleteStatisticsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Statistics(src.Statistics)
            {}

            ~DeleteStatisticsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output["ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct EntityStatisticChildValue : public PlayFabBaseModel
        {
            std::string ChildName;
            std::string Metadata;
            Int32 Value;

            EntityStatisticChildValue() :
                PlayFabBaseModel(),
                ChildName(),
                Metadata(),
                Value()
            {}

            EntityStatisticChildValue(const EntityStatisticChildValue& src) :
                PlayFabBaseModel(),
                ChildName(src.ChildName),
                Metadata(src.Metadata),
                Value(src.Value)
            {}

            ~EntityStatisticChildValue() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct EntityStatisticValue : public PlayFabBaseModel
        {
            std::map<std::string, EntityStatisticChildValue> ChildStatistics;
            std::string Metadata;
            std::string Name;
            Boxed<Int32> Value;
            Int32 Version;

            EntityStatisticValue() :
                PlayFabBaseModel(),
                ChildStatistics(),
                Metadata(),
                Name(),
                Value(),
                Version()
            {}

            EntityStatisticValue(const EntityStatisticValue& src) :
                PlayFabBaseModel(),
                ChildStatistics(src.ChildStatistics),
                Metadata(src.Metadata),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            ~EntityStatisticValue() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ChildStatistics"], ChildStatistics);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Value"], Value);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildStatistics; ToJsonUtilO(ChildStatistics, each_ChildStatistics); output["ChildStatistics"] = each_ChildStatistics;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct DeleteStatisticsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;
            std::map<std::string, EntityStatisticValue> Statistics;

            DeleteStatisticsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion(),
                Statistics()
            {}

            DeleteStatisticsResponse(const DeleteStatisticsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion),
                Statistics(src.Statistics)
            {}

            ~DeleteStatisticsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
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

        struct EntityLineage : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string GroupId;
            std::string MasterPlayerAccountId;
            std::string NamespaceId;
            std::string TitleId;
            std::string TitlePlayerAccountId;

            EntityLineage() :
                PlayFabBaseModel(),
                CharacterId(),
                GroupId(),
                MasterPlayerAccountId(),
                NamespaceId(),
                TitleId(),
                TitlePlayerAccountId()
            {}

            EntityLineage(const EntityLineage& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                GroupId(src.GroupId),
                MasterPlayerAccountId(src.MasterPlayerAccountId),
                NamespaceId(src.NamespaceId),
                TitleId(src.TitleId),
                TitlePlayerAccountId(src.TitlePlayerAccountId)
            {}

            ~EntityLineage() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["GroupId"], GroupId);
                FromJsonUtilS(input["MasterPlayerAccountId"], MasterPlayerAccountId);
                FromJsonUtilS(input["NamespaceId"], NamespaceId);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["TitlePlayerAccountId"], TitlePlayerAccountId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_GroupId; ToJsonUtilS(GroupId, each_GroupId); output["GroupId"] = each_GroupId;
                Json::Value each_MasterPlayerAccountId; ToJsonUtilS(MasterPlayerAccountId, each_MasterPlayerAccountId); output["MasterPlayerAccountId"] = each_MasterPlayerAccountId;
                Json::Value each_NamespaceId; ToJsonUtilS(NamespaceId, each_NamespaceId); output["NamespaceId"] = each_NamespaceId;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_TitlePlayerAccountId; ToJsonUtilS(TitlePlayerAccountId, each_TitlePlayerAccountId); output["TitlePlayerAccountId"] = each_TitlePlayerAccountId;
                return output;
            }
        };

        struct EntityLeaderboardEntry : public PlayFabBaseModel
        {
            std::string DisplayName;
            Boxed<EntityKey> Entity;
            std::string EntityLeaderboardMetadata;
            Boxed<EntityLineage> pfEntityLineage;
            std::string Metadata;
            Int32 Rank;
            Int32 Score;

            EntityLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                Entity(),
                EntityLeaderboardMetadata(),
                pfEntityLineage(),
                Metadata(),
                Rank(),
                Score()
            {}

            EntityLeaderboardEntry(const EntityLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Entity(src.Entity),
                EntityLeaderboardMetadata(src.EntityLeaderboardMetadata),
                pfEntityLineage(src.pfEntityLineage),
                Metadata(src.Metadata),
                Rank(src.Rank),
                Score(src.Score)
            {}

            ~EntityLeaderboardEntry() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityLeaderboardMetadata"], EntityLeaderboardMetadata);
                FromJsonUtilO(input["EntityLineage"], pfEntityLineage);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["Rank"], Rank);
                FromJsonUtilP(input["Score"], Score);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityLeaderboardMetadata; ToJsonUtilS(EntityLeaderboardMetadata, each_EntityLeaderboardMetadata); output["EntityLeaderboardMetadata"] = each_EntityLeaderboardMetadata;
                Json::Value each_pfEntityLineage; ToJsonUtilO(pfEntityLineage, each_pfEntityLineage); output["EntityLineage"] = each_pfEntityLineage;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Rank; ToJsonUtilP(Rank, each_Rank); output["Rank"] = each_Rank;
                Json::Value each_Score; ToJsonUtilP(Score, each_Score); output["Score"] = each_Score;
                return output;
            }
        };

        struct GetEntityLeaderboardRequest : public PlayFabRequestCommon
        {
            std::string ChildName;
            std::string EntityType;
            Uint32 MaxResults;
            Boxed<Uint32> StartingPosition;
            std::string StatisticName;
            Boxed<Uint32> StatisticVersion;

            GetEntityLeaderboardRequest() :
                PlayFabRequestCommon(),
                ChildName(),
                EntityType(),
                MaxResults(),
                StartingPosition(),
                StatisticName(),
                StatisticVersion()
            {}

            GetEntityLeaderboardRequest(const GetEntityLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                ChildName(src.ChildName),
                EntityType(src.EntityType),
                MaxResults(src.MaxResults),
                StartingPosition(src.StartingPosition),
                StatisticName(src.StatisticName),
                StatisticVersion(src.StatisticVersion)
            {}

            ~GetEntityLeaderboardRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilP(input["MaxResults"], MaxResults);
                FromJsonUtilP(input["StartingPosition"], StartingPosition);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_MaxResults; ToJsonUtilP(MaxResults, each_MaxResults); output["MaxResults"] = each_MaxResults;
                Json::Value each_StartingPosition; ToJsonUtilP(StartingPosition, each_StartingPosition); output["StartingPosition"] = each_StartingPosition;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct GetEntityLeaderboardResponse : public PlayFabResultCommon
        {
            std::list<EntityLeaderboardEntry> Rankings;
            Uint32 StatisticVersion;

            GetEntityLeaderboardResponse() :
                PlayFabResultCommon(),
                Rankings(),
                StatisticVersion()
            {}

            GetEntityLeaderboardResponse(const GetEntityLeaderboardResponse& src) :
                PlayFabResultCommon(),
                Rankings(src.Rankings),
                StatisticVersion(src.StatisticVersion)
            {}

            ~GetEntityLeaderboardResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Rankings"], Rankings);
                FromJsonUtilP(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Rankings; ToJsonUtilO(Rankings, each_Rankings); output["Rankings"] = each_Rankings;
                Json::Value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct GetLeaderboardAroundEntityRequest : public PlayFabRequestCommon
        {
            std::string ChildName;
            Boxed<EntityKey> Entity;
            Uint32 Offset;
            std::string StatisticName;
            Boxed<Uint32> StatisticVersion;

            GetLeaderboardAroundEntityRequest() :
                PlayFabRequestCommon(),
                ChildName(),
                Entity(),
                Offset(),
                StatisticName(),
                StatisticVersion()
            {}

            GetLeaderboardAroundEntityRequest(const GetLeaderboardAroundEntityRequest& src) :
                PlayFabRequestCommon(),
                ChildName(src.ChildName),
                Entity(src.Entity),
                Offset(src.Offset),
                StatisticName(src.StatisticName),
                StatisticVersion(src.StatisticVersion)
            {}

            ~GetLeaderboardAroundEntityRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["Offset"], Offset);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Offset; ToJsonUtilP(Offset, each_Offset); output["Offset"] = each_Offset;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct GetLeaderboardForEntitiesRequest : public PlayFabRequestCommon
        {
            std::string ChildName;
            std::list<std::string> Entities;
            std::string EntityType;
            std::string StatisticName;
            Boxed<Uint32> StatisticVersion;

            GetLeaderboardForEntitiesRequest() :
                PlayFabRequestCommon(),
                ChildName(),
                Entities(),
                EntityType(),
                StatisticName(),
                StatisticVersion()
            {}

            GetLeaderboardForEntitiesRequest(const GetLeaderboardForEntitiesRequest& src) :
                PlayFabRequestCommon(),
                ChildName(src.ChildName),
                Entities(src.Entities),
                EntityType(src.EntityType),
                StatisticName(src.StatisticName),
                StatisticVersion(src.StatisticVersion)
            {}

            ~GetLeaderboardForEntitiesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilS(input["Entities"], Entities);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilS(input["StatisticName"], StatisticName);
                FromJsonUtilP(input["StatisticVersion"], StatisticVersion);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_Entities; ToJsonUtilS(Entities, each_Entities); output["Entities"] = each_Entities;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                Json::Value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output["StatisticVersion"] = each_StatisticVersion;
                return output;
            }
        };

        struct GetStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            std::string Name;

            GetStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                Name()
            {}

            GetStatisticDefinitionRequest(const GetStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                Name(src.Name)
            {}

            ~GetStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct GetStatisticDefinitionResponse : public PlayFabResultCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            time_t Created;
            Boxed<time_t> LastResetTime;
            Boxed<LeaderboardDefinition> pfLeaderboardDefinition;
            std::string Name;
            Uint32 Version;

            GetStatisticDefinitionResponse() :
                PlayFabResultCommon(),
                AggregationMethod(),
                Created(),
                LastResetTime(),
                pfLeaderboardDefinition(),
                Name(),
                Version()
            {}

            GetStatisticDefinitionResponse(const GetStatisticDefinitionResponse& src) :
                PlayFabResultCommon(),
                AggregationMethod(src.AggregationMethod),
                Created(src.Created),
                LastResetTime(src.LastResetTime),
                pfLeaderboardDefinition(src.pfLeaderboardDefinition),
                Name(src.Name),
                Version(src.Version)
            {}

            ~GetStatisticDefinitionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilO(input["LeaderboardDefinition"], pfLeaderboardDefinition);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_pfLeaderboardDefinition; ToJsonUtilO(pfLeaderboardDefinition, each_pfLeaderboardDefinition); output["LeaderboardDefinition"] = each_pfLeaderboardDefinition;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetStatisticDefinitionsRequest : public PlayFabRequestCommon
        {

            GetStatisticDefinitionsRequest() :
                PlayFabRequestCommon()
            {}

            GetStatisticDefinitionsRequest(const GetStatisticDefinitionsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetStatisticDefinitionsRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct StatisticDefinition : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            time_t Created;
            Boxed<time_t> LastResetTime;
            Boxed<LeaderboardDefinition> pfLeaderboardDefinition;
            std::string Name;
            Uint32 Version;

            StatisticDefinition() :
                PlayFabBaseModel(),
                AggregationMethod(),
                Created(),
                LastResetTime(),
                pfLeaderboardDefinition(),
                Name(),
                Version()
            {}

            StatisticDefinition(const StatisticDefinition& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                Created(src.Created),
                LastResetTime(src.LastResetTime),
                pfLeaderboardDefinition(src.pfLeaderboardDefinition),
                Name(src.Name),
                Version(src.Version)
            {}

            ~StatisticDefinition() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilO(input["LeaderboardDefinition"], pfLeaderboardDefinition);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_pfLeaderboardDefinition; ToJsonUtilO(pfLeaderboardDefinition, each_pfLeaderboardDefinition); output["LeaderboardDefinition"] = each_pfLeaderboardDefinition;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetStatisticDefinitionsResponse : public PlayFabResultCommon
        {
            std::list<StatisticDefinition> StatisticDefinitions;

            GetStatisticDefinitionsResponse() :
                PlayFabResultCommon(),
                StatisticDefinitions()
            {}

            GetStatisticDefinitionsResponse(const GetStatisticDefinitionsResponse& src) :
                PlayFabResultCommon(),
                StatisticDefinitions(src.StatisticDefinitions)
            {}

            ~GetStatisticDefinitionsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["StatisticDefinitions"], StatisticDefinitions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_StatisticDefinitions; ToJsonUtilO(StatisticDefinitions, each_StatisticDefinitions); output["StatisticDefinitions"] = each_StatisticDefinitions;
                return output;
            }
        };

        struct IncrementStatisticVersionRequest : public PlayFabRequestCommon
        {
            std::string Name;

            IncrementStatisticVersionRequest() :
                PlayFabRequestCommon(),
                Name()
            {}

            IncrementStatisticVersionRequest(const IncrementStatisticVersionRequest& src) :
                PlayFabRequestCommon(),
                Name(src.Name)
            {}

            ~IncrementStatisticVersionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct IncrementStatisticVersionResponse : public PlayFabResultCommon
        {
            Uint32 Version;
            Uint32 VersionToBeDeleted;

            IncrementStatisticVersionResponse() :
                PlayFabResultCommon(),
                Version(),
                VersionToBeDeleted()
            {}

            IncrementStatisticVersionResponse(const IncrementStatisticVersionResponse& src) :
                PlayFabResultCommon(),
                Version(src.Version),
                VersionToBeDeleted(src.VersionToBeDeleted)
            {}

            ~IncrementStatisticVersionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilP(input["VersionToBeDeleted"], VersionToBeDeleted);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_VersionToBeDeleted; ToJsonUtilP(VersionToBeDeleted, each_VersionToBeDeleted); output["VersionToBeDeleted"] = each_VersionToBeDeleted;
                return output;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string ChildName;
            std::string Metadata;
            std::string Name;
            Int32 Value;
            Boxed<Uint32> Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                ChildName(),
                Metadata(),
                Name(),
                Value(),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                ChildName(src.ChildName),
                Metadata(src.Metadata),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticUpdate() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildName"], ChildName);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Value"], Value);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildName; ToJsonUtilS(ChildName, each_ChildName); output["ChildName"] = each_ChildName;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Value; ToJsonUtilP(Value, each_Value); output["Value"] = each_Value;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct UpdateLeaderboardDefinition : public PlayFabBaseModel
        {
            std::list<std::string> ChildLeaderboardNames;
            Boxed<Uint32> DynamicChildLeaderboardMaxSize;
            bool ProvisionLeaderboard;

            UpdateLeaderboardDefinition() :
                PlayFabBaseModel(),
                ChildLeaderboardNames(),
                DynamicChildLeaderboardMaxSize(),
                ProvisionLeaderboard()
            {}

            UpdateLeaderboardDefinition(const UpdateLeaderboardDefinition& src) :
                PlayFabBaseModel(),
                ChildLeaderboardNames(src.ChildLeaderboardNames),
                DynamicChildLeaderboardMaxSize(src.DynamicChildLeaderboardMaxSize),
                ProvisionLeaderboard(src.ProvisionLeaderboard)
            {}

            ~UpdateLeaderboardDefinition() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChildLeaderboardNames"], ChildLeaderboardNames);
                FromJsonUtilP(input["DynamicChildLeaderboardMaxSize"], DynamicChildLeaderboardMaxSize);
                FromJsonUtilP(input["ProvisionLeaderboard"], ProvisionLeaderboard);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChildLeaderboardNames; ToJsonUtilS(ChildLeaderboardNames, each_ChildLeaderboardNames); output["ChildLeaderboardNames"] = each_ChildLeaderboardNames;
                Json::Value each_DynamicChildLeaderboardMaxSize; ToJsonUtilP(DynamicChildLeaderboardMaxSize, each_DynamicChildLeaderboardMaxSize); output["DynamicChildLeaderboardMaxSize"] = each_DynamicChildLeaderboardMaxSize;
                Json::Value each_ProvisionLeaderboard; ToJsonUtilP(ProvisionLeaderboard, each_ProvisionLeaderboard); output["ProvisionLeaderboard"] = each_ProvisionLeaderboard;
                return output;
            }
        };

        struct UpdateStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            Boxed<UpdateLeaderboardDefinition> LeaderboardDefinition;
            std::string Name;
            std::string NewName;

            UpdateStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                LeaderboardDefinition(),
                Name(),
                NewName()
            {}

            UpdateStatisticDefinitionRequest(const UpdateStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                LeaderboardDefinition(src.LeaderboardDefinition),
                Name(src.Name),
                NewName(src.NewName)
            {}

            ~UpdateStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilO(input["LeaderboardDefinition"], LeaderboardDefinition);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["NewName"], NewName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_LeaderboardDefinition; ToJsonUtilO(LeaderboardDefinition, each_LeaderboardDefinition); output["LeaderboardDefinition"] = each_LeaderboardDefinition;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_NewName; ToJsonUtilS(NewName, each_NewName); output["NewName"] = each_NewName;
                return output;
            }
        };

        struct UpdateStatisticsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityLeaderboardMetadata;
            Boxed<Int32> ExpectedProfileVersion;
            Boxed<bool> ForceUpdate;
            std::list<StatisticUpdate> Statistics;

            UpdateStatisticsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                EntityLeaderboardMetadata(),
                ExpectedProfileVersion(),
                ForceUpdate(),
                Statistics()
            {}

            UpdateStatisticsRequest(const UpdateStatisticsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                EntityLeaderboardMetadata(src.EntityLeaderboardMetadata),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                ForceUpdate(src.ForceUpdate),
                Statistics(src.Statistics)
            {}

            ~UpdateStatisticsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityLeaderboardMetadata"], EntityLeaderboardMetadata);
                FromJsonUtilP(input["ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilP(input["ForceUpdate"], ForceUpdate);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityLeaderboardMetadata; ToJsonUtilS(EntityLeaderboardMetadata, each_EntityLeaderboardMetadata); output["EntityLeaderboardMetadata"] = each_EntityLeaderboardMetadata;
                Json::Value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output["ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                Json::Value each_ForceUpdate; ToJsonUtilP(ForceUpdate, each_ForceUpdate); output["ForceUpdate"] = each_ForceUpdate;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct UpdateStatisticsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;
            std::map<std::string, EntityStatisticValue> Statistics;

            UpdateStatisticsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion(),
                Statistics()
            {}

            UpdateStatisticsResponse(const UpdateStatisticsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion),
                Statistics(src.Statistics)
            {}

            ~UpdateStatisticsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

    }
}

#endif
