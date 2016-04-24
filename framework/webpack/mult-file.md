# 多文件打包策略
## 多文件单独加载
```javascript
module.exports = {
//  多个文件，单独加载
  entry: {
    bundle1: './entry1.js',
    bundle2: './entry2.js'
  },
  output: {
    filename: '[name].js'
  }
};
```
## 多个文件打包成一个文件
```javascript
module.exports = {
  // 多个文件合并打包
  entry: [
    './entry1.js',
    './entry2.js'
  ],
  output: {
    filename: 'bundle.js'
  }
```
