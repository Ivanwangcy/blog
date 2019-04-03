# React Native Web App

可以实现react native 和 react 的多端融合，统一一套代码。

## 开始使用 react-native-web

需要用到的库：

[react-native-web](https://github.com/necolas/react-native-web)
[create-react-native-web-app](https://github.com/orYoffe/create-react-native-web-app)


## 使用现有的脚手架搭建项目

安装 create-react-native-web-app

```sh
$ npm i -g create-react-native-web-app
```

### Run create-react-native-web-app <project-directory>

```sh
$ create-react-native-web-app myApp
$ npm install
$ npm run web
$ npm run ios
$ npm run android
```
### 安装路由

react-router-native & react-router-dom

## 集成到现有项目

在 webpack 配置文件中增加 alias:

```sh
  resolve: {
    ...other, // 其它配置项目
    alias: {
      // Support React Native Web
      // https://www.smashingmagazine.com/2016/08/a-glimpse-into-the-future-with-react-native-for-web/
      'react-native': 'react-native-web',
    },
```

## 参考：

> [react-native-web 集成示例](https://react-native-training.github.io/react-native-elements/blog/2018/12/13/react-native-web.html#implement-withheader)
> [示例(源码)](https://github.com/haruelrovix/gitphone)
