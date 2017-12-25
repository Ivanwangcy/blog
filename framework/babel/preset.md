# babel-preset-env

废弃了 babel-preset-es2015 ，成为新的替代品。

## 配置文件 .babelrc
```js
{
  // "presets": [ "es2015" ], // 不再使用
  "presets": [ "env", {
     modules: false,
     ...
  }],
  ...
}

// 目标环境配置 ，指定浏览器版本
{
  "presets": [
    ["env", {
      "targets": {
        "browsers": ["last 2 versions", "safari >= 7"]
      }
    }]
  ]
}

// Node 应用
{
  "presets": [
    ["env", {
      "targets": {
        modules: false,
        "node": "6.10"
        // or
        "node": "current"
      }
    }]
  ]
}
```
