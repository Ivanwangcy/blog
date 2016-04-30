# NodeJS
 `REPL`模式（ Read-Evaluate-Print-Loop，输入 -求值 -输出 -循环）即交互式命令行解析器
## 安装包
```bash
$ npm install -g ***
$ npm install npm@latest -g  # NPM 更新到 最新版本
$ node # 进入 repl 模式
```
## REPL 模式
```sh
> .help # REPL 常用命令帮助

> .load # 载入 js 文件

> .save  # 保存当前会话中输入的所有代码

> .exit   # 退出
```
退出的方式：**快捷键是ctrl+d, ctrl+c 按两次 或者输入.exit 退出**
## require 函数使用
## 创建服务器
```javascript

var http = require("http");

http.createServer(function (request, response) {
  response.write("Hello World!");
  response.end();
}).listen(8888);

```
