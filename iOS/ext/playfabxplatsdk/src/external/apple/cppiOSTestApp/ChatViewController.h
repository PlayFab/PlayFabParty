/*
 * Copyright (c) Microsoft Corporation
 *
 * ViewController.h
 *
 */

#import <UIKit/UIKit.h>

@interface ChatViewController : UIViewController
{
    NSMutableData* responseData;
    NSArray* cookies;
}

@property (nonatomic, retain) NSMutableData* responseData;
@property (nonatomic, retain) NSArray* cookies;

- (void) returnHtmlFromPost:(NSString *)responseString;
@end

