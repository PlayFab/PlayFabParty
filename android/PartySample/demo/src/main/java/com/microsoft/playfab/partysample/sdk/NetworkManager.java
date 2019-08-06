package com.microsoft.playfab.partysample.sdk;

import android.util.Log;
import android.widget.Toast;

public class NetworkManager {
    static {
        System.loadLibrary("partysample");
    }

    private MessageManager messageManager;

    private static NetworkManager networkManager;

    private NetworkManager() {
    }

    public static NetworkManager getInstance() {
        if (networkManager == null) {
            networkManager = new NetworkManager();
        }
        return networkManager;
    }

    public native boolean initialize(String name);

    public native boolean createAndConnectToNetwork(String type, String languageCode);

    public native boolean joinNetwork(String networkId);

    public native void leaveNetwork();

    public native void sendTextMessage(String message, boolean isTTS);

    public native void doWork();

    public native void getPlayerState();

    public native void setLanguage(int idx);

    public native void setPlayFabTitleID(String titleID);

    public native void setPlayerVolume(float zeroToOne);

    public native boolean connectedToNetwork();

    public void onNetworkCreated(String network) {
        Log.d(getClass().getSimpleName(), "onNetworkCreated: " + network);
        getMessageManager().sendNetworkCreatedMessage(network);
        getMessageManager().sendErrorMessage("Connected to network: " + network);
    }

    public void onMessageReceived(String sender, String message) {
        Log.d(getClass().getSimpleName(), "onMessageReceived: " + sender + ": " + message);
        getMessageManager().sendTextMsgReceivedMessage(sender, message, false);
    }

    public void onTranscriptMessageReceived(String sender, String message) {
        Log.d(getClass().getSimpleName(), "onTranscriptMessageReceived: " + sender + ": " + message);
        getMessageManager().sendTextMsgReceivedMessage(sender, message, true);
    }

    public void onPlayerJoined(String playerId, String name) {
        Log.d(getClass().getSimpleName(), "onPlayerJoined: " + playerId + ": " + name);
        getMessageManager().sendPlayerJoinMessage(playerId, name);
    }

    public void onPlayerLeft(String playerId) {
        Log.d(getClass().getSimpleName(), "onPlayerLeft: " + playerId);
        getMessageManager().sendPlayerLeftMessage(playerId);
    }

    public void toastMessage(String message) {
        getMessageManager().toastMessage(message);
    }

    public void resetChat(String error) {
        getMessageManager().sendResetMessage(error);
    }
    public void resetMessage() {
        getMessageManager().sendResetMessage("Left");
    }

    public void addErrorMessage(String message) {
        getMessageManager().sendErrorMessage(message);
    }

    /**
     *
     * @param playerId
     * @param state : muted, slient, talking
     */
    public void updatePlayerState(String playerId, String state) {
        Log.d(getClass().getSimpleName(), "updatePlayerState: " + playerId + ": " + state);
        getMessageManager().sendPlayerStatusMessage(playerId, state);
    }

    public MessageManager getMessageManager() {
        return MessageManager.getInstance();
    }

}
