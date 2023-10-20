package com.microsoft.playfab.partysample.demo;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.preference.PreferenceManager;
import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.widget.EditText;
import android.widget.TextView;
import android.content.SharedPreferences;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    static final int AUDIO_PERMISSION_REQUEST_CODE = 10;
    public static final String cCachedPlayFabTitleIDKey = "cached_playfab_title_id";
    private boolean hasPermission;
    EditText titleIdEditText;
    TextView titleIdWarningTextView;
    ArrayList<Button> buttons;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        loadButtons();
        configureTitleIDEditor();
        tryLoadCachedTitleID();

        checkPermissions();
    }

    private void configureTitleIDEditor() {
        titleIdEditText = (EditText)findViewById(R.id.editText_TitleID);
        titleIdWarningTextView = (TextView)findViewById(R.id.textView_TitleIDWarning);
        titleIdEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) { }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                if(s.length() == 0) {
                    onInvalidTitleID();
                }
                else {
                    cacheTitleID(s.toString());
                    onValidTitleID();
                }
            }

            @Override
            public void afterTextChanged(Editable s) { }
        });
    }

    private void cacheTitleID(String s) {
        SharedPreferences.Editor prefEditor = PreferenceManager.getDefaultSharedPreferences(MainActivity.this).edit();
        prefEditor.putString(cCachedPlayFabTitleIDKey, s);
        prefEditor.commit();
    }

    private void onInvalidTitleID() {
        titleIdWarningTextView.setText("PlayFab title ID must be populated");
        enableButtons(false);
    }

    private void onValidTitleID() {
        titleIdWarningTextView.setText("");
        enableButtons(true);
    }

    private void tryLoadCachedTitleID() {
        SharedPreferences myPreferences
                = PreferenceManager.getDefaultSharedPreferences(MainActivity.this);

        String titleID = myPreferences.getString(cCachedPlayFabTitleIDKey, "");
        if(titleID.length() > 0) {
            titleIdEditText.getText().clear();
            titleIdEditText.getText().append(titleID);
            onValidTitleID();
        } else if(titleIdEditText.getText().length() > 0) {
            cacheTitleID(titleIdEditText.getText().toString());
            onValidTitleID();
        } else {
            onInvalidTitleID();
        }
    }

    private void loadButtons() {
        buttons = new ArrayList<>();
        buttons.add((Button)findViewById(R.id.btnUser1));
        buttons.add((Button)findViewById(R.id.btnUser2));
        buttons.add((Button)findViewById(R.id.btnUser3));
        buttons.add((Button)findViewById(R.id.btnUser4));

    }

    private void enableButtons(Boolean enable) {
        for(Button btn : buttons) {
            btn.setEnabled(enable);
            if(enable) {
                btn.getBackground().setAlpha(255);
            } else {
                btn.getBackground().setAlpha(50);
            }
        }
    }

    public void onBtnUserClicked(View view) {
        if (!hasPermission) {
            Toast.makeText(this, "Please grant audio permission for app", Toast.LENGTH_SHORT).show();
            return;
        }

        Button button = (Button)view;

        Intent intent = new Intent(this, ChatActivity.class);
        intent.putExtra("name", button.getText());
        intent.putExtra(cCachedPlayFabTitleIDKey, titleIdEditText.getText().toString());
        startActivity(intent);
    }

    public void checkPermissions() {
        requestPermission(new String[] {
                Manifest.permission.RECORD_AUDIO,
                Manifest.permission.READ_EXTERNAL_STORAGE,
                Manifest.permission.WRITE_EXTERNAL_STORAGE,
                Manifest.permission.BLUETOOTH_SCAN,
                Manifest.permission.BLUETOOTH_CONNECT,
                Manifest.permission.MODIFY_AUDIO_SETTINGS },
                AUDIO_PERMISSION_REQUEST_CODE
        );
    }

    public void requestPermission(String[] permission, int requestCode ) {
        hasPermission = true;
        for (String p : permission) {
            if (!hasPermission(p)) {
                hasPermission = false;
                if (ActivityCompat.shouldShowRequestPermissionRationale(this, p)) {
                    Toast.makeText(this, "Missing Permission: " + p, Toast.LENGTH_SHORT).show();
                }
            }
        }

        if (!hasPermission) {
            ActivityCompat.requestPermissions(this,
                    permission,
                    requestCode);
        }
    }

    public boolean hasPermission(String permission) {
        return ContextCompat.checkSelfPermission(this, permission) == PackageManager.PERMISSION_GRANTED;
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        switch (requestCode) {
            case AUDIO_PERMISSION_REQUEST_CODE: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    hasPermission = true;
                } else {
                    hasPermission = false;
                }
                break;
            }
        }
    }
}
