## sass 文件加载依赖包
```sh
$ npm install node-sass sass-loader
```
## webpack.config.js 配置文件,  增加
```javascript
  {
    test: /\.scss$/,
    loaders: ['style', 'css?sourceMap', 'sass?sourceMap']
  }
```
## 新建 .scss 文件, 并测试
```css
@import "style.scss";

.main {
  .foot{
    font-size: 20px;
  }
}
```
