## 开始使用 bisheng
Transform Markdown files into a SPA website using React.

## 配置文件 bisheng.config.js
```js
// 默认配置文件
//
module.exports = {
  source: './posts',
  output: './_site',
  lazyLoad: false,
  theme: './_theme',
  port: 8000,
};



//bisheng-theme-one
// 默认主题配置
module.exports = {
  lazyLoad: true,
  root: '/',
  plugins: ['bisheng-plugin-description'],
  pick: {
    posts(markdownData) {
      return {
        meta: markdownData.meta,
        description: markdownData.description,
      };
    }
  }
};

```
## 主题 _theme
