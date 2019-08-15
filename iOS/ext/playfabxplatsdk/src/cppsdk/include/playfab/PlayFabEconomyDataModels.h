#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace EconomyModels
    {
        // Economy Enums
        enum ConcernCategory
        {
            ConcernCategoryNone,
            ConcernCategoryOffensiveContent,
            ConcernCategoryChildExploitation,
            ConcernCategoryMalwareOrVirus,
            ConcernCategoryPrivacyConcerns,
            ConcernCategoryMisleadingApp,
            ConcernCategoryPoorPerformance,
            ConcernCategoryReviewResponse,
            ConcernCategorySpamAdvertising,
            ConcernCategoryProfanity
        };

        inline void ToJsonEnum(const ConcernCategory input, Json::Value& output)
        {
            if (input == ConcernCategoryNone) output = Json::Value("None");
            if (input == ConcernCategoryOffensiveContent) output = Json::Value("OffensiveContent");
            if (input == ConcernCategoryChildExploitation) output = Json::Value("ChildExploitation");
            if (input == ConcernCategoryMalwareOrVirus) output = Json::Value("MalwareOrVirus");
            if (input == ConcernCategoryPrivacyConcerns) output = Json::Value("PrivacyConcerns");
            if (input == ConcernCategoryMisleadingApp) output = Json::Value("MisleadingApp");
            if (input == ConcernCategoryPoorPerformance) output = Json::Value("PoorPerformance");
            if (input == ConcernCategoryReviewResponse) output = Json::Value("ReviewResponse");
            if (input == ConcernCategorySpamAdvertising) output = Json::Value("SpamAdvertising");
            if (input == ConcernCategoryProfanity) output = Json::Value("Profanity");
        }
        inline void FromJsonEnum(const Json::Value& input, ConcernCategory& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "None") output = ConcernCategoryNone;
            if (inputStr == "OffensiveContent") output = ConcernCategoryOffensiveContent;
            if (inputStr == "ChildExploitation") output = ConcernCategoryChildExploitation;
            if (inputStr == "MalwareOrVirus") output = ConcernCategoryMalwareOrVirus;
            if (inputStr == "PrivacyConcerns") output = ConcernCategoryPrivacyConcerns;
            if (inputStr == "MisleadingApp") output = ConcernCategoryMisleadingApp;
            if (inputStr == "PoorPerformance") output = ConcernCategoryPoorPerformance;
            if (inputStr == "ReviewResponse") output = ConcernCategoryReviewResponse;
            if (inputStr == "SpamAdvertising") output = ConcernCategorySpamAdvertising;
            if (inputStr == "Profanity") output = ConcernCategoryProfanity;
        }

        enum ContainerType
        {
            ContainerTypeNone,
            ContainerTypeBundles,
            ContainerTypeStores,
            ContainerTypeSubscriptions
        };

        inline void ToJsonEnum(const ContainerType input, Json::Value& output)
        {
            if (input == ContainerTypeNone) output = Json::Value("None");
            if (input == ContainerTypeBundles) output = Json::Value("Bundles");
            if (input == ContainerTypeStores) output = Json::Value("Stores");
            if (input == ContainerTypeSubscriptions) output = Json::Value("Subscriptions");
        }
        inline void FromJsonEnum(const Json::Value& input, ContainerType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "None") output = ContainerTypeNone;
            if (inputStr == "Bundles") output = ContainerTypeBundles;
            if (inputStr == "Stores") output = ContainerTypeStores;
            if (inputStr == "Subscriptions") output = ContainerTypeSubscriptions;
        }

        enum DisplayPropertyType
        {
            DisplayPropertyTypeQueryDateTime,
            DisplayPropertyTypeQueryDouble,
            DisplayPropertyTypeQueryString,
            DisplayPropertyTypeSearchString
        };

        inline void ToJsonEnum(const DisplayPropertyType input, Json::Value& output)
        {
            if (input == DisplayPropertyTypeQueryDateTime) output = Json::Value("QueryDateTime");
            if (input == DisplayPropertyTypeQueryDouble) output = Json::Value("QueryDouble");
            if (input == DisplayPropertyTypeQueryString) output = Json::Value("QueryString");
            if (input == DisplayPropertyTypeSearchString) output = Json::Value("SearchString");
        }
        inline void FromJsonEnum(const Json::Value& input, DisplayPropertyType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "QueryDateTime") output = DisplayPropertyTypeQueryDateTime;
            if (inputStr == "QueryDouble") output = DisplayPropertyTypeQueryDouble;
            if (inputStr == "QueryString") output = DisplayPropertyTypeQueryString;
            if (inputStr == "SearchString") output = DisplayPropertyTypeSearchString;
        }

        enum ModerationStatus
        {
            ModerationStatusUnknown,
            ModerationStatusAwaitingModeration,
            ModerationStatusApproved,
            ModerationStatusRejected
        };

        inline void ToJsonEnum(const ModerationStatus input, Json::Value& output)
        {
            if (input == ModerationStatusUnknown) output = Json::Value("Unknown");
            if (input == ModerationStatusAwaitingModeration) output = Json::Value("AwaitingModeration");
            if (input == ModerationStatusApproved) output = Json::Value("Approved");
            if (input == ModerationStatusRejected) output = Json::Value("Rejected");
        }
        inline void FromJsonEnum(const Json::Value& input, ModerationStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = ModerationStatusUnknown;
            if (inputStr == "AwaitingModeration") output = ModerationStatusAwaitingModeration;
            if (inputStr == "Approved") output = ModerationStatusApproved;
            if (inputStr == "Rejected") output = ModerationStatusRejected;
        }

        enum PublishResult
        {
            PublishResultUnknown,
            PublishResultPending,
            PublishResultSucceeded,
            PublishResultFailed,
            PublishResultCanceled
        };

        inline void ToJsonEnum(const PublishResult input, Json::Value& output)
        {
            if (input == PublishResultUnknown) output = Json::Value("Unknown");
            if (input == PublishResultPending) output = Json::Value("Pending");
            if (input == PublishResultSucceeded) output = Json::Value("Succeeded");
            if (input == PublishResultFailed) output = Json::Value("Failed");
            if (input == PublishResultCanceled) output = Json::Value("Canceled");
        }
        inline void FromJsonEnum(const Json::Value& input, PublishResult& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = PublishResultUnknown;
            if (inputStr == "Pending") output = PublishResultPending;
            if (inputStr == "Succeeded") output = PublishResultSucceeded;
            if (inputStr == "Failed") output = PublishResultFailed;
            if (inputStr == "Canceled") output = PublishResultCanceled;
        }

        // Economy Classes
        struct CatalogAlternateId : public PlayFabBaseModel
        {
            std::string Type;
            std::string Value;

            CatalogAlternateId() :
                PlayFabBaseModel(),
                Type(),
                Value()
            {}

            CatalogAlternateId(const CatalogAlternateId& src) :
                PlayFabBaseModel(),
                Type(src.Type),
                Value(src.Value)
            {}

            ~CatalogAlternateId() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct CurrencyDetails : public PlayFabBaseModel
        {
            Boxed<CatalogAlternateId> AlternateId;
            Int32 Amount;
            std::string CurrencyId;
            std::string InstanceId;

            CurrencyDetails() :
                PlayFabBaseModel(),
                AlternateId(),
                Amount(),
                CurrencyId(),
                InstanceId()
            {}

            CurrencyDetails(const CurrencyDetails& src) :
                PlayFabBaseModel(),
                AlternateId(src.AlternateId),
                Amount(src.Amount),
                CurrencyId(src.CurrencyId),
                InstanceId(src.InstanceId)
            {}

            ~CurrencyDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
                FromJsonUtilS(input["InstanceId"], InstanceId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                Json::Value each_InstanceId; ToJsonUtilS(InstanceId, each_InstanceId); output["InstanceId"] = each_InstanceId;
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

            void FromJson(Json::Value& input) override
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

        struct AddVirtualCurrenciesRequest : public PlayFabRequestCommon
        {
            std::list<CurrencyDetails> Currencies;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;

            AddVirtualCurrenciesRequest() :
                PlayFabRequestCommon(),
                Currencies(),
                Entity(),
                IdempotencyId()
            {}

            AddVirtualCurrenciesRequest(const AddVirtualCurrenciesRequest& src) :
                PlayFabRequestCommon(),
                Currencies(src.Currencies),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId)
            {}

            ~AddVirtualCurrenciesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct CurrencyResponseDto : public PlayFabBaseModel
        {
            Int32 Amount;
            Boxed<Int32> ChangedAmount;
            std::string CurrencyId;

            CurrencyResponseDto() :
                PlayFabBaseModel(),
                Amount(),
                ChangedAmount(),
                CurrencyId()
            {}

            CurrencyResponseDto(const CurrencyResponseDto& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ChangedAmount(src.ChangedAmount),
                CurrencyId(src.CurrencyId)
            {}

            ~CurrencyResponseDto() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["ChangedAmount"], ChangedAmount);
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ChangedAmount; ToJsonUtilP(ChangedAmount, each_ChangedAmount); output["ChangedAmount"] = each_ChangedAmount;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                return output;
            }
        };

        struct AddVirtualCurrenciesResult : public PlayFabResultCommon
        {
            std::list<CurrencyResponseDto> Currencies;
            std::string IdempotencyId;

            AddVirtualCurrenciesResult() :
                PlayFabResultCommon(),
                Currencies(),
                IdempotencyId()
            {}

            AddVirtualCurrenciesResult(const AddVirtualCurrenciesResult& src) :
                PlayFabResultCommon(),
                Currencies(src.Currencies),
                IdempotencyId(src.IdempotencyId)
            {}

            ~AddVirtualCurrenciesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct CatalogSpecificConfig : public PlayFabBaseModel
        {
            std::list<std::string> ContentTypes;
            std::list<std::string> Tags;

            CatalogSpecificConfig() :
                PlayFabBaseModel(),
                ContentTypes(),
                Tags()
            {}

            CatalogSpecificConfig(const CatalogSpecificConfig& src) :
                PlayFabBaseModel(),
                ContentTypes(src.ContentTypes),
                Tags(src.Tags)
            {}

            ~CatalogSpecificConfig() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContentTypes"], ContentTypes);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentTypes; ToJsonUtilS(ContentTypes, each_ContentTypes); output["ContentTypes"] = each_ContentTypes;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct DeepLinkFormat : public PlayFabBaseModel
        {
            std::string Format;
            std::string Platform;

            DeepLinkFormat() :
                PlayFabBaseModel(),
                Format(),
                Platform()
            {}

            DeepLinkFormat(const DeepLinkFormat& src) :
                PlayFabBaseModel(),
                Format(src.Format),
                Platform(src.Platform)
            {}

            ~DeepLinkFormat() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Format"], Format);
                FromJsonUtilS(input["Platform"], Platform);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Format; ToJsonUtilS(Format, each_Format); output["Format"] = each_Format;
                Json::Value each_Platform; ToJsonUtilS(Platform, each_Platform); output["Platform"] = each_Platform;
                return output;
            }
        };

        struct DisplayPropertyIndexInfo : public PlayFabBaseModel
        {
            std::string Name;
            Boxed<DisplayPropertyType> Type;

            DisplayPropertyIndexInfo() :
                PlayFabBaseModel(),
                Name(),
                Type()
            {}

            DisplayPropertyIndexInfo(const DisplayPropertyIndexInfo& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Type(src.Type)
            {}

            ~DisplayPropertyIndexInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilE(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Type; ToJsonUtilE(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct UserGeneratedContentSpecificConfig : public PlayFabBaseModel
        {
            std::list<std::string> ContentTypes;
            bool Enabled;
            std::list<std::string> Tags;

            UserGeneratedContentSpecificConfig() :
                PlayFabBaseModel(),
                ContentTypes(),
                Enabled(),
                Tags()
            {}

            UserGeneratedContentSpecificConfig(const UserGeneratedContentSpecificConfig& src) :
                PlayFabBaseModel(),
                ContentTypes(src.ContentTypes),
                Enabled(src.Enabled),
                Tags(src.Tags)
            {}

            ~UserGeneratedContentSpecificConfig() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContentTypes"], ContentTypes);
                FromJsonUtilP(input["Enabled"], Enabled);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentTypes; ToJsonUtilS(ContentTypes, each_ContentTypes); output["ContentTypes"] = each_ContentTypes;
                Json::Value each_Enabled; ToJsonUtilP(Enabled, each_Enabled); output["Enabled"] = each_Enabled;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct CatalogConfig : public PlayFabBaseModel
        {
            std::list<std::string> Admins;
            Boxed<CatalogSpecificConfig> Catalog;
            std::list<DeepLinkFormat> DeepLinkFormats;
            std::list<DisplayPropertyIndexInfo> DisplayPropertyIndexInfos;
            std::list<std::string> Reviewers;
            Boxed<UserGeneratedContentSpecificConfig> UserGeneratedContent;

            CatalogConfig() :
                PlayFabBaseModel(),
                Admins(),
                Catalog(),
                DeepLinkFormats(),
                DisplayPropertyIndexInfos(),
                Reviewers(),
                UserGeneratedContent()
            {}

            CatalogConfig(const CatalogConfig& src) :
                PlayFabBaseModel(),
                Admins(src.Admins),
                Catalog(src.Catalog),
                DeepLinkFormats(src.DeepLinkFormats),
                DisplayPropertyIndexInfos(src.DisplayPropertyIndexInfos),
                Reviewers(src.Reviewers),
                UserGeneratedContent(src.UserGeneratedContent)
            {}

            ~CatalogConfig() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Admins"], Admins);
                FromJsonUtilO(input["Catalog"], Catalog);
                FromJsonUtilO(input["DeepLinkFormats"], DeepLinkFormats);
                FromJsonUtilO(input["DisplayPropertyIndexInfos"], DisplayPropertyIndexInfos);
                FromJsonUtilS(input["Reviewers"], Reviewers);
                FromJsonUtilO(input["UserGeneratedContent"], UserGeneratedContent);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Admins; ToJsonUtilS(Admins, each_Admins); output["Admins"] = each_Admins;
                Json::Value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output["Catalog"] = each_Catalog;
                Json::Value each_DeepLinkFormats; ToJsonUtilO(DeepLinkFormats, each_DeepLinkFormats); output["DeepLinkFormats"] = each_DeepLinkFormats;
                Json::Value each_DisplayPropertyIndexInfos; ToJsonUtilO(DisplayPropertyIndexInfos, each_DisplayPropertyIndexInfos); output["DisplayPropertyIndexInfos"] = each_DisplayPropertyIndexInfos;
                Json::Value each_Reviewers; ToJsonUtilS(Reviewers, each_Reviewers); output["Reviewers"] = each_Reviewers;
                Json::Value each_UserGeneratedContent; ToJsonUtilO(UserGeneratedContent, each_UserGeneratedContent); output["UserGeneratedContent"] = each_UserGeneratedContent;
                return output;
            }
        };

        struct Content : public PlayFabBaseModel
        {
            std::string Id;
            std::string MaxClientVersion;
            std::string MinClientVersion;
            std::list<std::string> Tags;
            std::string Type;
            std::string Url;

            Content() :
                PlayFabBaseModel(),
                Id(),
                MaxClientVersion(),
                MinClientVersion(),
                Tags(),
                Type(),
                Url()
            {}

            Content(const Content& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                MaxClientVersion(src.MaxClientVersion),
                MinClientVersion(src.MinClientVersion),
                Tags(src.Tags),
                Type(src.Type),
                Url(src.Url)
            {}

            ~Content() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["MaxClientVersion"], MaxClientVersion);
                FromJsonUtilS(input["MinClientVersion"], MinClientVersion);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_MaxClientVersion; ToJsonUtilS(MaxClientVersion, each_MaxClientVersion); output["MaxClientVersion"] = each_MaxClientVersion;
                Json::Value each_MinClientVersion; ToJsonUtilS(MinClientVersion, each_MinClientVersion); output["MinClientVersion"] = each_MinClientVersion;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct DeepLink : public PlayFabBaseModel
        {
            std::string Platform;
            std::string Url;

            DeepLink() :
                PlayFabBaseModel(),
                Platform(),
                Url()
            {}

            DeepLink(const DeepLink& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                Url(src.Url)
            {}

            ~DeepLink() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Platform"], Platform);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Platform; ToJsonUtilS(Platform, each_Platform); output["Platform"] = each_Platform;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct Image : public PlayFabBaseModel
        {
            std::string Id;
            std::list<std::string> Locales;
            std::string Tag;
            std::string Type;
            std::string Url;

            Image() :
                PlayFabBaseModel(),
                Id(),
                Locales(),
                Tag(),
                Type(),
                Url()
            {}

            Image(const Image& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Locales(src.Locales),
                Tag(src.Tag),
                Type(src.Type),
                Url(src.Url)
            {}

            ~Image() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Locales"], Locales);
                FromJsonUtilS(input["Tag"], Tag);
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Locales; ToJsonUtilS(Locales, each_Locales); output["Locales"] = each_Locales;
                Json::Value each_Tag; ToJsonUtilS(Tag, each_Tag); output["Tag"] = each_Tag;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct CatalogPriceAmount : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string CurrencyId;

            CatalogPriceAmount() :
                PlayFabBaseModel(),
                Amount(),
                CurrencyId()
            {}

            CatalogPriceAmount(const CatalogPriceAmount& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CurrencyId(src.CurrencyId)
            {}

            ~CatalogPriceAmount() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                return output;
            }
        };

        struct CatalogPriceInstance : public PlayFabBaseModel
        {
            std::list<CatalogPriceAmount> Amounts;

            CatalogPriceInstance() :
                PlayFabBaseModel(),
                Amounts()
            {}

            CatalogPriceInstance(const CatalogPriceInstance& src) :
                PlayFabBaseModel(),
                Amounts(src.Amounts)
            {}

            ~CatalogPriceInstance() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Amounts"], Amounts);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amounts; ToJsonUtilO(Amounts, each_Amounts); output["Amounts"] = each_Amounts;
                return output;
            }
        };

        struct CatalogPrice : public PlayFabBaseModel
        {
            Boxed<double> PayoutAmount;
            std::list<CatalogPriceInstance> Prices;
            Boxed<Int32> Sort;

            CatalogPrice() :
                PlayFabBaseModel(),
                PayoutAmount(),
                Prices(),
                Sort()
            {}

            CatalogPrice(const CatalogPrice& src) :
                PlayFabBaseModel(),
                PayoutAmount(src.PayoutAmount),
                Prices(src.Prices),
                Sort(src.Sort)
            {}

            ~CatalogPrice() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PayoutAmount"], PayoutAmount);
                FromJsonUtilO(input["Prices"], Prices);
                FromJsonUtilP(input["Sort"], Sort);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PayoutAmount; ToJsonUtilP(PayoutAmount, each_PayoutAmount); output["PayoutAmount"] = each_PayoutAmount;
                Json::Value each_Prices; ToJsonUtilO(Prices, each_Prices); output["Prices"] = each_Prices;
                Json::Value each_Sort; ToJsonUtilP(Sort, each_Sort); output["Sort"] = each_Sort;
                return output;
            }
        };

        struct CatalogItemReference : public PlayFabBaseModel
        {
            Boxed<Int32> Amount;
            std::string Id;
            Boxed<CatalogPrice> Price;

            CatalogItemReference() :
                PlayFabBaseModel(),
                Amount(),
                Id(),
                Price()
            {}

            CatalogItemReference(const CatalogItemReference& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Id(src.Id),
                Price(src.Price)
            {}

            ~CatalogItemReference() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Price"], Price);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Price; ToJsonUtilO(Price, each_Price); output["Price"] = each_Price;
                return output;
            }
        };

        struct ModerationState : public PlayFabBaseModel
        {
            Boxed<time_t> LastModifiedDate;
            std::string Reason;
            Boxed<ModerationStatus> Status;

            ModerationState() :
                PlayFabBaseModel(),
                LastModifiedDate(),
                Reason(),
                Status()
            {}

            ModerationState(const ModerationState& src) :
                PlayFabBaseModel(),
                LastModifiedDate(src.LastModifiedDate),
                Reason(src.Reason),
                Status(src.Status)
            {}

            ~ModerationState() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["LastModifiedDate"], LastModifiedDate);
                FromJsonUtilS(input["Reason"], Reason);
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LastModifiedDate; ToJsonUtilT(LastModifiedDate, each_LastModifiedDate); output["LastModifiedDate"] = each_LastModifiedDate;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct PayoutInfo : public PlayFabBaseModel
        {
            std::string AccountSellerId;
            std::string TaxCode;
            std::string Uaid;

            PayoutInfo() :
                PlayFabBaseModel(),
                AccountSellerId(),
                TaxCode(),
                Uaid()
            {}

            PayoutInfo(const PayoutInfo& src) :
                PlayFabBaseModel(),
                AccountSellerId(src.AccountSellerId),
                TaxCode(src.TaxCode),
                Uaid(src.Uaid)
            {}

            ~PayoutInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AccountSellerId"], AccountSellerId);
                FromJsonUtilS(input["TaxCode"], TaxCode);
                FromJsonUtilS(input["Uaid"], Uaid);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountSellerId; ToJsonUtilS(AccountSellerId, each_AccountSellerId); output["AccountSellerId"] = each_AccountSellerId;
                Json::Value each_TaxCode; ToJsonUtilS(TaxCode, each_TaxCode); output["TaxCode"] = each_TaxCode;
                Json::Value each_Uaid; ToJsonUtilS(Uaid, each_Uaid); output["Uaid"] = each_Uaid;
                return output;
            }
        };

        struct Rating : public PlayFabBaseModel
        {
            Boxed<float> Average;
            Boxed<Int32> Count1Star;
            Boxed<Int32> Count2Star;
            Boxed<Int32> Count3Star;
            Boxed<Int32> Count4Star;
            Boxed<Int32> Count5Star;
            Boxed<Int32> TotalCount;

            Rating() :
                PlayFabBaseModel(),
                Average(),
                Count1Star(),
                Count2Star(),
                Count3Star(),
                Count4Star(),
                Count5Star(),
                TotalCount()
            {}

            Rating(const Rating& src) :
                PlayFabBaseModel(),
                Average(src.Average),
                Count1Star(src.Count1Star),
                Count2Star(src.Count2Star),
                Count3Star(src.Count3Star),
                Count4Star(src.Count4Star),
                Count5Star(src.Count5Star),
                TotalCount(src.TotalCount)
            {}

            ~Rating() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Average"], Average);
                FromJsonUtilP(input["Count1Star"], Count1Star);
                FromJsonUtilP(input["Count2Star"], Count2Star);
                FromJsonUtilP(input["Count3Star"], Count3Star);
                FromJsonUtilP(input["Count4Star"], Count4Star);
                FromJsonUtilP(input["Count5Star"], Count5Star);
                FromJsonUtilP(input["TotalCount"], TotalCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Average; ToJsonUtilP(Average, each_Average); output["Average"] = each_Average;
                Json::Value each_Count1Star; ToJsonUtilP(Count1Star, each_Count1Star); output["Count1Star"] = each_Count1Star;
                Json::Value each_Count2Star; ToJsonUtilP(Count2Star, each_Count2Star); output["Count2Star"] = each_Count2Star;
                Json::Value each_Count3Star; ToJsonUtilP(Count3Star, each_Count3Star); output["Count3Star"] = each_Count3Star;
                Json::Value each_Count4Star; ToJsonUtilP(Count4Star, each_Count4Star); output["Count4Star"] = each_Count4Star;
                Json::Value each_Count5Star; ToJsonUtilP(Count5Star, each_Count5Star); output["Count5Star"] = each_Count5Star;
                Json::Value each_TotalCount; ToJsonUtilP(TotalCount, each_TotalCount); output["TotalCount"] = each_TotalCount;
                return output;
            }
        };

        struct SubscriptionDetails : public PlayFabBaseModel
        {
            double DurationInSeconds;

            SubscriptionDetails() :
                PlayFabBaseModel(),
                DurationInSeconds()
            {}

            SubscriptionDetails(const SubscriptionDetails& src) :
                PlayFabBaseModel(),
                DurationInSeconds(src.DurationInSeconds)
            {}

            ~SubscriptionDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["DurationInSeconds"], DurationInSeconds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DurationInSeconds; ToJsonUtilP(DurationInSeconds, each_DurationInSeconds); output["DurationInSeconds"] = each_DurationInSeconds;
                return output;
            }
        };

        struct CatalogItemMetadata : public PlayFabBaseModel
        {
            Boxed<bool> AllowMultipleStacks;
            std::list<CatalogAlternateId> AlternateIds;
            std::list<Content> Contents;
            std::string ContentType;
            Boxed<time_t> CreationDate;
            Boxed<EntityKey> CreatorEntityKey;
            std::list<DeepLink> DeepLinks;
            std::map<std::string, std::string> Description;
            Json::Value DisplayProperties;
            std::string DisplayVersion;
            Boxed<time_t> EndDate;
            std::string ETag;
            std::string Id;
            std::list<Image> Images;
            Boxed<bool> IsConsumable;
            Boxed<bool> IsHidden;
            Boxed<bool> IsStackable;
            std::list<CatalogItemReference> ItemReferences;
            Boxed<time_t> LastModifiedDate;
            Boxed<ModerationState> Moderation;
            Boxed<PayoutInfo> pfPayoutInfo;
            std::list<std::string> Platforms;
            Boxed<CatalogPrice> Price;
            Boxed<Rating> pfRating;
            Boxed<EntityKey> SourceEntityKey;
            Boxed<time_t> StartDate;
            Boxed<SubscriptionDetails> Subscription;
            std::list<std::string> Tags;
            std::map<std::string, std::string> Title;
            std::string Type;

            CatalogItemMetadata() :
                PlayFabBaseModel(),
                AllowMultipleStacks(),
                AlternateIds(),
                Contents(),
                ContentType(),
                CreationDate(),
                CreatorEntityKey(),
                DeepLinks(),
                Description(),
                DisplayProperties(),
                DisplayVersion(),
                EndDate(),
                ETag(),
                Id(),
                Images(),
                IsConsumable(),
                IsHidden(),
                IsStackable(),
                ItemReferences(),
                LastModifiedDate(),
                Moderation(),
                pfPayoutInfo(),
                Platforms(),
                Price(),
                pfRating(),
                SourceEntityKey(),
                StartDate(),
                Subscription(),
                Tags(),
                Title(),
                Type()
            {}

            CatalogItemMetadata(const CatalogItemMetadata& src) :
                PlayFabBaseModel(),
                AllowMultipleStacks(src.AllowMultipleStacks),
                AlternateIds(src.AlternateIds),
                Contents(src.Contents),
                ContentType(src.ContentType),
                CreationDate(src.CreationDate),
                CreatorEntityKey(src.CreatorEntityKey),
                DeepLinks(src.DeepLinks),
                Description(src.Description),
                DisplayProperties(src.DisplayProperties),
                DisplayVersion(src.DisplayVersion),
                EndDate(src.EndDate),
                ETag(src.ETag),
                Id(src.Id),
                Images(src.Images),
                IsConsumable(src.IsConsumable),
                IsHidden(src.IsHidden),
                IsStackable(src.IsStackable),
                ItemReferences(src.ItemReferences),
                LastModifiedDate(src.LastModifiedDate),
                Moderation(src.Moderation),
                pfPayoutInfo(src.pfPayoutInfo),
                Platforms(src.Platforms),
                Price(src.Price),
                pfRating(src.pfRating),
                SourceEntityKey(src.SourceEntityKey),
                StartDate(src.StartDate),
                Subscription(src.Subscription),
                Tags(src.Tags),
                Title(src.Title),
                Type(src.Type)
            {}

            ~CatalogItemMetadata() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AllowMultipleStacks"], AllowMultipleStacks);
                FromJsonUtilO(input["AlternateIds"], AlternateIds);
                FromJsonUtilO(input["Contents"], Contents);
                FromJsonUtilS(input["ContentType"], ContentType);
                FromJsonUtilT(input["CreationDate"], CreationDate);
                FromJsonUtilO(input["CreatorEntityKey"], CreatorEntityKey);
                FromJsonUtilO(input["DeepLinks"], DeepLinks);
                FromJsonUtilS(input["Description"], Description);
                DisplayProperties = input["DisplayProperties"];
                FromJsonUtilS(input["DisplayVersion"], DisplayVersion);
                FromJsonUtilT(input["EndDate"], EndDate);
                FromJsonUtilS(input["ETag"], ETag);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Images"], Images);
                FromJsonUtilP(input["IsConsumable"], IsConsumable);
                FromJsonUtilP(input["IsHidden"], IsHidden);
                FromJsonUtilP(input["IsStackable"], IsStackable);
                FromJsonUtilO(input["ItemReferences"], ItemReferences);
                FromJsonUtilT(input["LastModifiedDate"], LastModifiedDate);
                FromJsonUtilO(input["Moderation"], Moderation);
                FromJsonUtilO(input["pfPayoutInfo"], pfPayoutInfo);
                FromJsonUtilS(input["Platforms"], Platforms);
                FromJsonUtilO(input["Price"], Price);
                FromJsonUtilO(input["pfRating"], pfRating);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilT(input["StartDate"], StartDate);
                FromJsonUtilO(input["Subscription"], Subscription);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["Title"], Title);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowMultipleStacks; ToJsonUtilP(AllowMultipleStacks, each_AllowMultipleStacks); output["AllowMultipleStacks"] = each_AllowMultipleStacks;
                Json::Value each_AlternateIds; ToJsonUtilO(AlternateIds, each_AlternateIds); output["AlternateIds"] = each_AlternateIds;
                Json::Value each_Contents; ToJsonUtilO(Contents, each_Contents); output["Contents"] = each_Contents;
                Json::Value each_ContentType; ToJsonUtilS(ContentType, each_ContentType); output["ContentType"] = each_ContentType;
                Json::Value each_CreationDate; ToJsonUtilT(CreationDate, each_CreationDate); output["CreationDate"] = each_CreationDate;
                Json::Value each_CreatorEntityKey; ToJsonUtilO(CreatorEntityKey, each_CreatorEntityKey); output["CreatorEntityKey"] = each_CreatorEntityKey;
                Json::Value each_DeepLinks; ToJsonUtilO(DeepLinks, each_DeepLinks); output["DeepLinks"] = each_DeepLinks;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                output["DisplayProperties"] = DisplayProperties;
                Json::Value each_DisplayVersion; ToJsonUtilS(DisplayVersion, each_DisplayVersion); output["DisplayVersion"] = each_DisplayVersion;
                Json::Value each_EndDate; ToJsonUtilT(EndDate, each_EndDate); output["EndDate"] = each_EndDate;
                Json::Value each_ETag; ToJsonUtilS(ETag, each_ETag); output["ETag"] = each_ETag;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Images; ToJsonUtilO(Images, each_Images); output["Images"] = each_Images;
                Json::Value each_IsConsumable; ToJsonUtilP(IsConsumable, each_IsConsumable); output["IsConsumable"] = each_IsConsumable;
                Json::Value each_IsHidden; ToJsonUtilP(IsHidden, each_IsHidden); output["IsHidden"] = each_IsHidden;
                Json::Value each_IsStackable; ToJsonUtilP(IsStackable, each_IsStackable); output["IsStackable"] = each_IsStackable;
                Json::Value each_ItemReferences; ToJsonUtilO(ItemReferences, each_ItemReferences); output["ItemReferences"] = each_ItemReferences;
                Json::Value each_LastModifiedDate; ToJsonUtilT(LastModifiedDate, each_LastModifiedDate); output["LastModifiedDate"] = each_LastModifiedDate;
                Json::Value each_Moderation; ToJsonUtilO(Moderation, each_Moderation); output["Moderation"] = each_Moderation;
                Json::Value each_pfPayoutInfo; ToJsonUtilO(pfPayoutInfo, each_pfPayoutInfo); output["PayoutInfo"] = each_pfPayoutInfo;
                Json::Value each_Platforms; ToJsonUtilS(Platforms, each_Platforms); output["Platforms"] = each_Platforms;
                Json::Value each_Price; ToJsonUtilO(Price, each_Price); output["Price"] = each_Price;
                Json::Value each_pfRating; ToJsonUtilO(pfRating, each_pfRating); output["Rating"] = each_pfRating;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct CatalogSearchRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string Filter;
            std::string OrderBy;
            std::string Search;
            std::string Select;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            std::string TitleId;
            Int32 Top;

            CatalogSearchRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Filter(),
                OrderBy(),
                Search(),
                Select(),
                Skip(),
                SourceEntityKey(),
                TitleId(),
                Top()
            {}

            CatalogSearchRequest(const CatalogSearchRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Filter(src.Filter),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Select(src.Select),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                TitleId(src.TitleId),
                Top(src.Top)
            {}

            ~CatalogSearchRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilS(input["Select"], Select);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Select; ToJsonUtilS(Select, each_Select); output["Select"] = each_Select;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct CatalogSearchResult : public PlayFabResultCommon
        {
            Boxed<Int32> Count;
            std::list<CatalogItemMetadata> Items;

            CatalogSearchResult() :
                PlayFabResultCommon(),
                Count(),
                Items()
            {}

            CatalogSearchResult(const CatalogSearchResult& src) :
                PlayFabResultCommon(),
                Count(src.Count),
                Items(src.Items)
            {}

            ~CatalogSearchResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct InventoryItemDetails : public PlayFabBaseModel
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string Duration;
            Boxed<time_t> ExpirationDate;
            std::string InstanceId;
            bool IsSubscription;
            std::string ItemId;
            std::string Marketplace;
            Boxed<bool> MergeProperties;
            std::string Origin;
            std::string OriginId;
            std::map<std::string, std::string> Properties;
            Int32 Quantity;

            InventoryItemDetails() :
                PlayFabBaseModel(),
                AlternateId(),
                Duration(),
                ExpirationDate(),
                InstanceId(),
                IsSubscription(),
                ItemId(),
                Marketplace(),
                MergeProperties(),
                Origin(),
                OriginId(),
                Properties(),
                Quantity()
            {}

            InventoryItemDetails(const InventoryItemDetails& src) :
                PlayFabBaseModel(),
                AlternateId(src.AlternateId),
                Duration(src.Duration),
                ExpirationDate(src.ExpirationDate),
                InstanceId(src.InstanceId),
                IsSubscription(src.IsSubscription),
                ItemId(src.ItemId),
                Marketplace(src.Marketplace),
                MergeProperties(src.MergeProperties),
                Origin(src.Origin),
                OriginId(src.OriginId),
                Properties(src.Properties),
                Quantity(src.Quantity)
            {}

            ~InventoryItemDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["Duration"], Duration);
                FromJsonUtilT(input["ExpirationDate"], ExpirationDate);
                FromJsonUtilS(input["InstanceId"], InstanceId);
                FromJsonUtilP(input["IsSubscription"], IsSubscription);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Marketplace"], Marketplace);
                FromJsonUtilP(input["MergeProperties"], MergeProperties);
                FromJsonUtilS(input["Origin"], Origin);
                FromJsonUtilS(input["OriginId"], OriginId);
                FromJsonUtilS(input["Properties"], Properties);
                FromJsonUtilP(input["Quantity"], Quantity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_Duration; ToJsonUtilS(Duration, each_Duration); output["Duration"] = each_Duration;
                Json::Value each_ExpirationDate; ToJsonUtilT(ExpirationDate, each_ExpirationDate); output["ExpirationDate"] = each_ExpirationDate;
                Json::Value each_InstanceId; ToJsonUtilS(InstanceId, each_InstanceId); output["InstanceId"] = each_InstanceId;
                Json::Value each_IsSubscription; ToJsonUtilP(IsSubscription, each_IsSubscription); output["IsSubscription"] = each_IsSubscription;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Marketplace; ToJsonUtilS(Marketplace, each_Marketplace); output["Marketplace"] = each_Marketplace;
                Json::Value each_MergeProperties; ToJsonUtilP(MergeProperties, each_MergeProperties); output["MergeProperties"] = each_MergeProperties;
                Json::Value each_Origin; ToJsonUtilS(Origin, each_Origin); output["Origin"] = each_Origin;
                Json::Value each_OriginId; ToJsonUtilS(OriginId, each_OriginId); output["OriginId"] = each_OriginId;
                Json::Value each_Properties; ToJsonUtilS(Properties, each_Properties); output["Properties"] = each_Properties;
                Json::Value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output["Quantity"] = each_Quantity;
                return output;
            }
        };

        struct ConsumeInventoryItemsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::list<InventoryItemDetails> Items;

            ConsumeInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                Items()
            {}

            ConsumeInventoryItemsRequest(const ConsumeInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~ConsumeInventoryItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct InventoryItemResponseDto : public PlayFabBaseModel
        {
            Int32 Amount;
            Boxed<Int32> ChangedAmount;
            std::string InstanceId;
            std::string ItemId;
            std::map<std::string, std::string> Properties;
            std::string Receipt;

            InventoryItemResponseDto() :
                PlayFabBaseModel(),
                Amount(),
                ChangedAmount(),
                InstanceId(),
                ItemId(),
                Properties(),
                Receipt()
            {}

            InventoryItemResponseDto(const InventoryItemResponseDto& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ChangedAmount(src.ChangedAmount),
                InstanceId(src.InstanceId),
                ItemId(src.ItemId),
                Properties(src.Properties),
                Receipt(src.Receipt)
            {}

            ~InventoryItemResponseDto() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["ChangedAmount"], ChangedAmount);
                FromJsonUtilS(input["InstanceId"], InstanceId);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Properties"], Properties);
                FromJsonUtilS(input["Receipt"], Receipt);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ChangedAmount; ToJsonUtilP(ChangedAmount, each_ChangedAmount); output["ChangedAmount"] = each_ChangedAmount;
                Json::Value each_InstanceId; ToJsonUtilS(InstanceId, each_InstanceId); output["InstanceId"] = each_InstanceId;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Properties; ToJsonUtilS(Properties, each_Properties); output["Properties"] = each_Properties;
                Json::Value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output["Receipt"] = each_Receipt;
                return output;
            }
        };

        struct ConsumeInventoryItemsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<InventoryItemResponseDto> Items;

            ConsumeInventoryItemsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items()
            {}

            ConsumeInventoryItemsResult(const ConsumeInventoryItemsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~ConsumeInventoryItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct CreateBundleRequest : public PlayFabRequestCommon
        {
            bool AllowOverwrite;
            CatalogItemMetadata Bundle;
            std::string IdempotencyId;

            CreateBundleRequest() :
                PlayFabRequestCommon(),
                AllowOverwrite(),
                Bundle(),
                IdempotencyId()
            {}

            CreateBundleRequest(const CreateBundleRequest& src) :
                PlayFabRequestCommon(),
                AllowOverwrite(src.AllowOverwrite),
                Bundle(src.Bundle),
                IdempotencyId(src.IdempotencyId)
            {}

            ~CreateBundleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AllowOverwrite"], AllowOverwrite);
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowOverwrite; ToJsonUtilP(AllowOverwrite, each_AllowOverwrite); output["AllowOverwrite"] = each_AllowOverwrite;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct CreateBundleResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Bundle;
            std::string IdempotencyId;

            CreateBundleResult() :
                PlayFabResultCommon(),
                Bundle(),
                IdempotencyId()
            {}

            CreateBundleResult(const CreateBundleResult& src) :
                PlayFabResultCommon(),
                Bundle(src.Bundle),
                IdempotencyId(src.IdempotencyId)
            {}

            ~CreateBundleResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct CreateCurrencyRequest : public PlayFabRequestCommon
        {
            CatalogItemMetadata Currency;
            Boxed<EntityKey> Entity;

            CreateCurrencyRequest() :
                PlayFabRequestCommon(),
                Currency(),
                Entity()
            {}

            CreateCurrencyRequest(const CreateCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Currency(src.Currency),
                Entity(src.Entity)
            {}

            ~CreateCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currency"], Currency);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilO(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct CreateCurrencyResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> CurrencyMetadata;
            Boxed<EntityKey> Entity;

            CreateCurrencyResult() :
                PlayFabResultCommon(),
                CurrencyMetadata(),
                Entity()
            {}

            CreateCurrencyResult(const CreateCurrencyResult& src) :
                PlayFabResultCommon(),
                CurrencyMetadata(src.CurrencyMetadata),
                Entity(src.Entity)
            {}

            ~CreateCurrencyResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["CurrencyMetadata"], CurrencyMetadata);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyMetadata; ToJsonUtilO(CurrencyMetadata, each_CurrencyMetadata); output["CurrencyMetadata"] = each_CurrencyMetadata;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct CreateDraftItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            CatalogItemMetadata Item;

            CreateDraftItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Item()
            {}

            CreateDraftItemRequest(const CreateDraftItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Item(src.Item)
            {}

            ~CreateDraftItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct CreateDraftItemResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Item;

            CreateDraftItemResult() :
                PlayFabResultCommon(),
                Item()
            {}

            CreateDraftItemResult(const CreateDraftItemResult& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~CreateDraftItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct ReviewSubmission : public PlayFabBaseModel
        {
            bool IsInstalled;
            std::string ItemVersion;
            Int32 Rating;
            std::string ReviewText;
            std::string Title;

            ReviewSubmission() :
                PlayFabBaseModel(),
                IsInstalled(),
                ItemVersion(),
                Rating(),
                ReviewText(),
                Title()
            {}

            ReviewSubmission(const ReviewSubmission& src) :
                PlayFabBaseModel(),
                IsInstalled(src.IsInstalled),
                ItemVersion(src.ItemVersion),
                Rating(src.Rating),
                ReviewText(src.ReviewText),
                Title(src.Title)
            {}

            ~ReviewSubmission() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IsInstalled"], IsInstalled);
                FromJsonUtilS(input["ItemVersion"], ItemVersion);
                FromJsonUtilP(input["Rating"], Rating);
                FromJsonUtilS(input["ReviewText"], ReviewText);
                FromJsonUtilS(input["Title"], Title);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsInstalled; ToJsonUtilP(IsInstalled, each_IsInstalled); output["IsInstalled"] = each_IsInstalled;
                Json::Value each_ItemVersion; ToJsonUtilS(ItemVersion, each_ItemVersion); output["ItemVersion"] = each_ItemVersion;
                Json::Value each_Rating; ToJsonUtilP(Rating, each_Rating); output["Rating"] = each_Rating;
                Json::Value each_ReviewText; ToJsonUtilS(ReviewText, each_ReviewText); output["ReviewText"] = each_ReviewText;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                return output;
            }
        };

        struct CreateOrUpdateReviewRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;
            Boxed<ReviewSubmission> Review;

            CreateOrUpdateReviewRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId(),
                Review()
            {}

            CreateOrUpdateReviewRequest(const CreateOrUpdateReviewRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId),
                Review(src.Review)
            {}

            ~CreateOrUpdateReviewRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilO(input["Review"], Review);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Review; ToJsonUtilO(Review, each_Review); output["Review"] = each_Review;
                return output;
            }
        };

        struct CreateOrUpdateReviewResult : public PlayFabResultCommon
        {

            CreateOrUpdateReviewResult() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateReviewResult(const CreateOrUpdateReviewResult&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateReviewResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateStoreRequest : public PlayFabRequestCommon
        {
            bool AllowOverwrite;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            CatalogItemMetadata Store;

            CreateStoreRequest() :
                PlayFabRequestCommon(),
                AllowOverwrite(),
                Entity(),
                IdempotencyId(),
                Store()
            {}

            CreateStoreRequest(const CreateStoreRequest& src) :
                PlayFabRequestCommon(),
                AllowOverwrite(src.AllowOverwrite),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Store(src.Store)
            {}

            ~CreateStoreRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AllowOverwrite"], AllowOverwrite);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowOverwrite; ToJsonUtilP(AllowOverwrite, each_AllowOverwrite); output["AllowOverwrite"] = each_AllowOverwrite;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct CreateStoreResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            Boxed<CatalogItemMetadata> Store;

            CreateStoreResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Store()
            {}

            CreateStoreResult(const CreateStoreResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Store(src.Store)
            {}

            ~CreateStoreResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct CreateSubscriptionRequest : public PlayFabRequestCommon
        {
            bool AllowOverwrite;
            std::string IdempotencyId;
            CatalogItemMetadata Subscription;

            CreateSubscriptionRequest() :
                PlayFabRequestCommon(),
                AllowOverwrite(),
                IdempotencyId(),
                Subscription()
            {}

            CreateSubscriptionRequest(const CreateSubscriptionRequest& src) :
                PlayFabRequestCommon(),
                AllowOverwrite(src.AllowOverwrite),
                IdempotencyId(src.IdempotencyId),
                Subscription(src.Subscription)
            {}

            ~CreateSubscriptionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AllowOverwrite"], AllowOverwrite);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Subscription"], Subscription);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowOverwrite; ToJsonUtilP(AllowOverwrite, each_AllowOverwrite); output["AllowOverwrite"] = each_AllowOverwrite;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                return output;
            }
        };

        struct CreateSubscriptionResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            Boxed<CatalogItemMetadata> Subscription;

            CreateSubscriptionResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Subscription()
            {}

            CreateSubscriptionResult(const CreateSubscriptionResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Subscription(src.Subscription)
            {}

            ~CreateSubscriptionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Subscription"], Subscription);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                return output;
            }
        };

        struct UploadInfo : public PlayFabBaseModel
        {
            std::string FileName;
            Int32 FileSize;

            UploadInfo() :
                PlayFabBaseModel(),
                FileName(),
                FileSize()
            {}

            UploadInfo(const UploadInfo& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                FileSize(src.FileSize)
            {}

            ~UploadInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilP(input["FileSize"], FileSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_FileSize; ToJsonUtilP(FileSize, each_FileSize); output["FileSize"] = each_FileSize;
                return output;
            }
        };

        struct CreateUploadUrlsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::list<UploadInfo> Files;
            Boxed<EntityKey> SourceEntityKey;

            CreateUploadUrlsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Files(),
                SourceEntityKey()
            {}

            CreateUploadUrlsRequest(const CreateUploadUrlsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Files(src.Files),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~CreateUploadUrlsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Files"], Files);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Files; ToJsonUtilO(Files, each_Files); output["Files"] = each_Files;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct UploadUrlMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string Id;
            std::string Url;

            UploadUrlMetadata() :
                PlayFabBaseModel(),
                FileName(),
                Id(),
                Url()
            {}

            UploadUrlMetadata(const UploadUrlMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                Id(src.Id),
                Url(src.Url)
            {}

            ~UploadUrlMetadata() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct CreateUploadUrlsResult : public PlayFabResultCommon
        {
            std::list<UploadUrlMetadata> UploadUrls;

            CreateUploadUrlsResult() :
                PlayFabResultCommon(),
                UploadUrls()
            {}

            CreateUploadUrlsResult(const CreateUploadUrlsResult& src) :
                PlayFabResultCommon(),
                UploadUrls(src.UploadUrls)
            {}

            ~CreateUploadUrlsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["UploadUrls"], UploadUrls);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_UploadUrls; ToJsonUtilO(UploadUrls, each_UploadUrls); output["UploadUrls"] = each_UploadUrls;
                return output;
            }
        };

        struct DeleteBundleByFriendlyIdRequest : public PlayFabRequestCommon
        {
            std::string FriendlyId;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteBundleByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                FriendlyId(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteBundleByFriendlyIdRequest(const DeleteBundleByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                FriendlyId(src.FriendlyId),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteBundleByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteBundleByIdRequest : public PlayFabRequestCommon
        {
            std::string Id;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteBundleByIdRequest() :
                PlayFabRequestCommon(),
                Id(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteBundleByIdRequest(const DeleteBundleByIdRequest& src) :
                PlayFabRequestCommon(),
                Id(src.Id),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteBundleByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteBundleResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;

            DeleteBundleResult() :
                PlayFabResultCommon(),
                IdempotencyId()
            {}

            DeleteBundleResult(const DeleteBundleResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId)
            {}

            ~DeleteBundleResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct DeleteItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            DeleteItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            DeleteItemRequest(const DeleteItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~DeleteItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct DeleteItemResult : public PlayFabResultCommon
        {

            DeleteItemResult() :
                PlayFabResultCommon()
            {}

            DeleteItemResult(const DeleteItemResult&) :
                PlayFabResultCommon()
            {}

            ~DeleteItemResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteStoreByFriendlyIdRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FriendlyId;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteStoreByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FriendlyId(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteStoreByFriendlyIdRequest(const DeleteStoreByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FriendlyId(src.FriendlyId),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteStoreByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteStoreByIdRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string Id;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteStoreByIdRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Id(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteStoreByIdRequest(const DeleteStoreByIdRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Id(src.Id),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteStoreByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteStoreResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;

            DeleteStoreResult() :
                PlayFabResultCommon(),
                IdempotencyId()
            {}

            DeleteStoreResult(const DeleteStoreResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId)
            {}

            ~DeleteStoreResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct DeleteSubscriptionByFriendlyIdRequest : public PlayFabRequestCommon
        {
            std::string FriendlyId;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteSubscriptionByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                FriendlyId(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteSubscriptionByFriendlyIdRequest(const DeleteSubscriptionByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                FriendlyId(src.FriendlyId),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteSubscriptionByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteSubscriptionByIdRequest : public PlayFabRequestCommon
        {
            std::string Id;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            DeleteSubscriptionByIdRequest() :
                PlayFabRequestCommon(),
                Id(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            DeleteSubscriptionByIdRequest(const DeleteSubscriptionByIdRequest& src) :
                PlayFabRequestCommon(),
                Id(src.Id),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~DeleteSubscriptionByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct DeleteSubscriptionResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;

            DeleteSubscriptionResult() :
                PlayFabResultCommon(),
                IdempotencyId()
            {}

            DeleteSubscriptionResult(const DeleteSubscriptionResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId)
            {}

            ~DeleteSubscriptionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct GetBundleByFriendlyIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string FriendlyId;
            Boxed<EntityKey> SourceEntityKey;

            GetBundleByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                FriendlyId(),
                SourceEntityKey()
            {}

            GetBundleByFriendlyIdRequest(const GetBundleByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                FriendlyId(src.FriendlyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetBundleByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetBundleByIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Id;
            Boxed<EntityKey> SourceEntityKey;

            GetBundleByIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Id(),
                SourceEntityKey()
            {}

            GetBundleByIdRequest(const GetBundleByIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Id(src.Id),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetBundleByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetBundleByMarketplaceOfferIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            Boxed<CatalogAlternateId> MarketplaceOfferId;
            Boxed<EntityKey> SourceEntityKey;

            GetBundleByMarketplaceOfferIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                MarketplaceOfferId(),
                SourceEntityKey()
            {}

            GetBundleByMarketplaceOfferIdRequest(const GetBundleByMarketplaceOfferIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                MarketplaceOfferId(src.MarketplaceOfferId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetBundleByMarketplaceOfferIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilO(input["MarketplaceOfferId"], MarketplaceOfferId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_MarketplaceOfferId; ToJsonUtilO(MarketplaceOfferId, each_MarketplaceOfferId); output["MarketplaceOfferId"] = each_MarketplaceOfferId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetBundleResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Bundle;
            std::string IdempotencyId;
            std::list<CatalogItemMetadata> ReferencedItems;

            GetBundleResult() :
                PlayFabResultCommon(),
                Bundle(),
                IdempotencyId(),
                ReferencedItems()
            {}

            GetBundleResult(const GetBundleResult& src) :
                PlayFabResultCommon(),
                Bundle(src.Bundle),
                IdempotencyId(src.IdempotencyId),
                ReferencedItems(src.ReferencedItems)
            {}

            ~GetBundleResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["ReferencedItems"], ReferencedItems);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReferencedItems; ToJsonUtilO(ReferencedItems, each_ReferencedItems); output["ReferencedItems"] = each_ReferencedItems;
                return output;
            }
        };

        struct GetCatalogConfigRequest : public PlayFabRequestCommon
        {

            GetCatalogConfigRequest() :
                PlayFabRequestCommon()
            {}

            GetCatalogConfigRequest(const GetCatalogConfigRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetCatalogConfigRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetCatalogConfigResult : public PlayFabResultCommon
        {
            Boxed<CatalogConfig> Config;

            GetCatalogConfigResult() :
                PlayFabResultCommon(),
                Config()
            {}

            GetCatalogConfigResult(const GetCatalogConfigResult& src) :
                PlayFabResultCommon(),
                Config(src.Config)
            {}

            ~GetCatalogConfigResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Config"], Config);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Config; ToJsonUtilO(Config, each_Config); output["Config"] = each_Config;
                return output;
            }
        };

        struct GetCurrencyByIdRequest : public PlayFabRequestCommon
        {
            std::string CurrencyId;
            Boxed<EntityKey> Entity;

            GetCurrencyByIdRequest() :
                PlayFabRequestCommon(),
                CurrencyId(),
                Entity()
            {}

            GetCurrencyByIdRequest(const GetCurrencyByIdRequest& src) :
                PlayFabRequestCommon(),
                CurrencyId(src.CurrencyId),
                Entity(src.Entity)
            {}

            ~GetCurrencyByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetCurrencyByIdResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Currency;

            GetCurrencyByIdResult() :
                PlayFabResultCommon(),
                Currency()
            {}

            GetCurrencyByIdResult(const GetCurrencyByIdResult& src) :
                PlayFabResultCommon(),
                Currency(src.Currency)
            {}

            ~GetCurrencyByIdResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currency"], Currency);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilO(Currency, each_Currency); output["Currency"] = each_Currency;
                return output;
            }
        };

        struct GetDraftItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            GetDraftItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            GetDraftItemRequest(const GetDraftItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~GetDraftItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct GetDraftItemResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Item;

            GetDraftItemResult() :
                PlayFabResultCommon(),
                Item()
            {}

            GetDraftItemResult(const GetDraftItemResult& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~GetDraftItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct GetDraftItemsRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            Boxed<EntityKey> Entity;

            GetDraftItemsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                Entity()
            {}

            GetDraftItemsRequest(const GetDraftItemsRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                Entity(src.Entity)
            {}

            ~GetDraftItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetDraftItemsResult : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            std::list<CatalogItemMetadata> Items;

            GetDraftItemsResult() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Count(),
                Items()
            {}

            GetDraftItemsResult(const GetDraftItemsResult& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                Items(src.Items)
            {}

            ~GetDraftItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GetInventoryItemsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::map<std::string, std::string> ReceiptData;
            bool ShouldGenerateReceipt;

            GetInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                ReceiptData(),
                ShouldGenerateReceipt()
            {}

            GetInventoryItemsRequest(const GetInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                ReceiptData(src.ReceiptData),
                ShouldGenerateReceipt(src.ShouldGenerateReceipt)
            {}

            ~GetInventoryItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["ReceiptData"], ReceiptData);
                FromJsonUtilP(input["ShouldGenerateReceipt"], ShouldGenerateReceipt);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output["ReceiptData"] = each_ReceiptData;
                Json::Value each_ShouldGenerateReceipt; ToJsonUtilP(ShouldGenerateReceipt, each_ShouldGenerateReceipt); output["ShouldGenerateReceipt"] = each_ShouldGenerateReceipt;
                return output;
            }
        };

        struct SubscriptionItemResponseDto : public PlayFabBaseModel
        {
            Boxed<time_t> ExpirationDate;
            std::list<std::string> ItemIds;
            std::string Marketplace;
            std::string OfferId;
            std::string Receipt;

            SubscriptionItemResponseDto() :
                PlayFabBaseModel(),
                ExpirationDate(),
                ItemIds(),
                Marketplace(),
                OfferId(),
                Receipt()
            {}

            SubscriptionItemResponseDto(const SubscriptionItemResponseDto& src) :
                PlayFabBaseModel(),
                ExpirationDate(src.ExpirationDate),
                ItemIds(src.ItemIds),
                Marketplace(src.Marketplace),
                OfferId(src.OfferId),
                Receipt(src.Receipt)
            {}

            ~SubscriptionItemResponseDto() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["ExpirationDate"], ExpirationDate);
                FromJsonUtilS(input["ItemIds"], ItemIds);
                FromJsonUtilS(input["Marketplace"], Marketplace);
                FromJsonUtilS(input["OfferId"], OfferId);
                FromJsonUtilS(input["Receipt"], Receipt);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpirationDate; ToJsonUtilT(ExpirationDate, each_ExpirationDate); output["ExpirationDate"] = each_ExpirationDate;
                Json::Value each_ItemIds; ToJsonUtilS(ItemIds, each_ItemIds); output["ItemIds"] = each_ItemIds;
                Json::Value each_Marketplace; ToJsonUtilS(Marketplace, each_Marketplace); output["Marketplace"] = each_Marketplace;
                Json::Value each_OfferId; ToJsonUtilS(OfferId, each_OfferId); output["OfferId"] = each_OfferId;
                Json::Value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output["Receipt"] = each_Receipt;
                return output;
            }
        };

        struct GetInventoryItemsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<InventoryItemResponseDto> Items;
            std::string Receipt;
            std::list<SubscriptionItemResponseDto> Subscriptions;

            GetInventoryItemsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items(),
                Receipt(),
                Subscriptions()
            {}

            GetInventoryItemsResult(const GetInventoryItemsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items),
                Receipt(src.Receipt),
                Subscriptions(src.Subscriptions)
            {}

            ~GetInventoryItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
                FromJsonUtilS(input["Receipt"], Receipt);
                FromJsonUtilO(input["Subscriptions"], Subscriptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                Json::Value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output["Receipt"] = each_Receipt;
                Json::Value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output["Subscriptions"] = each_Subscriptions;
                return output;
            }
        };

        struct GetMyReviewRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            GetMyReviewRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            GetMyReviewRequest(const GetMyReviewRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~GetMyReviewRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct Review : public PlayFabBaseModel
        {
            Int32 HelpfulNegative;
            Int32 HelpfulnessVotes;
            Int32 HelpfulPositive;
            bool IsInstalled;
            std::string ItemId;
            std::string ItemVersion;
            std::string Locale;
            Int32 Rating;
            std::string ReviewerId;
            std::string ReviewId;
            std::string ReviewText;
            time_t Submitted;
            std::string Title;

            Review() :
                PlayFabBaseModel(),
                HelpfulNegative(),
                HelpfulnessVotes(),
                HelpfulPositive(),
                IsInstalled(),
                ItemId(),
                ItemVersion(),
                Locale(),
                Rating(),
                ReviewerId(),
                ReviewId(),
                ReviewText(),
                Submitted(),
                Title()
            {}

            Review(const Review& src) :
                PlayFabBaseModel(),
                HelpfulNegative(src.HelpfulNegative),
                HelpfulnessVotes(src.HelpfulnessVotes),
                HelpfulPositive(src.HelpfulPositive),
                IsInstalled(src.IsInstalled),
                ItemId(src.ItemId),
                ItemVersion(src.ItemVersion),
                Locale(src.Locale),
                Rating(src.Rating),
                ReviewerId(src.ReviewerId),
                ReviewId(src.ReviewId),
                ReviewText(src.ReviewText),
                Submitted(src.Submitted),
                Title(src.Title)
            {}

            ~Review() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["HelpfulNegative"], HelpfulNegative);
                FromJsonUtilP(input["HelpfulnessVotes"], HelpfulnessVotes);
                FromJsonUtilP(input["HelpfulPositive"], HelpfulPositive);
                FromJsonUtilP(input["IsInstalled"], IsInstalled);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemVersion"], ItemVersion);
                FromJsonUtilS(input["Locale"], Locale);
                FromJsonUtilP(input["Rating"], Rating);
                FromJsonUtilS(input["ReviewerId"], ReviewerId);
                FromJsonUtilS(input["ReviewId"], ReviewId);
                FromJsonUtilS(input["ReviewText"], ReviewText);
                FromJsonUtilT(input["Submitted"], Submitted);
                FromJsonUtilS(input["Title"], Title);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_HelpfulNegative; ToJsonUtilP(HelpfulNegative, each_HelpfulNegative); output["HelpfulNegative"] = each_HelpfulNegative;
                Json::Value each_HelpfulnessVotes; ToJsonUtilP(HelpfulnessVotes, each_HelpfulnessVotes); output["HelpfulnessVotes"] = each_HelpfulnessVotes;
                Json::Value each_HelpfulPositive; ToJsonUtilP(HelpfulPositive, each_HelpfulPositive); output["HelpfulPositive"] = each_HelpfulPositive;
                Json::Value each_IsInstalled; ToJsonUtilP(IsInstalled, each_IsInstalled); output["IsInstalled"] = each_IsInstalled;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemVersion; ToJsonUtilS(ItemVersion, each_ItemVersion); output["ItemVersion"] = each_ItemVersion;
                Json::Value each_Locale; ToJsonUtilS(Locale, each_Locale); output["Locale"] = each_Locale;
                Json::Value each_Rating; ToJsonUtilP(Rating, each_Rating); output["Rating"] = each_Rating;
                Json::Value each_ReviewerId; ToJsonUtilS(ReviewerId, each_ReviewerId); output["ReviewerId"] = each_ReviewerId;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                Json::Value each_ReviewText; ToJsonUtilS(ReviewText, each_ReviewText); output["ReviewText"] = each_ReviewText;
                Json::Value each_Submitted; ToJsonUtilT(Submitted, each_Submitted); output["Submitted"] = each_Submitted;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                return output;
            }
        };

        struct GetMyReviewResult : public PlayFabResultCommon
        {
            Boxed<Review> pfReview;

            GetMyReviewResult() :
                PlayFabResultCommon(),
                pfReview()
            {}

            GetMyReviewResult(const GetMyReviewResult& src) :
                PlayFabResultCommon(),
                pfReview(src.pfReview)
            {}

            ~GetMyReviewResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["pfReview"], pfReview);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfReview; ToJsonUtilO(pfReview, each_pfReview); output["Review"] = each_pfReview;
                return output;
            }
        };

        struct GetPublishedItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            GetPublishedItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            GetPublishedItemRequest(const GetPublishedItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~GetPublishedItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct GetPublishedItemResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Item;

            GetPublishedItemResult() :
                PlayFabResultCommon(),
                Item()
            {}

            GetPublishedItemResult(const GetPublishedItemResult& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~GetPublishedItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct GetReviewsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;
            std::string OrderBy;
            Int32 Skip;
            Int32 Top;

            GetReviewsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId(),
                OrderBy(),
                Skip(),
                Top()
            {}

            GetReviewsRequest(const GetReviewsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId),
                OrderBy(src.OrderBy),
                Skip(src.Skip),
                Top(src.Top)
            {}

            ~GetReviewsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct GetReviewsResult : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            Boxed<EntityKey> Entity;
            std::list<Review> Reviews;

            GetReviewsResult() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Count(),
                Entity(),
                Reviews()
            {}

            GetReviewsResult(const GetReviewsResult& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                Entity(src.Entity),
                Reviews(src.Reviews)
            {}

            ~GetReviewsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Reviews"], Reviews);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Reviews; ToJsonUtilO(Reviews, each_Reviews); output["Reviews"] = each_Reviews;
                return output;
            }
        };

        struct GetStoreByFriendlyIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string FriendlyId;
            Boxed<EntityKey> SourceEntityKey;

            GetStoreByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                FriendlyId(),
                SourceEntityKey()
            {}

            GetStoreByFriendlyIdRequest(const GetStoreByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                FriendlyId(src.FriendlyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetStoreByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetStoreByIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Id;
            Boxed<EntityKey> SourceEntityKey;

            GetStoreByIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Id(),
                SourceEntityKey()
            {}

            GetStoreByIdRequest(const GetStoreByIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Id(src.Id),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetStoreByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetStoreResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<CatalogItemMetadata> ReferencedItems;
            Boxed<CatalogItemMetadata> Store;

            GetStoreResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                ReferencedItems(),
                Store()
            {}

            GetStoreResult(const GetStoreResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                ReferencedItems(src.ReferencedItems),
                Store(src.Store)
            {}

            ~GetStoreResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["ReferencedItems"], ReferencedItems);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReferencedItems; ToJsonUtilO(ReferencedItems, each_ReferencedItems); output["ReferencedItems"] = each_ReferencedItems;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct GetSubscriptionByFriendlyIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string FriendlyId;
            Boxed<EntityKey> SourceEntityKey;

            GetSubscriptionByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                FriendlyId(),
                SourceEntityKey()
            {}

            GetSubscriptionByFriendlyIdRequest(const GetSubscriptionByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                FriendlyId(src.FriendlyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetSubscriptionByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetSubscriptionByIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Id;
            Boxed<EntityKey> SourceEntityKey;

            GetSubscriptionByIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Id(),
                SourceEntityKey()
            {}

            GetSubscriptionByIdRequest(const GetSubscriptionByIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Id(src.Id),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetSubscriptionByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetSubscriptionByMarketplaceOfferIdRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            Boxed<CatalogAlternateId> MarketplaceOfferId;
            Boxed<EntityKey> SourceEntityKey;

            GetSubscriptionByMarketplaceOfferIdRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                MarketplaceOfferId(),
                SourceEntityKey()
            {}

            GetSubscriptionByMarketplaceOfferIdRequest(const GetSubscriptionByMarketplaceOfferIdRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                MarketplaceOfferId(src.MarketplaceOfferId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~GetSubscriptionByMarketplaceOfferIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilO(input["MarketplaceOfferId"], MarketplaceOfferId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_MarketplaceOfferId; ToJsonUtilO(MarketplaceOfferId, each_MarketplaceOfferId); output["MarketplaceOfferId"] = each_MarketplaceOfferId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct GetSubscriptionResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<CatalogItemMetadata> ReferencedItems;
            Boxed<CatalogItemMetadata> Subscription;

            GetSubscriptionResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                ReferencedItems(),
                Subscription()
            {}

            GetSubscriptionResult(const GetSubscriptionResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                ReferencedItems(src.ReferencedItems),
                Subscription(src.Subscription)
            {}

            ~GetSubscriptionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["ReferencedItems"], ReferencedItems);
                FromJsonUtilO(input["Subscription"], Subscription);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReferencedItems; ToJsonUtilO(ReferencedItems, each_ReferencedItems); output["ReferencedItems"] = each_ReferencedItems;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                return output;
            }
        };

        struct GetUgcItemModerationStateRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            GetUgcItemModerationStateRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            GetUgcItemModerationStateRequest(const GetUgcItemModerationStateRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~GetUgcItemModerationStateRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct GetUgcItemModerationStateResult : public PlayFabResultCommon
        {
            Boxed<ModerationState> State;

            GetUgcItemModerationStateResult() :
                PlayFabResultCommon(),
                State()
            {}

            GetUgcItemModerationStateResult(const GetUgcItemModerationStateResult& src) :
                PlayFabResultCommon(),
                State(src.State)
            {}

            ~GetUgcItemModerationStateResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["State"], State);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_State; ToJsonUtilO(State, each_State); output["State"] = each_State;
                return output;
            }
        };

        struct GetVirtualCurrenciesRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;

            GetVirtualCurrenciesRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId()
            {}

            GetVirtualCurrenciesRequest(const GetVirtualCurrenciesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId)
            {}

            ~GetVirtualCurrenciesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct GetVirtualCurrenciesResult : public PlayFabResultCommon
        {
            std::list<CurrencyResponseDto> Currencies;
            std::string IdempotencyId;

            GetVirtualCurrenciesResult() :
                PlayFabResultCommon(),
                Currencies(),
                IdempotencyId()
            {}

            GetVirtualCurrenciesResult(const GetVirtualCurrenciesResult& src) :
                PlayFabResultCommon(),
                Currencies(src.Currencies),
                IdempotencyId(src.IdempotencyId)
            {}

            ~GetVirtualCurrenciesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct GrantInventoryItemsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::list<InventoryItemDetails> Items;

            GrantInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                Items()
            {}

            GrantInventoryItemsRequest(const GrantInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~GrantInventoryItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GrantInventoryItemsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<InventoryItemResponseDto> Items;

            GrantInventoryItemsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items()
            {}

            GrantInventoryItemsResult(const GrantInventoryItemsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~GrantInventoryItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct HelpfulnessVoteRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            bool IsHelpful;
            std::string ReviewId;

            HelpfulnessVoteRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IsHelpful(),
                ReviewId()
            {}

            HelpfulnessVoteRequest(const HelpfulnessVoteRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IsHelpful(src.IsHelpful),
                ReviewId(src.ReviewId)
            {}

            ~HelpfulnessVoteRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["IsHelpful"], IsHelpful);
                FromJsonUtilS(input["ReviewId"], ReviewId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IsHelpful; ToJsonUtilP(IsHelpful, each_IsHelpful); output["IsHelpful"] = each_IsHelpful;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                return output;
            }
        };

        struct HelpfulnessVoteResult : public PlayFabResultCommon
        {

            HelpfulnessVoteResult() :
                PlayFabResultCommon()
            {}

            HelpfulnessVoteResult(const HelpfulnessVoteResult&) :
                PlayFabResultCommon()
            {}

            ~HelpfulnessVoteResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PublishItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ETag;
            std::string ItemId;

            PublishItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ETag(),
                ItemId()
            {}

            PublishItemRequest(const PublishItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ETag(src.ETag),
                ItemId(src.ItemId)
            {}

            ~PublishItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ETag"], ETag);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ETag; ToJsonUtilS(ETag, each_ETag); output["ETag"] = each_ETag;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct PublishItemResult : public PlayFabResultCommon
        {

            PublishItemResult() :
                PlayFabResultCommon()
            {}

            PublishItemResult(const PublishItemResult&) :
                PlayFabResultCommon()
            {}

            ~PublishItemResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PublishStatusRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            PublishStatusRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            PublishStatusRequest(const PublishStatusRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~PublishStatusRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct PublishStatusResult : public PlayFabResultCommon
        {
            Boxed<PublishResult> Result;
            std::string StatusMessage;

            PublishStatusResult() :
                PlayFabResultCommon(),
                Result(),
                StatusMessage()
            {}

            PublishStatusResult(const PublishStatusResult& src) :
                PlayFabResultCommon(),
                Result(src.Result),
                StatusMessage(src.StatusMessage)
            {}

            ~PublishStatusResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Result"], Result);
                FromJsonUtilS(input["StatusMessage"], StatusMessage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Result; ToJsonUtilE(Result, each_Result); output["Result"] = each_Result;
                Json::Value each_StatusMessage; ToJsonUtilS(StatusMessage, each_StatusMessage); output["StatusMessage"] = each_StatusMessage;
                return output;
            }
        };

        struct PurchaseItemCurrency : public PlayFabBaseModel
        {
            std::string CurrencyId;
            Int32 ExpectedPrice;

            PurchaseItemCurrency() :
                PlayFabBaseModel(),
                CurrencyId(),
                ExpectedPrice()
            {}

            PurchaseItemCurrency(const PurchaseItemCurrency& src) :
                PlayFabBaseModel(),
                CurrencyId(src.CurrencyId),
                ExpectedPrice(src.ExpectedPrice)
            {}

            ~PurchaseItemCurrency() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
                FromJsonUtilP(input["ExpectedPrice"], ExpectedPrice);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                Json::Value each_ExpectedPrice; ToJsonUtilP(ExpectedPrice, each_ExpectedPrice); output["ExpectedPrice"] = each_ExpectedPrice;
                return output;
            }
        };

        struct PurchaseStoreInfo : public PlayFabBaseModel
        {
            std::string FriendlyId;
            std::string Id;

            PurchaseStoreInfo() :
                PlayFabBaseModel(),
                FriendlyId(),
                Id()
            {}

            PurchaseStoreInfo(const PurchaseStoreInfo& src) :
                PlayFabBaseModel(),
                FriendlyId(src.FriendlyId),
                Id(src.Id)
            {}

            ~PurchaseStoreInfo() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct PurchaseItemByFriendlyIdRequest : public PlayFabRequestCommon
        {
            bool AutoConsume;
            std::list<PurchaseItemCurrency> Currencies;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::string ItemFriendlyId;
            std::map<std::string, std::string> Properties;
            Int32 Quantity;
            bool ReturnInventory;
            Boxed<PurchaseStoreInfo> Store;
            std::string Uaid;

            PurchaseItemByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                AutoConsume(),
                Currencies(),
                Entity(),
                IdempotencyId(),
                ItemFriendlyId(),
                Properties(),
                Quantity(),
                ReturnInventory(),
                Store(),
                Uaid()
            {}

            PurchaseItemByFriendlyIdRequest(const PurchaseItemByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                AutoConsume(src.AutoConsume),
                Currencies(src.Currencies),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                ItemFriendlyId(src.ItemFriendlyId),
                Properties(src.Properties),
                Quantity(src.Quantity),
                ReturnInventory(src.ReturnInventory),
                Store(src.Store),
                Uaid(src.Uaid)
            {}

            ~PurchaseItemByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AutoConsume"], AutoConsume);
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["ItemFriendlyId"], ItemFriendlyId);
                FromJsonUtilS(input["Properties"], Properties);
                FromJsonUtilP(input["Quantity"], Quantity);
                FromJsonUtilP(input["ReturnInventory"], ReturnInventory);
                FromJsonUtilO(input["Store"], Store);
                FromJsonUtilS(input["Uaid"], Uaid);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AutoConsume; ToJsonUtilP(AutoConsume, each_AutoConsume); output["AutoConsume"] = each_AutoConsume;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ItemFriendlyId; ToJsonUtilS(ItemFriendlyId, each_ItemFriendlyId); output["ItemFriendlyId"] = each_ItemFriendlyId;
                Json::Value each_Properties; ToJsonUtilS(Properties, each_Properties); output["Properties"] = each_Properties;
                Json::Value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output["Quantity"] = each_Quantity;
                Json::Value each_ReturnInventory; ToJsonUtilP(ReturnInventory, each_ReturnInventory); output["ReturnInventory"] = each_ReturnInventory;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                Json::Value each_Uaid; ToJsonUtilS(Uaid, each_Uaid); output["Uaid"] = each_Uaid;
                return output;
            }
        };

        struct PurchaseItemByIdRequest : public PlayFabRequestCommon
        {
            bool AutoConsume;
            std::list<PurchaseItemCurrency> Currencies;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::string ItemId;
            std::map<std::string, std::string> Properties;
            Int32 Quantity;
            bool ReturnInventory;
            Boxed<PurchaseStoreInfo> Store;
            std::string Uaid;

            PurchaseItemByIdRequest() :
                PlayFabRequestCommon(),
                AutoConsume(),
                Currencies(),
                Entity(),
                IdempotencyId(),
                ItemId(),
                Properties(),
                Quantity(),
                ReturnInventory(),
                Store(),
                Uaid()
            {}

            PurchaseItemByIdRequest(const PurchaseItemByIdRequest& src) :
                PlayFabRequestCommon(),
                AutoConsume(src.AutoConsume),
                Currencies(src.Currencies),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                ItemId(src.ItemId),
                Properties(src.Properties),
                Quantity(src.Quantity),
                ReturnInventory(src.ReturnInventory),
                Store(src.Store),
                Uaid(src.Uaid)
            {}

            ~PurchaseItemByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AutoConsume"], AutoConsume);
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Properties"], Properties);
                FromJsonUtilP(input["Quantity"], Quantity);
                FromJsonUtilP(input["ReturnInventory"], ReturnInventory);
                FromJsonUtilO(input["Store"], Store);
                FromJsonUtilS(input["Uaid"], Uaid);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AutoConsume; ToJsonUtilP(AutoConsume, each_AutoConsume); output["AutoConsume"] = each_AutoConsume;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Properties; ToJsonUtilS(Properties, each_Properties); output["Properties"] = each_Properties;
                Json::Value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output["Quantity"] = each_Quantity;
                Json::Value each_ReturnInventory; ToJsonUtilP(ReturnInventory, each_ReturnInventory); output["ReturnInventory"] = each_ReturnInventory;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                Json::Value each_Uaid; ToJsonUtilS(Uaid, each_Uaid); output["Uaid"] = each_Uaid;
                return output;
            }
        };

        struct PurchaseItemResultCurrency : public PlayFabBaseModel
        {
            Int32 Amount;
            Int32 ChangedAmount;
            std::string CurrencyId;

            PurchaseItemResultCurrency() :
                PlayFabBaseModel(),
                Amount(),
                ChangedAmount(),
                CurrencyId()
            {}

            PurchaseItemResultCurrency(const PurchaseItemResultCurrency& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ChangedAmount(src.ChangedAmount),
                CurrencyId(src.CurrencyId)
            {}

            ~PurchaseItemResultCurrency() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["ChangedAmount"], ChangedAmount);
                FromJsonUtilS(input["CurrencyId"], CurrencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ChangedAmount; ToJsonUtilP(ChangedAmount, each_ChangedAmount); output["ChangedAmount"] = each_ChangedAmount;
                Json::Value each_CurrencyId; ToJsonUtilS(CurrencyId, each_CurrencyId); output["CurrencyId"] = each_CurrencyId;
                return output;
            }
        };

        struct PurchaseItemResultItem : public PlayFabBaseModel
        {
            Int32 Amount;
            Boxed<Int32> ChangedAmount;
            std::string FriendlyId;
            std::string InstanceId;
            std::string ItemId;
            std::string ItemType;
            std::map<std::string, std::string> Properties;

            PurchaseItemResultItem() :
                PlayFabBaseModel(),
                Amount(),
                ChangedAmount(),
                FriendlyId(),
                InstanceId(),
                ItemId(),
                ItemType(),
                Properties()
            {}

            PurchaseItemResultItem(const PurchaseItemResultItem& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ChangedAmount(src.ChangedAmount),
                FriendlyId(src.FriendlyId),
                InstanceId(src.InstanceId),
                ItemId(src.ItemId),
                ItemType(src.ItemType),
                Properties(src.Properties)
            {}

            ~PurchaseItemResultItem() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["ChangedAmount"], ChangedAmount);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["InstanceId"], InstanceId);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemType"], ItemType);
                FromJsonUtilS(input["Properties"], Properties);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ChangedAmount; ToJsonUtilP(ChangedAmount, each_ChangedAmount); output["ChangedAmount"] = each_ChangedAmount;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_InstanceId; ToJsonUtilS(InstanceId, each_InstanceId); output["InstanceId"] = each_InstanceId;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemType; ToJsonUtilS(ItemType, each_ItemType); output["ItemType"] = each_ItemType;
                Json::Value each_Properties; ToJsonUtilS(Properties, each_Properties); output["Properties"] = each_Properties;
                return output;
            }
        };

        struct PurchaseItemResult : public PlayFabResultCommon
        {
            std::list<PurchaseItemResultCurrency> Currencies;
            std::string IdempotencyId;
            std::list<PurchaseItemResultItem> InventoryItems;
            bool InventoryTooLarge;
            std::list<PurchaseItemResultItem> PurchasedItems;

            PurchaseItemResult() :
                PlayFabResultCommon(),
                Currencies(),
                IdempotencyId(),
                InventoryItems(),
                InventoryTooLarge(),
                PurchasedItems()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabResultCommon(),
                Currencies(src.Currencies),
                IdempotencyId(src.IdempotencyId),
                InventoryItems(src.InventoryItems),
                InventoryTooLarge(src.InventoryTooLarge),
                PurchasedItems(src.PurchasedItems)
            {}

            ~PurchaseItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["InventoryItems"], InventoryItems);
                FromJsonUtilP(input["InventoryTooLarge"], InventoryTooLarge);
                FromJsonUtilO(input["PurchasedItems"], PurchasedItems);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_InventoryItems; ToJsonUtilO(InventoryItems, each_InventoryItems); output["InventoryItems"] = each_InventoryItems;
                Json::Value each_InventoryTooLarge; ToJsonUtilP(InventoryTooLarge, each_InventoryTooLarge); output["InventoryTooLarge"] = each_InventoryTooLarge;
                Json::Value each_PurchasedItems; ToJsonUtilO(PurchasedItems, each_PurchasedItems); output["PurchasedItems"] = each_PurchasedItems;
                return output;
            }
        };

        struct ReportItemRequest : public PlayFabRequestCommon
        {
            Boxed<ConcernCategory> Concern;
            Boxed<EntityKey> Entity;
            std::string ItemId;
            std::string Reason;

            ReportItemRequest() :
                PlayFabRequestCommon(),
                Concern(),
                Entity(),
                ItemId(),
                Reason()
            {}

            ReportItemRequest(const ReportItemRequest& src) :
                PlayFabRequestCommon(),
                Concern(src.Concern),
                Entity(src.Entity),
                ItemId(src.ItemId),
                Reason(src.Reason)
            {}

            ~ReportItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Concern"], Concern);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Concern; ToJsonUtilE(Concern, each_Concern); output["Concern"] = each_Concern;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                return output;
            }
        };

        struct ReportItemResult : public PlayFabResultCommon
        {

            ReportItemResult() :
                PlayFabResultCommon()
            {}

            ReportItemResult(const ReportItemResult&) :
                PlayFabResultCommon()
            {}

            ~ReportItemResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ReportReviewRequest : public PlayFabRequestCommon
        {
            Boxed<ConcernCategory> pfConcernCategory;
            Boxed<EntityKey> Entity;
            std::string ReviewId;

            ReportReviewRequest() :
                PlayFabRequestCommon(),
                pfConcernCategory(),
                Entity(),
                ReviewId()
            {}

            ReportReviewRequest(const ReportReviewRequest& src) :
                PlayFabRequestCommon(),
                pfConcernCategory(src.pfConcernCategory),
                Entity(src.Entity),
                ReviewId(src.ReviewId)
            {}

            ~ReportReviewRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["pfConcernCategory"], pfConcernCategory);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ReviewId"], ReviewId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfConcernCategory; ToJsonUtilE(pfConcernCategory, each_pfConcernCategory); output["ConcernCategory"] = each_pfConcernCategory;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                return output;
            }
        };

        struct ReportReviewResult : public PlayFabResultCommon
        {

            ReportReviewResult() :
                PlayFabResultCommon()
            {}

            ReportReviewResult(const ReportReviewResult&) :
                PlayFabResultCommon()
            {}

            ~ReportReviewResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ReviewSummaryRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;

            ReviewSummaryRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId()
            {}

            ReviewSummaryRequest(const ReviewSummaryRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId)
            {}

            ~ReviewSummaryRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct ReviewSummaryResult : public PlayFabResultCommon
        {
            Boxed<Review> LeastFavorableReview;
            Boxed<Review> MostFavorableReview;
            Boxed<Rating> pfRating;
            Int32 ReviewsCount;

            ReviewSummaryResult() :
                PlayFabResultCommon(),
                LeastFavorableReview(),
                MostFavorableReview(),
                pfRating(),
                ReviewsCount()
            {}

            ReviewSummaryResult(const ReviewSummaryResult& src) :
                PlayFabResultCommon(),
                LeastFavorableReview(src.LeastFavorableReview),
                MostFavorableReview(src.MostFavorableReview),
                pfRating(src.pfRating),
                ReviewsCount(src.ReviewsCount)
            {}

            ~ReviewSummaryResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["LeastFavorableReview"], LeastFavorableReview);
                FromJsonUtilO(input["MostFavorableReview"], MostFavorableReview);
                FromJsonUtilO(input["pfRating"], pfRating);
                FromJsonUtilP(input["ReviewsCount"], ReviewsCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LeastFavorableReview; ToJsonUtilO(LeastFavorableReview, each_LeastFavorableReview); output["LeastFavorableReview"] = each_LeastFavorableReview;
                Json::Value each_MostFavorableReview; ToJsonUtilO(MostFavorableReview, each_MostFavorableReview); output["MostFavorableReview"] = each_MostFavorableReview;
                Json::Value each_pfRating; ToJsonUtilO(pfRating, each_pfRating); output["Rating"] = each_pfRating;
                Json::Value each_ReviewsCount; ToJsonUtilP(ReviewsCount, each_ReviewsCount); output["ReviewsCount"] = each_ReviewsCount;
                return output;
            }
        };

        struct ReviewTakedown : public PlayFabBaseModel
        {
            std::string ItemId;
            std::string ReviewId;

            ReviewTakedown() :
                PlayFabBaseModel(),
                ItemId(),
                ReviewId()
            {}

            ReviewTakedown(const ReviewTakedown& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ReviewId(src.ReviewId)
            {}

            ~ReviewTakedown() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ReviewId"], ReviewId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                return output;
            }
        };

        struct SearchBundlesRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Filter;
            std::string IdempotencyId;
            std::string OrderBy;
            std::string Search;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            Int32 Top;

            SearchBundlesRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Filter(),
                IdempotencyId(),
                OrderBy(),
                Search(),
                Skip(),
                SourceEntityKey(),
                Top()
            {}

            SearchBundlesRequest(const SearchBundlesRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Filter(src.Filter),
                IdempotencyId(src.IdempotencyId),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                Top(src.Top)
            {}

            ~SearchBundlesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct SearchBundlesResult : public PlayFabResultCommon
        {
            std::list<GetBundleResult> Bundles;
            std::string IdempotencyId;

            SearchBundlesResult() :
                PlayFabResultCommon(),
                Bundles(),
                IdempotencyId()
            {}

            SearchBundlesResult(const SearchBundlesResult& src) :
                PlayFabResultCommon(),
                Bundles(src.Bundles),
                IdempotencyId(src.IdempotencyId)
            {}

            ~SearchBundlesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundles"], Bundles);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundles; ToJsonUtilO(Bundles, each_Bundles); output["Bundles"] = each_Bundles;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct SearchForItemsContainingItemByFriendlyIdRequest : public PlayFabRequestCommon
        {
            Boxed<ContainerType> pfContainerType;
            std::list<std::string> FriendlyIds;
            std::string IdempotencyId;
            Boxed<EntityKey> SourceEntityKey;

            SearchForItemsContainingItemByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                pfContainerType(),
                FriendlyIds(),
                IdempotencyId(),
                SourceEntityKey()
            {}

            SearchForItemsContainingItemByFriendlyIdRequest(const SearchForItemsContainingItemByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                pfContainerType(src.pfContainerType),
                FriendlyIds(src.FriendlyIds),
                IdempotencyId(src.IdempotencyId),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~SearchForItemsContainingItemByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["pfContainerType"], pfContainerType);
                FromJsonUtilS(input["FriendlyIds"], FriendlyIds);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfContainerType; ToJsonUtilE(pfContainerType, each_pfContainerType); output["ContainerType"] = each_pfContainerType;
                Json::Value each_FriendlyIds; ToJsonUtilS(FriendlyIds, each_FriendlyIds); output["FriendlyIds"] = each_FriendlyIds;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct SearchForItemsContainingItemByIdRequest : public PlayFabRequestCommon
        {
            Boxed<ContainerType> pfContainerType;
            std::string IdempotencyId;
            std::list<std::string> Ids;
            Boxed<EntityKey> SourceEntityKey;

            SearchForItemsContainingItemByIdRequest() :
                PlayFabRequestCommon(),
                pfContainerType(),
                IdempotencyId(),
                Ids(),
                SourceEntityKey()
            {}

            SearchForItemsContainingItemByIdRequest(const SearchForItemsContainingItemByIdRequest& src) :
                PlayFabRequestCommon(),
                pfContainerType(src.pfContainerType),
                IdempotencyId(src.IdempotencyId),
                Ids(src.Ids),
                SourceEntityKey(src.SourceEntityKey)
            {}

            ~SearchForItemsContainingItemByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["pfContainerType"], pfContainerType);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["Ids"], Ids);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfContainerType; ToJsonUtilE(pfContainerType, each_pfContainerType); output["ContainerType"] = each_pfContainerType;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Ids; ToJsonUtilS(Ids, each_Ids); output["Ids"] = each_Ids;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                return output;
            }
        };

        struct SearchForItemsContainingItemResult : public PlayFabResultCommon
        {
            std::list<CatalogItemMetadata> Bundles;
            std::string IdempotencyId;
            std::list<CatalogItemMetadata> Stores;
            std::list<CatalogItemMetadata> Subscriptions;

            SearchForItemsContainingItemResult() :
                PlayFabResultCommon(),
                Bundles(),
                IdempotencyId(),
                Stores(),
                Subscriptions()
            {}

            SearchForItemsContainingItemResult(const SearchForItemsContainingItemResult& src) :
                PlayFabResultCommon(),
                Bundles(src.Bundles),
                IdempotencyId(src.IdempotencyId),
                Stores(src.Stores),
                Subscriptions(src.Subscriptions)
            {}

            ~SearchForItemsContainingItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundles"], Bundles);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Stores"], Stores);
                FromJsonUtilO(input["Subscriptions"], Subscriptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundles; ToJsonUtilO(Bundles, each_Bundles); output["Bundles"] = each_Bundles;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Stores; ToJsonUtilO(Stores, each_Stores); output["Stores"] = each_Stores;
                Json::Value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output["Subscriptions"] = each_Subscriptions;
                return output;
            }
        };

        struct SearchInStoreByFriendlyIdRequest : public PlayFabRequestCommon
        {
            std::string Filter;
            std::string FriendlyId;
            std::string IdempotencyId;
            std::string OrderBy;
            std::string Search;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            Int32 Top;

            SearchInStoreByFriendlyIdRequest() :
                PlayFabRequestCommon(),
                Filter(),
                FriendlyId(),
                IdempotencyId(),
                OrderBy(),
                Search(),
                Skip(),
                SourceEntityKey(),
                Top()
            {}

            SearchInStoreByFriendlyIdRequest(const SearchInStoreByFriendlyIdRequest& src) :
                PlayFabRequestCommon(),
                Filter(src.Filter),
                FriendlyId(src.FriendlyId),
                IdempotencyId(src.IdempotencyId),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                Top(src.Top)
            {}

            ~SearchInStoreByFriendlyIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["FriendlyId"], FriendlyId);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_FriendlyId; ToJsonUtilS(FriendlyId, each_FriendlyId); output["FriendlyId"] = each_FriendlyId;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct SearchInStoreByIdRequest : public PlayFabRequestCommon
        {
            std::string Filter;
            std::string Id;
            std::string IdempotencyId;
            std::string OrderBy;
            std::string Search;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            Int32 Top;

            SearchInStoreByIdRequest() :
                PlayFabRequestCommon(),
                Filter(),
                Id(),
                IdempotencyId(),
                OrderBy(),
                Search(),
                Skip(),
                SourceEntityKey(),
                Top()
            {}

            SearchInStoreByIdRequest(const SearchInStoreByIdRequest& src) :
                PlayFabRequestCommon(),
                Filter(src.Filter),
                Id(src.Id),
                IdempotencyId(src.IdempotencyId),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                Top(src.Top)
            {}

            ~SearchInStoreByIdRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct SearchInStoreResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<CatalogItemMetadata> Items;

            SearchInStoreResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items()
            {}

            SearchInStoreResult(const SearchInStoreResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~SearchInStoreResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct SearchStoresRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Filter;
            std::string IdempotencyId;
            std::string OrderBy;
            std::string Search;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            Int32 Top;

            SearchStoresRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Filter(),
                IdempotencyId(),
                OrderBy(),
                Search(),
                Skip(),
                SourceEntityKey(),
                Top()
            {}

            SearchStoresRequest(const SearchStoresRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Filter(src.Filter),
                IdempotencyId(src.IdempotencyId),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                Top(src.Top)
            {}

            ~SearchStoresRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct SearchStoresResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<GetStoreResult> Stores;

            SearchStoresResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Stores()
            {}

            SearchStoresResult(const SearchStoresResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Stores(src.Stores)
            {}

            ~SearchStoresResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Stores"], Stores);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Stores; ToJsonUtilO(Stores, each_Stores); output["Stores"] = each_Stores;
                return output;
            }
        };

        struct SearchSubscriptionsRequest : public PlayFabRequestCommon
        {
            bool ExpandReferencedItems;
            std::string Filter;
            std::string IdempotencyId;
            std::string OrderBy;
            std::string Search;
            Int32 Skip;
            Boxed<EntityKey> SourceEntityKey;
            Int32 Top;

            SearchSubscriptionsRequest() :
                PlayFabRequestCommon(),
                ExpandReferencedItems(),
                Filter(),
                IdempotencyId(),
                OrderBy(),
                Search(),
                Skip(),
                SourceEntityKey(),
                Top()
            {}

            SearchSubscriptionsRequest(const SearchSubscriptionsRequest& src) :
                PlayFabRequestCommon(),
                ExpandReferencedItems(src.ExpandReferencedItems),
                Filter(src.Filter),
                IdempotencyId(src.IdempotencyId),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Skip(src.Skip),
                SourceEntityKey(src.SourceEntityKey),
                Top(src.Top)
            {}

            ~SearchSubscriptionsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpandReferencedItems"], ExpandReferencedItems);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilP(input["Skip"], Skip);
                FromJsonUtilO(input["SourceEntityKey"], SourceEntityKey);
                FromJsonUtilP(input["Top"], Top);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpandReferencedItems; ToJsonUtilP(ExpandReferencedItems, each_ExpandReferencedItems); output["ExpandReferencedItems"] = each_ExpandReferencedItems;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Skip; ToJsonUtilP(Skip, each_Skip); output["Skip"] = each_Skip;
                Json::Value each_SourceEntityKey; ToJsonUtilO(SourceEntityKey, each_SourceEntityKey); output["SourceEntityKey"] = each_SourceEntityKey;
                Json::Value each_Top; ToJsonUtilP(Top, each_Top); output["Top"] = each_Top;
                return output;
            }
        };

        struct SearchSubscriptionsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<GetSubscriptionResult> Subscriptions;

            SearchSubscriptionsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Subscriptions()
            {}

            SearchSubscriptionsResult(const SearchSubscriptionsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Subscriptions(src.Subscriptions)
            {}

            ~SearchSubscriptionsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Subscriptions"], Subscriptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output["Subscriptions"] = each_Subscriptions;
                return output;
            }
        };

        struct SetInventoryItemsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::list<InventoryItemDetails> Items;

            SetInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                Items()
            {}

            SetInventoryItemsRequest(const SetInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~SetInventoryItemsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct SetInventoryItemsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<InventoryItemResponseDto> Items;

            SetInventoryItemsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items()
            {}

            SetInventoryItemsResult(const SetInventoryItemsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~SetInventoryItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct SetUgcItemModerationStateRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string ItemId;
            std::string Reason;
            Boxed<ModerationStatus> Status;

            SetUgcItemModerationStateRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ItemId(),
                Reason(),
                Status()
            {}

            SetUgcItemModerationStateRequest(const SetUgcItemModerationStateRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ItemId(src.ItemId),
                Reason(src.Reason),
                Status(src.Status)
            {}

            ~SetUgcItemModerationStateRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Reason"], Reason);
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct SetUgcItemModerationStateResult : public PlayFabResultCommon
        {

            SetUgcItemModerationStateResult() :
                PlayFabResultCommon()
            {}

            SetUgcItemModerationStateResult(const SetUgcItemModerationStateResult&) :
                PlayFabResultCommon()
            {}

            ~SetUgcItemModerationStateResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct SetVirtualCurrenciesRequest : public PlayFabRequestCommon
        {
            std::list<CurrencyDetails> Currencies;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;

            SetVirtualCurrenciesRequest() :
                PlayFabRequestCommon(),
                Currencies(),
                Entity(),
                IdempotencyId()
            {}

            SetVirtualCurrenciesRequest(const SetVirtualCurrenciesRequest& src) :
                PlayFabRequestCommon(),
                Currencies(src.Currencies),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId)
            {}

            ~SetVirtualCurrenciesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct SetVirtualCurrenciesResult : public PlayFabResultCommon
        {
            std::list<CurrencyResponseDto> Currencies;
            std::string IdempotencyId;

            SetVirtualCurrenciesResult() :
                PlayFabResultCommon(),
                Currencies(),
                IdempotencyId()
            {}

            SetVirtualCurrenciesResult(const SetVirtualCurrenciesResult& src) :
                PlayFabResultCommon(),
                Currencies(src.Currencies),
                IdempotencyId(src.IdempotencyId)
            {}

            ~SetVirtualCurrenciesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct SubtractVirtualCurrenciesRequest : public PlayFabRequestCommon
        {
            std::list<CurrencyDetails> Currencies;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;

            SubtractVirtualCurrenciesRequest() :
                PlayFabRequestCommon(),
                Currencies(),
                Entity(),
                IdempotencyId()
            {}

            SubtractVirtualCurrenciesRequest(const SubtractVirtualCurrenciesRequest& src) :
                PlayFabRequestCommon(),
                Currencies(src.Currencies),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId)
            {}

            ~SubtractVirtualCurrenciesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct SubtractVirtualCurrenciesResult : public PlayFabResultCommon
        {
            std::list<CurrencyResponseDto> Currencies;
            std::string IdempotencyId;

            SubtractVirtualCurrenciesResult() :
                PlayFabResultCommon(),
                Currencies(),
                IdempotencyId()
            {}

            SubtractVirtualCurrenciesResult(const SubtractVirtualCurrenciesResult& src) :
                PlayFabResultCommon(),
                Currencies(src.Currencies),
                IdempotencyId(src.IdempotencyId)
            {}

            ~SubtractVirtualCurrenciesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currencies"], Currencies);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currencies; ToJsonUtilO(Currencies, each_Currencies); output["Currencies"] = each_Currencies;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct TakedownReviewsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::list<ReviewTakedown> Reviews;

            TakedownReviewsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Reviews()
            {}

            TakedownReviewsRequest(const TakedownReviewsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Reviews(src.Reviews)
            {}

            ~TakedownReviewsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Reviews"], Reviews);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Reviews; ToJsonUtilO(Reviews, each_Reviews); output["Reviews"] = each_Reviews;
                return output;
            }
        };

        struct TakedownReviewsResult : public PlayFabResultCommon
        {

            TakedownReviewsResult() :
                PlayFabResultCommon()
            {}

            TakedownReviewsResult(const TakedownReviewsResult&) :
                PlayFabResultCommon()
            {}

            ~TakedownReviewsResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct UpdateBundleRequest : public PlayFabRequestCommon
        {
            CatalogItemMetadata Bundle;
            std::string IdempotencyId;

            UpdateBundleRequest() :
                PlayFabRequestCommon(),
                Bundle(),
                IdempotencyId()
            {}

            UpdateBundleRequest(const UpdateBundleRequest& src) :
                PlayFabRequestCommon(),
                Bundle(src.Bundle),
                IdempotencyId(src.IdempotencyId)
            {}

            ~UpdateBundleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct UpdateBundleResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Bundle;
            std::string IdempotencyId;

            UpdateBundleResult() :
                PlayFabResultCommon(),
                Bundle(),
                IdempotencyId()
            {}

            UpdateBundleResult(const UpdateBundleResult& src) :
                PlayFabResultCommon(),
                Bundle(src.Bundle),
                IdempotencyId(src.IdempotencyId)
            {}

            ~UpdateBundleResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Bundle"], Bundle);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output["Bundle"] = each_Bundle;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                return output;
            }
        };

        struct UpdateCatalogConfigRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogConfig> Config;
            Boxed<EntityKey> Entity;

            UpdateCatalogConfigRequest() :
                PlayFabRequestCommon(),
                Config(),
                Entity()
            {}

            UpdateCatalogConfigRequest(const UpdateCatalogConfigRequest& src) :
                PlayFabRequestCommon(),
                Config(src.Config),
                Entity(src.Entity)
            {}

            ~UpdateCatalogConfigRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Config"], Config);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Config; ToJsonUtilO(Config, each_Config); output["Config"] = each_Config;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct UpdateCatalogConfigResult : public PlayFabResultCommon
        {

            UpdateCatalogConfigResult() :
                PlayFabResultCommon()
            {}

            UpdateCatalogConfigResult(const UpdateCatalogConfigResult&) :
                PlayFabResultCommon()
            {}

            ~UpdateCatalogConfigResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct UpdateCurrencyRequest : public PlayFabRequestCommon
        {
            CatalogItemMetadata Currency;
            Boxed<EntityKey> Entity;

            UpdateCurrencyRequest() :
                PlayFabRequestCommon(),
                Currency(),
                Entity()
            {}

            UpdateCurrencyRequest(const UpdateCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Currency(src.Currency),
                Entity(src.Entity)
            {}

            ~UpdateCurrencyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currency"], Currency);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilO(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct UpdateCurrencyResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Currency;
            Boxed<EntityKey> Entity;

            UpdateCurrencyResult() :
                PlayFabResultCommon(),
                Currency(),
                Entity()
            {}

            UpdateCurrencyResult(const UpdateCurrencyResult& src) :
                PlayFabResultCommon(),
                Currency(src.Currency),
                Entity(src.Entity)
            {}

            ~UpdateCurrencyResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Currency"], Currency);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Currency; ToJsonUtilO(Currency, each_Currency); output["Currency"] = each_Currency;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct UpdateDraftItemRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            CatalogItemMetadata Item;

            UpdateDraftItemRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Item()
            {}

            UpdateDraftItemRequest(const UpdateDraftItemRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Item(src.Item)
            {}

            ~UpdateDraftItemRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct UpdateDraftItemResult : public PlayFabResultCommon
        {
            Boxed<CatalogItemMetadata> Item;

            UpdateDraftItemResult() :
                PlayFabResultCommon(),
                Item()
            {}

            UpdateDraftItemResult(const UpdateDraftItemResult& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~UpdateDraftItemResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct UpdateInventoryItemsPropertiesRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::list<InventoryItemDetails> Items;

            UpdateInventoryItemsPropertiesRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                Items()
            {}

            UpdateInventoryItemsPropertiesRequest(const UpdateInventoryItemsPropertiesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items)
            {}

            ~UpdateInventoryItemsPropertiesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct UpdateInventoryPropertiesItemsResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<InventoryItemResponseDto> Items;
            std::list<SubscriptionItemResponseDto> Subscriptions;

            UpdateInventoryPropertiesItemsResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Items(),
                Subscriptions()
            {}

            UpdateInventoryPropertiesItemsResult(const UpdateInventoryPropertiesItemsResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Items(src.Items),
                Subscriptions(src.Subscriptions)
            {}

            ~UpdateInventoryPropertiesItemsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Items"], Items);
                FromJsonUtilO(input["Subscriptions"], Subscriptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                Json::Value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output["Subscriptions"] = each_Subscriptions;
                return output;
            }
        };

        struct UpdateStoreRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            CatalogItemMetadata Store;

            UpdateStoreRequest() :
                PlayFabRequestCommon(),
                Entity(),
                IdempotencyId(),
                Store()
            {}

            UpdateStoreRequest(const UpdateStoreRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Store(src.Store)
            {}

            ~UpdateStoreRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct UpdateStoreResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            Boxed<CatalogItemMetadata> Store;

            UpdateStoreResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Store()
            {}

            UpdateStoreResult(const UpdateStoreResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Store(src.Store)
            {}

            ~UpdateStoreResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct UpdateSubscriptionRequest : public PlayFabRequestCommon
        {
            std::string IdempotencyId;
            CatalogItemMetadata Subscription;

            UpdateSubscriptionRequest() :
                PlayFabRequestCommon(),
                IdempotencyId(),
                Subscription()
            {}

            UpdateSubscriptionRequest(const UpdateSubscriptionRequest& src) :
                PlayFabRequestCommon(),
                IdempotencyId(src.IdempotencyId),
                Subscription(src.Subscription)
            {}

            ~UpdateSubscriptionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Subscription"], Subscription);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                return output;
            }
        };

        struct UpdateSubscriptionResult : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            Boxed<CatalogItemMetadata> Subscription;

            UpdateSubscriptionResult() :
                PlayFabResultCommon(),
                IdempotencyId(),
                Subscription()
            {}

            UpdateSubscriptionResult(const UpdateSubscriptionResult& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                Subscription(src.Subscription)
            {}

            ~UpdateSubscriptionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Subscription"], Subscription);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Subscription; ToJsonUtilO(Subscription, each_Subscription); output["Subscription"] = each_Subscription;
                return output;
            }
        };

    }
}

#endif
