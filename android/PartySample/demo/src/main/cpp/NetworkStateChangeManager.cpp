#include "PartyDemo.h"

NetworkStateChangeManager::NetworkStateChangeManager()
{
}

void
NetworkStateChangeManager::onPlayerLeft(
    PartyString playerId
    )
{
    OnChatControlDestroyed(GetUserName(playerId));
    m_userMap.erase(playerId);
}

void
NetworkStateChangeManager::ProcessEndpointMessage(
    std::string& sender,
    std::string& message
    )
{

    //OnEndpointMessageReceived(GetUserName(sender).c_str(), message.c_str());
    m_userMap.emplace(sender, message);
    OnChatControlCreated(GetUserName(sender).c_str());
}

// Called when a text chat message is sent to the chat control.
void
NetworkStateChangeManager::ProcessTextMessage(
    std::string& sender,
    std::string& message
    )
{
    OnEndpointMessageReceived(GetUserName(sender).c_str(), message.c_str());
}

// Called when a voice transcription is sent to the chat control.
void
NetworkStateChangeManager::ProcessVoiceMessage(
    std::string& sender,
    std::string& message
    )
{
    OnVoiceChatTranscriptionReceived(GetUserName(sender).c_str(), message.c_str());
}

const
std::string
NetworkStateChangeManager::GetUserName(
    const std::string& sender
    )
{
    auto search = m_userMap.find(sender);
    if (search != m_userMap.end())
    {
        return search->second;
    }
    else
    {
        return sender;
    }
}

std::map<const std::string, const std::string>*
NetworkStateChangeManager::GetUserMap()
{
    return &m_userMap;
}