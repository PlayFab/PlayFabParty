#import "SelectViewController.h"

@interface SelectViewController ()

@property (strong, nonatomic) IBOutlet UIPickerView *pickerView;
@property (strong, nonatomic) IBOutlet UIButton *selectButton;

@end

@implementation SelectViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.pickerView.delegate = self;
    self.pickerView.dataSource = self;
    self.pickerView.showsSelectionIndicator = YES;
    //[self.view addSubview:userPickerView];
    
    [self.pickerView reloadAllComponents];

    [self.pickerView selectRow:self.selectedRow inComponent:0 animated:YES];
}

- (IBAction)handleOnSelectButtonClicked:(id)sender {
    NSInteger row = [self.pickerView selectedRowInComponent:0];
    __weak __typeof(self)weakSelf = self;
    [self dismissViewControllerAnimated:YES completion:^{
         __strong __typeof(weakSelf)strongSelf = weakSelf;
        if (strongSelf.selectButtonTappedBlock) {
            strongSelf.selectButtonTappedBlock(row);
        }
    }];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return [self.dataSource count];
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return self.dataSource[row];
}

@end
