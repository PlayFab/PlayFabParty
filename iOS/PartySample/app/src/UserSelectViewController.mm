//--------------------------------------------------------------------------------------
// UserSelectViewController.m
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#import "UserSelectViewController.h"
#include "Config.h"

@interface UserSelectViewController ()
@property (strong, nonatomic) IBOutlet UIPickerView *userPickerView;
@property (strong, nonatomic) IBOutlet UIButton *selectButton;

@end

@implementation UserSelectViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //["Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6"]
    
    //UIPickerView * picker = [UIPickerView new];
    _userPickerView.delegate = self;
    _userPickerView.dataSource = self;
    _userPickerView.showsSelectionIndicator = YES;
    //[self.view addSubview:userPickerView];
    
    [_userPickerView reloadAllComponents];
    int selectedRow = Config::GetSelectedNameIndex();
    [_userPickerView selectRow:selectedRow inComponent:0 animated:YES];
}

- (IBAction)handleOnSelectButtonClicked:(id)sender {
    NSInteger row = [_userPickerView selectedRowInComponent:0];
    Config::SetSelectedNameIndex(int(row));
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return Config::GetNameListLength();
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    NSString * title = nil;
    
    const char** nameList = Config::GetNameList();
    
    title = [[NSString alloc] initWithCString:nameList[row] encoding:NSUTF8StringEncoding];

    return title;
}

@end
