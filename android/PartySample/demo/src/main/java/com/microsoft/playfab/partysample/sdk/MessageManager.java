package com.microsoft.playfab.partysample.sdk;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

public class MessageManager {

    public static final int MSG_NETWORK_CREATED = 1;
    public static final int MSG_PLAYER_JOIN = 2;
    public static final int MSG_PLAYER_LEFT = 3;
    public static final int MSG_PLAYER_STATUS = 4;
    public static final int MSG_TEXT_RECEIVED = 5;
    public static final int MSG_TOAST_MSG = 6;
    public static final int MSG_RESET_CHAT = 7;
    public static final int MSG_ERROR = 8;
    public static final int MSG_LEAVE = 9;

    private static MessageManager messageManager;

    private MessageManager() {
    }

    public static MessageManager getInstance() {
        if (messageManager == null) {
            messageManager = new MessageManager();
        }
        return messageManager;
    }

    private Handler handler;

    public Handler getHandler() {
        return handler;
    }

    public void setHandler(Handler handler) {
        this.handler = handler;
    }


    public void sendNetworkCreatedMessage(String network) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("network", network);
        message.setData(data);
        message.what = MSG_NETWORK_CREATED;
        handler.sendMessage(message);
    }

    public void sendPlayerJoinMessage(String playerId, String name) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("playerId", playerId);
        data.putString("name", name);
        message.setData(data);
        message.what = MSG_PLAYER_JOIN;
        handler.sendMessage(message);
    }

    public void sendPlayerLeftMessage(String playerId) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("playerId", playerId);
        message.setData(data);
        message.what = MSG_PLAYER_LEFT;
        handler.sendMessage(message);
    }

    public void sendPlayerStatusMessage(String playerId, String state) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("playerId", playerId);
        data.putString("state", state);
        message.setData(data);
        message.what = MSG_PLAYER_STATUS;
        handler.sendMessage(message);
    }

    public void sendTextMsgReceivedMessage(String playerId, String text, boolean isTranscriptor) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("playerId", playerId);
        data.putString("text", text);
        data.putBoolean("isTranscriptor", isTranscriptor);
        message.setData(data);
        message.what = MSG_TEXT_RECEIVED;
        handler.sendMessage(message);
    }

    public void toastMessage(String text) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("text", text);
        message.setData(data);
        message.what = MSG_TOAST_MSG;
        handler.sendMessage(message);
    }

    public void sendResetMessage(String error) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("error", error);
        message.setData(data);
        message.what = MSG_RESET_CHAT;
        handler.sendMessage(message);
    }

    public void sendErrorMessage(String error) {
        Message message = new Message();
        Bundle data = new Bundle();
        data.putString("error", error);
        message.setData(data);
        message.what = MSG_ERROR;
        handler.sendMessage(message);
    }

    public void sendLeaveMessage() {
        Message message = new Message();
        message.what = MSG_LEAVE;
        handler.sendMessage(message);
    }
}
