#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SelectViewController : UIViewController<UIPickerViewDelegate, UIPickerViewDataSource>

@property (strong, nonatomic) NSArray* dataSource;
@property (assign, nonatomic) NSInteger selectedRow;
@property (copy, nonatomic) void (^selectButtonTappedBlock)(NSInteger selectedRow);

@end

NS_ASSUME_NONNULL_END
