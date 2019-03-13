//
//  AddressPickerView.h
//  testUTF8
//
//  Created by rhcf_wujh on 16/7/14.
//  Copyright © 2016年 wjh. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AddressCity : NSObject

@property (nonatomic ,strong) NSString * cityName;/**< 城市名*/
@property (nonatomic ,strong) NSArray  * areas;/**< 城市包含的所有地区*/
/**
 *  初始化城市
 *
 *  @param name  城市名字
 *  @param areas 城市包含的地区
 *
 *  @return 初始化城市
 */
- (instancetype)initWithName:(NSString *)name
                       areas:(NSArray *)areas;
/**
 *  初始化城市
 *
 *  @param cityName 城市名字
 *  @param areas    城市包含的地区
 *
 *  @return 初始化城市
 */
+ (instancetype)cityWithName:(NSString *)cityName
                       areas:(NSArray *)areas;
@end

@interface AddressProvince : NSObject

@property (nonatomic, strong) NSString       * name;/**< 省名字*/
@property (nonatomic, strong) NSArray        * cities;/**< 该省包含的所有城市名称*/
@property (nonatomic, strong) NSMutableArray * cityModels;/**< 该省包含的所有城市模型*/
/**
 *  初始化省份
 *
 *  @param name   省名字
 *  @param cities 省包含的所有城市名字
 *
 *  @return 初始化省份
 */
- (instancetype)initWithName:(NSString *)name
                      cities:(NSArray *)cities;
/**
 *  初始化省份
 *
 *  @param name   省名字
 *  @param cities 省包含的所有城市名字
 *
 *  @return 初始化省份
 */
+ (instancetype)provinceWithName:(NSString *)name
                          cities:(NSArray *)cities;
@end

@interface AddressPickerViewModel : NSObject

@property(nonatomic, assign) NSInteger selectedProvince;

@end

@protocol AddressPickerViewDelegate <NSObject>

/** 取消按钮点击事件*/
- (void)cancelBtnClick;

/**
 *  完成按钮点击事件
 *
 *  @param province 当前选中的省份
 *  @param city     当前选中的市
 *  @param area     当前选中的区
 */
- (void)sureBtnClickReturnProvince:(NSString *)province
                              City:(NSString *)city
                              Area:(NSString *)area;

@end

@interface AddressPickerView : UIView

@property(nonatomic, copy) UIColor *backMaskColor;
@property(nonatomic, copy) UIColor *titleViewColor;
@property(nonatomic, copy) UIColor *titleColor;
@property(nonatomic, copy) UIColor *pickerViewColor;
@property(nonatomic, assign) CGFloat backMaskAlpha;

- (void)setTitleHeight:(CGFloat)titleHeight pickerViewHeight:(CGFloat)pickerHeight;

/**
 是否自动打开上次结果，默认为YES。
 */
@property (nonatomic, assign) BOOL isAutoOpenLast;

/** 实现点击按钮代理*/
@property (nonatomic ,weak) id<AddressPickerViewDelegate> delegate;

- (void)show;
- (void)show:(BOOL)animation;
- (void)hide;
- (void)hide:(BOOL)animation;

@end
