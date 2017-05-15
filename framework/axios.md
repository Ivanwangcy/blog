## axios Ajax 框架
适用于 node.js，web，React Native 等；
### 安装
```sh
$ npm install --save axios
```
### 使用
```javascript
import axios from 'axios'

// 基本用法
axios.get('/user?id=123456')
  .then((response) => {
    console.log(response);
  })
  .catch((error) => {
    console.log(error);
  })
```
