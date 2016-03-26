# Express
## getting started
## 安装 express
```bash
$ npm install express --save  
```
## 创建 public/index.html 略
## 创建文件 server.js
```javascript
var fs = require('fs');
var path = require('path');
var express = require('express');
var app = express();

app.set('port', (process.env.PORT || 4000));
app.use("/", express.static(path.join(__dirname, "public"))); // 默认路由


app.listen(app.get('port'), function() {
  console.log(('Server started: http://localhost:' + app.get('port')));
});
```
## 启动服务
```bash
$ node server.js
```
