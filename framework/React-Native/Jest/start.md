# Jest

Jest测试是在带有节点的命令行上运行的仅JavaScript测试。您可以使用以下命令运行现有的React Native jest测试：

```sh
cd react-native
npm test
```

```js
// package.json
  "scripts": {
    "test": "jest"
  },
  "jest": {
    "preset": "react-native"
  }
```

在Facebook，我们使用 Jest 来测试 React Native 应用程序。

通过阅读以下系列，深入了解如何测试正在运行的 React Native 应用程序示例：

* 第1部分：Jest - 快照开始发挥作用，
* 第2部分：Jest - Redux Snapshots用于您的Actions和Reducers。

## Snapshot Test

为组件创建一个快照测试，其中包含一些视图和文本组件以及一些样式：