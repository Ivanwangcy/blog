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
