# 使用Code Splitting 实现按需加载
require.ensure会生成一个小的打包文件。
```JavaScript
// 延迟加载
require.ensure([], function(require) {

  });
```
