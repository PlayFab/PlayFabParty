#include "pch.h"

void
NetworkStateChangeManager::Initialize(
    OnPlayerJoinedCallback onPlayerJoinedCallback,
    OnPlayerChatIndicatorUpdatedCallback onPlayerChatIndicatorUpdatedCallback,
    OnPlayerTextMessageReceivedCallback onPlayerTextMessageReceivedCallback,
    OnPlayerVoiceTranscriptionReceivedCallback onPlayerVoiceTranscriptionReceivedCallback,
    OnPlayerLeftCallback onPlayerLeftCallback
    )
{
    m_onPlayerJoinedCallback = onPlayerJoinedCallback;
    m_onPlayerChatIndicatorUpdatedCallback = onPlayerChatIndicatorUpdatedCallback;
    m_onPlayerTextMessageReceivedCallback = onPlayerTextMessageReceivedCallback;
    m_onPlayerVoiceTranscriptionReceivedCallback = onPlayerVoiceTranscriptionReceivedCallback;
    m_onPlayerLeftCallback = onPlayerLeftCallback;
}

void
NetworkStateChangeManager::ProcessStatusMessage(
    const std::string& system,
    const std::string& message
    )
{
    QueueLog(system, message);
}

void
NetworkStateChangeManager::ProcessPlayerJoined(
    const std::string& playerEntityId,
    const std::string& displayName
    )
{
    m_onPlayerJoinedCallback(playerEntityId.c_str(), displayName.c_str());
}

void
NetworkStateChangeManager::ProcessPlayerLeft(
    const std::string& playerEntityId
    )
{
    m_onPlayerLeftCallback(playerEntityId.c_str());
}

// Called when a text chat message is sent to the chat control.
void
NetworkStateChangeManager::ProcessTextMessage(
    const std::string& sender,
    const std::string& message
    )
{
    m_onPlayerTextMessageReceivedCallback(sender.c_str(), message.c_str());
}

// Called when a voice transcription is sent to the chat control.
void
NetworkStateChangeManager::ProcessVoiceMessage(
    const std::string& sender,
    const std::string& message
    )
{
    m_onPlayerVoiceTranscriptionReceivedCallback(sender.c_str(), message.c_str());
}

void
NetworkStateChangeManager::ProcessLocalChatIndicatorChange(
    const std::string& playerEntityId,
    Party::PartyLocalChatControlChatIndicator chatIndicator
    )
{
    m_onPlayerChatIndicatorUpdatedCallback(playerEntityId.c_str(), true, static_cast<int32_t>(chatIndicator));
}

// Called when a remote chat indicator changes
void
NetworkStateChangeManager::ProcessRemoteChatIndicatorChange(
    const std::string& playerEntityId,
    Party::PartyChatControlChatIndicator chatIndicator
    )
{
    m_onPlayerChatIndicatorUpdatedCallback(playerEntityId.c_str(), false, static_cast<int32_t>(chatIndicator));
}
