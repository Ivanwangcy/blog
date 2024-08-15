# SSE 服务设计

使用 EventSource 请求 SSE 接口

```sh
npm install @microsoft/fetch-event-source
```

get & post 方式请求

```js
// BEFORE:
const sse = new EventSource('/api/sse');
sse.onmessage = (ev) => {
    console.log(ev.data);
};

// AFTER:
import { fetchEventSource } from '@microsoft/fetch-event-source';

await fetchEventSource('/api/sse', {
    onmessage(ev) {
        console.log(ev.data);
    }
});
```

## 基于 express sse 服务

> 参考：
express:
<https://expressjs.com/en/starter/hello-world.html>
express-sse: <https://www.npmjs.com/package/express-sse?ref=ghost.ably.com>

express-sse github: <https://github.com/dpskvn/express-sse>

## 本地代理 SSE 接口问题

SSE前后端一切正常，但是fetchEventSource 的onmessage回调函数只在所有流都发送完毕后，才会执行一次。

  前端用的是Vue3，webpack打包，同时设置了Proxy：

  只需要加一行compress: false即可：

```js
devServer: {
    // 开发服务器配置
    proxy: {
      // 配置代理
      '/api': {
        target: 'http://localhost:5000', // 代理的目标地址
        changeOrigin: true, // 是否需要改变源
        pathRewrite: {
          '^/api': '' // 重写路径，去掉请求路径中的 /api
        },
      }
    }
  }

devServer: {
    compress: false,
    // 开发服务器配置
    proxy: {
      // 配置代理
      '/api': {
        target: 'http://localhost:5000', // 代理的目标地址
        changeOrigin: true, // 是否需要改变源
        pathRewrite: {
          '^/api': '' // 重写路径，去掉请求路径中的 /api
        },
      }
    }
  }
// ————————————————

```


<https://blog.csdn.net/qq_43592352/article/details/139033147>

