## React Native 添加字体库
### 自定义字体文件导入 ReactNative
1. 添加 font 组件库
```sh
$ npm install react-native-vector-icons --save
```

2. 导入字体文件夹 `node_modules/react-native-vector-icons/Fonts` 到项目中；
3. 修改 `Info.plist` 增加 `Fonts provided by application` 数组；
4. 添加 `item` 指定字体文件名称；
## iconfinder
[https://www.iconfinder.com/iconsets/miu](https://www.iconfinder.com/iconsets/miu)
## iconfont
[http://www.iconfont.cn/](http://www.iconfont.cn/) 图标字体资源丰富

```js
import Icon from 'react-native-vector-icons/Entypo'

const myIcon = (<Icon name="baidu" size={30} color="#900" />)
```
### 模拟字体的其它方式
- 使用 Base64 加入代码中；
- 使用 png 图片，设置尺寸，图片颜色 tintColor 实现图标复用；
- 合并图片，使用View 包裹 Image， Image使用决对定位的方式，控制要显示的图标位置；
