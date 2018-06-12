# 升级到新的 React Native 版本

升级到 React Native 的新版本可让您访问更多的 API，视图，开发人员工具和其他好东西。升级需要少量的努力，但我们试图让你更容易。这些说明有点不同，具体取决于你是使用`create-react-native-app` 还是 `react-native init` 来创建项目。

> [官方升级指南](https://facebook.github.io/react-native/docs/upgrading.html)

## 使用本机代码构建的项目

### 只有原生代码的项目

### 基于 git 升级

模块 `react-native-git-upgrade` 提供了一站式操作，以最少的冲突升级源文件。在引擎下，它分为两个阶段：

- 首先它会利用 Git 工具计算新旧版本文件间的差异并生成补丁；
- 然后，在用户的项目文件上应用补丁；

> **重要提示：您不必安装新版本的 react-native 软件包，它会自动安装。**

#### 1. 安装 Git 工具

#### 2. 安装 react-native-git-upgrade 模块

react-native-git-upgrade 模块提供一个 CLI，必须全局安装：

```sh
npm install -g react-native-git-upgrade
```

#### 3. 运行如下命令：

```sh
react-native-git-upgrade
```