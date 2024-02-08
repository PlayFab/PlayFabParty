using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows;
using System.Windows.Threading;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;
using System.Runtime.InteropServices;
using System.ComponentModel;

namespace PartySample
{
    public class LogEntry
    {
        public LogEntry(string source, string message)
        {
            this.Source = source;
            this.Message = message;
        }

        public string Source { get; }
        public string Message { get; }
    }

    public class PlayerEntry : System.ComponentModel.INotifyPropertyChanged
    {
        public PlayerEntry(string entityId, string displayName)
        {
            this.EntityId = entityId;
            this.DisplayName = displayName;
            this.ChatIndicator = "";
            this.LastMessage = "";
            this.IsMuted = false;
        }

        public string EntityId { get; }
        public string DisplayName { get; }
        public string ChatIndicator
        {
            get
            {
                return this._chatIndicator;
            }
            set
            {
                this._chatIndicator = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ChatIndicator"));
            }
        }

        public string LastMessage
        {
            get
            {
                return this._lastMessage;
            }
            set
            {
                this._lastMessage = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("LastMessage"));
            }
        }

        public bool IsMuted
        {
            get
            {
                return this._isMuted;
            }
            set
            {
                this._isMuted = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("MuteButtonText"));
            }
        }

        public string MuteButtonText
        {
            get
            {
                // This button functions as a toggle.
                // If we're muted, the button is an unmute button.
                // If we're not muted, the button is a mute button.
                return this._isMuted ? "🔊" : "🔇";
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private string _chatIndicator;
        private string _lastMessage;
        private bool _isMuted;
    }

    /// <summary>
    /// Interaction logic for PartySamplePage.xaml
    /// </summary>
    public partial class PartySamplePage : Page
    {
        // Log entries passed from the C++ app layer back to the C# GUI for presentation
        private ObservableCollection<LogEntry> logEntries;

        // A long running task to poll for new logs from the C++ sample app.
        private CancellationToken logPollingTaskCancellationToken;
        private Task logPollingTask;

        // A callback used by the C++ sample app to post new messages to log in the GUI.
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void LogCallback(
            [MarshalAs(UnmanagedType.LPStr)] string system,
            [MarshalAs(UnmanagedType.LPStr)] string message
            );
        private LogCallback logCallbackDelegate;

        // Player data passed from the C++ app layer back to the C# GUI for presentation
        private ObservableCollection<PlayerEntry> playerEntries;

        // Callbacks used by the C++ sample to update the UI with player changes
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void OnPlayerJoinedCallback(
            [MarshalAs(UnmanagedType.LPStr)] string entityId,
            [MarshalAs(UnmanagedType.LPStr)] string displayName
            );
        private OnPlayerJoinedCallback onPlayerJoinedDelegate;

        private delegate void OnPlayerChatIndicatorUpdatedCallback(
            [MarshalAs(UnmanagedType.LPStr)] string entityId,
            bool isLocalChatIndicator,
            Int32 chatIndicator
            );
        private OnPlayerChatIndicatorUpdatedCallback onPlayerChatIndicatorUpdatedDelegate;

        private delegate void OnPlayerTextMessageReceivedCallback(
            [MarshalAs(UnmanagedType.LPStr)] string senderEntityId,
            [MarshalAs(UnmanagedType.LPStr)] string message
            );
        private OnPlayerTextMessageReceivedCallback onPlayerTextMessageReceivedDelegate;

        private delegate void OnPlayerVoiceTranscriptionReceivedCallback(
            [MarshalAs(UnmanagedType.LPStr)] string speakerEntityId,
            [MarshalAs(UnmanagedType.LPStr)] string transcription
            );
        private OnPlayerVoiceTranscriptionReceivedCallback onPlayerVoiceTranscriptionReceivedDelegate;

        private delegate void OnPlayerLeftCallback(
            [MarshalAs(UnmanagedType.LPStr)] string entityId
            );
        private OnPlayerLeftCallback onPlayerLeftDelegate;

        public PartySamplePage(string titleId, string playFabPlayerCustomId)
        {
            InitializeComponent();

            this.TitleIdTextBlock.Text = "Party sample: " + titleId;

            this.logEntries = new ObservableCollection<LogEntry>();
            LogEntryList.ItemsSource = this.logEntries;

            this.playerEntries = new ObservableCollection<PlayerEntry>();
            PlayerList.ItemsSource = this.playerEntries;

            this.onPlayerJoinedDelegate = OnPlayerJoined;
            this.onPlayerChatIndicatorUpdatedDelegate = OnPlayerChatIndicatorUpdated;
            this.onPlayerTextMessageReceivedDelegate = OnPlayerTextMessageReceived;
            this.onPlayerVoiceTranscriptionReceivedDelegate = OnPlayerVoiceTranscriptionReceived;
            this.onPlayerLeftDelegate = OnPlayerLeft;

            PartySampleApp_Initialize(
                titleId,
                playFabPlayerCustomId,
                this.onPlayerJoinedDelegate,
                this.onPlayerChatIndicatorUpdatedDelegate,
                this.onPlayerTextMessageReceivedDelegate,
                this.onPlayerVoiceTranscriptionReceivedDelegate,
                this.onPlayerLeftDelegate);

            this.logPollingTaskCancellationToken = new CancellationTokenSource().Token;
            this.logPollingTask = Task.Factory.StartNew(
                PollForNewLogs,
                this.logPollingTaskCancellationToken,
                TaskCreationOptions.LongRunning,
                TaskScheduler.Default);

            this.logCallbackDelegate = LogNewMessage;
        }

        private void PollForNewLogs()
        {
            while (!this.logPollingTaskCancellationToken.IsCancellationRequested)
            {
                this.Dispatcher.Invoke(() =>
                {
                    PartySampleApp_PollLogQueue(this.logCallbackDelegate);
                });

                Thread.Sleep(100);
            }
        }

        private void LogNewMessage(string source, string message)
        {
            this.Dispatcher.VerifyAccess();
            this.logEntries.Add(new LogEntry(source, message));
        }

        private void OnPlayerJoined(string entityId, string displayName)
        {
            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            Action addPlayerAction = () => playerEntries.Add(new PlayerEntry(entityId, displayName));
            this.Dispatcher.BeginInvoke(addPlayerAction);
        }

        private PlayerEntry FindPlayerEntry(string entityId)
        {
            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            this.Dispatcher.VerifyAccess();
            foreach (var playerEntry in playerEntries)
            {
                if (playerEntry.EntityId == entityId)
                {
                    return playerEntry;
                }
            }
            return null;
        }

        private void OnPlayerChatIndicatorUpdated(string entityId, bool isLocalChatIndicator, Int32 chatIndicator)
        {
            string chatIndicatorString;

            if (isLocalChatIndicator)
            {
                switch (chatIndicator)
                {
                    case 0: // Party::PartyLocalChatControlChatIndicator::Silent
                        chatIndicatorString = "🔈";
                        break;
                    case 1: // Party::PartyLocalChatControlChatIndicator::Talking
                        chatIndicatorString = "🔊";
                        break;
                    case 2: // Party::PartyLocalChatControlChatIndicator::AudioInputMuted
                        chatIndicatorString = "🔇";
                        break;
                    case 3: // Party::PartyLocalChatControlChatIndicator::NoAudioInput
                        chatIndicatorString = "❌";
                        break;
                    default:
                        chatIndicatorString = "?";
                        break;
                }
            }
            else
            {
                switch (chatIndicator)
                {
                    case 0: // Party::PartyChatControlChatIndicator::Silent
                        chatIndicatorString = "🔈";
                        break;
                    case 1: // Party::PartyChatControlChatIndicator::Talking
                        chatIndicatorString = "🔊";
                        break;
                    case 2: // Party::PartyChatControlChatIndicator::IncomingVoiceDisabled
                        chatIndicatorString = "🛑";
                        break;
                    case 3: // Party::PartyChatControlChatIndicator::IncomingCommunicationsMuted
                        chatIndicatorString = "🤫";
                        break;
                    case 4: // Party::PartyChatControlChatIndicator::NoRemoteInput
                        chatIndicatorString = "❌";
                        break;
                    case 5: // Party::PartyChatControlChatIndicator::RemoteAudioInputMuted
                        chatIndicatorString = "🔇";
                        break;
                    default:
                        chatIndicatorString = "?";
                        break;
               }
            }

            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            Action updateChatIndicatorAction = () => FindPlayerEntry(entityId).ChatIndicator = chatIndicatorString;
            this.Dispatcher.BeginInvoke(updateChatIndicatorAction);
        }

        private void OnPlayerTextMessageReceived(string senderEntityId, string textMessage)
        {
            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            Action updatePlayerLastMessageAction = () => FindPlayerEntry(senderEntityId).LastMessage = "[text]: " + textMessage;
            this.Dispatcher.BeginInvoke(updatePlayerLastMessageAction);
        }

        private void OnPlayerVoiceTranscriptionReceived(string speakerEntityId, string transcription)
        {
            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            Action updatePlayerLastMessageAction = () => FindPlayerEntry(speakerEntityId).LastMessage = "[voice]: " + transcription;
            this.Dispatcher.BeginInvoke(updatePlayerLastMessageAction);
        }

        private void OnPlayerLeft(string entityId)
        {
            // playerEntries is an observable collection and so edits to it and its entries must be done on the Dispatcher thread
            Action removePlayerAction = () => playerEntries.Remove(FindPlayerEntry(entityId));
            this.Dispatcher.BeginInvoke(removePlayerAction);
        }

        private string TakeChatTextInput()
        {
            string input = this.ChatTextInput.Text;
            this.ChatTextInput.Text = "";
            return input;
        }

        private void SendTextButton_Click(object sender, RoutedEventArgs e)
        {
            PartySampleApp_SendChatText(TakeChatTextInput());
        }

        private void SendTtsButton_Click(object sender, RoutedEventArgs e)
        {
            PartySampleApp_SynthesizeTextToSpeech(TakeChatTextInput());
        }

        private void JoinButton_Click(object sender, RoutedEventArgs e)
        {
            ComboBoxItem selectedRoom = (ComboBoxItem)this.RoomDropDown.SelectedItem;
            string roomId = selectedRoom.Content.ToString();
            ComboBoxItem lang = (ComboBoxItem)this.LanguageDropDown.SelectedItem;
            string language = lang.Content.ToString();
            LogNewMessage("Setting", $"Language: \"{language}\".");
            LogNewMessage("Network", $"Joining \"{roomId}\" PartyNetwork...");
            PartySampleApp_JoinPartyNetwork(roomId, language);
        }

        private void CreateButton_Click(object sender, RoutedEventArgs e)
        {
            ComboBoxItem selectedRoom = (ComboBoxItem)this.RoomDropDown.SelectedItem;
            string roomId = selectedRoom.Content.ToString();
            ComboBoxItem lang = (ComboBoxItem)this.LanguageDropDown.SelectedItem;
            string language = lang.Content.ToString();
            LogNewMessage("Setting",$"Language: \"{language}\".");
            LogNewMessage("Network", $"Creating \"{roomId}\" PartyNetwork...");
            PartySampleApp_CreateAndJoinPartyNetwork(roomId, language);
        }

        private void LeaveButton_Click(object sender, RoutedEventArgs e)
        {
            ComboBoxItem selectedRoom = (ComboBoxItem)this.RoomDropDown.SelectedItem;
            string roomId = selectedRoom.Content.ToString();
            LogNewMessage("Network", $"Leaving \"{roomId}\" PartyNetwork...");
            PartySampleApp_LeavePartyNetwork();
        }

        private void MutePlayerButton_Click(object sender, RoutedEventArgs e)
        {
            Button senderButton = (Button)sender;
            var playerEntry = senderButton.DataContext as PlayerEntry;
            bool newMuteState = !playerEntry.IsMuted;
            playerEntry.IsMuted = newMuteState;
            PartySampleApp_SetPlayerMute(playerEntry.EntityId, newMuteState);
        }

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_Initialize(
            string titleId,
            string playFabPlayerCustomId,
            OnPlayerJoinedCallback onPlayerJoinedCallback,
            OnPlayerChatIndicatorUpdatedCallback onPlayerChatIndicatorUpdatedCallback,
            OnPlayerTextMessageReceivedCallback onPlayerTextMessageReceivedCallback,
            OnPlayerVoiceTranscriptionReceivedCallback onPlayerVoiceTranscriptionReceivedCallback,
            OnPlayerLeftCallback onPlayerLeftCallback);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_PollLogQueue(LogCallback logCallback);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_CreateAndJoinPartyNetwork(string partyNetworkRoomId, string language);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_JoinPartyNetwork(string partyNetworkRoomId, string language);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_LeavePartyNetwork();

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_SendChatText(string chatText);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_SynthesizeTextToSpeech(string textToSynthesize);

        [DllImport("PartySampleApp.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern void PartySampleApp_SetPlayerMute(string playerEntityId, bool isMuted);
    }
}
