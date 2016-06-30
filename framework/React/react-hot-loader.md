# React 组件热更新
安装（已经安装了 webpack, React, (hjs-webpack) 的前提）
```sh
$ npm i -D babel-preset-react-hmre
```
配置 `.babelrc` 文件如下
```javascript
{
  "presets": ["es2015", "stage-0", "react"],
  "env": {
    "development": {
      "presets": ["react-hmre"]
    }
  }
}
```
启动热更新
```sh

# 增加参数， 使 process.env.NODE_ENV === development
$ NODE_ENV=development webpack-dev-server

$ NODE_ENV=development hjs-dev-server # 启动服务器 默认端口 3000
```

## **注意**
- 使用纯函数渲染的无状态 `React` 组件无法实时更新，需要手动刷新页面；
- 标准的创建组件和ES6的类声明可以热更新，如：
```javascript

// 类声明的 React 组件，可以实时加载
export default class App extends Component {

  render() {
    return (
      <div>
        <h1>Hello hjs-webpack!!!!!!</h1>
        <p>史蒂夫史蒂夫阿斯顿发</p>
      </div>
    )
  }
}

```
