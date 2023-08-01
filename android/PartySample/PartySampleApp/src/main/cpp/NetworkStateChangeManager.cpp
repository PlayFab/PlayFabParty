#include "PartyDemo.h"

NetworkStateChangeManager::NetworkStateChangeManager()
{
}

void
NetworkStateChangeManager::ProcessStatusMessage(
    const std::string& system,
    const std::string& message
    )
{
    // Route status messages as fake endpoint messages so they show up in the chat window.
    OnEndpointMessageReceived(system.c_str(), message.c_str());
}

void
NetworkStateChangeManager::ProcessPlayerJoined(
    const std::string& playerEntityId,
    const std::string& displayName
    )
{

    m_userMap.emplace(playerEntityId, displayName);
    OnChatControlCreated(GetUserName(playerEntityId).c_str());
}

void
NetworkStateChangeManager::ProcessPlayerLeft(
    const std::string& playerEntityId
    )
{
    OnChatControlDestroyed(GetUserName(playerEntityId));
    m_userMap.erase(playerEntityId);
}

// Called when a text chat message is sent to the chat control.
void
NetworkStateChangeManager::ProcessTextMessage(
    const std::string& sender,
    const std::string& message
    )
{
    OnEndpointMessageReceived(GetUserName(sender).c_str(), message.c_str());
}

// Called when a voice transcription is sent to the chat control.
void
NetworkStateChangeManager::ProcessVoiceMessage(
    const std::string& sender,
    const std::string& message
    )
{
    OnVoiceChatTranscriptionReceived(GetUserName(sender).c_str(), message.c_str());
}

// Called when a local chat indicator changes
void
NetworkStateChangeManager::ProcessLocalChatIndicatorChange(
    const std::string&,
    Party::PartyLocalChatControlChatIndicator
    )
{
    // noop. Android doesn't currently use this for exposing chat indicator changes.
}

// Called when a remote chat indicator changes
void
NetworkStateChangeManager::ProcessRemoteChatIndicatorChange(
    const std::string&,
    Party::PartyChatControlChatIndicator
    )
{
    // noop. Android doesn't currently use this for exposing chat indicator changes.
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