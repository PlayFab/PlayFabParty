class NetworkStateChangeManager : public PartySample::INetworkStateChangeManager
{
public:

    NetworkStateChangeManager();

    // Called when a status message should be displayed to the user.
    void
    ProcessStatusMessage(
        const std::string& system,
        const std::string& message
        ) override;

    // Called when a player shares their display name with other players in the network.
    void
    ProcessPlayerJoined(
        const std::string& playerEntityId,
        const std::string& displayName
        ) override;

    // Called when a chat control has been destroyed
    void ProcessPlayerLeft(
        const std::string& playerEntityId
        ) override;

    // Called when a text chat message is sent to the chat control.
    void ProcessTextMessage(
        const std::string& sender,
        const std::string& message
        ) override;

    // Called when a voice transcription is sent to the chat control.
    void ProcessVoiceMessage(
        const std::string& sender,
        const std::string& message
        ) override;

    // Called when a local chat indicator changes
    void
    ProcessLocalChatIndicatorChange(
        const std::string& playerEntityId,
        Party::PartyLocalChatControlChatIndicator chatIndicator
        ) override;

    // Called when a remote chat indicator changes
    void
    ProcessRemoteChatIndicatorChange(
        const std::string& playerEntityId,
        Party::PartyChatControlChatIndicator chatIndicator
        ) override;

    std::map<const std::string, const std::string>*
    GetUserMap();

private:

    std::map<const std::string, const std::string> m_userMap;

    const std::string GetUserName(
        const std::string& sender
        );
};