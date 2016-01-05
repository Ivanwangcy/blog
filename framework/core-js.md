# 安装
$ npm i core-js
# node 环境下应用
```javascript
var Set = require("./node_modules/core-js/fn/set");
var from = require('./node_modules/core-js/library/fn/array/from');
from(new Set([1,2,3,2,1])); // => [1, 2, 3]
```
