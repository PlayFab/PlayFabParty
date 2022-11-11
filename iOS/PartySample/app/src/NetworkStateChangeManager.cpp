#include "pch.h"
#include "NetworkStateChangeManager.h"

NetworkStateChangeManager::NetworkStateChangeManager()
{
}

void
NetworkStateChangeManager::SetNetworkMessageHandler(
    INetworkMessageHandler *handler
    )
{
    m_handler = handler;
}

void
NetworkStateChangeManager::ProcessStatusMessage(
    const std::string& system,
    const std::string& message
    )
{
    // Route status messages as fake text messages so they show up in the chat window.
    assert(m_handler != nullptr);
    m_handler->OnTextMessageReceived(system, message, false);
}

void
NetworkStateChangeManager::ProcessPlayerJoined(
    const std::string& playerEntityId,
    const std::string& displayName
    )
{
    m_userMap.emplace(playerEntityId, displayName);
    assert(m_handler != nullptr);
    m_handler->OnPlayerJoin(displayName);
}

void
NetworkStateChangeManager::ProcessPlayerLeft(
    const std::string& playerEntityId
    )
{
    std::string userName = GetUserName(playerEntityId);
    assert(m_handler != nullptr);
    m_handler->OnPlayerLeft(userName);
    m_userMap.erase(playerEntityId);
}

// Called when a text chat message is sent to the chat control.
void
NetworkStateChangeManager::ProcessTextMessage(
    const std::string& sender,
    const std::string& message
    )
{
    assert(m_handler != nullptr);
    std::string userName = GetUserName(sender);
    m_handler->OnTextMessageReceived(userName, message, false);
}

// Called when a voice transcription is sent to the chat control.
void
NetworkStateChangeManager::ProcessVoiceMessage(
    const std::string& sender,
    const std::string& message
    )
{
    assert(m_handler != nullptr);
    std::string userName = GetUserName(sender);
    m_handler->OnTextMessageReceived(userName, message, true);
}

// Called when a local chat indicator changes
void
NetworkStateChangeManager::ProcessLocalChatIndicatorChange(
    const std::string&,
    Party::PartyLocalChatControlChatIndicator
    )
{
    // noop. iOS doesn't currently use this for exposing chat indicator changes.
}

// Called when a remote chat indicator changes
void
NetworkStateChangeManager::ProcessRemoteChatIndicatorChange(
    const std::string&,
    Party::PartyChatControlChatIndicator
    )
{
    // noop. iOS doesn't currently use this for exposing chat indicator changes.
}

std::map<const std::string, const std::string>*
NetworkStateChangeManager::GetUserMap()
{
    return &m_userMap;
}

const std::string
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
