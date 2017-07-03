# node 服务器应用开发
```js
let http = require('http')

http.createServer(function(){
  respone.writeHead(200, {'Content-Type': 'text/plain'})
  respone.write("Hello World!")
  respone.end()
}).listen(8888)
```
