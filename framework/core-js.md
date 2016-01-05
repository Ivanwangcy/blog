# 安装
$ npm i core-js
# node 环境下应用
```javascript
// 引用整个库
var corejs = require("./node_modules/core-js");
Array.from(new corejs.Set([1,2,3,2,1]));
// 单独引用函数
var Set = require("./node_modules/core-js/fn/set");
var from = require('./node_modules/core-js/library/fn/array/from');
from(new Set([1,2,3,2,1])); // => [1, 2, 3]
```
