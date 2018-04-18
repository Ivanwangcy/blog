# Text 组件用法详解

Text 组件是 React Native 最常用的组件之一。为了满足各种各样的需求我们需要了解它的用法，同时在开发过程中也会遇到了很多坑。下面根据我自身经历的经验进行梳理。

## Text 组件的基本用法

自定义组件中使用 Text，必须导入
Text 组件必须用容器组件包裹，例如：View, ImageBackground, Touchable\* 都算容器组件。

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

<!-- 变量文本组合 -->
<View>
  <Text>{`Text:${text}Text2:${text2}Text3:${text3}`}</Text>
</View>

<!-- 文本加空格（不能像html那样直接加空格） -->
<View>
  <Text>&nbsp;</Text> // 不会变成空格
  <Text>  内 容  </Text> // space invalid
</View>
```

## Text 组件的嵌套使用

Text 组件之间互相嵌套，子组件会继承父组件样式。子组件加样式时 lineHeight 不要覆盖父组件的，否则在 Android 环境显示有问题。如果字体差异比较大，建议分开写（主要原因是 Android 问题较多）。分开写要注意给可变文本增加 flex 属性。

```js
// 嵌套文本
<Text style={{fontSize: 14}}>
  {value1}
  <Text style={{ color: "red" }}>{value2}</Text> // 子组件继承 fontSize 14
  {value3}
</Text>


<Text style={{fontSize: 14}}>
  {value1}
  {value2}
</Text>
  <Text style={{ color: "red", fontSize: 25 }}>{value3}</Text> // 子组件继承 fontSize 14
```

## 图文混排，文字环绕

图文混排的是比较常用的组合方式。

注意：**Android 端有 Bug 不建议使用文本嵌套其它组件。**

```js
<Text>
  文本<Image source={Icons.url} />
</Text>
```

## 文字特效

## 自定义通用的 Text 组件
