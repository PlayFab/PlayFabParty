//
//  SimpleClientImpl.cpp
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#include "SimpleClientImpl.h"
#include "pch.h"

#include "Manager.h"
#include "Managers.h"
#include "NetworkStateChangeManager.h"
#include "PlayFabManager.h"
#include "NetworkManager.h"
#include "LanguageOptions.h"
#include "Config.h"

#include <stdio.h>
#include <iostream>
#include <string>


bool g_isRunning = false;
bool g_initializeCompleted = false;
bool g_shouldShutdown = false;
std::string g_pfTitle;

const char *
GetErrorMessage(
    PartyError error
    )
{
    PartyString errString = nullptr;
    PartyManager::GetErrorMessage(error, &errString);

    return errString;
}

struct ChatControlCustomContext
{
    PartyLocalChatControlChatIndicator chatIndicator;
    PartyString userIdentifier;
    std::unordered_map<PartyChatControl*, PartyChatControlChatIndicator> relativeChatIndicators;
};

void
SimpleClientImpl::Initialize(const char* pfTitle)
{
    g_isRunning = true;
    g_pfTitle = pfTitle;
    Managers::Initialize<NetworkStateChangeManager>();
}

void
SimpleClientImpl::SetNetworkMessageHandler(
    INetworkMessageHandler* messageHandler
    )
{
    Managers::Get<NetworkStateChangeManager>()->SetNetworkMessageHandler(messageHandler);
    m_messageHandler = messageHandler;
}

void
SimpleClientImpl::SignInLocalUser()
{
    SendSysLogToUI(FormatMessage("SignInLocalUser g_pfTitle: %s", g_pfTitle.c_str()));
    Managers::Get<PlayFabManager>()->Initialize(g_pfTitle.c_str());
    m_messageHandler->OnStartLoading();
    Managers::Get<PlayFabManager>()->SignIn(
        [this](bool isSucceeded, std::string message)
        {
            this->SendSysLogToUI(this->FormatMessage("SignIn: %s", isSucceeded ? "OK" : message.c_str()));
            m_messageHandler->OnEndLoading();
            if (isSucceeded)
            {
                std::map<const std::string, const std::string>* map = Managers::Get<NetworkStateChangeManager>()->GetUserMap();
                map->emplace(Managers::Get<PlayFabManager>()->EntityId(), Managers::Get<PlayFabManager>()->displayName());
                g_initializeCompleted = true;
            }
        },
        Config::GetSelectedName());
    std::string userName = Config::GetSelectedName();
    m_messageHandler->OnPlayerJoin(userName);
}

void
SimpleClientImpl::CreateNetwork(
    std::string &networkId
    )
{
    if (g_isRunning && g_initializeCompleted)
    {
        SendSysLogToUI(FormatMessage("CreateNetwork g_pfTitle: %s", g_pfTitle.c_str()));
        Managers::Get<NetworkManager>()->Initialize(g_pfTitle.c_str());
        m_messageHandler->OnStartLoading();
        Managers::Get<NetworkManager>()->CreateAndConnectToNetwork(
            networkId.c_str(),
            [this, networkId](std::string message)
            {
                this->SendSysLogToUI(this->FormatMessage("create network: %s", message.c_str()));
                Managers::Get<PlayFabManager>()->SetDescriptor(
                    networkId,
                    message, 
                    [this, message](void)
                    {
                        m_messageHandler->OnEndLoading();
                        this->SendSysLogToUI(this->FormatMessage("set network descriptor succeeded"));
                        std::string l_message = message;
                        m_messageHandler->OnNetworkCreated(l_message);
                    });
            },
            [this](PartyError error)
            {
                m_messageHandler->OnEndLoading();
                this->SendSysLogToUI(this->FormatMessage("create network failed: %s", GetErrorMessage(error)));
            });
    }
}

void
SimpleClientImpl::JoinNetwork(
    std::string &networkId
    )
{
    if (g_isRunning && g_initializeCompleted)
    {
        SendSysLogToUI(FormatMessage("JoinNetwork g_pfTitle: %s", g_pfTitle.c_str()));
        Managers::Get<NetworkManager>()->Initialize(g_pfTitle.c_str());
        m_messageHandler->OnStartLoading();
        Managers::Get<PlayFabManager>()->GetDescriptor(
            networkId.c_str(),
            [this, networkId](std::string message)
            {
                this->SendSysLogToUI(this->FormatMessage("OnGetDescriptorForConnectTo : %s", message.c_str()));
                m_messageHandler->OnGetDescriptorCompleted(networkId, message);
            });
    }
}

void
SimpleClientImpl::ConnectToNetwork(
    std::string networkId,
    std::string message
    )
{
    Managers::Get<NetworkManager>()->ConnectToNetwork(
        networkId.c_str(),
        message.c_str(),
        [this](void)
        {
            m_messageHandler->OnEndLoading();
            this->SendSysLogToUI(this->FormatMessage("OnConnectToNetwork succeeded"));
            m_messageHandler->OnJoinedNetwork();
        },
        [this](PartyError error)
        {
            m_messageHandler->OnEndLoading();
            this->SendSysLogToUI(this->FormatMessage("OnConnectToNetworkFailed: %s", GetErrorMessage(error)));
        });
}

void
SimpleClientImpl::LeaveNetwork()
{
    Managers::Get<NetworkManager>()->LeaveNetwork(
        [this](void)
        {
            this->SendSysLogToUI(this->FormatMessage("OnLeave: succeeded"));
            g_shouldShutdown = true;
        }
    );
}

void
SimpleClientImpl::SendSysLogToUI(
    std::string message
    )
{
    std::string senderId = "System";
    m_messageHandler->OnTextMessageReceived(senderId, message, false);
}

std::string
SimpleClientImpl::FormatMessage(const char* fmt, ...)
{
    int len;
    std::string str;
    va_list args;
    char buffer[4 * 1024];

    va_start(args, fmt);

    if ((len = vsnprintf(buffer, sizeof(buffer), fmt, args)) > 0)
    {
        if (len < sizeof(buffer))
        {
            str = buffer;
        }
        else
        {
            int maxsz = len + 1;
            char* buffer = (char*)malloc(maxsz);
            
            if (buffer)
            {
                len = vsnprintf(buffer, maxsz, fmt, args);

                if (len > 0 && len < maxsz)
                {
                    str = buffer;
                }

                free(buffer);
            }
        }
    }

    va_end(args);

    return str;
}

void
SimpleClientImpl::SendTextAsVoice(
    std::string text
    )
{
    Managers::Get<NetworkManager>()->SendTextAsVoice(text);
}

void
SimpleClientImpl::SendTextMessage(
    std::string text
    )
{
    Managers::Get<NetworkManager>()->SendTextAsVoice(text);
}

void
SimpleClientImpl::SetLanguageCode(
    int languageIndex
    )
{
    Managers::Get<NetworkManager>()->SetLanguageCode(
        LanguageOptions::s_languageCodes[languageIndex],
        LanguageOptions::s_languageNames[languageIndex]
        );
}

const char**
SimpleClientImpl::GetLanguageOptions()
{
    return LanguageOptions::s_languageNames;
}

int
SimpleClientImpl::GetDefaultLanguageIndex()
{
    return LanguageOptions::s_defaultLanguageIndex;
}

int
SimpleClientImpl::GetNumberOfLanguages()
{
    return LanguageOptions::s_numberOfLanguages;
}

void
SimpleClientImpl::Tick()
{
    if (g_isRunning)
    {
        Managers::Get<PlayFabManager>()->Tick();
        Managers::Get<NetworkManager>()->DoWork();
        GetPlayerState();
    }
    if (g_shouldShutdown)
    {
        g_shouldShutdown = false;
        Managers::Get<NetworkManager>()->Shutdown();
    }
}

void
SimpleClientImpl::GetPlayerState() {
    m_messageHandler->OnPlayerStatusUpdateStart();
    
    std::shared_ptr<NetworkManager> manager = Managers::Get<NetworkManager>();
    PartyLocalChatControl* localChatControl = manager->GetLocalChatControl();
    
    if (localChatControl == nullptr)
    {
        goto exit;
    }

    for (auto& item : *(Managers::Get<NetworkStateChangeManager>()->GetUserMap()))
    {
        std::string userIdentifier = item.first;
        
        PartyChatControl* chatControl = manager->GetChatControl(userIdentifier);
        if (chatControl != nullptr)
        {
            std::string userName = item.second;
            
            PartyError error;
            if (Config::GetSelectedName() == userName)
            {
                Party::PartyLocalChatControlChatIndicator indicator;
                error = localChatControl->GetLocalChatIndicator(&indicator);
                if (PARTY_FAILED(error))
                {
                    DEBUGLOG("GetPlayerState GetLocalChatIndicator failed: %s\n", GetErrorMessage(error));
                    goto exit;
                }
                
                std::string localChatControlChatIndicator = "silence";
                if (Party::PartyLocalChatControlChatIndicator::Talking == indicator)
                {
                    localChatControlChatIndicator = "talking";
                }
                m_messageHandler->OnPlayerStatusChange(userName, localChatControlChatIndicator);
            }
            else
            {
                Party::PartyChatControlChatIndicator indicator;
                error = localChatControl->GetChatIndicator(chatControl, &indicator);
                if (PARTY_FAILED(error))
                {
                    DEBUGLOG("GetPlayerState GetChatIndicator failed: %s\n", GetErrorMessage(error));
                    goto exit;
                }
                
                std::string chatControlChatIndicator = "silence";
                if (Party::PartyChatControlChatIndicator::Talking == indicator)
                {
                    chatControlChatIndicator = "talking";
                }
                m_messageHandler->OnPlayerStatusChange(userName, chatControlChatIndicator);
            }
        }
    }

exit:
    m_messageHandler->OnPlayerStatusUpdateEnd();
}

void
SimpleClientImpl::GlobalInitialize()
{
    // Add intialization tasks here
}

void
SimpleClientImpl::GlobalShutdown()
{
    // Add shutdown tasks here
}
