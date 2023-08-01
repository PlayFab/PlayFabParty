#pragma once

// Handles authorizing with playfab and accessing playfab storage for distribution of the network descriptor.
// Authorization happens through SignIn.
// Storage access happens through the set and get descriptor calls.
// Internally, cloud scripts are used to store the descriptor with the playfab title.

#include "Manager.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabAuthenticationDataModels.h"
#include "playfab/PlayFabEventsDataModels.h"
#include "playfab/PlayFabMultiplayerDataModels.h"
#include "playfab/PlayFabDataApi.h"

namespace PartySample
{

    class PlayFabManager : public Manager
    {
    public:
        PlayFabManager();
        ~PlayFabManager();

        // Initialize the playfab manager, setting the title id for future calls.
        void Initialize(const char* titleId);

        // Main function to get authorized with playfab before using the Party APIs.
        void SignIn(std::function<void(bool, std::string&)> callback, std::string userId);

        //Main update loop
        void Tick();

        std::string& EntityId() { return m_entityKey.Id; }
        std::string& EntityToken() { return m_entityToken; }
        std::string& displayName() { return m_displayName; }
        void setEntityId(std::string name) { m_entityKey.Id = name; }

        //Main functions for setting and getting the descriptor from a cloud script storage.
        void SetDescriptor(std::string key, std::string descriptor, std::function<void()> onComplete);
        void GetDescriptor(std::string key, std::function<void(std::string)> onComplete);

        //Callbacks used in the get and set cloud script flow.
        void onGetDescriptorFail(const PlayFab::PlayFabError&, void* customData);
        void onGetDescriptorSuccess(PlayFab::ClientModels::ExecuteCloudScriptResult& response, void* customData);
        void onSetDescriptorFailed(const PlayFab::PlayFabError&, void* customData);
        void onSetDescriptorSuccess(PlayFab::ClientModels::ExecuteCloudScriptResult& response, void* customData);

    private:
        PlayFab::ClientModels::LoginResult  m_loginResult;
        PlayFab::ClientModels::EntityKey  m_entityKey;
        std::string m_entityToken;
        std::string m_playfabId;
        std::string m_displayName;

        std::function<void()> m_onCompletedSettingDescriptor;
        std::function<void(std::string)> m_onCompletedGettingDescriptor;
    };

}
