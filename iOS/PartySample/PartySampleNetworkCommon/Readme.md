### PlayFab Configuration

This sample requires the title be configured for Party on the Multiplayer tab of Game Manager and relies on the following settings being configured in the PlayFab developer portal.

**Multiplayer Server Builds**

A server build has to be running for at least one region.
An empty zip file can be uploaded as the server build assets, 
and the build itself doesn't have to deploy healthily as long 
as the region is defined to have servers available.

**Cloud Script**

The following cloud script is required:

```javascript
//
// Used to store a network descriptor on the server retrievable by the roomId
// Inputs:
//    roomId - The hash key used to store and retrieve the network descriptor.
//    networkDescriptor - The network descriptor used to connect to a party network.
//
handlers.save_network_descriptor = function (args, context) 
{
  if (args && args.hasOwnProperty("roomId"))
  {
    var roomId = args.roomId;
  }
  else
  {
    return;
  }
  
  if (args && args.hasOwnProperty("networkDescriptor"))
  {
    var networkDescriptor = args.networkDescriptor;
  }
  else
  {
    return;
  }
  
  try {
    server.CreateSharedGroup({ SharedGroupId: roomId });
  } catch(err) {
    log.info("Shared group " + roomId + " already exists.");
    log.error(err);
  }

  var updateRequest = {
    SharedGroupId: roomId,
    Data: {
      "network": networkDescriptor
    }
  };

  server.UpdateSharedGroupData(updateRequest);
};

//
// Used to retrieve a previously stored network descriptor by roomId.
// Inputs:
//    roomId - The hash key used to store and retrieve the network descriptor.
//
handlers.get_network_descriptor = function (args, context) 
{
  if (args && args.hasOwnProperty("roomId"))
  {
    var roomId = args.roomId;
  }
  else
  {
    return;
  }
  
  try 
  {
    var getRes = server.GetSharedGroupData({ SharedGroupId: roomId });
    return getRes.Data;
  } 
  catch(err) 
  {
    return;
  }
};
```

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



