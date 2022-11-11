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
    SimpleClientEventHandler(id<ChatEventHandler> eventHandler, SimpleClientImpl* impl)
    {
        m_eventHandler = eventHandler;
        m_impl = impl;
    }
    
    void OnNetworkCreated(std::string &networkDescriptor) override
    {
        [m_eventHandler onNetworkCreated:StringToNSString(networkDescriptor)];
    }
        
    void OnJoinedNetwork() override
    {
        [m_eventHandler onJoinedNetwork];
    }
    
    void OnPlayerJoin(const std::string &playerId) override
    {
        [m_eventHandler onPlayerJoin:StringToNSString(playerId)];
    }

    void OnPlayerStatusUpdateStart(void) override
    {
        [m_eventHandler onPlayerStatusUpdateStart];
    }
    
    void OnPlayerStatusChange(const std::string &playerId, std::string &chatIndicator) override
    {
        [m_eventHandler onPlayerStatusChange:StringToNSString(playerId) withIndicator:StringToNSString(chatIndicator)];
    }

    void OnPlayerStatusUpdateEnd(void) override
    {
        [m_eventHandler onPlayerStatusUpdateEnd];
    }

    void OnPlayerLeft(std::string &playerId) override
    {
        [m_eventHandler onPlayerLeft:StringToNSString(playerId)];
    }
    
    void OnTextMessageReceived(const std::string &senderId, const std::string &message, bool isTranscript) override
    {
        [m_eventHandler onTextMessageReceived:StringToNSString(senderId) withText:StringToNSString(message) isTranscription:(BOOL)isTranscript];
    }

    void OnGetDescriptorCompleted(std::string networkId, std::string message) override
    {
        [m_eventHandler onGetDescriptorCompleted:StringToNSString(networkId) withNetworkDescriptor:StringToNSString(message)];
    }

    void OnStartLoading(void) override
    {
        [m_eventHandler onStartLoading];
    }
    
    void OnEndLoading(void) override
    {
        [m_eventHandler onEndLoading];
    }

private:
    id<ChatEventHandler> m_eventHandler;
    SimpleClientImpl* m_impl;
};


@interface NotificationReceiver : NSObject {
    id<NotificationReceiver> receiver;
}

@property(nonatomic, assign) id<NotificationReceiver> receiver;

- (id)init:(id<NotificationReceiver>)receiver;

@end

@implementation NotificationReceiver

@synthesize receiver = _receiver;

- (id)init:(id<NotificationReceiver>)receiver
{
    self = [super init];
    
    self.receiver = receiver;
    
    return self;
}

- (void)addObservers
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationHandlerDidEnterBackground:)
                                                 name:@"PartySample.DidEnterBackground" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationHandlerWillEnterForeground:)
                                                 name:@"PartySample.WillEnterForeground" object:nil];
}

- (void)removeObservers
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)notificationHandlerDidEnterBackground:(NSNotification*)notification
{
    [self.receiver didEnterBackground];
}

- (void)notificationHandlerWillEnterForeground:(NSNotification*)notification
{
    [self.receiver willEnterForeground];
}

@end



@interface SimpleClient ()

@property(nonatomic, retain) NSString* networkId;
@property(nonatomic, retain) NSString* networkDescriptor;

@end

@implementation SimpleClient

@synthesize notificationReceiver = _notificationReceiver;
@synthesize networkId = _networkId;
@synthesize networkDescriptor = _networkDescriptor;

SimpleClientImpl* m_impl;
SimpleClientEventHandler* clientEventHandler;

-(id)init
{
    self = [super init];
    
    if (self)
    {
        m_impl = new SimpleClientImpl();
        _chatEventHandler = nil;
        
        self.notificationReceiver = [[NotificationReceiver alloc] init:self];
        [self.notificationReceiver addObservers];
    }
    
    return self;
}

- (void)dealloc
{
    [self.notificationReceiver removeObservers];
    
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

-(void)initialize:(NSString *)pfTitle
{
    if (nullptr == m_impl)
    {
        return;
    }

    m_impl->Initialize([pfTitle UTF8String]);
}

-(void)setHandler:(id<ChatEventHandler>) handler
{
    _chatEventHandler = handler;
    
    if (nullptr != m_impl)
    {
        clientEventHandler = new SimpleClientEventHandler(self, m_impl);
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
    
    self.networkId = networkId;
    std::string convertedStr([networkId cStringUsingEncoding:NSUTF8StringEncoding]);
    
    m_impl->CreateNetwork(convertedStr);
}

-(void) joinNetwork:(NSString*) networkId
{
    if (nullptr == m_impl)
    {
        return;
    }
    
    self.networkId = networkId;
    std::string convertedStr([networkId cStringUsingEncoding:NSUTF8StringEncoding]);
    
    m_impl->JoinNetwork(convertedStr);
}

-(void) leaveNetwork
{
    if (nullptr == m_impl)
    {
        return;
    }

    self.networkId = nil;
    self.networkDescriptor = nil;
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

-(void) setVolume:(float)volume
{
    if (nullptr == m_impl)
    {
        return;
    }

    m_impl->SetVolume(volume);
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

#pragma mark - ChatEventHandler
-(void) onNetworkCreated:(NSString*) networkDescriptor
{
    self.networkDescriptor = networkDescriptor;

    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onNetworkCreated:networkDescriptor];
    });
}

-(void) onGetDescriptorCompleted:(NSString*) networkId withNetworkDescriptor:(NSString*) networkDescriptor
{
    self.networkId = networkId;
    self.networkDescriptor = networkDescriptor;

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        m_impl->ConnectToNetwork(NSStringToString(networkId), NSStringToString(networkDescriptor), false);
    });
}

-(void) onJoinedNetwork
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onJoinedNetwork];
    });
}

-(void) onPlayerJoin:(NSString*) userId
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onPlayerJoin:userId];
    });
}

-(void) onPlayerLeft:(NSString*) userId
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onPlayerLeft:userId];
    });
}

-(void) onPlayerStatusUpdateStart
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onPlayerStatusUpdateStart];
    });
}

-(void) onPlayerStatusChange:(NSString*)playerId withIndicator:(NSString*)indicatorName
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onPlayerStatusChange:playerId withIndicator:indicatorName];
    });
}

-(void) onPlayerStatusUpdateEnd
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onPlayerStatusUpdateEnd];
    });
}

-(void) onTextMessageReceived:(NSString*) userId withText:(NSString*) text isTranscription:(BOOL) isTranscription
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onTextMessageReceived:userId withText:text isTranscription:isTranscription];
    });
}

-(void) onToastMessage:(NSString*) text
{
    [_chatEventHandler onToastMessage:text];
}

-(void) onStartLoading
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onStartLoading];
    });
}

-(void) onEndLoading
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_chatEventHandler onEndLoading];
    });
}

#pragma mark - NotificationReceiver
- (void)didEnterBackground
{
    if(self.networkId.length > 0 && self.networkDescriptor.length > 0)
    {
        m_impl->LeaveNetwork();
    }
}

- (void)willEnterForeground
{
    if(self.networkId.length > 0 && self.networkDescriptor.length > 0)
    {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            m_impl->ConnectToNetwork(NSStringToString(self.networkId), NSStringToString(self.networkDescriptor), true);
        });
    }
}

@end



