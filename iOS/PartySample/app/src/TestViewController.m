//
//  TestViewController.m
//  PartySample
//
// Simple test view controller for RegionsChanged event testing
//

#import "TestViewController.h"
#import "SimpleClient.h"

@interface TestViewController ()

@property (strong, nonatomic) UIButton *btnConnectPlayFab;
@property (strong, nonatomic) UIButton *btnInitializeParty;
@property (strong, nonatomic) UITextView *tvLogs;
@property (strong, nonatomic) UIScrollView *scrollView;

@property (strong, nonatomic) SimpleClient *client;
@property (strong, nonatomic) NSTimer *doWorkTimer;
@property (nonatomic) BOOL isDoWorkRunning;

@end

@implementation TestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.isDoWorkRunning = NO;
    
    // Set default title ID (change to your actual title ID)
    if (!self.pfTitle || [self.pfTitle length] == 0) {
        self.pfTitle = @"YOUR_TITLE_ID_HERE";
    }
    
    // Create UI elements programmatically
    [self setupUI];
    
    // Initialize SimpleClient
    self.client = [[SimpleClient alloc] init];
    
    [self addLog:@"=== Party RegionsChanged Test ==="];
    [self addLog:@"1. Press 'Connect to PlayFab' (optional - requires WiFi)"];
    [self addLog:@"2. Press 'Initialize Party' to trigger RegionsChanged"];
    [self addLog:@"3. Watch for 'Region changed' message"];
    [self addLog:@""];
}

- (void)setupUI {
    // Create scroll view
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    self.scrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:self.scrollView];
    
    CGFloat padding = 20;
    CGFloat buttonHeight = 50;
    CGFloat yOffset = 50;
    CGFloat width = self.view.bounds.size.width - (padding * 2);
    
    // Create Connect to PlayFab button
    self.btnConnectPlayFab = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnConnectPlayFab.frame = CGRectMake(padding, yOffset, width, buttonHeight);
    [self.btnConnectPlayFab setTitle:@"Connect to PlayFab" forState:UIControlStateNormal];
    self.btnConnectPlayFab.backgroundColor = [UIColor colorWithRed:0.0 green:0.5 blue:1.0 alpha:1.0];
    [self.btnConnectPlayFab setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnConnectPlayFab.layer.cornerRadius = 8;
    self.btnConnectPlayFab.titleLabel.font = [UIFont boldSystemFontOfSize:18];
    [self.btnConnectPlayFab addTarget:self action:@selector(connectPlayFabTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollView addSubview:self.btnConnectPlayFab];
    
    yOffset += buttonHeight + 20;
    
    // Create Initialize Party button
    self.btnInitializeParty = [UIButton buttonWithType:UIButtonTypeSystem];
    self.btnInitializeParty.frame = CGRectMake(padding, yOffset, width, buttonHeight);
    [self.btnInitializeParty setTitle:@"Initialize Party" forState:UIControlStateNormal];
    self.btnInitializeParty.backgroundColor = [UIColor colorWithRed:0.0 green:0.7 blue:0.2 alpha:1.0];
    [self.btnInitializeParty setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.btnInitializeParty.layer.cornerRadius = 8;
    self.btnInitializeParty.titleLabel.font = [UIFont boldSystemFontOfSize:18];
    [self.btnInitializeParty addTarget:self action:@selector(initializePartyTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollView addSubview:self.btnInitializeParty];
    
    yOffset += buttonHeight + 20;
    
    // Create TextView for logs
    CGFloat logHeight = self.view.bounds.size.height - yOffset - padding;
    self.tvLogs = [[UITextView alloc] initWithFrame:CGRectMake(padding, yOffset, width, logHeight)];
    self.tvLogs.editable = NO;
    self.tvLogs.font = [UIFont fontWithName:@"Menlo" size:12];
    self.tvLogs.layer.borderColor = [UIColor grayColor].CGColor;
    self.tvLogs.layer.borderWidth = 1.0;
    self.tvLogs.layer.cornerRadius = 4;
    self.tvLogs.text = @"";
    [self.scrollView addSubview:self.tvLogs];
    
    self.scrollView.contentSize = CGSizeMake(width, yOffset + logHeight + padding);
}

- (IBAction)connectPlayFabTapped:(id)sender {
    [self addLog:@"=== Attempting PlayFab Login ==="];
    self.btnConnectPlayFab.enabled = NO;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [self.client initialize:self.pfTitle];
        [self.client signInLocalUser];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self addLog:@"PlayFab connection started (check logs for result)"];
            self.btnConnectPlayFab.enabled = YES;
        });
    });
}

- (IBAction)initializePartyTapped:(id)sender {
    [self addLog:@"=== Initializing PartyManager ==="];
    self.btnInitializeParty.enabled = NO;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BOOL success = [self.client initializePartyManager:self.pfTitle];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (success) {
                [self addLog:@"PartyManager initialized successfully"];
                [self addLog:@"Watching for RegionsChanged event..."];
                [self startDoWorkTimer];
            } else {
                [self addLog:@"PartyManager initialization failed"];
            }
            self.btnInitializeParty.enabled = YES;
        });
    });
}

- (void)startDoWorkTimer {
    if (self.isDoWorkRunning) {
        return;
    }
    
    self.isDoWorkRunning = YES;
    self.doWorkTimer = [NSTimer scheduledTimerWithTimeInterval:0.5
                                                        target:self
                                                      selector:@selector(doWork)
                                                      userInfo:nil
                                                       repeats:YES];
    [self addLog:@"DoWork timer started"];
}

- (void)doWork {
    if (self.client) {
        [self.client tick];
    }
}

- (void)addLog:(NSString *)message {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString *currentText = self.tvLogs.text ?: @"";
        self.tvLogs.text = [currentText stringByAppendingFormat:@"%@\n", message];
        
        // Scroll to bottom
        NSRange range = NSMakeRange(self.tvLogs.text.length - 1, 1);
        [self.tvLogs scrollRangeToVisible:range];
    });
}

- (void)dealloc {
    if (self.doWorkTimer) {
        [self.doWorkTimer invalidate];
        self.doWorkTimer = nil;
    }
}

@end
