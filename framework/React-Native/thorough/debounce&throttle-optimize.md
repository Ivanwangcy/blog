# 利用节流和防抖优化页面性能

防抖和节流是前端性能优化的常用手段，在 React Native 中同样非常适用。尤其要是追求媲美原生的极致体验，那就更不可少了。

## 

## 输入框节流



## Touchable 组件执行优化

使用方法很简单，在必要的地方使用 debounce 封装一下函数即可：

```js
import debounce from 'lodash/debounce';

<TouchableWithoutFeedback
        onPress={debounce(() => {
          this.handlePress();
        }, 200, {leading: false, trailing: true}).bind(this)}
      >
```