//
//  ViewController.m
//  chatdemo_ios
//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#import "ViewController.h"
#import "SimpleClient.h"
#import "SelectViewController.h"

const NSInteger kMaxChatLines = 100;
const NSString *kUserIdentify = @"com.microsoft.playfab.cofa.tool.key.user.identify";
const NSString *kUserIsMyID = @"com.microsoft.playfab.cofa.tool.key.user.ismyid";
const NSString *kUserTalkStatus = @"com.microsoft.playfab.cofa.tool.key.user.talk.status";

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UIButton *createButton;
@property (strong, nonatomic) IBOutlet UIButton *joinButton;
@property (strong, nonatomic) IBOutlet UIButton *leaveButton;

@property (strong, nonatomic) IBOutlet UIButton *selectLanguageCodeButton;
@property (strong, nonatomic) IBOutlet UIButton *selectNetworkButton;

@property (strong, nonatomic) IBOutlet UILabel *languageCodeLabel;
@property (strong, nonatomic) IBOutlet UILabel *networkLabel;

@property (strong, nonatomic) IBOutlet UIButton *chatOption1Button;
@property (strong, nonatomic) IBOutlet UIButton *chatOption2Button;
@property (strong, nonatomic) IBOutlet UIButton *chatOption3Button;
@property (strong, nonatomic) IBOutlet UITextView *chatTextView;

@property (strong, nonatomic) IBOutlet UIView *loadingView;

@property (weak, nonatomic) IBOutlet UITableView* userListTableView;
@property (strong, nonatomic) NSLock* userListLock;
@property (strong, nonatomic) NSMutableArray* remoteUsers;
@property (strong, nonatomic) NSMutableArray* reloadCells;
@property (strong, nonatomic) NSMutableArray* chatLineList;

@end

@implementation ViewController {
    bool m_isRunning;
    int m_language_index;
    NSTimer* m_timer;

    NSLock* m_userLock;
    NSMutableArray* m_remoteUsers;
    NSMutableArray* m_reloadCells;
    NSMutableDictionary* m_remoteUsersDict;
}

@synthesize userListLock = m_userListLock;
@synthesize remoteUsers = m_remoteUsers;
@synthesize reloadCells = m_reloadCells;

SimpleClient* m_client;

#pragma mark - life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    m_client = [[SimpleClient alloc] init];
    [m_client initialize: _pfTitle];
    [m_client setHandler:self];

    m_isRunning = false;    
    [self setLanguageCode: [m_client getDefaultLanguageIndex]]; // set default language
    
    _chatLineList = [[NSMutableArray alloc] init];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    
    [self startLoop];
    [m_client signInLocalUser];
    [self updateButtonStatus:NO];
    
    _chatTextView.layoutManager.allowsNonContiguousLayout = NO;
}

#pragma mark - button action

- (IBAction)handleCreateButtonClick:(id)sender
{
    [m_client createNetwork:_networkLabel.text];
}

- (IBAction)handleJoinButtonClick:(id)sender
{
    [m_client joinNetwork:_networkLabel.text];
}

- (IBAction)handleChatOptionClick:(UIButton*)sender
{
    NSString *label = sender.titleLabel.text;
    
    [m_client sendTextMessage:label];
}

- (IBAction)handleLeaveButtonClick:(UIButton*)sender
{
    NSDictionary* myUser;
    for (NSDictionary* user in self.remoteUsers)
    {
        if([[user objectForKey:kUserIsMyID] boolValue])
        {
            myUser = user;
            break;
        }
    }
    [self.remoteUsers removeAllObjects];
    [self.remoteUsers addObject:myUser];
    [self.userListTableView reloadData];

    [m_client leaveNetwork];
    
    [self updateButtonStatus:NO];
}

#pragma mark - private func

- (void) startLoop
{
    m_isRunning = YES;
    m_timer = [NSTimer scheduledTimerWithTimeInterval:1.0f/30.0f
                                             target:self selector:@selector(tick) userInfo:nil repeats:YES];
}

- (void) tick
{    
    if (nil != m_client)
    {
        [m_client tick];
    }
}

- (void) stopLoop
{
    [m_timer invalidate];
    m_timer = nil;
    m_isRunning = NO;
}

-(void)updateChatIndicatorWithPlayerId:(NSString *)player withIndicator:(NSString *)indicator
{
    int idx = 0;
    for (NSMutableDictionary* user in self.remoteUsers)
    {
        if([player compare:[user objectForKey:kUserIdentify]] == NSOrderedSame)
        {
            [user setObject:indicator forKey:kUserTalkStatus];
            [self.reloadCells addObject:[NSIndexPath indexPathForRow:idx inSection:0]];
            break;
        }
        idx ++;
    }
}

- (void)addUserToUserList:(NSString *)userId
{
    [self addUserToUserList:userId needToUpdateTableView:YES];
}

- (void)addUserToUserList:(NSString *)userId needToUpdateTableView:(bool)update
{
    if(userId == nil)
    {
        return ;
    }
    if([userId compare:@"System" options:NSCaseInsensitiveSearch] == NSOrderedSame)
    {
        return ;
    }
    NSString* myPlayId = [m_client getSelectedUserName];
    bool isMe = false;
    if(myPlayId)
    {
        if([userId compare:myPlayId options:NSCaseInsensitiveSearch] == NSOrderedSame)
        {
            isMe = true;
        }
    }
    
    id foundUser = nil;
    for (NSDictionary* user in self.remoteUsers)
    {
        if([userId compare:[user objectForKey:kUserIdentify]] == NSOrderedSame)
        {
            foundUser = user;
            break;
        }
    }
    if(foundUser == nil)
    {
        NSMutableDictionary* user = [[NSMutableDictionary alloc] init];
        [user setObject:userId forKey:kUserIdentify];
        [user setObject:@"silence" forKey:kUserTalkStatus];
        [user setObject:[NSNumber numberWithBool:isMe] forKey:kUserIsMyID];
        [self.remoteUsers addObject:user];
        [self.userListTableView reloadData];
    }
}

- (void)removeUserFromUserList:(NSString *)userId
{
    id foundUser = nil;
    for (NSDictionary* user in self.remoteUsers)
    {
        if([userId compare:[user objectForKey:kUserIdentify] options:NSCaseInsensitiveSearch] == NSOrderedSame)
        {
            foundUser = user;
            break;
        }
    }
    if(foundUser)
    {
        [self.remoteUsers removeObject:foundUser];
        [self.userListTableView reloadData];
    }
}

- (void)setLanguageCode:(NSInteger) languageIndex
{
    int select_index = (int) languageIndex;
    [m_client setLanguageCode:select_index];
    m_language_index = select_index;
    self.languageCodeLabel.text = [m_client getLanguageOptions][select_index];
}

- (void)updateButtonStatus: (BOOL) isChating
{
    _joinButton.enabled = !isChating;
    _createButton.enabled = !isChating;
    _selectLanguageCodeButton.enabled = !isChating;
    _selectNetworkButton.enabled = !isChating;
    
    _chatOption1Button.enabled = isChating;
    _chatOption2Button.enabled = isChating;
    _chatOption3Button.enabled = isChating;
    _leaveButton.enabled = isChating;
}

#pragma mark - ChatEventHandler

-(void) onNetworkCreated:(NSString*) networkDescriptor
{
    [self updateButtonStatus:YES];
}

-(void) onJoinedNetwork
{
    [self updateButtonStatus:YES];
}

-(void) onPlayerJoin:(NSString*) userId
{
    [self addUserToUserList:userId];
    
    [self onTextMessageReceived:@"System" withText:[NSString stringWithFormat:@"** %@ joined **", userId] isTranscription:false];
}

-(void) onPlayerLeft:(NSString*) userId
{
    [self onTextMessageReceived:@"System" withText:[NSString stringWithFormat:@"** %@ left **", userId] isTranscription:false];
    [self removeUserFromUserList:userId];
}

-(void) onPlayerStatusUpdateStart
{
    [self.reloadCells removeAllObjects];
}

-(void) onPlayerStatusChange:(NSString*)playerId withIndicator:(NSString*)indicatorName
{
    [self updateChatIndicatorWithPlayerId:playerId withIndicator:indicatorName];
}

-(void) onPlayerStatusUpdateEnd
{
    if([self.reloadCells count] > 0)
    {
        [self.userListTableView reloadRowsAtIndexPaths:self.reloadCells withRowAnimation:UITableViewRowAnimationNone];
    }
}

-(void) onTextMessageReceived:(NSString*) userId withText:(NSString*) text isTranscription:(BOOL) isTranscription
{
    NSString* format;
    
    if (isTranscription)
    {
        // No longer different but we could make it different for transcription later:
        format = @"\n[%@(transcription)] %@";
    }
    else
    {
        format = @"\n[%@] %@";
    }
    
    [_chatLineList addObject:[NSString stringWithFormat:format, userId, text]];
    
    while ([_chatLineList count] > kMaxChatLines)
    {
        [_chatLineList removeObjectAtIndex:0];
    }

    NSMutableString* newBuffer = [[NSMutableString alloc] init];
    NSUInteger l_count = [_chatLineList count];

    for (NSUInteger i = 0; i < l_count; i++)
    {
        [newBuffer appendString:[_chatLineList objectAtIndex:i]];
    }
    [newBuffer appendString:@"\n"];
    _chatTextView.text = newBuffer;
    
    if(_chatTextView.text.length > 0 ) {
        NSRange bottom = NSMakeRange(_chatTextView.text.length -1, 1);
        [_chatTextView scrollRangeToVisible:bottom];
    }

    [self addUserToUserList:userId needToUpdateTableView:YES];
}

-(void) onToastMessage:(NSString*) text
{
    NSLog(@"handle Toast Message: %@", text);
}

-(void) onStartLoading
{
    [UIView animateWithDuration:0.3 animations:^{
        self.loadingView.alpha = 0;
    } completion:^(BOOL finished) {
        self.loadingView.alpha = 1;
    }];
}

-(void) onEndLoading
{
    [UIView animateWithDuration:0.3 animations:^{
        self.loadingView.alpha = 1;
    } completion:^(BOOL finished) {
        self.loadingView.alpha = 0;
    }];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.remoteUsers count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"UserTableViewCell";
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    
    NSDictionary* user = [self.remoteUsers objectAtIndex:indexPath.row];
    
    cell.imageView.image = [UIImage imageNamed:[user objectForKey:kUserTalkStatus]];
    cell.textLabel.text = [user objectForKey:kUserIdentify];
    
    return cell;
}

#pragma mark - Navigation

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(nullable id)sender
{
    if ([segue.destinationViewController isKindOfClass:[SelectViewController class]]) {
        SelectViewController *destVC = (SelectViewController *)segue.destinationViewController;
        
        if ([@"SelectLanguage" isEqual:segue.identifier]) {
            destVC.dataSource = [m_client getLanguageOptions];
            destVC.selectedRow = [[NSNumber numberWithInt:m_language_index] integerValue];
            __weak __typeof(self)weakSelf = self;
            destVC.selectButtonTappedBlock = ^(NSInteger selectedRow) {
                __strong __typeof(weakSelf)strongSelf = weakSelf;
                [strongSelf setLanguageCode: selectedRow];
            };
        } else if ([@"SelectNetwork" isEqual:segue.identifier]) {
            NSArray *rooms = @[@"Room_1", @"Room_2", @"Room_3", @"Room_4"];
            destVC.dataSource = rooms;
            destVC.selectedRow = [rooms indexOfObject:self.networkLabel.text];
            __weak __typeof(self)weakSelf = self;
            destVC.selectButtonTappedBlock = ^(NSInteger selectedRow) {
                __strong __typeof(weakSelf)strongSelf = weakSelf;
                strongSelf.networkLabel.text = rooms[selectedRow];
            };
        }
    }
    
}

#pragma mark - geter and seter

- (NSLock *)userListLock
{
    if(m_userListLock == nil)
    {
        m_userListLock = [[NSLock alloc] init];
    }
    return m_userListLock;
}

- (NSMutableArray *)remoteUsers
{
    if(m_remoteUsers == nil)
    {
        m_remoteUsers = [[NSMutableArray alloc] init];
    }
    return m_remoteUsers;
}

- (NSMutableArray *)reloadCells
{
    if(m_reloadCells == nil)
    {
        m_reloadCells = [[NSMutableArray alloc] init];
    }
    return m_reloadCells;
}

@end
