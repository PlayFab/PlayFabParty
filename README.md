# PlayFabParty

The libraries, headers, documentation, and samples for PlayFab Party.

The compiled PlayFab Party library binaries are attached as zip assets to each tagged releases.

Please download, unzip, and copy the corresponding asset folder for your platform:

* iOS - `/iOS/bin/Release/`
* Android - `/android/bin/release/`
* Win32 - The win32 binaries are not included in the zip assets. They are available on download on [nuget](https://www.nuget.org/packages/Microsoft.PlayFab.PlayFabParty.Cpp.Windows).
* Linux - `/x64/Release/libparty.so`

### Using PlayFab Party in Production

We've included a pre-built binary of the [XPlatCppSDK](https://github.com/PlayFab/XPlatCppSdk) in our Release packages. **These pre-built binaries are intended for use only in the PartySamples.** You can find the binaries at the following locations:

* iOS:
```
PlayFabParty.framework-for-iOS-Release/PlayFabParty.framework-for-iOS-<arch>-Release/libplayfabxplatcppsdk.a
```

* Android:
```
libparty-android-release/<arch>/lib/libcppsdk.a
```

* Win32:
    * A pre-built `playfabxplatcppsdk.lib` binary for the XPlatCppSDK for Windows is *not included* in the nuget or in this repo. However, we do include a [`PlayFabXPlatCppSdk.vcxproj` file](win32/PartySample/dll/PlayFabXPlatCppSdk.vcxproj), that will compile and generate a `playfabxplatcppsdk.lib` to help your sample get up and running.

* Linux:
    * *Not Included*

**DO NOT USE THESE PRE-BUILT BINARIES IN PRODUCTION.**

These binaries are intended to help demonstrate a sample PlayFab Party application, and are not safe for production consumption.

Please consume the XPlatCppSDK from [source](https://github.com/PlayFab/XPlatCppSdk).