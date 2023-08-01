package com.microsoft.playfab.partysample.model;

public class ChatMember {

    public static final String STATE_MUTED = "muted";
    public static final String STATE_SILENT = "silent";
    public static final String STATE_TALKING = "talking";

    String id;
    String name;
    boolean isTalking;
    int voiceLevel;
    boolean isCurrent;
    boolean isMute;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getVoiceLevel() {
        return voiceLevel;
    }

    public void setVoiceLevel(int voiceLevel) {
        this.voiceLevel = voiceLevel;
    }

    public boolean isCurrent() {
        return isCurrent;
    }

    public void setCurrent(boolean current) {
        isCurrent = current;
    }

    public boolean isMute() {
        return isMute;
    }

    public void setMute(boolean mute) {
        isMute = mute;
    }

    public boolean isTalking() {
        return isTalking;
    }

    public void setTalking(boolean talking) {
        isTalking = talking;
    }
}
