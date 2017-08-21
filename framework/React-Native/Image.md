## Image 图像组件
```js

// 相对路径，可以不设置宽高
<Image
  source={require('./img/favicon.png')}
/>

// 外部链接 需要指定宽高
<Image
  style={{width: 50, height: 50}}
  source={{uri: 'https://facebook.github.io/react/img/logo_og.png'}}
/>

// base64 图片url
<Image
  style={{width: 66, height: 58}}
  source={{uri: 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADMAAAAzCAYAAAA6oTAqAAAAEXRFWHRTb2Z0d2FyZQBwbmdjcnVzaEB1SfMAAABQSURBVGje7dSxCQBACARB+2/ab8BEeQNhFi6WSYzYLYudDQYGBgYGBgYGBgYGBgYGBgZmcvDqYGBgmhivGQYGBgYGBgYGBgYGBgYGBgbmQw+P/eMrC5UTVAAAAABJRU5ErkJggg=='}}
/>
```
## 背景图片
## Styles
### resizeMode enum('cover', 'contain', 'stretch', 'repeat', 'center')
决定当组件尺寸和图片尺寸不成比例的时候如何调整图片的大小。
- cover: 在保持图片宽高比的前提下缩放图片，直到宽度和高度都大于等于容器视图的尺寸（如果容器有padding内衬的话，则相应减去）。译注：这样图片完全覆盖甚至超出容器，容器中不留任何空白。
- contain: 在保持图片宽高比的前提下缩放图片，直到宽度和高度都小于等于容器视图的尺寸（如果容器有padding内衬的话，则相应减去）。译注：这样图片完全被包裹在容器中，容器中可能留有空白
- stretch: 拉伸图片且不维持宽高比，直到宽高都刚好填满容器。
- repeat: 重复平铺图片直到填满容器。图片会维持原始尺寸。仅iOS可用。
- center: 居中不拉伸。

```js
image {
  resizeMode:
  width:
  height:
  tintColor: 'aquamarine' // 为所有非透明的像素指定一个颜色
}
```
