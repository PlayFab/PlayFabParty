#pragma once

#include "Manager.h"

// Interface for handling messages resulting from network state changes.

namespace PartySample
{
    
    class INetworkStateChangeManager : public Manager
    {
    public:
        // Called when a chat control has been destroyed
        virtual void onPlayerLeft(PartyString playerId) = 0;
        
        // Called when an endpoint message is received from another chat control.
        // Used to send the user display name to other chat controls. Replaces the onPlayerJoin functionality.
        virtual void ProcessEndpointMessage(std::string& sender, std::string& message) = 0;
        
        // Called when a text chat message is sent to the chat control.
        virtual void ProcessTextMessage(std::string& sender, std::string &message) = 0;
        
        // Called when a voice transcription is sent to the chat control.
        virtual void ProcessVoiceMessage(std::string& sender, std::string &message) = 0;
    };
    
}

