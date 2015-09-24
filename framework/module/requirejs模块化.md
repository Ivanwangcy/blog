#模块化加载
##require.js 
页面只需引用require.js这个文件, data-main 属性 指定包下列的js文件, 即可加载jQuery
```javascript
require.config({
  baseUrl: "js/lib" // jquery 存放路径
});

define(["jquery"], function ($) {
  $(function() {
    alert("成功加载 Jquery! ");
  });
});
```
##shime
