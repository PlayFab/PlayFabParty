# PlayFab Party SDK for macOS

## Logging

The Party C++ library includes logging capabilities with a configurable verbosity level. Logging configuration is defined in `PlayFabPartyLogger.json` file which can be deployed as an asset along with the application.

When this file is detected by the application at runtime it will use it to enable logging as configured. The following verbosity levels are currently supported:
1. `VERBOSE` - everything
2. `INFO` - less than everything, only important messages and errors
3. `ERROR` - only errors

The logging is disabled by default, but can be enabled with "enabled" property set to `true`.

### Example configuration file

```json
{
    "enabled": false,
    "bufferSize": 1048576,
    "maxNumberOfItemsInBatch": 500,
    "maxBatchWaitTimeInSeconds": 1,
    "readBufferWaitTimeInMilliseconds": 1,
    "logFolder": "<any local path>",
    "logLevel": "VERBOSE",
    "xrnLogEnabled": false,
    "maxLogFileSizeInMegabytes": 100,
    "logAreaFlags_ApiInOut": -1,
    "logAreaFlags_FnInOut": 18056,
    "logAreaFlags_Log": 20104
}
```

### Instructions

1. Enable **FileSharing** for your application, this can be done through the **Info.plist** file of your application.
2. Copy the `PlayFabPartyLogger.json` file into any local directory of your device.
3. Run the application.
4. The path to log files is specified by "logFolder" property of `PlayFabPartyLogger.json`.