#pragma once
// Url.h -- Obj-C
#pragma once
#import <CoreFoundation/CoreFoundation.h>
#import <UIKit/UIKit.h>

@interface ObjectCppPostUrl : NSObject
{
    NSMutableData* responseData;
    UIViewController* viewController;
    
}

@property (nonatomic, retain) UIViewController* viewController;

+(void) setRequest : (NSMutableURLRequest *)request;
+(NSMutableURLRequest *)getRequest;
+(void)prepare : (NSString *)url withBody: (NSString *) body ;
+(void)open;
+(void)SetPlayFabPredefinedHeaders;

@end
