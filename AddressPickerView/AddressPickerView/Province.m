//
//  Province.m
//  UIPickerVIew_City
//
//  Created by qianfeng on 15/6/24.
//  Copyright (c) 2015年 yangxin. All rights reserved.
//

#import "Province.h"


@implementation Province

// 成员方法创建
- (instancetype)initWithName:(NSString *)name
                      cities:(NSArray *)cities
{
    if (self = [super init]) {
        _name = name;
        _cities = cities;
    }
    
    return self;
}

// 类方法创建
+ (instancetype)provinceWithName:(NSString *)name
                          cities:(NSArray *)cities{
    Province *p = [[Province alloc] initWithName:name
                                          cities:cities];
    return p;
}



@end
