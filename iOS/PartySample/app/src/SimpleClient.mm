//
//  SimpleClient.cpp
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#include "SimpleClient.h"
#include "SimpleClientImpl.h"

#include "INetworkMessageHandler.h"
#include "Config.h"

// forward-declaration of helper methods:
std::string NSStringToString(NSString* str);
NSString* StringToNSString (const std::string& str);

// class to bridge callbacks and do conversion from C++
class SimpleClientEventHandler : public INetworkMessageHandler
{
public:
    SimpleClientEventHandler(id<ChatEventHandler> eventHandler)
    {
        m_eventHandler = eventHandler;
    }
    
    void OnNetworkCreated(std::string &networkDescriptor) override
    {
        std::string l_networkDescriptor = networkDescriptor;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onNetworkCreated:StringToNSString(l_networkDescriptor)];
        });
    }
        
    void OnJoinedNetwork() override
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onJoinedNetwork];
        });
    }
    
    void OnPlayerJoin(std::string &playerId) override
    {
        std::string l_playerId = playerId;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onPlayerJoin:StringToNSString(l_playerId)];
        });
    }

    void OnPlayerStatusUpdateStart(void) override
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onPlayerStatusUpdateStart];
        });
    }
    
    void OnPlayerStatusChange(const std::string &playerId, std::string &chatIndicator) override
    {
        std::string l_playerId = playerId;
        std::string l_chatIndicator = chatIndicator;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onPlayerStatusChange:StringToNSString(l_playerId) withIndicator:StringToNSString(l_chatIndicator)];
        });
    }

    void OnPlayerStatusUpdateEnd(void) override
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onPlayerStatusUpdateEnd];
        });
    }

    void OnPlayerLeft(std::string &playerId) override
    {
        std::string l_playerId = playerId;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onPlayerLeft:StringToNSString(l_playerId)];
        });
    }
    
    void OnTextMessageReceived(std::string &senderId, std::string &message, bool isTranscript) override
    {
        std::string l_senderId = senderId;
        std::string l_message = message;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onTextMessageReceived:StringToNSString(l_senderId) withText:StringToNSString(l_message) isTranscription:isTranscript];
        });
    }
    
    void OnStartLoading(void) override
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onStartLoading];
        });
    }
    
    void OnEndLoading(void) override
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [m_eventHandler onEndLoading];
        });
    }

private:
    id<ChatEventHandler> m_eventHandler;
};


@interface SimpleClient ()

@end

@implementation SimpleClient

SimpleClientImpl* m_impl;
SimpleClientEventHandler* clientEventHandler;

-(id)init
{
    self = [super init];
    
    if (self)
    {
        m_impl = new SimpleClientImpl();
        _chatEventHandler = nil;
    }
    
    return self;
}

- (void)dealloc
{
    if (nullptr != clientEventHandler)
    {
        delete clientEventHandler;
        clientEventHandler = nullptr;
    }
    if (nullptr != m_impl)
    {
        delete m_impl;
        m_impl = nullptr;
    }
}

-(void)initialize
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    m_impl->Initialize();
}

-(void)setHandler:(id<ChatEventHandler>) handler
{
    _chatEventHandler = handler;
    
    if (nullptr != m_impl)
    {
        clientEventHandler = new SimpleClientEventHandler(_chatEventHandler);
        m_impl->SetNetworkMessageHandler(clientEventHandler);
    }
}

-(void)signInLocalUser
{
    if (nullptr == m_impl)
    {
        return;
    }
    m_impl->SignInLocalUser();
}

-(void) createNetwork:(NSString*) networkId
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    std::string convertedStr([networkId cStringUsingEncoding:NSUTF8StringEncoding]);
    
    m_impl->CreateNetwork(convertedStr);
}

-(void) joinNetwork:(NSString*) networkId
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    std::string convertedStr([networkId cStringUsingEncoding:NSUTF8StringEncoding]);
    
    m_impl->JoinNetwork(convertedStr);
}

-(void) leaveNetwork
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    m_impl->LeaveNetwork();
}

-(void) sendTextAsVoice:(NSString*) text
{
    if (nullptr == m_impl)
    {
        return;
    }

    m_impl->SendTextAsVoice(NSStringToString(text));
}

-(void) sendTextMessage:(NSString*) text
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    m_impl->SendTextMessage(NSStringToString(text));
}

-(void) setLanguageCode:(int)languageIndex
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    m_impl->SetLanguageCode(languageIndex);
}

-(NSArray *)getLanguageOptions
{
    NSMutableArray *languageOptionArray = [[NSMutableArray alloc] init];
    
    if (nullptr == m_impl)
    {
        return languageOptionArray;
    }
    
    const char** languageOptions = m_impl->GetLanguageOptions();
    int numberOfLanguages = m_impl->GetNumberOfLanguages();
    for (int index = 0; index < numberOfLanguages; index++) {
        [languageOptionArray addObject:StringToNSString(languageOptions[index])];
    }

    return languageOptionArray;
}

-(int)getDefaultLanguageIndex
{
    if (nullptr == m_impl)
    {
        return 0;
    }
    
    return m_impl->GetDefaultLanguageIndex();
}

-(NSString*) getSelectedUserName
{
    const char* username = Config::GetSelectedName();
    return [NSString stringWithUTF8String:username];
}

-(void) tick
{
    if (nullptr == m_impl)
    {
        return;
    }
    m_impl->Tick();
}

+(void)globalInitialize
{
    SimpleClientImpl::GlobalInitialize();
}

+(void)globalShutdown
{
    SimpleClientImpl::GlobalShutdown();
}

// HELPER METHODS:
std::string NSStringToString(NSString* str)
{
    NSStringEncoding pEncode    =   CFStringConvertEncodingToNSStringEncoding (kCFStringEncodingUTF8);
    NSData* pSData              =   [ str dataUsingEncoding : pEncode ];
    
    return std::string ( (char*) [ pSData bytes ], [ pSData length] / sizeof ( char ) );
}

NSString* StringToNSString (const std::string& str)
{
  NSString* pString = [ [ NSString alloc ]
                       initWithBytes : (char*)str.data()
                       length : str.size() * sizeof(char)
                       encoding : CFStringConvertEncodingToNSStringEncoding ( kCFStringEncodingUTF8 ) ];
  return pString;
}
                   
@end



