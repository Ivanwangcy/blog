# babel
主要功能：代码转换 -- 进行ES6到ES5的转换。
它有一个，[在线交互式编程环境](https://babeljs.io/repl/)

# 安装
```sh
# 预处理插件
# babel-preset-es2015 ES6语法包
# babel-preset-react react JSX 解析包
$ npm install babel-loader babel-core babel-preset-es2015 babel-preset-react --save-dev
# 依赖于 webpack , 使用webpack 辅助编译
$ npm install webpack --save-dev
```
# webpack 配置
```JavaScript
module: {
  loaders: [
    {
      test: /\.jsx?$/,
      exclude: /(node_modules|bower_modules)/,
      loader: 'babel',
      query: {
        presets: ['es2015', 'react']
      }
    }
  ]
}
```
## babel 配置文件 .babelrc
```JavaScript
{
  "presets": [
    "es2015",
    "react"
  ]
}
```

# ##测试
引入browser.js
