#pragma once

// Handles the Party API network configruation, setup, and routing state changes to other managers.
// This does the heavy lifting of creating chat controls, authorizing them with networks, and
// keeping track of what is in the network, as well as sending messages through the network to
// other endpoints and chat controls.

#include "pch.h"
#include "PlayFabManager.h"
#include "NetworkMessages.h"

namespace PartySample
{

    // Represents the current state of the Network Manager for processing create, join, and leave network attempts.
    enum class NetworkManagerState
    {
        Initialize,
        WaitingForNetwork,
        NetworkConnected,
        WaitingForConnect,
        Leaving
    };

    class NetworkManager : public Manager
    {
    public:
        NetworkManager();
        ~NetworkManager();

        // Initializes party manager with the appropriate titleId for all future calls,
        // Sets up a local user using the currently authenticated playfab entity id and token,
        // And sets up chat controls for when the user is connected to a network.
        void Initialize(const char* titleId);

        //Creates a new network and registers it with the playfab title, storing connection information by keying off the network Id.
        void CreateAndConnectToNetwork(const char *networkId, std::function<void(std::string)> callback = nullptr, std::function<void(PartyError)> errorCallback = nullptr);
        //Connects the current user and chat control to the specified network descriptor using the network Id as an invite Id.
        void ConnectToNetwork(const char *networkId, const char* descriptor, std::function<void(void)> callback = nullptr, std::function<void(PartyError)> errorCallback = nullptr);
        // Sends an endpoint message containing non chat information.
        void SendNetworkMessage(const NetworkMessage& message);
        // Sends a message as a synthesized voice message to all available chat controls.
        void SendTextAsVoice(std::string text);
        // Sends a message as plain text to all available chat controls.
        void SendTextMessage(PartyString text);
        // Disconnects the chat control from the currently connected network.
        void LeaveNetwork(std::function<void(void)> callback = nullptr);
        // Disposes of the local user and chat controls.
        void Shutdown();

        // Main update loop.
        void DoWork();

        // Store the langauge code and profile locally for when the chat control is created.
        void SetLanguageCode(const char* lang, const char* name);
        const char* GetLanguageCode() { return m_languageCode; }
        const char* GetLanguageName() { return m_languageName; }

        // Allows access to currently connected chat controls.
        Party::PartyChatControl* GetChatControl(const std::string& peer);
        Party::PartyLocalChatControl* GetLocalChatControl() { return m_localChatControl; }

        // Mute or unmute the microphone.
        void setAudioInputEnabled(bool enabled);

        // Returns whether the chat control has been connected, to show user join or left messages
        bool getIsChatControlConnected();

        // Returns whether the text to speech profile has been set.
        bool getIsTextToSpeechProfileSet();

        // Current network state.
        inline NetworkManagerState State() { return m_state; }

        // Convert a party error to a human readable message.
        PartyString GetErrorMessage(PartyError error);

        // Set callback to handle local user removed
        // Local user removed means current user dropped from party
        void SetOnLocalUserRemoved(std::function<void(void)> callback);

    private:
        bool InternalConnectToNetwork(const Party::PartyNetworkDescriptor& descriptor, const char *networkId, std::function<void(PartyError)> errorCallback);
        void setTextToSpeechProfile();
        bool isTranslationInTheLocalLanguage(Party::PartyTranslation translation);
        std::string findExpectedTranslation(Party::PartyTranslation *translations, int translationCount);

        std::function<void(std::string)> m_onNetworkCreated;
        std::function<void(PartyError)> m_onNetworkCreatedError;
        std::function<void(PartyError)> m_onNetworkConnectedError;
        std::function<void(void)> m_onNetworkConnected;
        std::function<void(void)> m_onNetworkDestroyed;
        std::function<void(void)> m_onLocalUserRemoved;
        NetworkManagerState m_state;
        std::map<std::string, Party::PartyChatControl*> m_chatControls;
        Party::PartyLocalUser* m_localUser;
        Party::PartyLocalEndpoint* m_localEndpoint;
        Party::PartyLocalChatControl* m_localChatControl;
        Party::PartyNetwork* m_network;
        PartyString m_languageCode;
        PartyString m_languageName;
        bool m_isChatControlConnected;
        bool m_isTextToSpeechProfileSet;
        bool m_partyInitialized;
        bool m_populateProfilesCompleted;
        std::atomic_bool m_ttsProfileNeedsUpdate;
        std::mutex m_networkLock;
    };

}
