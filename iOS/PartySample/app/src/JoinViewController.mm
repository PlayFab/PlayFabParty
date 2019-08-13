#import "JoinViewController.h"
#include "Config.h"

@interface JoinViewController ()

@property (strong, nonatomic) IBOutlet UILabel *selectNameLabel;

@end

@implementation JoinViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

-(IBAction) unwindToRootViewController:(UIStoryboardSegue*)segue{
    const char* username = Config::GetSelectedName();
    _selectNameLabel.text = [NSString stringWithUTF8String:username];
}

@end
