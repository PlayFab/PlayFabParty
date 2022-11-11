#pragma once

// Handles the Party API network configruation, setup, and routing state changes to other managers.
// This does the heavy lifting of creating chat controls, authorizing them with networks, and
// keeping track of what is in the network, as well as sending messages through the network to
// other endpoints and chat controls.

#include "pch.h"
#include "PlayFabManager.h"
#include "NetworkMessages.h"
#include <set>

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

        // Creates a new network and registers it with the playfab title, storing connection information by keying off the network Id.
        void CreateAndConnectToNetwork(const char* networkId, std::function<void(std::string)> callback = nullptr, std::function<void(PartyError)> errorCallback = nullptr);
        // Connects the current user and chat control to the specified network descriptor using the network Id as an invite Id.
        void ConnectToNetwork(const char* networkId, const char* descriptor, std::function<void(void)> callback = nullptr, std::function<void(PartyError)> errorCallback = nullptr);
        // Sends an endpoint message containing non chat information.
        void SendNetworkMessage(uint32_t targetCount, Party::PartyEndpoint** targets, const NetworkMessage& message);
        // Broadcasts an endpoint message containing non chat information.
        void BroadcastNetworkMessage(const NetworkMessage& message);
        // Sends a message as a synthesized voice message to all available chat controls.
        void SendTextAsVoice(std::string text);
        // Sends a message as plain text to all available chat controls.
        void SendTextMessage(PartyString text);
        // Disconnects the chat control from the currently connected network.
        void LeaveNetwork(std::function<void(void)> callback = nullptr);
        // Disposes of the local user and chat controls.
        void Shutdown();
        // Sets the volume
        void SetPlayerVolume(float volumeZeroToOne);

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
        void SetLocalPlayerMuted(bool isMuted);
        // Mute or unmute a remote player
        void SetRemotePlayerMuted(const std::string& remotePlayerEntityId, bool isMuted);

        // Returns whether the chat control has been connected, to show user join or left messages
        bool getIsChatControlConnected();

        // Returns whether the text to speech profile has been set.
        bool getIsTextToSpeechProfileSet();

        // Current network state.
        inline NetworkManagerState State() { return m_state; }

        // Convert a party error to a human readable message.
        PartyString GetErrorMessage(PartyError error);

        // Set callback to handle if the network gets destroyed for any reason
        // The callback takes a bool param for if we expected the destruction
        // such as if the user initiated leaving the network.
        // In the event of an unanticipated disconnect, we apply reconnect logic
        // at the app layer.
        void SetOnNetworkDestroyed(std::function<void(bool)> callback);

        // Check if network is currently trying to connect.
        bool IsConnecting() const;

        // If Audio IO devices have been configured on ChatControls but disconnected
        // this method will restore them.
        void ConnectAudioInput();

        // If Audio IO devices have been disconnected have been configured on ChatControls
        // this method will disconnect them and cache information so they can be reconnected
        // later if desired.
        void DisconnectAudioInput();

    private:
        PartyError CreateChatControlIfNecessary();
        bool InternalConnectToNetwork(const Party::PartyNetworkDescriptor& descriptor, const char* networkId, std::function<void(PartyError)> errorCallback);
        void setTextToSpeechProfile();
        bool isTranslationInTheLocalLanguage(Party::PartyTranslation translation);
        std::string findExpectedTranslation(Party::PartyTranslation* translations, int translationCount);
        void ProcessChatIndicatorUpdates();

        void HandlePlayerJoined(
            const std::string& newPlayerEntityId,
            const std::string& newPlayerDisplayName
            );

        void HandleIncomingTextMessage(
            const std::string& senderPlayerEntityId,
            const std::string& message
            );

        void HandleIncomingVoiceTranscription(
            const std::string& senderPlayerEntityId,
            const std::string& transcription
            );

        void HandleLocalChatIndicatorUpdate(
            const std::string& localPlayerEntityId,
            Party::PartyLocalChatControlChatIndicator chatIndicator
            );

        void HandleRemoteChatIndicatorUpdate(
            const std::string& remotePlayerEntityId,
            Party::PartyChatControlChatIndicator chatIndicator
            );

        void HandlePlayerLeft(
            const std::string& playerEntityId
            );

        std::function<void(std::string)> m_onNetworkCreated;
        std::function<void(PartyError)> m_onNetworkCreatedError;
        std::function<void(PartyError)> m_onNetworkConnectedError;
        std::function<void(void)> m_onNetworkConnected;
        std::function<void(void)> m_onNetworkLeft;
        std::function<void(bool)> m_onNetworkDestroyed;
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
        float m_renderVolume;

        // These players have (1) Joined the network and (2) sent their display name to other players
        std::set<std::string> m_remotePlayers;

        // PlayFab Party is responsive enough that a UI which can handle frequent updates can poll for the chat
        // indicators every frame. Since this code is shared across a number of UI frameworks, we'll cache the chat
        // indicators and only alert the UI when they've changed.
        std::map<Party::PartyLocalChatControl*, Party::PartyLocalChatControlChatIndicator> m_localChatControlIndicatorCache;
        std::map<Party::PartyChatControl*, Party::PartyChatControlChatIndicator> m_remoteChatControlIndicatorCache;
    };
}
