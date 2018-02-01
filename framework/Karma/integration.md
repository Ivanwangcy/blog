# Karma 测试框架环境搭建与接入 Travis-CI／Coveralls
Karma 是一个基于Nodejs的自动化单元测试框架，可以用于主 web 流浏览器测试，可以集成到 ci 和代码覆盖率工具等。  
## karma 环境搭建
首先需要在Github上创建一个项目，克隆到本地。
1. 全局安装 karma 相关库, 单元测试库 mocha, 断言库 should。
```sh
$ npm i -g karma-cli
$ npm i -D karma karma-chrome-launcher karma-mocha mocha should karma-firefox-launcher
```
2. 使用 karma init 生成一份 karma 配置文件， karma.conf.js;
3. 执行 `karma start` 查看是否成功；
4. 写一些测试用例，并使测试通过；
5. 测试用例写法参考链接：
  - [assert](http://nodejs.cn/api/assert.html)
  - [should](https://my.oschina.net/u/1753171/blog/291817), [should 源码地址](https://github.com/shouldjs/should.js)
  - [mocha](https://mochajs.org/)
  - [karma](http://karma-runner.github.io/)

## 接入 Travis CI

1. 进入 [Travis 官网](https://travis-ci.org/)，关联 GitHub 账号，开启需要集成的项目。  
2. 在代码库顶级目录下创建 `.travis.yml` 文件，添加基础内容，node 执行环境，node 版本信息；

  ```sh
  language: node_js
  node_js:
    - 8
  ```

3. `.travis.yml` 增加 karma 支持

  ```sh
  # 火狐浏览器 增加如下配置信息
  addons:
    firefox: "latest"

  before_install:
    - export CHROME_BIN=chromium-browser # 增加 chrome 浏览器配置
    - "export DISPLAY=:99.0"
    - "sh -e /etc/init.d/xvfb start"
    - sleep 3 # give xvfb some time to start
  ```

4. 修改 karma.conf.js 配置文件;

  ```js

  module.exports = function(config) {
    config.set({
      ... // 其它配置项

      // 增加一个自定义的 chrome 启动，针对 traivs 环境，供 browsers 使用
      customLaunchers: {
          Chrome_travis_ci: {
              base: 'Chrome',
              flags: ['--no-sandbox']
          }
      },
      // 增加 chrome 和 Firefox 浏览器启动项
      // 在 travis 环境中使用 自定义的 Chrome_travis_ci 启动
      browsers: ['Firefox', process.env.TRAVIS ? 'Chrome_travis_ci' : 'Chrome'],

      // 在 travis 环境 需要终止服务
      singleRun: process.env.TRAVIS,

    })
  }
  ```

## 接入 coveralls - 代码覆盖率

1. 进入 [coveralls 官网](https://coveralls.io/), 与 Travis 类似，关联账号，开启项目访问。
2. 安装 coveralls 相关库文件；

```sh
$ npm i -D coveralls karma-coverage karma-coveralls
```

3. 修改 `karma.conf.js` 增加 coveralls 配置项

```js
module.exports = function(config) {
  config.set({
    ... // 其它配置项

    // 集成覆盖率报告库，生成覆盖率统计
    // coverage reporter generates the coverage
    reporters: ['coverage', 'coveralls'],

    // 需要测试代码覆盖率的文件
    preprocessors: {
      // source files, that you wanna generate coverage for
      // do not include tests or libraries
      // (these files will be instrumented by Istanbul)
      'js/*.js': ['coverage'],
      'quz/*.js': ['coverage'],
      'test/*.js': ['coverage']
    },

    // 生成报告的文件存放位置
    coverageReporter: {
      type: 'lcov', // lcov or lcovonly are required for generating lcov.info files
      dir: 'coverage/' // 需要增加到 忽略文件 .gitignore -> coverage ，以免提交到仓库
    }

  })
}
```

## 最后

- 到 [`travis-ci` 官网](https://travis-ci.org/) 查看是否集成成功，成功后 出现这样的图标样式：[![Build Status](https://travis-ci.org/Ivanwangcy/homework1.svg?branch=master)](https://travis-ci.org/Ivanwangcy/homework1)
- 到 [`coveralls` 官网](https://coveralls.io/) 查看是否集成成功，成功后 出现这样的图标样式:
[![Coverage Status](https://coveralls.io/repos/github/Ivanwangcy/homework1/badge.svg?branch=master)](https://coveralls.io/github/Ivanwangcy/homework1?branch=master)
- 可以把成功后的图标放到自己仓库的 `README.md` 中；
