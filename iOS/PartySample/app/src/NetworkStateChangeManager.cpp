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
NetworkStateChangeManager::onPlayerLeft(
    PartyString playerId
    )
{
    std::string userName = GetUserName(playerId);
    assert(m_handler != nullptr);
    m_handler->OnPlayerLeft(userName);
    m_userMap.erase(playerId);
}

void
NetworkStateChangeManager::ProcessEndpointMessage(
    std::string &sender, 
    std::string &message)
{
    m_userMap.emplace(sender, message);
    assert(m_handler != nullptr);
    m_handler->OnPlayerJoin(message);
}

// Called when a text chat message is sent to the chat control.
void
NetworkStateChangeManager::ProcessTextMessage(
    std::string &sender, 
    std::string &message
    )
{
    assert(m_handler != nullptr);
    std::string userName = GetUserName(sender);
    m_handler->OnTextMessageReceived(userName, message, false);
}

// Called when a voice transcription is sent to the chat control.
void
NetworkStateChangeManager::ProcessVoiceMessage(
    std::string &sender, 
    std::string &message
    )
{
    assert(m_handler != nullptr);
    std::string userName = GetUserName(sender);
    m_handler->OnTextMessageReceived(userName, message, true);
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
