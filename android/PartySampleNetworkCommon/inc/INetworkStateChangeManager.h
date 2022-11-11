#pragma once

#include "Manager.h"

// Interface for handling messages resulting from network state changes.

namespace PartySample
{
    class INetworkStateChangeManager : public Manager
    {
    public:
        // Called when a status message should be displayed to the user.
        virtual void ProcessStatusMessage(const std::string& system, const std::string& message) = 0;

        // Called when a player shares their display name with other players in the network.
        virtual void ProcessPlayerJoined(const std::string& playerEntityId, const std::string& displayName) = 0;

        // Called when a chat control has been destroyed
        virtual void ProcessPlayerLeft(const std::string& playerEntityId) = 0;

        // Called when a text chat message is sent to the chat control.
        virtual void ProcessTextMessage(const std::string& sender, const std::string& message) = 0;

        // Called when a voice transcription is sent to the chat control.
        virtual void ProcessVoiceMessage(const std::string& sender, const std::string& message) = 0;

        // Called when a local chat indicator changes
        virtual void ProcessLocalChatIndicatorChange(const std::string& playerEntityId, Party::PartyLocalChatControlChatIndicator chatIndicator) = 0;

        // Called when a remote chat indicator changes
        virtual void ProcessRemoteChatIndicatorChange(const std::string& playerEntityId, Party::PartyChatControlChatIndicator chatIndicator) = 0;
    };
}
