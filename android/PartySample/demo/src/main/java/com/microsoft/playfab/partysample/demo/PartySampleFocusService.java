package com.microsoft.playfab.partysample.demo;

import android.app.Service;
import android.content.Intent;
import android.media.AudioAttributes;
import android.media.AudioFocusRequest;
import android.media.AudioManager;
import android.os.Binder;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.util.Log;


// A note to library consumers: In order to be a well-behaving audio application on Android, your
// application is expected to both request audio focus as needed and handle notifications for audio
// focus loss. This class is provided as an example for how to cooperatively respond to focus
// changes when using this library.  In this case, when losing focus we disconnect the audio input
// because it frees up contentious microphone resources under the hood, thereby allowing other
// applications to properly initialize their own resources and offer the best possible user experience.
// For more information on handling audio focus for Android, please see their documentation here:
// https://developer.android.com/guide/topics/media-apps/audio-focus
public class PartySampleFocusService extends Service {


    private AudioManager mAudioManager;
    private AudioFocusRequest mFocusRequest;
    private boolean mHasFocus = true;

    @Override
    public void onCreate() {
        super.onCreate();
        mAudioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
        Log.d("AudioFocusService", "After onNativeSetFocusService");
    }

    AudioManager.OnAudioFocusChangeListener audioFocusChangeListener = new AudioManager.OnAudioFocusChangeListener() {
        public void onAudioFocusChange(int focusChange) {

            switch (focusChange) {
                case AudioManager.AUDIOFOCUS_GAIN:
                    Log.d("AudioFocusService", "AUDIOFOCUS_GAIN");
                    mHasFocus = true;
                    connectAudioInput();
                    break;
                case AudioManager.AUDIOFOCUS_LOSS:
                    Log.d("AudioFocusService", "AUDIOFOCUS_LOSS");
                    mHasFocus = false;
                    disconnectAudioInput();
                    break;
                case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT:
                    Log.d("AudioFocusService", "AUDIOFOCUS_LOSS_TRANSIENT");
                    mHasFocus = false;
                    disconnectAudioInput();
                    break;
                case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK:
                    Log.d("AudioFocusService", "AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK");
                    mHasFocus = false;
                    disconnectAudioInput();
                    break;
            }
        }
    };

    public boolean requestFocus() {
        // Request audio focus for playback
        int result;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O)  {
            mFocusRequest =  new AudioFocusRequest.Builder(AudioManager.AUDIOFOCUS_GAIN)
                    .setAudioAttributes(
                            new AudioAttributes.Builder()
                                    .setLegacyStreamType(AudioAttributes.CONTENT_TYPE_SPEECH)
                                    .build())
                    .setOnAudioFocusChangeListener(audioFocusChangeListener)
                    .build();
            result = mAudioManager.requestAudioFocus(mFocusRequest);
        } else {
            result = mAudioManager.requestAudioFocus(audioFocusChangeListener,
                    // Use default stream type.
                    AudioManager.STREAM_VOICE_CALL,
                    // Request permanent focus.
                    AudioManager.AUDIOFOCUS_GAIN);
        }
        mHasFocus = result == AudioManager.AUDIOFOCUS_REQUEST_GRANTED;
        return mHasFocus;
    }

    public void abandonFocus() {
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            if (mFocusRequest != null) {
                mAudioManager.abandonAudioFocusRequest(mFocusRequest);
            }
        }
        else {
            mAudioManager.abandonAudioFocus(audioFocusChangeListener);
        }
    }

    public boolean hasFocus() {
        return mHasFocus;
    }

    IBinder mBinder = new LocalBinder();

    public class LocalBinder extends Binder {
        public PartySampleFocusService getServiceInstance() {
            return PartySampleFocusService.this;
        }
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return mBinder;
    }


  public native void disconnectAudioInput();
  public native void connectAudioInput();
}
