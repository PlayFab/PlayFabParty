//
//  INetworkMessageHandler.h
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#ifndef INetworkMessageHandler_h
#define INetworkMessageHandler_h

#include <string>

class INetworkMessageHandler
{
public:
    
    INetworkMessageHandler()
    {
    }
    
    virtual
    ~INetworkMessageHandler() = default;
    
    virtual
    void
    OnNetworkCreated(
        std::string &networkDescriptor
        ) = 0;
    
    virtual
    void
    OnJoinedNetwork() = 0;
    
    virtual
    void
    OnPlayerJoin(
         std::string &playerId
         ) = 0;
    
    virtual
    void
    OnPlayerLeft(
         std::string &playerId
         ) = 0;

    virtual
    void
    OnPlayerStatusUpdateStart(void) = 0;
    
    virtual
    void
    OnPlayerStatusChange(
        const std::string &playerId,
        std::string &chatIndicator
        ) = 0;
    
    virtual
    void
    OnPlayerStatusUpdateEnd(void) = 0;

    virtual
    void
    OnTextMessageReceived(
        std::string &senderId,
        std::string &message,
        bool isTranscript
        ) = 0;
    
    virtual
    void OnStartLoading(void) = 0;

    virtual
    void OnEndLoading(void) = 0;

};
#endif /* INetworkMessageHandler_h */
