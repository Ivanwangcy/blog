# Node 集成 MongoDB 与 Mongoose 进行 CRUD 操作

首先确保你[安装了 MongoDB](./mac-install.md) 和 Node.js。

## 安装 mongoose

mongoose 是MongoDB 与 Node.js 的驱动库文件，下面使用 npm 命令行安装 mongoose：

```sh
npm install mongoose
```

## 开始使用

```js
  var mongoose = require('mongoose');
```