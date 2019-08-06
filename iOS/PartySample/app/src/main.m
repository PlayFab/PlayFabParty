//--------------------------------------------------------------------------------------
// main.m
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "SimpleClient.h"

int main(int argc, char * argv[]) {
    int result = 0;
    
    @autoreleasepool {
        [SimpleClient globalInitialize];
        result = UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
    [SimpleClient globalShutdown];
    
    return result;
}
