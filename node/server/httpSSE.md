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


