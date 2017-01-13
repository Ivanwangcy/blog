## 开始使用 bisheng

Transform Markdown files into a SPA website using React.  
转换Markdown文件成为一个 React 单页应用的站点。

### 默认配置文件 bisheng.config.js

```js
// 默认配置文件
//
module.exports = {
  source: './posts', // Markdown 源文件
  output: './_site',
  lazyLoad: false,
  theme: './_theme', // 主题文件，定义解析 markdown 的样式
  port: 8000,
};
```

### 示例主题演示  [bisheng-theme-one](https://github.com/benjycui/bisheng-theme-one)

#### 主题配置文件 `_theme`
```js
module.exports = {
  lazyLoad: true, // 是否采用懒加载
  root: '/', // 主目录
  plugins: ['bisheng-plugin-description'], // markdown 描述信息，提取插件
  pick: { // 需要提取的内容
    posts(markdownData) { // posts -- source 文件夹名称
      return {
        meta: markdownData.meta,
        description: markdownData.description,
      };
    }
  }
};
```

#### Markdown 文件及主题约定规则 /posts/hello-world.md  
定义描述信息如: 标题，发布日期，标签等
```md
---
title: Hello world!
publishDate: 2016-05-05
tags:
  - test
---

The first article which is posted by BiSheng.

---

Hello world!

```js
(function () {
  console.log('Hello world!');
})();
```

```
#### 主题文件剖析
1. 定义文档结构，路由，站点入口，获取描述信息等；
```js
module.exports = {
  home: '/',
  sitename: 'One',
  // tagline: 'The one theme for bisheng',
  // navigation: [{
  //   title: 'BiSheng',
  //   link: 'https://github.com/benjycui/bisheng',
  // }],
  // footer: 'Copyright and so on...',
  // hideBisheng: true,
  github: 'https://github.com/benjycui/bisheng-theme-one',
  routes: [{
    path: '/',
    component: './template/Archive',
  }, {
    path: '/posts/:post',
    component: './template/Post',
  }, {
    path: '/tags',
    component: './template/TagCloud',
    dataPath: '/',
  }],
};

```
#### 启动测试服务器

```js
$ bisheng start

// 指定其它配置文件启动
$ bisheng start -c ./site/bisheng.config.js
```
