### PlayFab Configuration

This sample requires the title be configured for Party. You'll need to enable Party support by going to the Multiplayer tab of the Game Manager, going to the Party tab, and turning it on. You will need to add billing information, even as running this sample app won't incur any charges as long as your title is in Development mode.

**Cloud Script**

To run this sample, you will need a Cloud Script in order to synchronize room IDs across clients.

In the Game Manager, go to the "Automation" tab, and then the "Revisions" section of the "Cloud Script" screen. Paste in the contents of the "cloudScript.js" file in this folder.

### Accessing Playfab Storage For Network Descriptors

The following functions in PlayFabManager.cpp are used to set and get the descriptor from playfab.

Setting the descriptor:

The descriptor is saved by the title using the
save_network_descriptor call above. The network descriptor from
the created network and a room id are passed to the cloud
script as parameters. the roomId is synonamous with the network
invite identifier and the network id from the room drop down
menu. This call is implemented in the PlayFabManager class and
accepts a callback function that is issued on completion of the attempt.

```C++
void 
PartySample::PlayFabManager::SetDescriptor(
    std::string key, 
    std::string descriptor, 
    std::function<void()> onComplete
    )
{
    m_onCompletedSettingDescriptor = onComplete;

    // Create data indicating to network Id as a key and the descriptor as a value to be stored on the title group storage.
    Json::Value param;
    param["roomId"] = key;
    param["networkDescriptor"] = descriptor;

    // Create the save network descriptor cloud script call using the above data.
    ClientModels::ExecuteCloudScriptRequest request;
    request.FunctionName = "save_network_descriptor";
    request.FunctionParameter = param;

    // Put a message in the chat window indicating that the descriptor is being saved
    char messageBuffer[500];
    sprintf(messageBuffer, "Saving out network data: %s.", descriptor.c_str());
    std::string sender("System");
    std::string message(messageBuffer);
    Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

    // Execute the above cloud script.
    PlayFabClientAPI::ExecuteCloudScript(request, onSetDescriptorSuccessCallback, onSetDescriptorFailCallback);
}
```

Getting the Network Descriptor from Playfab:

This function calls get_network_descriptor above with the
roomId as a parameter. From the demo app, this is the room
drop down id and the invite id. It is implemented in the
PlayfabManager class and accepts a callback with a string
parameter, where the string is the retreived descriptor. If no
descriptor was found or an error occured, the callback is
issued with an empty string.

```C++
void 
PartySample::PlayFabManager::GetDescriptor(
	std::string key, 
	std::function<void(std::string)> onComplete
	)
{
	// Set the completion callback.
	m_onCompletedGettingDescriptor = onComplete;

	// Set the network id that we are using to identify which descriptor we want.
	Json::Value param;
	param["roomId"] = key;

	// Create a network request to get the network descriptor with the above key.
	ClientModels::ExecuteCloudScriptRequest request;
	request.FunctionName = "get_network_descriptor";
	request.FunctionParameter = param;

	//Execute the cloud script.
	PlayFabClientAPI::ExecuteCloudScript(request, onGetObjectSuccessCallback, onGetObjectFailCallback);
}
```



