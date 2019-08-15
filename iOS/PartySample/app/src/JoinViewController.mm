#import "JoinViewController.h"
#include "Config.h"
#import "ViewController.h"

extern const char* c_pfTitleId;
NSString *kTitleKey = @"TitleKey";

@interface JoinViewController ()

@property (strong, nonatomic) IBOutlet UILabel *selectNameLabel;
@property (strong, nonatomic) IBOutlet UILabel *errorMsgLabel;
@property (strong, nonatomic) IBOutlet UIButton *loginButton;
@property (strong, nonatomic) IBOutlet UITextField *titleTextField;
@end

@implementation JoinViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSString *pfTitleId = [[NSUserDefaults standardUserDefaults] stringForKey: kTitleKey];
    if (pfTitleId)
    {
        self.titleTextField.text = pfTitleId;
    }
    else
    {
        self.titleTextField.text = [NSString stringWithUTF8String:c_pfTitleId];
    }

    BOOL hasTitle = (_titleTextField.text && [_titleTextField.text length] > 0);
    self.errorMsgLabel.hidden = hasTitle;
    [self.loginButton setEnabled:hasTitle];
}

- (IBAction) unwindToRootViewController:(UIStoryboardSegue*)segue{
    const char* username = Config::GetSelectedName();
    _selectNameLabel.text = [NSString stringWithUTF8String:username];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing: YES];
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    BOOL hasTitle = (_titleTextField.text && [_titleTextField.text length] > 0);
    self.errorMsgLabel.hidden = hasTitle;
    [self.loginButton setEnabled:hasTitle];
}

#pragma mark - Navigation

- (BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(nullable id)sender
{
    return (_titleTextField.text && [_titleTextField.text length] > 0);
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(nullable id)sender
{
    if ([segue.destinationViewController isKindOfClass:[ViewController class]]) {
        ViewController *destVC = (ViewController *)segue.destinationViewController;
        destVC.pfTitle = self.titleTextField.text;

        NSString *pfTitleId = [[NSUserDefaults standardUserDefaults] stringForKey: kTitleKey];
        if (![pfTitleId isEqualToString:_titleTextField.text]) {
            [[NSUserDefaults standardUserDefaults] setObject:_titleTextField.text forKey:kTitleKey];
            [[NSUserDefaults standardUserDefaults] synchronize];
        }
    }
}

@end
