#ifndef PARTYDEMO_H
#define PARTYDEMO_H
#include "pch.h"

void
OnChatControlDestroyed(
    std::string sender
    );

void
OnChatControlCreated(
    std::string sender
    );

void
OnEndpointMessageReceived(
    std::string sender,
    std::string message
    );

void
OnPlayerStateChange(
    std::string player,
    std::string state
    );

void
OnVoiceChatTranscriptionReceived(
    std::string sender,
    std::string message
    );

void
SendSysLogToUI(
    const char* format,
    ...
    );

#endif //PARTYDEMO_H
