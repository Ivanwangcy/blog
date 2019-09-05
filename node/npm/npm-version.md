# npm 包版本号管理

使用 npm version 管理项目版本号：

## 用法

```sh
npm version --help
# npm version [<newversion> | major | minor | patch | premajor | preminor | prepatch | prerelease [--preid=<prerelease-id>] | from-git]
```

* major 主版本号
* minor 次版本号
* patch 补丁号
* premajor 预备主版本
* preminor 预备次版本
* prepatch 预备补丁版本
* prerelease 预发布版本

## 版本号策略

* 版本号格式：主版本号.次版本号.修订号；

* 主版本号：当你做了不兼容的 API 修改；

* 次版本号：当你做了向后兼容的功能性新增；

* 修订号：当你做了向后兼容的问题修正；