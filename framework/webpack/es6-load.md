# 编译 ES6 文件
```javascript
loaders: [
  {
    test: /\.js$/,
    exclude: /(node_modules|bower_modules)/,
    loader: 'babel',
    // 配置文件.babelrc 替代下面属性
    query: {
      presets: ['es2015'],
      plugins: ['transform-runtime']
    }
  }
  ```
