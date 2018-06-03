# 前端跨域请求的实现方式

由于浏览器的[同源策略](http://www.ruanyifeng.com/blog/2016/04/same-origin-policy.html)，进行 web 开发时经常会遇到跨域问题，因此每个前端工程师都要了解跨域得实现方式。跨域的实现方式也有很多种，下面总结了一些跨域方式。有些方式是不常用的，但是很有必要去了解其原理。

## 为什么会有跨域

出于安全问题的考虑，Netscape提出的一个著名的安全策略——`同源策略（（same-origin policy））`，所有浏览器都实行了它，同源策略是浏览器最核心最基础的安全策略。同源策略是指：A网页设置的 Cookie，B网页不能打开，除非这两个网页"同源"。所谓"同源"指的是"三个相同"——`协议相同，域名相同，端口相同`。只要协议、域名、端口有任何一个不同，都被当作是不同域之间的请求——跨域操作。

跨域会受到各种限制：（1） Cookie、LocalStorage 和 IndexDB 无法读取。（2） DOM 无法获得。（3） AJAX 请求不能发送。这样做的好处是可以规避一些 [CSRF](http://www.cnblogs.com/hyddd/archive/2009/04/09/1432744.html) 攻击。

我们最常用的就是要跨域请求接口，下面就来看看怎样来做到。

## 使用 jsonp 实现跨域请求

最常见的一种跨域方式，其原理是利用了 script 标签不受同源策略的限制，在页面中动态插入 script 标签后使用 src 获取需要的资源，src 属性的内容是请求的服务端接口的URL，以 get 方式将回调函数名称告诉后端，后端响应时返回js脚本，调用回调函数，并将前端的数据以参数的形式传递给回调函数。

前端代码：

```js
/**
 * 方法1
 */
window.xxx = function (value) {
  console.log(value)
}

var script = document.createElement('script')
script.src = 'http://x.stuq.com:7001/json?callback=xxx'
document.body.appendChild(script)
```

后端代码（以 node 为例）：

```js
app.get('/json', (req,res) => {
  let callback = req.query.callback;
  let obj = {
    type : 'jsonp',
    name : 'weapon-x'
  };
  res.writeHead(200, {"Content-Type": "text/javascript"});
  res.end(callback + '(' + JSON.stringify(obj) + ')');
})
```

弊端：

* 需要后端支持；
* 回调函数必须是全局变量；
* 只能使用 GET 方式请求；
* 有安全问题，一些重要信息不应该使用这种方式；

## 使用 Image

Image 跨域原理与 jsonp 类似，只是将 script 标签换成 Image 对象来发起请求。（同理不受同源策略限制的标签如下，都可以动态创建，请求后再销毁）：

* `<script src="..."></script>` 标签嵌入跨域脚本。语法错误信息只能在同源脚本中捕捉到。
* `<link rel="stylesheet" href="...">` 标签嵌入CSS。由于CSS的松散的语法规则，CSS的跨域需要一个设置正确的Content-Type 消息头。不同浏览器有不同的限制： IE, Firefox, Chrome, Safari (跳至CVE-2010-0051)部分 和 Opera。
* `<img>`嵌入图片。支持的图片格式包括PNG,JPEG,GIF,BMP,SVG,...
* `<video>` 和 `<audio>`嵌入多媒体资源。
* `<object>`, `<embed>` 和 `<applet>` 的插件。
* `@font-face` 引入的字体。一些浏览器允许跨域字体（ cross-origin fonts），一些需要同源字体（same-origin fonts）。
* `<frame>` 和 `<iframe>` 载入的任何资源。站点可以使用 X-Frame-Options 消息头来阻止这种形式的跨域交互。

代码示例：

```js
 let requestImg = new Image(1,1);
  requestImg.src = '请求的URL?xxx=各种参数';
  requestImg.onload = () => {
      requestImg = null;
  };
  requestImg.onerror = () => {
    requestImg = null;
  };
```

这种方式适合只发送请求，服务器端接收，不需要响应，不会影响前端主流程。适合的应用场景：埋点上报，性能监控等。

## 使用 iframe

结合 iframe 可以实现多种方式进行跨域请求。

### iframe + hash

A 站点页面监听 `onhashchange` 事件，获取 `location.hash` 传递过来的数据。动态创建 iframe 嵌入 B 站点页面（B 页面在请求服务器中定义），B 站点页面发起请求将数据放入 parent.location.href 的 hash 值中。A 站点页面即可获取数据。

代码示例：

```js
// A 页面
var iframe = document.createElement('iframe')
iframe.src = '[B 页面URL]'
document.body.appendChild(iframe)

window.onhashchange = function () {
  console.log(location.hash)
}


// B 页面
var xhr = new XMLHttpRequest()
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
      // 将数据转换成 json 字符串，再放入 hash 中
        var res = JSON.parse(xhr.responseText)
        parent.location.href = `'[A 页面的 URL]'#msg=${res.msg}`
    }
}
xhr.open('GET', '[B页面同域请求URL]', true)
xhr.send(null)
```

### iframe + window.name

动态创建一个 iframe 加载需要跨域请求站点的页面，这个页面去请求接口将返回的数据放到window.name 全局变量上面，设置完成后修改 iframe 页面的 `location.href`为其它URL，当前页面可以等 iframe 二次加载完成后读取 `iframe.contentWindow.name` 属性获取跨域数据。

代码示例：

```js
// A 页面

var iframe = document.createElement('iframe')
iframe.src = '[B 页面URL]'
document.body.appendChild(iframe)

var times = 0
iframe.onload = function () {
    if (++times === 2) { // 第二次加载才会有数据
        console.log(JSON.parse(iframe.contentWindow.name))
    }
}

// B 页面

var xhr = new XMLHttpRequest()
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        window.name = xhr.responseText
        location.href = '[重新赋值其它可访问 URL]'
    }
}
xhr.open('GET', '[请求 URL]', true)
xhr.send(null)
```

### iframe + postMessage

A 页面动态创建 iframe 跨域访问 B页面，注册 message 事件，接收 B 页面传递的数据。
B 页面请求成功后使用 postMessage 发送数据。

```js
// A 页面
var iframe = document.createElement('iframe')
iframe.src = '[跨域页面 URL]'
document.body.appendChild(iframe)

window.addEventListener('message', function(e) {
  console.log(JSON.parse(e.data))
}, false);

// B 页面
var xhr = new XMLHttpRequest()
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        parent.postMessage(xhr.responseText, '*')
    }
}
xhr.open('GET', 'http://x.stuq.com:7001/json', true)
xhr.send(null)
```

这几种方式都需要跨域服务器端提供一个中转页面，供 iframe 加载，外网页面通过协定的方式获取想要的数据，并不太实用同样存在安全性问题，需要服务器端做安全性验证。

## WebSocket

WebSocket 是一种通信协议，使用`ws://`（非加密）和`wss://`（加密）作为协议前缀。该协议不实行同源策略，只要服务器端允许，即可进行跨域通信。（示例URL: ws://example.com/some/path）

请求示例：

```js

// 客户端的简单用法
var ws = new WebSocket("wss://echo.websocket.org");

ws.onopen = function(evt) {
  console.log("Connection open ...");
  ws.send("Hello WebSockets!");
};

ws.onmessage = function(evt) {
  console.log( "Received Message: " + evt.data);
  ws.close();
};

ws.onclose = function(evt) {
  console.log("Connection closed.");
};

// 请求信息
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Cache-Control: no-cache
Connection: Upgrade
Host: echo.websocket.org
Origin: http://localhost:8081
Pragma: no-cache
Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits
Sec-WebSocket-Key: nhmjefX8ZRitq6KTfozwow==
Sec-WebSocket-Version: 13
Upgrade: websocket
User-Agent: Mozilla/5.0 (iPhone; CPU iPhone OS 10_3_1 like Mac OS X) AppleWebKit/603.1.30 (KHTML, like Gecko) Version/10.0 Mobile/14E304 Safari/602.1
```

WebSocket 请求信息会带上 `origin` 请求来源信息，服务器端可以设置白名单进行匹配，是否允许访问。

请求成功后的信息：

```js
Access-Control-Allow-Credentials: true
Access-Control-Allow-Headers: x-websocket-protocol
Access-Control-Allow-Headers: x-websocket-version
Access-Control-Allow-Headers: x-websocket-extensions
Access-Control-Allow-Headers: authorization
Access-Control-Allow-Headers: content-type
Access-Control-Allow-Origin: http://localhost:8081
Connection: Upgrade
Date: Fri, 01 Jun 2018 08:56:13 GMT
Sec-WebSocket-Accept: LF3nLLkN5A0NTjHYM34osjZEmOU=
Server: Kaazing Gateway
Upgrade: websocket
```

## 跨域资源共享 CORS

CORS是一个W3C标准，全称是"跨域资源共享"（Cross-origin resource sharing）。它允许浏览器向跨源服务器，发出 XMLHttpRequest 请求，从而克服了 AJAX 只能同源使用的限制。

实现CORS通信的关键是服务器。只要服务器实现了CORS接口，就可以跨源通信。服务器端只需要设置 Access-Control-Allow-Origin 头信息即可实现简单的跨域。

设置`Access-Control-Allow-Origin:*`是允许任何来源的请求，相当于忽视了同源策略的限制，实际项目开发或者考虑安全性中千万不要这样干。可以在服务端维护一个白名单列表，如果请求的 origin 与白名单中配置就设置为允许的源。

```js
res.header("Access-Control-Allow-Origin", allowOrgin); // 允许的源
res.header('Access-Control-Allow-Credentials', 'true');// 是否可以带 cookie 信息
```

> 参考：[浏览器同源政策及其规避方法](http://www.ruanyifeng.com/blog/2016/04/same-origin-policy.html)
