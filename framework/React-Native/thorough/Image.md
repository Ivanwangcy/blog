# 图片组件

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

## 自定义图标组件

提取了一些通用的部分做成组件，适应大部分业务场景。

```js
/* @flow */

import React, { Component } from 'react';
import { Image, Style } from 'react-native';
import Icons from '../../../Assets/images'
import isString from 'lodash/isString'

/**
 * [props source 支持传字符串]
 * [props size   图片尺寸（宽高都相对，可以传这一个值，否则使用样式设置宽高）]
 * [props defaultSource 自带到家默认图]
 * [props ohterProps 支持图片的其它属性]
 * @type {[type]}
 */
export default class DJImage extends Component {

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
        defaultSource={Icons.defaultSudoku}
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