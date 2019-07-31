# nrm -- NPM registry manager

npm 仓库源地址管理。

[官方 github 源码地址](https://github.com/Pana/nrm)

## 安装

```
$ npm install -g nrm
```

## 用法

```sh
$ nrm add mynpm http://npm.mynpm.com/

$ nrm ls

* npm -----  https://registry.npmjs.org/
  yarn ----- https://registry.yarnpkg.com
  cnpm ----  http://r.cnpmjs.org/
  taobao --  https://registry.npm.taobao.org/
  nj ------  https://registry.nodejitsu.com/
  mynpm -- http://npm.mynpm.com/
  
$ nrm use mynpm 
```
