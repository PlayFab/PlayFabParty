# PartySample

PartySample is a sample Android application with the PlayFabParty library integrated into it. Its purpose is to demonstrate the main functional capabilities provided by the PlayFabParty API.

_Note: a registered PlayFab title is required to use PartySample app. Please refer to corresponding documentation._

## Building and Deploying to Device
Please use the latest Android Studio. If you run into any issues, please refer to the [FAQ](#faq) before filing a GitHub Issue.

1. Download `PlayFabParty.Android.Release.zip` (previously `libparty-android-release.zip`) from one of the PlayFab Party GitHub [repository releases](https://github.com/PlayFab/PlayFabParty/releases).
2. Unzip the contents of the downloaded archive directly into `<REPO ROOT>/android/bin/release/`.
3. In Android Studio, open a project, navigate to your cloned repository and select `<REPO ROOT>/android/PartySample/`.
4. After the project has opened, run `Gradle Sync` in Android Studio.
5. Navigate to `Build > Select Build Variant`. In the sidebar that opens, change the `Active Build Variant` for `:demo` to `fullRelease`.
6. Navigate to `Build > Make Project`. You should see both the Java and C++ builds kickoff. You should see the following text if the build was successful.
    ```
    BUILD SUCCESSFUL in xm xxs
    29 actionable tasks: 29 executed
    ```
7. In the top right, select the device you wish to deploy the `PartySample` app to. Navigate to `Run > Run 'demo'`.

    a. You may run into the following error:
    ```
    Error: The apk for your currently selected variant cannot be signed. Please specify a signing configuration for this variant (<build-variant>).
    ```
    If you have a `signingConfig` you'd like to use, you may do so. Otherwise, you can just select the `Fix` button. That will add a `signingConfig` line to your `build.gradle` that looks like this: `signingConfig signingConfigs.debug`. **DO NOT CHECK THIS LINE INTO YOUR PRODUCTION APPLICATIONS.**

    After you're clicked `Fix` and you've confirmed the line has been added, you can run the application again.
5. If everything has gone well, you should see the application pop up on your device asking for permissions!

## Running
As the PartySample app starts on your Android device it will show a screen asking you to provide a PlayFab title ID and select a sample user. Please provide the required information and tap "Login".

On the subsequent screen, you can choose your desired room number, language, and then `Create`, `Join` or `Leave` to get in and out of party rooms with other users.

The application is designed to demo PlayFabParty's voice, transcription and translation capabilities. Chat with your friends and then dig into the code to see how it's done!

Good luck!

## FAQ
1. If you see an error similar to this:

    ```
    Unsupported Java. 
    Your build is currently configured to use Java 17.0.6 and Gradle 6.6.

    Possible solution:
    - Upgrade Gradle wrapper to 7.2 version and re-import the project
    ```

    Navigate to `Android Studio > Settings > Build, Execution, Deployment > Build Tools > Gradle` and change the Gradle JDK to version 1.8. You may need to download it.

    After you have changed the Gradle JDK to version 1.8, run `Gradle Sync` again and verify that the error has disappeared.
