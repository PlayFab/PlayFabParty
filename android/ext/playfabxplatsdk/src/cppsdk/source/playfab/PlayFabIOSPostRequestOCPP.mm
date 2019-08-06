#include <playfab/PlayFabIOSPostRequestCPP.h>
#import <playfab/PlayFabIOSPostRequestOCPP.h>
#import <UIKit/UIKit.h>

using namespace PlayFabInternal;
static NSMutableURLRequest *myRequest;
static NSMutableData* responseData;
static CallRequestContainer *reqContainer;
static NSData* myRequestBodyData;
static Int32 statusCode;

@implementation ObjectCppPostUrl

+( void )prepare: (NSString* )url withBody: (NSString *) body
{
    //create the request
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]];
    
    //it is a POST request
    request.HTTPMethod = @"POST";
    
    
    //convert payload data and set it to the HTTPBody property
    NSString *stringData = body ;//@"some data";
    NSData *requestBodyData = [ stringData dataUsingEncoding:NSUTF8StringEncoding];
    request.HTTPBody = requestBodyData;
    myRequestBodyData = requestBodyData;
    
    //add body length as another header value
    [request setValue:[NSString stringWithFormat:@"%tu", [requestBodyData length]] forHTTPHeaderField:@"Content-Length"];
    
    myRequest = request;
}

+( void )open
{
 
#ifdef ASYNC_REQUEST
    NSLog(@"Async call %@\n", myRequest);
    //Create url connection and fire an asynchronous request
    NSURLConnection *conn = [[NSURLConnection alloc] initWithRequest: myRequest delegate:self];
#else
    
#ifdef USE_NSURLCONNECTION
    
    NSLog(@"Sync call %@\n", myRequest);
    //Create an synchronous request and waiting for a response
    NSHTTPURLResponse *response;
    NSError   *error = nil;
    NSData *data = [NSURLConnection sendSynchronousRequest:myRequest returningResponse:&response error:&error];
    
    //check for an error
    if (error !=nil  ) {
        NSLog(@"Error on load = %@", [error localizedDescription]);
        
        //setting error code to reqContainer and return
        
       // SetErrorInfo(reqContainer, "Error in NSURLConnection sendSynchronous request");
    } else {

        //check the HTTP status
        if ([response isKindOfClass:[NSHTTPURLResponse class]]) {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
            
            //if response indicates it is not OK, return the info back
            if (httpResponse.statusCode != 200 ) {
                NSLog(@"status code != 200");
                //setting error code to reqContainer and return
            } else {
                NSString* responseString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
                NSLog(@"SDK: the html from this URL was %@", responseString);
                //parse the data returned and set to reqContainer
                if (reqContainer != nullptr ) {
                    char *cstr = (char *)[data bytes];
                    reqContainer->responseString.append(cstr);
                }
            }
          }
    }
#else
    
    uint32_t requestBodySize = [myRequestBodyData length];
    NSData* data = myRequestBodyData; //[NSData dataWithBytes:myRequestBodyData length:requestBodySize];
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *dataTask = [session uploadTaskWithRequest:myRequest fromData:data completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
		statusCode = httpResponse.statusCode;
        if(httpResponse.statusCode == 200)
        {
            if (reqContainer != nullptr ) {
                char *cstr = (char *)[data bytes];
                reqContainer->responseString.append(cstr);
            }

            NSError *parseError = nil;
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
            NSLog(@"SDK: The response is - %@",responseDictionary);
  
            NSLog(@"SDK call successful");
        }
        else
        {
            NSLog(@"Error");
        }
    }];
    [dataTask resume];
    
#endif
    
    
#endif
    
}

#ifdef ASYNC_REQUEST
+( void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{
    [responseData setLength:0];
}

+( void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [responseData appendData:data];
}


+ (void) connectionDidFinishLoading:(NSURLConnection *)connection {
 //   [connection release];
    
    NSString* responseString = [[NSString alloc] initWithData:responseData encoding:NSUTF8StringEncoding];
    NSLog(@"SDK: the response from this request call was %@", responseString);
    
 //   [responseString release];
    
    //hack - start the next request here :|
    //  DoHttpPostWithCookie* service = [[DoHttpPostWithCookie alloc] initWithViewController:self];
    //  [service startHttpRequestWithCookie:self.cookies];
}

+ (void) connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    NSLog(@"SDK: something very bad happened here");
}

#endif

+( void)SetPlayFabPredefinedHeaders
{
 //   NSMutableURLRequest *request = myRequest;
    //set predefined headers
    
    [myRequest setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [myRequest setValue:@"application/json;charset=utf8" forHTTPHeaderField:@"Content-Type"];
    [myRequest setValue:@"true" forHTTPHeaderField:@"X-ReportErrorAsSuccess"];
    [myRequest setValue:@"XPlatCppSdk-3.2.181220" forHTTPHeaderField:@"X-PlatFabSDK"];
    
    
}

+( void)setRequest : (NSMutableURLRequest *)request
{
    myRequest = request;
}
+( NSMutableURLRequest *)getRequest
{
    return myRequest;
}

@end

void PlayFabIOSPostRequestCPP::prepare( const std::string &cppurl,  const std::string  &cppbody)
{
    NSString *url1 = [ NSString stringWithCString:cppurl.c_str() encoding:[NSString defaultCStringEncoding]];
    NSString *body1= [NSString stringWithCString:cppbody.c_str() encoding:[NSString defaultCStringEncoding]];
    [ ObjectCppPostUrl prepare : url1  withBody : body1];
    
}



void PlayFabIOSPostRequestCPP::AddContainerHeaders(const std::string &HeaderKey, const std::string &HeaderValue)
{
    NSString *HeaderK = [ NSString stringWithCString:HeaderKey.c_str() encoding:[NSString defaultCStringEncoding]];
    NSString *HeaderV = [NSString stringWithCString:HeaderValue.c_str() encoding:[NSString defaultCStringEncoding]];

    [myRequest setValue:HeaderV forHTTPHeaderField:HeaderK];
  
}

bool PlayFabIOSPostRequestCPP::open(CallRequestContainer& req, Int32& httpStatusCode)
{
    reqContainer = &req;
    httpStatusCode = 0;
	//reqContainer = req;
    [ ObjectCppPostUrl open ];
	//above call weill set statusCode and append reposne to req.responseString  
	httpStatusCode = statusCode;
	return true;


}

void PlayFabIOSPostRequestCPP::SetPlayFabPredefinedHeaders()
{
    [ ObjectCppPostUrl SetPlayFabPredefinedHeaders];
}
