# 自定义ios原生组件

## 创建头文件

```objective-c
// CustomViewManager.h
#import <React/RCTBridgeModule.h>
#import <React/RCTViewManager.h>

@interface CustomViewManager : RCTViewManager
@end

```

## 创建实现类

```objective-c

// CustomViewManager.m
#import "CustomViewManager.h"
@implementation CustomViewManager

 RCT_EXPORT_MODULE(CustomView)

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

## javascript 导入原生模块

```js
const CustomView = requireNativeComponent('CustomView', null);

<CustomView />
```
