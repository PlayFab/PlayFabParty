# PlayFabParty

The libraries, headers, documentation, and samples for PlayFab Party.

The compiled PlayFab Party library binaries are attached as zip assets to each tagged releases.

Please download, unzip, and copy the corresponding asset folder for your platform:

* iOS - `/iOS/bin/Release/`
* Android - `/android/bin/release/`
* Win32 - The win32 binaries are not included in the zip assets. They are available on download on [nuget](https://www.nuget.org/packages/Microsoft.PlayFab.PlayFabParty.Cpp.Windows).
* Linux - `/x64/Release/libparty.so`

## Troubleshooting

### WSL Compatibility

While WSL can be used as a build platform to create Party binaries, it is not supported as a runtime platform to use Party SDK and its features. A machine with a Linux OS is required to take advantage of all Party features.