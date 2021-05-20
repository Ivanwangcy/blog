# Taro 3.0

支持 Vue、Nerv、React 框架编写多端应用。

## Taro 2 迁移到 Taro 3

## Taro UI 适配 3.0

## 升级Taro 3 有待优化项

- Taro UI 组件库不支持按需加载，全量导致主包变大；

- 子包公共代码被提取到主包 common 文件中了也会导致主包变大；
  - 问题跟进：
  - <https://github.com/NervJS/taro/issues/5645>
- Taro 