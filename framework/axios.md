## axios Ajax 框架
适用于 node.js，web，React Native 等；
### 安装
```sh
$ npm install --save axios
```
### `GET` 请求用法
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

// 同上
axios.get(('/user', {
    params: {
      id: 123456
    }
  })
  .then((response) => {
    console.log(response);
  })
  .catch((error) => {
    console.log(error);
  })
```
# #
