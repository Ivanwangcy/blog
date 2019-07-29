# 自定义ios原生组件

## 创建头文件

```objective-c
// CostomViewManager.h
#import <React/RCTBridgeModule.h>
#import <React/RCTViewManager.h>

@interface CostomViewManager : RCTViewManager
@end

```

## 创建实现类

```objective-c

// CostomViewManager.m
#import "CostomViewManager.h"
@implementation CostomViewManager

 RCT_EXPORT_MODULE(CostomView)

 - (UIView *)view
 {
    UIView *view = [[UIView alloc] init];

    view.backgroundColor = [UIColor colorWithRed:255 green:87 blue:87 alpha:1];
    view.layer.cornerRadius = 10.0f;
    view.layer.masksToBounds = YES;
    
   return view;
 }

@end


```
