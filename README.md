# PlayFabParty

The libraries, headers, documentation, and samples for PlayFab Party.

The compiled PlayFab Party library binaries are attached as zip assets to each tagged releases.

Please download, unzip, and copy the corresponding asset folder for your platform:

* iOS - `/iOS/bin/Release/`
* Android - `/android/bin/release/`
* Win32 - The win32 binaries are not included in the zip assets. They are available on download on [nuget](https://www.nuget.org/packages/Microsoft.PlayFab.PlayFabParty.Cpp.Windows).
* Linux - `/x64/Release/libparty.so`

## Logging
The underlying Party C++ library includes logging capabilities with a configurable verbosity level. Logging configuration is defined in `PlayFabPartyLogger.json` file which can be deployed as an asset along with the application. An example of configuration file:

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

When this file is detected by the application in runtime it will use it to enable logging as configured. The following verbosity levels are currently supported:
1. `VERBOSE` - everything
2. `INFO` - less than everything, only important messages and errors
3. `ERROR` - only errors

The logging is disabled by default, but can be enabled with "enabled" property set to `true`.

Instructions to enable logging for specific platform.
Platform|Where to put PlayFabPartyLogger.json (permission needed)|`logFolder` value|How to view logs
|-|-|-|-|
Linux|Create a folder "/home/{user}/PlayFabParty/" where {user} is the current user logged in | /home/{user}/PlayFabParty/log/ | Navigate to the `/home/{user}/PlayFabParty/log/` directory and open logs directly
iOS|Inside the application folder (Set UIFileSharingEnabled to true in the Info.plist of the app)|/app_sandbox_storage/Documents/|Copy logs from `logFolder` to PC
Android|Create a folder "\sdcard\PlayFabParty\config" (External storage folder requires READ_EXTERNAL_STORAGE permission)|/sdcard/PlayFabParty/log/|Copy logs from `logFolder` to PC and open in NotePad++
macOS|~/Documents (Set UIFileSharingEnabled to true in the Info.plist of the app)|~/Documents|Open logs directly in `logFolder`

## WSL Compatibility

PlayFab Party for Linux is not intended to run on the Windows Subsystem for Linux (WSL) as it does not have built in support for system sound. As a result, chat features will not function properly. Please run on a dedicated Linux machine to take advantage of all Party features.
