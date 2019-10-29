# PartySample

PartySample is a sample iOS application with PlayFabParty framework integrated into it. Its purpose is to demonstrate the main functional capabilities provided by PlayFabParty API.

_Note: a registered PlayFab title is required to use PartySample app. Please refer to corresponding documentation._

## Building
Please use the latest Xcode.

1. Download `PlayFabParty.framework-for-iOS-(arch)-(no/with-bitcode)-Release.zip` from a PlayFabParty's GitHub repository release.
2. Unzip it and copy `PlayFabParty.framework` and `libplayfabxplatcppsdk.a` to folder `/iOS/bin/Release` in your cloned PlayFabParty repository.
3. Navigate to `/iOS/PartySample/app` in your repository and open `partysample_ios.xcodeproj` in Xcode.
4. Select `partysample_ios` project in the Project Navigator. Select `partysample_ios` target in the main panel. Please provide your iOS developer signing settings (Provisioning Profile, Team, Signing Certificate).
5. Set `partysample_ios` as the active scheme (usually in the top left corner of Xcode window).
6. Select your destination device (iPhone, iPad)
7. Build and Run using standard Xcode operations.

## Running
As PartySample app starts on an iOS device it will show a screen asking to provide a PlayFab title ID and select a sample user. Please provide required information and tap "Login". Create, Join or Leave party rooms to interact with other users.
