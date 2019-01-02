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
## 配置示例：
```js
{
  "root": true,
  "parser": "babel-eslint",
  "extends": "eslint-config-airbnb",
  "parserOptions": {
    "ecmaVersion": 6,
    "ecmaFeatures": {
      "jsx": true,
      "experimentalObjectRestSpread": true
    }
  },
  "env": {
    "browser": true,
    "mocha": true
  },
  "plugins": ["react", "babel"],
  "rules": {
    "react/prefer-stateless-function": 0,
    "no-console": 0,
    "no-use-before-define": 0,
    "jsx-a11y/label-has-for": 0,
    "jsx-a11y/no-static-element-interactions": 0,
    "jsx-a11y/anchor-has-content": 0,
    "jsx-a11y/click-events-have-key-events": 0,
    "jsx-a11y/anchor-is-valid": 0,
    "react/no-array-index-key": 0,
    "func-names": 0,
    "arrow-body-style": 0,
    "react/sort-comp": 0,
    "react/prop-types": 0,
    "react/jsx-first-prop-new-line": 0,
    "react/jsx-filename-extension": [
      1,
      {
        "extensions": [".js", ".jsx"]
      }
    ],
    "import/extensions": 0,
    "import/no-unresolved": 0,
    "import/no-extraneous-dependencies": 0,
    "prefer-destructuring": 0,
    "no-param-reassign": 0,
    "no-return-assign": 0,
    "max-len": 0,
    "consistent-return": 0,
    "no-redeclare": 0,
    "react/require-extension": 0,
    "react/no-danger": 0,
    "comma-dangle": ["error", "always-multiline"],
    "function-paren-newline": 0,
    "object-curly-newline": 0,
    "no-restricted-globals": 0,
    "react/jsx-no-bind": 0,
    "no-mixed-operators": 0,
    "import/prefer-default-export": 0,
    "react/forbid-prop-types": 0,
    "global-require": 0,
    "arrow-parens": ["error", "as-needed"]
  }
}

```
