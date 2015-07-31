//
//  DOPDropDownMenu.h
//  DOPDropDownMenuDemo
//
//  Created by weizhou on 9/26/14.
//  Copyright (c) 2014 fengweizhou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DOPIndexPath : NSObject

@property (nonatomic, assign) NSInteger column;
@property (nonatomic, assign) NSInteger row;
- (instancetype)initWithColumn:(NSInteger)column row:(NSInteger)row;
+ (instancetype)indexPathWithCol:(NSInteger)col row:(NSInteger)row;

@end

#pragma mark - data source protocol
@class DOPDropDownMenu;

@protocol DOPDropDownMenuDataSource <NSObject>

@required
- (NSInteger)menu:(DOPDropDownMenu *)menu numberOfRowsInColumn:(NSInteger)column;
- (NSString *)menu:(DOPDropDownMenu *)menu titleForColumnAtIndex:(NSInteger)index;
- (NSString *)menu:(DOPDropDownMenu *)menu titleForRowAtIndexPath:(DOPIndexPath *)indexPath;
@optional
//default value is 1
- (NSInteger)numberOfColumnsInMenu:(DOPDropDownMenu *)menu;

@end

#pragma mark - delegate
@protocol DOPDropDownMenuDelegate <NSObject>
@optional
- (void)menu:(DOPDropDownMenu *)menu didSelectRowAtIndexPath:(DOPIndexPath *)indexPath;
- (void)menu:(DOPDropDownMenu *)menu didSelectColumnAtIndex:(NSUInteger)index;
@end

#pragma mark - interface
@interface DOPDropDownMenu : UIView <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, weak) id <DOPDropDownMenuDataSource> dataSource;
@property (nonatomic, weak) id <DOPDropDownMenuDelegate> delegate;

@property (nonatomic, strong) UIColor *indicatorColor;//箭头颜色
@property (nonatomic, strong) UIColor *indicatorColorSelected;//箭头选中颜色
@property (nonatomic, strong) UIColor *textColor;//选项卡文字颜色
@property (nonatomic, strong) UIColor *textColorSelected;//选项卡选中文字颜色
@property (nonatomic, strong) UIColor *columnSelectedColor;//选项卡选中颜色
@property (nonatomic, strong) UIColor *separatorColor;//选项卡分割线颜色
@property (nonatomic, strong) UIColor *rowTextColor;//行文字颜色
@property (nonatomic, strong) UIColor *rowTextColorSelected;//行文字选中颜色

@property (nonatomic, assign) BOOL      isChangeMenuTitle;
@property (nonatomic, assign) NSInteger currentTapedMenudIndex;//此变量是点击menu时设置的。
@property (nonatomic, assign) NSInteger previousSelectedMenudIndex;//下次点击menu后才设置的,用于记录前一个menu
/**
 *  the width of menu will be set to screen width defaultly
 *
 *  @param origin the origin of this view's frame
 *  @param height menu's height
 *
 *  @return menu
 */
- (instancetype)initWithOrigin:(CGPoint)origin andHeight:(CGFloat)height;
- (NSString *)titleForRowAtIndexPath:(DOPIndexPath *)indexPath;

//programmatically dismiss
- (void)dismiss;

/**
 *  此方法需在DOPDropDownMenu加入view作为子视图后调用才可以正常作用。
 *
 *  @param index 选中index
 */
- (void)menuSelectedWithIndex:(NSInteger)index;
@end
