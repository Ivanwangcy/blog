## React Native 版本升级
>>> 参考：[React Native升级指南|v0.40+升级适配经验与心得](http://www.devio.org/2017/01/17/React-Native%E5%8D%87%E7%BA%A7%E6%8C%87%E5%8D%97-v0.40+%E5%8D%87%E7%BA%A7%E9%80%82%E9%85%8D%E7%BB%8F%E9%AA%8C%E4%B8%8E%E5%BF%83%E5%BE%97/)

### 基本用法
```sh
$ npm install -g react-native-git-upgrade
$ cd MyReactNativeApp
$ react-native-git-upgrade
```

1. 安装 `react-native-git-upgrade` 模块

```sh
# 全局安装
$ npm install -g react-native-git-upgrade
```

2. 进入项目目录执行更新命令

```sh
$ react-native-git-upgrade
```

### 替代方案

如果使用 `react-native-git-upgrade`, 自动升级不起作用，请手动升级

1. 更新 react-native 依赖包 并保存

  ```sh
  $ npm install --save react-native@X.Y # 指定的版本号
  # 更新 react
  $ npm install --save react@R
  ```

2. 升级项目模板

```sh
$ react-native upgrade
```

### 启动端口号修改

```sh
npm start -- --port=8888
```

### 解决冲突
