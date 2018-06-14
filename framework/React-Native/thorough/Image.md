# 图片组件的一些常见问题汇总

图片组件是使用频率非常高的组件，应用场景也比较多。下面是在公司项目开发过程中遇到的各种问题和解决方案做了一个总结。

## 自定义通用图标组件

### 重写默认的 Image

提取了一些通用的部分做成组件，适应大部分业务场景。

```js
/* @flow */

import React, { Component } from 'react';
import { Image, Style } from 'react-native';
import Icons from '../../../Assets/images'
import isString from 'lodash/isString'

/**
 * [props source 支持传字符串（CDN url）和本地图片(对象)]
 * [props size   图片尺寸（宽高都相对，可以传这一个值，否则使用样式设置宽高）]
 * [props defaultSource 默认图]
 * [props ohterProps 支持图片的其它属性]
 * @type {[type]}
 */
export default class CustomImage extends Component {

  static defaultProps = {
    size: 56
  }

  render() {
    let props = this.props;
    let { source, size, style } = props;
    if (isString(source)) {
      source = {uri: source}
    }
    return (
      <Image
        defaultSource={Icons.defaultSudoku} // 默认图
        {...props}
        source={!!source ? source : Icons.defaultSudoku}
        style={[
          {
            width: size,
            height: size
          },
          StyleSheet.flatten(style)
        ]}
      />
    );
  }
}

```

### 高频图标定制 IconArrow

```js
import React, { Component } from 'react';
import { Animated, StyleSheet } from 'react-native';
import PropTypes from 'prop-types';

import Icons from '../../Assets/images';

/**
 * [IconArrow(>) 箭头图标使用方法]
 * @type {UIComponent}
 * direction 箭头方向枚举值（'top', 'right', 'bottom', 'left'）, 默认为 right
 * size 图标大小数字型 默认 15
 * color 图标颜色字符串型 默认 白色
 * style 支持自定义样式
 *
 * 导入方式：
 * import { IconArrow } from '../../../components/UIComponents';
 *
 * 组件渲染：
 * <IconArrow direction="bottom" size={13} color='#666' style={styles.arrow} />
 * 
 * 由于某些场景需要需要动画过渡显示箭头，因此直接使用了 Animated.Image
 */
export default class IconArrow extends Component {
  static propTypes = {
    direction: PropTypes.oneOf(['top', 'right', 'bottom', 'left']),
    size: PropTypes.number,
    color: PropTypes.string
  };

  static defaultProps = {
    size: 15
  };

  getDegVal(direction) {
    let degVal = 0;
    switch (direction) {
      case 'bottom':
        degVal = 90;
        break;
      case 'top':
        degVal = -90;
        break;
      case 'left':
        degVal = 180;
        break;
      default:
        0;
    }

    return degVal;
  }

  render() {
    let { direction, size, style, color } = this.props;
    let deg = this.getDegVal(direction);
    return (
      <Animated.Image
        style={[
          {
            width: size,
            height: size,
            tintColor: color,
            transform: [
              {
                rotateZ: `${deg}deg`
              }
            ]
          },
          StyleSheet.flatten(style)
        ]}
        source={Icons.fowordArrow}
      />
    );
  }
}
```

其它使用频率较高的图片也可以使用类似的方式定制一下，可以减少很多重复代码，用起来简单。

## 高清图加载

原生开发通常会使用适配视网膜高清屏幕的高清图，在 React Native 加载非常简单。

```js
// source images@2x.png and images@3x.png
// 自动适配，加载 2x or 3x 图片
import images from 'images.png'
<Image source={images}></Image>
```

## sprite 拼图的应用

大量的图片都放在本地会影响包的体积大小，可以将小图片合并到一张图放到CDN上。通常的web开发加载拼图的方式很简单，但是在 React Native 中该怎样做呢？下面是具体的 sprite 拼图加载方案：

使用一个 View 包装图片，View 的大小为切图大小，超出部分 hide，Image 是合并后的原图大小，用绝对或者相对定位控制显示位置，传递不同的 left 和 top 即可模拟backgroundPosition。

```html
<View style={styles.starWrap} key={val}>
  <Image style={[styles.star, {left: starLeft}]} source={{uri: 'http://static-o2o.360buyimg.com/daojia/new/images/icon/newStar.png'}}></Image>
</View>
```

```js
starWrap: {
  height: 10,
  width: 10,
  overflow: 'hidden',
  alignSelf: 'center',
  backgroundColor: 'transparent'
},
star: {
  height: 10,
  width: 50
},
```

**使用拼图时，Android 平台会有溢出问题，需要给外层容器增加：`backgroundColor: 'transparent'` 样式**

## 图片高斯模糊

Image 组件，高斯模糊效果使用 `blurRadius` 属性，如：

```js
<Image
  source={{
    uri: imgURL
  }}
  blurRadius={50}
  style={styles.imgStyle}
/>
```

## 背景图

早期版本 Image 组件可以作为容器组件，内部可以嵌套子元素，但是新版本不允许这样做了，Image 变成了自闭合组件。那么需要实现一个背景容器组件，首先使用 View 做容器，图片使用绝对定位占满整个容器，代码如下：

```js
  const {children, style, imageStyle, ...props} = this.props;

  return (
    <View style={style}>
      <Image
        {...props}
        style={[
          StyleSheet.absoluteFill,
          {
            width: style.width,
            height: style.height,
          },
          imageStyle
        ]}
      />
      {children}
    </View>
  );
```

**React Native 0.46 版本以后可以直接使用 ImageBackground 组件。**
