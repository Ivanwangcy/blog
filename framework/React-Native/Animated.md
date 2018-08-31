# Animated

## 绝对定位动画使用 `_animatedValue.getLayout()` 方法更简洁

```js
_animatedValue.getLayout()
<=>
{
  left: this._animatedValue.x,
    top: this._animatedValue.y
}
```

## 位移使用 `_animatedValue.getTranslateTransform()` 更简洁

```js
transform: _animatedValue.getTranslateTransform()
<=>
transform: [
    {
        translateX: this._animatedValue.x
    },
    {
        translateY: this._animatedValue.y
    }
]
```

## 同时设置多个值 `_animatedValue.interpolate()`

```js
// 使用插值的方式 设置更多属性
// 例：使用 interpolate 赋予其它值，达到同一个动画其它属性联动的效果
style={{
  opacity: this.state.fadeAnim, // Binds directly
  transform: [{
    translateY: this.state.fadeAnim.interpolate({
      inputRange: [0, 1],
      outputRange: [150, 0]  // 0 : 150, 0.5 : 75, 1 : 0
    }),
  }],
}}
```

### Animated.View + timing 简单示例

```js
import React from 'react'
import { Animated, Easing, StyleSheet, Text, View, } from 'react-native'

export default class FadeInView extends React.Component {
  state: any

  construtor (props) {
    super(props)
    this.state = {
      fadeAnim: new Animated.Value(0) // opacity 0
    }
  }

  componentDidMount () {
    Animated.timing(
      this.state.fadeAnim,
      {
        toValue: 1,  // 0 - 1
        duration: 2000
      }
    ).start()
  }

  render () {
    return (
      <Animated.View
        style={{
          opacity: this.state.FadeAnim
        }}>
        {this.props.children}
      </Animated.View>
    )
  }
}
```

## transform 动画

```js
state = {
  animatedValue: new Animated.ValueXY({ x: 0, y: posTop })
};

// Animate the movement
Animated.timing(this.state.animatedValue, {
  delay: 1000,
  duration: 800,
  easing: Easing.linear,
  toValue: {
    x: newX,
    y: newY
  }
}).start(({ finished }) => {
  // finished true/false 是否完成动画
  // Animate again after current animation finished
  // 动画完成之后的处理
  this.animate();
});

style: {
  transform: animatedValue.getTranslateTransform();
}
```

## 创建一个非动画库的动画组件

```js
// 例如 没有 Animated.SectionList ，可以使用 createAnimatedComponent 封装成动画组件
const AnimatedSectionList = Animated.createAnimatedComponent(SectionList);
```

## Easing 动画缓动效果

默认 ease-in-out

## spring
