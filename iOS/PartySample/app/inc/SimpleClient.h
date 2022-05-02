//
//  SimpleClient.h
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#ifndef SIMPLECLIENT_H
#define SIMPLECLIENT_H

#import <Foundation/Foundation.h>
#import "ChatEventHandler.h"

@class NotificationReceiver;

@protocol NotificationReceiver

- (void)didEnterBackground;
- (void)willEnterForeground;

@end

@interface SimpleClient : NSObject <ChatEventHandler, NotificationReceiver> {
    NSString* _networkId;
    NSString* _networkDescriptor;

}

@property (nonatomic) id<ChatEventHandler> chatEventHandler;

@property (nonatomic)  NotificationReceiver *notificationReceiver;

-(void) initialize:(NSString*)pfTitle;
-(void) setHandler:(id<ChatEventHandler>) messageHandler;
-(void) signInLocalUser;

-(void) createNetwork:(NSString*) networkId;
-(void) joinNetwork:(NSString*) networkId;
-(void) leaveNetwork;

-(void) sendTextAsVoice:(NSString*) text;
-(void) sendTextMessage:(NSString*) text;
-(void) setLanguageCode:(int) languageIndex;
-(void) setVolume:(float) volume;
-(NSArray *) getLanguageOptions;
-(int) getDefaultLanguageIndex;

-(NSString*) getSelectedUserName;

-(void) tick;

+(void) globalInitialize;
+(void) globalShutdown;

@end

#endif
