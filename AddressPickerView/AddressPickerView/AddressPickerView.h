//
//  AddressPickerView.h
//  testUTF8
//
//  Created by rhcf_wujh on 16/7/14.
//  Copyright © 2016年 wjh. All rights reserved.
//

#import <UIKit/UIKit.h>

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

/** 实现点击按钮代理*/
@property (nonatomic ,weak) id<AddressPickerViewDelegate> delegate;

- (void)show;
- (void)hide;

@end
