#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace EventsModels
    {
        // Events Enums
        // Events Classes
        struct DeleteEventSamplingRatioRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            std::string EventNamespace;

            DeleteEventSamplingRatioRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EventName(),
                EventNamespace()
            {}

            DeleteEventSamplingRatioRequest(const DeleteEventSamplingRatioRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace)
            {}

            ~DeleteEventSamplingRatioRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                return output;
            }
        };

        struct DeleteEventSamplingRatioResult : public PlayFabResultCommon
        {

            DeleteEventSamplingRatioResult() :
                PlayFabResultCommon()
            {}

            DeleteEventSamplingRatioResult(const DeleteEventSamplingRatioResult&) :
                PlayFabResultCommon()
            {}

            ~DeleteEventSamplingRatioResult() = default;

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

        struct EventContents : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            Boxed<time_t> OriginalTimestamp;
            Json::Value Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            ~EventContents() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["OriginalId"], OriginalId);
                FromJsonUtilT(input["OriginalTimestamp"], OriginalTimestamp);
                Payload = input["Payload"];
                FromJsonUtilS(input["PayloadJSON"], PayloadJSON);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_OriginalId; ToJsonUtilS(OriginalId, each_OriginalId); output["OriginalId"] = each_OriginalId;
                Json::Value each_OriginalTimestamp; ToJsonUtilT(OriginalTimestamp, each_OriginalTimestamp); output["OriginalTimestamp"] = each_OriginalTimestamp;
                output["Payload"] = Payload;
                Json::Value each_PayloadJSON; ToJsonUtilS(PayloadJSON, each_PayloadJSON); output["PayloadJSON"] = each_PayloadJSON;
                return output;
            }
        };

        struct EventSamplingRatio : public PlayFabBaseModel
        {
            std::string EventName;
            std::string EventNamespace;
            Int32 Ratio;

            EventSamplingRatio() :
                PlayFabBaseModel(),
                EventName(),
                EventNamespace(),
                Ratio()
            {}

            EventSamplingRatio(const EventSamplingRatio& src) :
                PlayFabBaseModel(),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace),
                Ratio(src.Ratio)
            {}

            ~EventSamplingRatio() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
                FromJsonUtilP(input["Ratio"], Ratio);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                Json::Value each_Ratio; ToJsonUtilP(Ratio, each_Ratio); output["Ratio"] = each_Ratio;
                return output;
            }
        };

        struct GetEventSamplingRatioRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            std::string EventNamespace;

            GetEventSamplingRatioRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EventName(),
                EventNamespace()
            {}

            GetEventSamplingRatioRequest(const GetEventSamplingRatioRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace)
            {}

            ~GetEventSamplingRatioRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                return output;
            }
        };

        struct GetEventSamplingRatioResult : public PlayFabResultCommon
        {
            std::string EventName;
            std::string EventNamespace;
            Int32 Ratio;

            GetEventSamplingRatioResult() :
                PlayFabResultCommon(),
                EventName(),
                EventNamespace(),
                Ratio()
            {}

            GetEventSamplingRatioResult(const GetEventSamplingRatioResult& src) :
                PlayFabResultCommon(),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace),
                Ratio(src.Ratio)
            {}

            ~GetEventSamplingRatioResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
                FromJsonUtilP(input["Ratio"], Ratio);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                Json::Value each_Ratio; ToJsonUtilP(Ratio, each_Ratio); output["Ratio"] = each_Ratio;
                return output;
            }
        };

        struct GetEventSamplingRatiosRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetEventSamplingRatiosRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetEventSamplingRatiosRequest(const GetEventSamplingRatiosRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetEventSamplingRatiosRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct GetEventSamplingRatiosResult : public PlayFabResultCommon
        {
            std::list<EventSamplingRatio> Ratios;

            GetEventSamplingRatiosResult() :
                PlayFabResultCommon(),
                Ratios()
            {}

            GetEventSamplingRatiosResult(const GetEventSamplingRatiosResult& src) :
                PlayFabResultCommon(),
                Ratios(src.Ratios)
            {}

            ~GetEventSamplingRatiosResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Ratios"], Ratios);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Ratios; ToJsonUtilO(Ratios, each_Ratios); output["Ratios"] = each_Ratios;
                return output;
            }
        };

        struct SetEventSamplingRatioRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            std::string EventNamespace;
            Int32 Ratio;

            SetEventSamplingRatioRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EventName(),
                EventNamespace(),
                Ratio()
            {}

            SetEventSamplingRatioRequest(const SetEventSamplingRatioRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace),
                Ratio(src.Ratio)
            {}

            ~SetEventSamplingRatioRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EventName"], EventName);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
                FromJsonUtilP(input["Ratio"], Ratio);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EventName; ToJsonUtilS(EventName, each_EventName); output["EventName"] = each_EventName;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                Json::Value each_Ratio; ToJsonUtilP(Ratio, each_Ratio); output["Ratio"] = each_Ratio;
                return output;
            }
        };

        struct SetEventSamplingRatioResult : public PlayFabResultCommon
        {

            SetEventSamplingRatioResult() :
                PlayFabResultCommon()
            {}

            SetEventSamplingRatioResult(const SetEventSamplingRatioResult&) :
                PlayFabResultCommon()
            {}

            ~SetEventSamplingRatioResult() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct WriteEventsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Events(src.Events)
            {}

            ~WriteEventsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Events"], Events);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Events; ToJsonUtilO(Events, each_Events); output["Events"] = each_Events;
                return output;
            }
        };

        struct WriteEventsResponse : public PlayFabResultCommon
        {
            std::list<std::string> AssignedEventIds;

            WriteEventsResponse() :
                PlayFabResultCommon(),
                AssignedEventIds()
            {}

            WriteEventsResponse(const WriteEventsResponse& src) :
                PlayFabResultCommon(),
                AssignedEventIds(src.AssignedEventIds)
            {}

            ~WriteEventsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AssignedEventIds"], AssignedEventIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssignedEventIds; ToJsonUtilS(AssignedEventIds, each_AssignedEventIds); output["AssignedEventIds"] = each_AssignedEventIds;
                return output;
            }
        };

    }
}

#endif
