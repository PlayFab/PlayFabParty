//
//  ChatEventHandler.h
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#ifndef ChatEventHandler_h
#define ChatEventHandler_h

@protocol ChatEventHandler

-(void) onNetworkCreated:(NSString*) networkDescriptor;
-(void) onJoinedNetwork;
-(void) onPlayerJoin:(NSString*) userId;
-(void) onPlayerLeft:(NSString*) userId;
-(void) onPlayerStatusUpdateStart;
-(void) onPlayerStatusChange:(NSString*)playerId withIndicator:(NSString*)indicatorName;
-(void) onPlayerStatusUpdateEnd;
-(void) onTextMessageReceived:(NSString*) userId withText:(NSString*) text isTranscription:(BOOL) isTranscription;
-(void) onToastMessage:(NSString*) text;
-(void) onStartLoading;
-(void) onEndLoading;

@end

#endif /* ChatEventHandler_h */
