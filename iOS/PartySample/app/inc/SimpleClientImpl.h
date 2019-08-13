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
    Initialize();
    
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
        const char *format,
        const char *message
        );

    INetworkMessageHandler* m_messageHandler;
};
#endif /* SimpleClientImpl_hpp */
