package com.microsoft.playfab.partysample.demo;

import android.app.Activity;
import android.app.Dialog;
import android.os.AsyncTask;
import android.os.Handler;
import android.os.Message;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.microsoft.playfab.partysample.adapter.MemberAdapter;
import com.microsoft.playfab.partysample.adapter.MessageAdapter;
import com.microsoft.playfab.partysample.model.ChatMember;
import com.microsoft.playfab.partysample.model.ChatMessage;
import com.microsoft.playfab.partysample.sdk.MessageManager;
import com.microsoft.playfab.partysample.sdk.NetworkManager;

import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class ChatActivity extends AppCompatActivity {

    private RecyclerView memberRecyclerView;
    private RecyclerView messageRecyclerView;

    private Spinner roomSpinner;
    private Spinner languageSpinner;

    private Button btnCreate;
    private Button btnJoin;
    private Button btnLeave;
    private long lastBackPressedAt = 0;
    private Switch ttsSwitch;
    private Button btnHeyTeam;
    private Button btnImScared;
    private Button btnGoodLuck;

    private ConstraintLayout progressLayout;
    private TextView progressText;

    private List<ChatMember> members;
    private MemberAdapter memberAdapter;
    private List<ChatMessage> messages;
    private MessageAdapter messageAdapter;

    private String memberName;
    private String memberId;

    private Handler messageHandler;
    private NetworkManager networkManager;

    PartyInitializeTask partyInitializeTask;
    Timer partyWorkTimer;
    Timer playerStateTimer;

    String networkType;
    boolean isCreate = false;
    String languageCode;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_chat);

        getSupportActionBar().hide();

        memberId = getIntent().getStringExtra("name");
        memberName = memberId;

        btnCreate = findViewById(R.id.btnCreate);
        btnJoin = findViewById(R.id.btnJoin);
        btnLeave = findViewById(R.id.btnLeave);
        btnHeyTeam = findViewById(R.id.btnHieyTeam);
        btnImScared = findViewById(R.id.btnImScared);
        btnGoodLuck = findViewById(R.id.btnGoodLuck);

        ttsSwitch = findViewById(R.id.switchTTS);

        ttsSwitch.setChecked(true);

        progressLayout = findViewById(R.id.progressLayout);
        progressText = findViewById(R.id.progressText);

        roomSpinner = findViewById(R.id.roomSpinner);

        languageSpinner = findViewById(R.id.languageSpinner);

        // This is the index of the en-us option in languages.xml
        // Used as the default option to be selected.
        final int englishUsLanguageOptionIndex = 12;

        languageSpinner.setSelection(englishUsLanguageOptionIndex);
        Spinner t = (Spinner)languageSpinner;
        t.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                networkManager.setLanguage(position);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                // No action
            }
        });

        setChatConnected(false);

        View.OnTouchListener onTouchListener = new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                v.requestFocusFromTouch();
                return false;
            }
        };

        memberRecyclerView = findViewById(R.id.memberRecyclerView);

        memberRecyclerView.setDescendantFocusability(ViewGroup.FOCUS_BEFORE_DESCENDANTS);
        memberRecyclerView.setFocusable(true);
        memberRecyclerView.setFocusableInTouchMode(true);
        memberRecyclerView.setOnTouchListener(onTouchListener);

        initMembers();
        memberAdapter = new MemberAdapter(members);
        memberRecyclerView.setAdapter(memberAdapter);

        LinearLayoutManager memberLayoutManager = new LinearLayoutManager(this);
        memberLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        memberRecyclerView.addItemDecoration(new DividerItemDecoration(this,DividerItemDecoration.VERTICAL));
        memberRecyclerView.setLayoutManager(memberLayoutManager);

        messageRecyclerView = findViewById(R.id.msgRecyclerView);

        messageRecyclerView.setDescendantFocusability(ViewGroup.FOCUS_BEFORE_DESCENDANTS);
        messageRecyclerView.setFocusable(true);
        messageRecyclerView.setFocusableInTouchMode(true);
        messageRecyclerView.setOnTouchListener(onTouchListener);

        messages = new ArrayList<>();
        messageAdapter = new MessageAdapter(messages);
        messageRecyclerView.setAdapter(messageAdapter);
        LinearLayoutManager messageLayoutManager = new LinearLayoutManager(this);
        messageLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        messageRecyclerView.setLayoutManager(messageLayoutManager);

        initManagers();

        partyWorkTimer = new Timer("party-work");
        playerStateTimer = new Timer("party-state");

        partyInitializeTask = new PartyInitializeTask(this);
        partyInitializeTask.execute(NetworkManager.getInstance());
    }

    @Override
    public void onBackPressed() {
        long now = System.currentTimeMillis();
        if (lastBackPressedAt + 2000 > now) {
            exitApp();
        } else {
            Toast.makeText(this, "Press again to exit", Toast.LENGTH_SHORT).show();
        }

        lastBackPressedAt = now;
    }

    public void initManagers() {
        networkManager = NetworkManager.getInstance();
        networkManager.setPlayFabTitleID(getIntent().getStringExtra(MainActivity.cCachedPlayFabTitleIDKey));
        messageHandler = new MessageHandler();
        MessageManager.getInstance().setHandler(messageHandler);
    }

    public void initMembers() {
        members = new ArrayList<>();
        ChatMember member = new ChatMember();
        member.setId(memberId);
        member.setName(memberName);
        member.setCurrent(true);
        members.add(member);
    }

    public void onBtnCreateClick(View view) {
        Log.d("chat", "create");

        isCreate = true;
        networkType = roomSpinner.getSelectedItem().toString().trim();
        languageCode = Integer.toString(languageSpinner.getSelectedItemPosition());

        CreateChatTask task = new CreateChatTask();
        task.execute(networkType, languageCode);
    }

    public void onBtnJoinClick(View view) {
        Log.d("chat", "join");

        networkType = roomSpinner.getSelectedItem().toString().trim();

        isCreate = false;

        JoinChatTask task = new JoinChatTask();
        task.execute(networkType);
    }

    public void onQucikMsgBtnClick(View view) {

        Button button = (Button) view;
        String text = button.getText().toString();
        Log.d("chat", "quick send: " + text);

        boolean isTTS = ttsSwitch.isChecked();

        sendMessage(memberName, text, isTTS);
    }

    public void onBtnLeaveClick(View view) {
        Log.d("chat", "leave");

        leaveChat();
    }

    public Dialog createLoadingDialog(String msg) {
        LayoutInflater inflater = getLayoutInflater();
        View v = inflater.inflate(R.layout.loading_dialog, null);
        LinearLayout layout = v.findViewById(R.id.loading_layout);
        TextView tipTextView = v.findViewById(R.id.tipTextView);
        tipTextView.setText(msg);

        Dialog loadingDialog = new Dialog(this, R.style.loadingDialog);
        loadingDialog.setCancelable(false);
        loadingDialog.setContentView(layout, new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT,
            LinearLayout.LayoutParams.MATCH_PARENT));
        return loadingDialog;
    }

    public void sendMessage(String name, final String msg, final boolean isTTS) {
        // Call sendTextMessage in a new thread to separate UI thread and SDK call thread
        new Thread() {
            public void run() {
                networkManager.sendTextMessage(msg, isTTS);
            }
        }.start();

        messageAdapter.addMessage(name, msg);
        messageRecyclerView.post(new Runnable() {
            @Override
            public void run() {
                messageRecyclerView.scrollToPosition(messageRecyclerView.getAdapter().getItemCount() - 1);
            }
        });
    }

    public void leaveChat() {
        LeaveChatTask leaveChatTask = new LeaveChatTask(this);
        leaveChatTask.execute(networkManager);
    }

    public void exitApp() {
        LeaveChatTask leaveChatTask = new LeaveChatTask(this);
        leaveChatTask.setExit(true);
        leaveChatTask.execute(networkManager);
    }

    public void resetMessage() {
        messageAdapter.clear();
    }

    public void resetChat() {
        setChatConnected(false);

        networkType = null;

        if (playerStateTimer != null) {
            playerStateTimer.cancel();
            playerStateTimer = null;
        }

        memberAdapter.clear();
    }

    public void setChatConnected(boolean isConnected) {
        btnCreate.setEnabled(!isConnected);
        btnJoin.setEnabled(!isConnected);
        btnLeave.setEnabled(isConnected);
        btnHeyTeam.setEnabled(isConnected);
        btnImScared.setEnabled(isConnected);
        btnGoodLuck.setEnabled(isConnected);
        roomSpinner.setEnabled(!isConnected);
        languageSpinner.setEnabled(!isConnected);
    }

    public synchronized void updatePlayerState() {
        if (playerStateTimer != null) {
            playerStateTimer.cancel();
        }
        playerStateTimer = new Timer("party-state");
        playerStateTimer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                networkManager.getPlayerState();
            }
        }, 100, 800);
    }

    private class PartyInitializeTask extends AsyncTask<NetworkManager, Integer, Integer> {

        private Activity activity;

        public PartyInitializeTask(Activity activity) {
            this.activity = activity;
        }

        @Override
        protected void onPreExecute() {
            progressText.setText(R.string.progress_initializing);
            progressLayout.setVisibility(View.VISIBLE);
        }

        @Override
        protected Integer doInBackground(NetworkManager... networkManagers) {
            final NetworkManager networkManager = networkManagers[0];
            if (!networkManager.initialize(memberId)) {
                return 1;
            }

            partyWorkTimer.scheduleAtFixedRate(new TimerTask() {
                @Override
                public void run() {
                    networkManager.doWork();
                }
            }, 200, 800);

            return 0;
        }

        @Override
        protected void onPostExecute(Integer integer) {
            progressLayout.setVisibility(View.GONE);

            if (integer.equals(1)) {
                Toast.makeText(activity, "Initialize failed!", Toast.LENGTH_LONG).show();
                activity.finish();
            }
        }
    }

    class LeaveChatTask extends AsyncTask<NetworkManager, Integer, Integer> {

        private Activity activity;
        private boolean isExit;

        public LeaveChatTask(Activity activity) {
            this.activity = activity;
            isExit = false;
        }

        public void setExit(boolean exit) {
            isExit = exit;
        }

        @Override
        protected void onPreExecute() {
            progressText.setText(R.string.progress_leaving);
            progressLayout.setVisibility(View.VISIBLE);
        }

        @Override
        protected Integer doInBackground(NetworkManager... networkManagers) {
            final NetworkManager networkManager = networkManagers[0];

            Log.d("chat", "doInBackground ");
            networkManager.leaveNetwork();

            return 0;
        }

        @Override
        protected void onPostExecute(Integer integer) {
            Log.d("chat", "onPostExecute " + integer);

            if (integer.equals(0)) {
                partyInitializeTask.cancel(false);

                resetChat();

                progressLayout.setVisibility(View.GONE);

                if (isExit) {
                    activity.finish();
                    moveTaskToBack(true);
                    android.os.Process.killProcess(android.os.Process.myPid());
                    System.exit(0);
                }
            }
        }
    }

    class CreateChatTask extends AsyncTask<String, Integer, Integer> {
        Dialog dialog;

        @Override
        protected void onPreExecute() {
            dialog = createLoadingDialog("Creating");
            dialog.show();
        }

        @Override
        protected Integer doInBackground(String... params) {
            String networkId = params[0];
            String languageCode = params[1];
            if(networkManager.createAndConnectToNetwork(networkId, languageCode))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        @Override
        protected void onPostExecute(Integer integer) {
            if(integer == 1) {
                setChatConnected(true);
            }
            dialog.cancel();
        }
    }

    class JoinChatTask extends AsyncTask<String, Integer, Integer> {
        Dialog dialog;

        @Override
        protected void onPreExecute() {
            dialog = createLoadingDialog("Joining");
            dialog.show();
        }

        @Override
        protected Integer doInBackground(String... networkIds) {
            String networkId = networkIds[0];

            if(networkManager.joinNetwork(networkId)) {
                return 1;
            }
            else {
                return 0;
            }
        }

        @Override
        protected void onPostExecute(Integer integer) {
            if(integer == 1) {
                setChatConnected(true);
            }
            dialog.cancel();
        }
    }

    class MessageHandler extends Handler {
        @Override
        public void handleMessage(Message msg) {
            Log.d("chat", "handleMessage");

            Bundle data = msg.getData();
            switch (msg.what) {
                case MessageManager.MSG_NETWORK_CREATED: {
                    String networkID = data.getString("network");

                    updatePlayerState();
                    setChatConnected(true);
                    break;
                }
                case MessageManager.MSG_TEXT_RECEIVED: {
                    String playerId = data.getString("playerId");
                    String text = data.getString("text");
                    boolean isTranscriptor = data.getBoolean("isTranscriptor");
                    String name = playerId;
                    if (!memberId.equals(playerId)) {
                        String tag = isTranscriptor ? "Transcript" : "Text";
                        name += " [" + tag + "]:";
                    }
                    messageAdapter.addMessage(name, text);

                    messageRecyclerView.post(new Runnable() {
                        @Override
                        public void run() {
                        messageRecyclerView.scrollToPosition(messageRecyclerView.getAdapter().getItemCount() - 1);
                        }
                    });

                    break;
                }
                case MessageManager.MSG_PLAYER_JOIN: {
                    String playerId = data.getString("playerId");
                    String name = data.getString("name");
                    if (memberId.equals(playerId)) {
                        break;
                    }
                    memberAdapter.addMember(playerId, name);

                    break;
                }
                case MessageManager.MSG_PLAYER_LEFT: {
                    String playerId = data.getString("playerId");
                    if (memberId.equals(playerId)) {
                        break;
                    }
                    memberAdapter.removeMember(playerId);
                    break;
                }
                case MessageManager.MSG_PLAYER_STATUS: {
                    String playerId = data.getString("playerId");
                    String state = data.getString("state");
                    memberAdapter.updateMemberState(playerId, state);
                    break;
                }
                case MessageManager.MSG_TOAST_MSG: {
                    String text = data.getString("text");
                    Toast.makeText(getApplicationContext(), text, Toast.LENGTH_LONG).show();
                    break;
                }
                case MessageManager.MSG_RESET_CHAT: {
                    String error = data.getString("error");
                    if(error == "Left") {
                        resetMessage();
                    }
                    else {
                        Toast.makeText(getApplicationContext(), error, Toast.LENGTH_LONG).show();

                        resetChat();
                        break;
                    }
                }
                case MessageManager.MSG_ERROR: {
                    String text = data.getString("error");
                    String name = "System [Text]:";
                    messageAdapter.addMessage(name, text);

                    messageRecyclerView.post(new Runnable() {
                        @Override
                        public void run() {
                            messageRecyclerView.scrollToPosition(messageRecyclerView.getAdapter().getItemCount() - 1);
                        }
                    });
                    break;
                }
                case MessageManager.MSG_LEAVE: {
                    Log.d("chat", "leave");

                    leaveChat();
                    break;
                }
            }
        }
    }
}
