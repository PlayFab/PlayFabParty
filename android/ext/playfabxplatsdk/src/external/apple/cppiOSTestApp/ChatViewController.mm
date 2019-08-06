/*
 * Copyright (c) Microsoft Corporation
 *
 * ViewController.m
 *
 */

#import "ChatViewController.h"
#import <Foundation/Foundation.h>
#import <playfab/PlayFabClientApi.h>
#import <playfab/PlayFabClientDataModels.h>
#import <playfab/PlayFabAuthenticationApi.h>
#import <playfab/PlayFabAuthenticationDataModels.h>
#import <playfab/PlayFabProfilesApi.h>
#import <playfab/PlayFabProfilesDataModels.h>
#import <playfab/PlayFabSettings.h>
#import <playfab/OneDSEventsDataModels.h>
#import <playfab/PlayFabEventsApi.h>
#import <playfab/PlayFabEventsDataModels.h>
#import <playfab/PlayFabEventApi.h>
#import <playfab/OneDSEventsApi.h>
#import <playfab/PlayFabTransportHeaders.h>

@interface ChatViewController ()

@end

@implementation ChatViewController
@synthesize responseData;
@synthesize cookies;
static bool loginCompleted = false;

- (void)dealloc
{
    //    [cookies release];
    //    [responseData release];
    //    [super dealloc];
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

void OnPlayFabFail(const PlayFab::PlayFabError& error, void*)
{
    NSLog(@"=============PlayFab call Failed %s", error.GenerateErrorReport().c_str());
}

void OnProfile(const PlayFab::ClientModels::GetPlayerProfileResult& result, void*)
{
    NSLog(@"===========PlayFab Profile Success: %s", result.PlayerProfile->DisplayName.c_str());
    
}
void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void*)
{
    NSLog(@"==========PlayFab Login Success %s", result.PlayFabId.c_str());
    
    NSLog(@"==========PlayFab GetProfile API Call ");
    
    PlayFab::ClientModels::GetPlayerProfileRequest request;
    PlayFab::PlayFabClientAPI::GetPlayerProfile(request, OnProfile, OnPlayFabFail);
    loginCompleted = true;
    
}

void OnLoginFailed(const PlayFab::PlayFabError& error, void* customData)
{
    NSLog(@"===========PlayFab call Failed");
    loginCompleted = true;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    responseData = [NSMutableData new];
    //following code use the types of PlayFab XPlatCppIOS for request data composition
    
    NSLog(@"========startinmg PlayFab Login API call");
    PlayFab::PlayFabSettings::titleId = "6195";
    PlayFab::PlayFabSettings::threadedCallbacks = true;
    PlayFab::ClientModels::LoginWithCustomIDRequest request;
    request.CustomId = "test_GSDK";
    request.CreateAccount = true;
    NSLog(@"========ready to make PlayFab Login API call");
    PlayFab::PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnLoginFailed);
    NSLog(@"========after making PlayFab Login API call");
    
    while (!loginCompleted)
    {
        std::this_thread::yield();
    }
    
    NSLog(@"==========login completed");
}


- (void) connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    [responseData setLength:0];
}

- (void) connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [responseData appendData:data];
}

- (void) connectionDidFinishLoading:(NSURLConnection *)connection {
    //  [connection release];
    
    NSString* responseString = [[NSString alloc] initWithData:responseData encoding:NSUTF8StringEncoding];
    NSLog(@"playfab-login-test: the html from this URL was %@", responseString);
    
    //  [responseString release];
    
    //hack - start the next request here :|
    //  DoHttpPostWithCookie* service = [[DoHttpPostWithCookie alloc] initWithViewController:self];
    //  [service startHttpRequestWithCookie:self.cookies];
}

- (void) connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    NSLog(@"something very bad happened here");
}

- (NSURLRequest *)connection:(NSURLConnection *)connection willSendRequest:(NSURLRequest *)request redirectResponse:(NSHTTPURLResponse *)response {
    
    if (response != nil) {
        NSArray* authToken = [NSHTTPCookie
                              cookiesWithResponseHeaderFields:[response allHeaderFields]
                              forURL:[NSURL URLWithString:@""]];
        
        if ([authToken count] > 0) {
            [self setCookies:authToken];
            NSLog(@"cookies property %@", self.cookies);
        }
    }
    
    return request;
}

- (void) returnHtmlFromPost:(NSString *)responseString
{
    //this is called from the new object we created when the "connectionDidFinishLoading" is complete
    NSLog(@"got this response back from the post with cookies %@", responseString);
}

@end
