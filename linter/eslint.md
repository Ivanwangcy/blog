## eslint

全局安装
```sh
$ npm install eslint
```
`Atom` 下 安装插件
```sh
$ apm install linter
$ apm install linter-eslint
```
## 配置 '.eslintrc' or '.eslintrc.js'

## lint 配置复用 eslint-config
- extends: "eslint:recommended"  默认的 lint 配置
- `eslint-config-fbjs` extends: 'fbjs' facebook 配置
- `eslint-config-standard` extends: 'standard' 标准配置

##配置生成工具
## eslint 插件

## 跳过检测的代码，可以增加如下注释
```js
/* eslint-disable */

alert('foo'); // 不需要检测的代码

/* eslint-enable */

/* eslint-disable */
    //  代码块儿
/* eslint-enable */

 // 不检查下一行代码

 // eslint-disable-next-line
```
