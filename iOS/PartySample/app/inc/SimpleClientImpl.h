//
//  SimpleClientImpl.hpp
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#ifndef SimpleClientImpl_h
#define SimpleClientImpl_h

#include <string>
#include <functional>

#include "INetworkMessageHandler.h"


class SimpleClientImpl
{
public:
    void
    Initialize(
        const char* pfTitle
        );

    void
    SetNetworkMessageHandler(
        INetworkMessageHandler* handler
        );
    
    void
    SignInLocalUser();
    
    void
    CreateNetwork(
        std::string& networkId
        );
    
    void
    JoinNetwork(
        std::string& networkId
        );

    void
    ConnectToNetwork(
        std::string networkId,
        std::string message
        );

    void
    LeaveNetwork();

    void
    SendTextAsVoice(
        std::string text
        );
    
    void
    SendTextMessage(
        std::string
        text
        );
    
    void
    SetLanguageCode(
        int
        languageIndex
        );
    
    const char**
    GetLanguageOptions();
    
    int
    GetDefaultLanguageIndex();
    
    int
    GetNumberOfLanguages();
    
    void
    Tick();
    
    static
    void
    GlobalInitialize();
    
    static
    void
    GlobalShutdown();

private:
    void
    GetPlayerState();
    
    void
    SendSysLogToUI(
        std::string message
        );

    std::string
    FormatMessage(const char* fmt, ...);

    INetworkMessageHandler* m_messageHandler;
};
#endif /* SimpleClientImpl_hpp */
