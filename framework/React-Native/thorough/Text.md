# Text 组件用法详解

Text 组件是 React Native 最常用的组件之一。为了满足各种各样的需求我们需要了解它的用法，同时在开发过程中也会遇到了很多坑。下面根据我自身经历的经验进行梳理。

## Text 组件的基本用法

自定义组件中使用 Text，必须导入
Text 组件必须用容器组件包裹，例如：View, ImageBackground, Touchable* 都算容器组件。

```js
import React from 'react';
import { Text, View } from 'react-native';
<!-- 常规文本 -->
<View>
<Text>文本内容</Text>
</View>

<!-- 变量文本 -->
<View>
<Text>{text}</Text>
</View>
```

## Text 组件的嵌套使用

## 图文混排，文字环绕

## 文字特效

## 自定义通用的 Text 组件