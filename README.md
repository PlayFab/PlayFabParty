# PlayFabParty

The libraries, headers, documentation, and samples for PlayFab Party.

The compiled PlayFab Party library binaries are attached as ZIP assets to each tagged release.

Please download, unzip, and copy the corresponding asset folder for your platform:

* iOS - `/iOS/bin/Release/`
* Android - `/android/bin/release/`
* Win32 - The Win32 binaries are not included in the ZIP assets. They are available for download on [NuGet](https://www.nuget.org/packages/Microsoft.PlayFab.PlayFabParty.Cpp.Windows).
* Linux - `/x64/Release/libparty.so`

## Logging

The underlying Party C++ library includes logging capabilities with a configurable verbosity level. Logging configuration is defined in the `PlayFabPartyLogger.json` file, which can be deployed as an asset along with the application. An example configuration file is shown below:

```json
{
    "enabled": false,
    "bufferSize": 16384,
    "maxNumberOfItemsInBatch": 100,
    "maxBatchWaitTimeInSeconds": 1,
    "readBufferWaitTimeInMilliseconds": 1,
    "logFolder": "/platform-specific-path/",
    "logLevel": "VERBOSE",
    "xrnLogEnabled": false,
    "consoleEnabled": false,
    "maxLogFileSizeInMegabytes": 0
}
```

When this file is detected by the application at runtime, it will be used to enable logging as configured. The following verbosity levels are currently supported:

1. `VERBOSE` - everything
2. `INFO` - less than everything, only important messages and errors
3. `ERROR` - only errors

Logging is disabled by default but can be enabled by setting the `enabled` property to `true`.

Instructions for enabling logging on each platform:

| Platform | Where to put `PlayFabPartyLogger.json` (permission needed) | `logFolder` value | How to view logs |
| --- | --- | --- | --- |
| Linux | Create the `/home/{user}/PlayFabParty/` folder, where `{user}` is the currently logged-in user. | `/home/{user}/PlayFabParty/log/` | Navigate to the `/home/{user}/PlayFabParty/log/` directory and open the logs directly. |
| iOS | Inside the application folder (set `UIFileSharingEnabled` to `true` in the app's `Info.plist` file). | `/app_sandbox_storage/Documents/` | Copy the logs from `logFolder` to a PC. |
| Android | In Android Studio, go to **View > Tool Windows > Device Explorer**. Create the `/PlayFabParty/config` folder in `/storage/emulated/0/Android/data/{Application name}/files/`, where `{Application name}` is your app. (The external storage folder requires the `READ_EXTERNAL_STORAGE` permission.) | In Android Studio, go to **View > Tool Windows > Device Explorer**. Create the `/PlayFabParty/log` folder in `/storage/emulated/0/Android/data/{Application name}/files/`, where `{Application name}` is your app. | Copy the logs from `log` to a PC and open them in your text editor of choice. |
| macOS | `~/Documents` (set `UIFileSharingEnabled` to `true` in the app's `Info.plist` file). | `~/Documents` | Open the logs directly in `logFolder`. |

## WSL Compatibility

PlayFab Party for Linux is not intended to run on the Windows Subsystem for Linux (WSL), as it does not have built-in support for system sound. As a result, chat features will not function properly. Please run it on a dedicated Linux machine to take advantage of all Party features.

## Android Logging

When logs do not appear in Device Explorer, you may need to close and reopen Android Studio so the application can refresh and properly display the files.
