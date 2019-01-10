## 常用插件

### babel-plugin-transform-decorators-legacy ES6+ 的装饰器模式
"plugins": ["transform-decorators-legacy"]

babel 官网的 装饰器插件：plugin-proposal-decorators
```js
    "plugins": [
      [
        "@babel/plugin-proposal-decorators",
        {
          "legacy": true
        }
      ],
      ["@babel/plugin-proposal-class-properties", { "loose" : true }]
    ]
```
.eslintrc
```js
"parserOptions": {
        "ecmaFeatures": {
            "legacyDecorators": true,
            "experimentalObjectRestSpread": true,
            "jsx": true
        },
        "sourceType": "module",
        "ecmaVersion": 7
    },
.........
```
### babel-plugin-transform-remove-console 自动移除 log 插件
"plugins": ["transform-remove-console"]
