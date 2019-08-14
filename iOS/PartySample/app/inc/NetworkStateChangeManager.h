class NetworkStateChangeManager : public INetworkStateChangeManager
{
public:

    NetworkStateChangeManager();
    
    void
    SetNetworkMessageHandler(
        INetworkMessageHandler* handler
        );

    // Called when a chat control has been destroyed
    void
    onPlayerLeft(
        PartyString playerId
        );

    // Called when an endpoint message is received from another chat control.
    // Used to send the user display name to other chat controls. Replaces the onPlayerJoin functionality.
    void
    ProcessEndpointMessage(
        std::string& sender, 
        std::string& message
        );

    // Called when a text chat message is sent to the chat control.
    void
    ProcessTextMessage(
        std::string& sender, 
        std::string &message
        );

    // Called when a voice transcription is sent to the chat control.
    void
    ProcessVoiceMessage(
        std::string& sender, 
        std::string &message
        );

    std::map<const std::string, const std::string>*
    GetUserMap();
    
private:

    const std::string
    GetUserName(
        const std::string& sender
        );
    
    INetworkMessageHandler* m_handler;
    std::map<const std::string, const std::string> m_userMap;

};
