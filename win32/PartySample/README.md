# Prerequisites

* .NET framework (4.8 preferred and tested on Win10 and Win7)
* KB3102810 (for Windows 7)

# Sample structure

The sample is setup as WPF app with the GUI logic implemented in C# in the `gui` directory and the real sample logic implemented in an unmanaged C++ dll in the `dll` directory.

## Notable files

* `gui/PartySample.xaml.cs`
* `dll/App.cpp`
