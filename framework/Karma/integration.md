# Karma 测试框架环境搭建与接入 Travis-CI／Coveralls
Karma 是一个基于Nodejs的自动化单元测试框架，可以用于主 web 流浏览器测试，可以集成到 ci 和代码覆盖率工具等。  
## karma 环境搭建
首先需要在Github上创建一个项目，克隆到本地。
1. 全局安装 karma , 单元测试库 mocha, 断言库 should。
```sh
$ npm i -g karma-cli
```
