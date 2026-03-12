package com.microsoft.playfab.partysample.demo;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.ScrollView;
import android.text.method.ScrollingMovementMethod;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;

import com.microsoft.playfab.partysample.sdk.NetworkManager;

import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {

    public static final String cCachedPlayFabTitleIDKey = "cached_playfab_title_id";
    
    private Button btnConnectPlayFab;
    private Button btnInitializeParty;
    private TextView tvLogs;
    private ScrollView scrollView;
    private NetworkManager networkManager;
    private Timer doWorkTimer;
    private boolean isDoWorkRunning = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views
        btnConnectPlayFab = findViewById(R.id.btn_connect_playfab);
        btnInitializeParty = findViewById(R.id.btn_initialize_party);
        tvLogs = findViewById(R.id.tv_logs);
        scrollView = findViewById(R.id.scroll_view);
        
        tvLogs.setMovementMethod(new ScrollingMovementMethod());
        
        networkManager = NetworkManager.getInstance();
        NetworkManager.setMainActivity(this);  // Set reference for logging
        
        // Set PlayFab Title ID (hardcoded for simplicity - change to your title ID)
        String titleId = "E9302";
        networkManager.setPlayFabTitleID(titleId);
        
        // Save title ID to preferences for ChatActivity
        SharedPreferences.Editor prefEditor = PreferenceManager.getDefaultSharedPreferences(this).edit();
        prefEditor.putString(cCachedPlayFabTitleIDKey, titleId);
        prefEditor.apply();
        
        // Button 1: Connect to PlayFab (optional - tests with WiFi)
        btnConnectPlayFab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addLog("=== Attempting PlayFab Login ===");
                btnConnectPlayFab.setEnabled(false);
                
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        final boolean success = networkManager.connectToPlayFab("test_user_" + System.currentTimeMillis());
                        
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (success) {
                                    addLog("PlayFab connection started (check logs for result)");
                                } else {
                                    addLog("PlayFab connection initiation failed");
                                }
                                btnConnectPlayFab.setEnabled(true);
                            }
                        });
                    }
                }).start();
            }
        });
        
        // Button 2: Initialize Party (works with or without WiFi)
        btnInitializeParty.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addLog("=== Initializing PartyManager ===");
                btnInitializeParty.setEnabled(false);
                
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        final boolean success = networkManager.initializePartyManager();
                        
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (success) {
                                    addLog("PartyManager initialized successfully");
                                    addLog("Watching for RegionsChanged event...");
                                    startDoWorkTimer();
                                } else {
                                    addLog("PartyManager initialization failed");
                                }
                                btnInitializeParty.setEnabled(true);
                            }
                        });
                    }
                }).start();
            }
        });
        
        addLog("=== Party RegionsChanged Test ===");
        addLog("1. Press 'Connect to PlayFab' (optional - requires WiFi)");
        addLog("2. Press 'Initialize Party' to trigger RegionsChanged");
        addLog("3. Watch for 'Region changed' message");
        addLog("");
    }

    private void startDoWorkTimer() {
        if (isDoWorkRunning) {
            return;
        }
        
        isDoWorkRunning = true;
        doWorkTimer = new Timer("party-dowork");
        doWorkTimer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                networkManager.doWork();
            }
        }, 100, 500);  // Check every 500ms
        
        addLog("DoWork timer started");
    }

    public void addLog(final String message) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                tvLogs.append(message + "\n");
                scrollView.post(new Runnable() {
                    @Override
                    public void run() {
                        scrollView.fullScroll(View.FOCUS_DOWN);
                    }
                });
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (doWorkTimer != null) {
            doWorkTimer.cancel();
        }
    }
}
