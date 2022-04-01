#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace AuthenticationModels
    {
        // Authentication Enums
        enum class LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello,
            LoginIdentityProviderGameServer,
            LoginIdentityProviderCustomServer,
            LoginIdentityProviderNintendoSwitch,
            LoginIdentityProviderFacebookInstantGames,
            LoginIdentityProviderOpenIdConnect
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, Json::Value& output)
        {
            if (input == LoginIdentityProvider::LoginIdentityProviderUnknown) output = Json::Value("Unknown");
            if (input == LoginIdentityProvider::LoginIdentityProviderPlayFab) output = Json::Value("PlayFab");
            if (input == LoginIdentityProvider::LoginIdentityProviderCustom) output = Json::Value("Custom");
            if (input == LoginIdentityProvider::LoginIdentityProviderGameCenter) output = Json::Value("GameCenter");
            if (input == LoginIdentityProvider::LoginIdentityProviderGooglePlay) output = Json::Value("GooglePlay");
            if (input == LoginIdentityProvider::LoginIdentityProviderSteam) output = Json::Value("Steam");
            if (input == LoginIdentityProvider::LoginIdentityProviderXBoxLive) output = Json::Value("XBoxLive");
            if (input == LoginIdentityProvider::LoginIdentityProviderPSN) output = Json::Value("PSN");
            if (input == LoginIdentityProvider::LoginIdentityProviderKongregate) output = Json::Value("Kongregate");
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebook) output = Json::Value("Facebook");
            if (input == LoginIdentityProvider::LoginIdentityProviderIOSDevice) output = Json::Value("IOSDevice");
            if (input == LoginIdentityProvider::LoginIdentityProviderAndroidDevice) output = Json::Value("AndroidDevice");
            if (input == LoginIdentityProvider::LoginIdentityProviderTwitch) output = Json::Value("Twitch");
            if (input == LoginIdentityProvider::LoginIdentityProviderWindowsHello) output = Json::Value("WindowsHello");
            if (input == LoginIdentityProvider::LoginIdentityProviderGameServer) output = Json::Value("GameServer");
            if (input == LoginIdentityProvider::LoginIdentityProviderCustomServer) output = Json::Value("CustomServer");
            if (input == LoginIdentityProvider::LoginIdentityProviderNintendoSwitch) output = Json::Value("NintendoSwitch");
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames) output = Json::Value("FacebookInstantGames");
            if (input == LoginIdentityProvider::LoginIdentityProviderOpenIdConnect) output = Json::Value("OpenIdConnect");
        }
        inline void FromJsonEnum(const Json::Value& input, LoginIdentityProvider& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = LoginIdentityProvider::LoginIdentityProviderUnknown;
            if (inputStr == "PlayFab") output = LoginIdentityProvider::LoginIdentityProviderPlayFab;
            if (inputStr == "Custom") output = LoginIdentityProvider::LoginIdentityProviderCustom;
            if (inputStr == "GameCenter") output = LoginIdentityProvider::LoginIdentityProviderGameCenter;
            if (inputStr == "GooglePlay") output = LoginIdentityProvider::LoginIdentityProviderGooglePlay;
            if (inputStr == "Steam") output = LoginIdentityProvider::LoginIdentityProviderSteam;
            if (inputStr == "XBoxLive") output = LoginIdentityProvider::LoginIdentityProviderXBoxLive;
            if (inputStr == "PSN") output = LoginIdentityProvider::LoginIdentityProviderPSN;
            if (inputStr == "Kongregate") output = LoginIdentityProvider::LoginIdentityProviderKongregate;
            if (inputStr == "Facebook") output = LoginIdentityProvider::LoginIdentityProviderFacebook;
            if (inputStr == "IOSDevice") output = LoginIdentityProvider::LoginIdentityProviderIOSDevice;
            if (inputStr == "AndroidDevice") output = LoginIdentityProvider::LoginIdentityProviderAndroidDevice;
            if (inputStr == "Twitch") output = LoginIdentityProvider::LoginIdentityProviderTwitch;
            if (inputStr == "WindowsHello") output = LoginIdentityProvider::LoginIdentityProviderWindowsHello;
            if (inputStr == "GameServer") output = LoginIdentityProvider::LoginIdentityProviderGameServer;
            if (inputStr == "CustomServer") output = LoginIdentityProvider::LoginIdentityProviderCustomServer;
            if (inputStr == "NintendoSwitch") output = LoginIdentityProvider::LoginIdentityProviderNintendoSwitch;
            if (inputStr == "FacebookInstantGames") output = LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames;
            if (inputStr == "OpenIdConnect") output = LoginIdentityProvider::LoginIdentityProviderOpenIdConnect;
        }

        // Authentication Classes
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

        struct ActivateAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            ActivateAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            ActivateAPIKeyRequest(const ActivateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~ActivateAPIKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct ActivateAPIKeyResponse : public PlayFabResultCommon
        {

            ActivateAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            ActivateAPIKeyResponse(const ActivateAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~ActivateAPIKeyResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            std::string APIKeySecret;
            time_t Created;

            CreateAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(),
                APIKeyId(),
                APIKeySecret(),
                Created()
            {}

            CreateAPIKeyDetails(const CreateAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                APIKeySecret(src.APIKeySecret),
                Created(src.Created)
            {}

            ~CreateAPIKeyDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilS(input["APIKeySecret"], APIKeySecret);
                FromJsonUtilT(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_APIKeySecret; ToJsonUtilS(APIKeySecret, each_APIKeySecret); output["APIKeySecret"] = each_APIKeySecret;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct CreateAPIKeyRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            CreateAPIKeyRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            CreateAPIKeyRequest(const CreateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~CreateAPIKeyRequest() = default;

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

        struct CreateAPIKeyResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<CreateAPIKeyDetails> Key;

            CreateAPIKeyResponse() :
                PlayFabResultCommon(),
                Entity(),
                Key()
            {}

            CreateAPIKeyResponse(const CreateAPIKeyResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Key(src.Key)
            {}

            ~CreateAPIKeyResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Key"], Key);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Key; ToJsonUtilO(Key, each_Key); output["Key"] = each_Key;
                return output;
            }
        };

        struct DeactivateAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            DeactivateAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            DeactivateAPIKeyRequest(const DeactivateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~DeactivateAPIKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeactivateAPIKeyResponse : public PlayFabResultCommon
        {

            DeactivateAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            DeactivateAPIKeyResponse(const DeactivateAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~DeactivateAPIKeyResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            DeleteAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            DeleteAPIKeyRequest(const DeleteAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~DeleteAPIKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteAPIKeyResponse : public PlayFabResultCommon
        {

            DeleteAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            DeleteAPIKeyResponse(const DeleteAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteAPIKeyResponse() = default;

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

        struct GetAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            time_t Created;

            GetAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(),
                APIKeyId(),
                Created()
            {}

            GetAPIKeyDetails(const GetAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                Created(src.Created)
            {}

            ~GetAPIKeyDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilT(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct GetAPIKeysRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            GetAPIKeysRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetAPIKeysRequest(const GetAPIKeysRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetAPIKeysRequest() = default;

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

        struct GetAPIKeysResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::list<GetAPIKeyDetails> Keys;

            GetAPIKeysResponse() :
                PlayFabResultCommon(),
                Entity(),
                Keys()
            {}

            GetAPIKeysResponse(const GetAPIKeysResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Keys(src.Keys)
            {}

            ~GetAPIKeysResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Keys"], Keys);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Keys; ToJsonUtilO(Keys, each_Keys); output["Keys"] = each_Keys;
                return output;
            }
        };

        struct GetEntityTokenRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            GetEntityTokenRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetEntityTokenRequest() = default;

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

        struct GetEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            GetEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            GetEntityTokenResponse(const GetEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~GetEntityTokenResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityToken"], EntityToken);
                FromJsonUtilT(input["TokenExpiration"], TokenExpiration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output["TokenExpiration"] = each_TokenExpiration;
                return output;
            }
        };

        struct ValidateEntityTokenRequest : public PlayFabRequestCommon
        {
            std::string EntityToken;

            ValidateEntityTokenRequest() :
                PlayFabRequestCommon(),
                EntityToken()
            {}

            ValidateEntityTokenRequest(const ValidateEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                EntityToken(src.EntityToken)
            {}

            ~ValidateEntityTokenRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["EntityToken"], EntityToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                return output;
            }
        };

        struct ValidateEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<LoginIdentityProvider> IdentityProvider;
            Boxed<EntityLineage> Lineage;

            ValidateEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                IdentityProvider(),
                Lineage()
            {}

            ValidateEntityTokenResponse(const ValidateEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                IdentityProvider(src.IdentityProvider),
                Lineage(src.Lineage)
            {}

            ~ValidateEntityTokenResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilE(input["IdentityProvider"], IdentityProvider);
                FromJsonUtilO(input["Lineage"], Lineage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdentityProvider; ToJsonUtilE(IdentityProvider, each_IdentityProvider); output["IdentityProvider"] = each_IdentityProvider;
                Json::Value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output["Lineage"] = each_Lineage;
                return output;
            }
        };

    }
}

#endif
