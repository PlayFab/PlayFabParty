# PartySample

PartySample is a sample Android application with the PlayFabParty library integrated into it. Its purpose is to demonstrate the main functional capabilities provided by PlayFabParty API.

_Note: a registered PlayFab title is required to use PartySample app. Please refer to corresponding documentation._

## Building and Deploying to Device
Please use the latest Android Studio.

1. Download `libparty_a-for-Android-Release.zip` from one of the PlayFabParty GitHub repository releases.
2. Unzip the contents of the downloaded archive directly into `<REPO ROOT>/android/bin/release/`.
3. In Android Studio, open a project, navigate to your cloned repository and select `<REPO ROOT>/android/PartySample/`
4. Once the project has opened and gradle has synced, in Android Studio select `Run->Run 'demo'`
5. Select your destination device and press `OK`

## Configuring PlayFab
Before the Android app will work, you need to configure your PlayFab instance correctly in the Game Manager. See `Readme.md` within the `../PartySampleNetworkCommon` folder for detailed instructions.

## Running
As the PartySample app starts on your Android device it will show a screen asking you to provide a PlayFab title ID and select a sample user. Please provide the required information and tap "Login". 

On the subsequent screen, you can choose your desired room number, language, and then `Create`, `Join` or `Leave` to get in and out of party rooms with other users.

The application is designed to demo PlayFabParty's voice, transcription and translation capabilities.  Chat with your friends and then dig into the code to see how it's done!

Good luck!