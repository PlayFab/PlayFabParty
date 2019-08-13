//
//  ViewController.h
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChatEventHandler.h"

@interface ViewController : UIViewController <ChatEventHandler, UITableViewDelegate, UITableViewDataSource>

@end

