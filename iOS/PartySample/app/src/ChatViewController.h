//
//  ViewController.h
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChatEventHandler.h"

@interface ChatViewController : UIViewController <ChatEventHandler, UITableViewDelegate, UITableViewDataSource>

@property (strong, nonatomic) NSString *pfTitle;

@end

