# Webpack 实战

-- 入门、进阶与调优（第二版）

github 地址： <https://github.com/yuhaoju/webpack-config-handbook>

## Webpack 介绍

模块打包工具（module bundler）的任务就是解决模块间依赖，使其打包后的结果能运行在浏览器上。它的工作方式主要分为两种：

- 将所有模块打包到一个 js 文件中，需要一次性全部加载；
- 将页面初始化时需要的入口模块独立打包，其它模块异步加载；

目前比较流行的模块打包工具：Webpack、Vite、Parcel、Rollup等。

## webpack 性能调优

