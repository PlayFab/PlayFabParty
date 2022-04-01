# Prerequisites

* A PlayFab Title
    * Make sure you've followed the instructions in [PartySampleNetworkCommon/Readme.md](PartySampleNetworkCommon/Readme.md) to setup the Cloudscript used by this sample
* .NET framework (4.8 preferred and tested on Win10 and Win7)
* KB3102810 (for Windows 7)

# Sample structure

The sample is setup as WPF app with the GUI logic implemented in C# in the `gui` directory and the real sample logic implemented in an unmanaged C++ dll in the `dll` directory.

## Notable files

* `gui/PartySample.xaml.cs` - the logic for the main GUI page
* `dll/App.cpp` - exposes the interface used by the GUI to interact with the PlayFab Party DLL
* `PartySampleNetworkCommon/NetworkManager.cpp` - Provides a simplified interface for the PlayFab Party DLL (used by `App.cpp`)
* `PartySampleNetworkCommon/PlayFabManager.cpp` - Manages all of the PlayFab functionality outside of Party (login, cloudscript, etc)
