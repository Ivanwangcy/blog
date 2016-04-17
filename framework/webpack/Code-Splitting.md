# 使用Code Splitting 实现按需加载
require.ensure会生成一个小的打包文件。
```JavaScript
// 延迟加载
require.ensure([], function(require) {
    var ListView = require('./module/list').default;
    ReactDOM.render(
      <ListView />,
      document.querySelector(".container")
    );
  });

  // 使用 bundle-loader 更简洁
  var load = require('bundle-loader!./module/list');

  load(function(file){
      var ListView = file.default;
      ReactDOM.render(
        <ListView />,
        document.querySelector(".container")
      );
  })
```
