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

@interface SimpleClient : NSObject

@property (nonatomic) id<ChatEventHandler> chatEventHandler;

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
