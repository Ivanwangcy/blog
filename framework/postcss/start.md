## postcss 使用
```js
postCSSConfig = [
  
  // 自动前缀
  autoprefixer({
    browsers: [
      'ie >= 9',
      'ie_mob >= 10',
      'ff >= 30',
      'chrome >= 34',
      'safari >= 7',
      'opera >= 23',
      'ios >= 7',
      'android >= 4.4',
      'bb >= 10'
    ]
  }),

  //
  require('postcss-flexibility')
]
```
