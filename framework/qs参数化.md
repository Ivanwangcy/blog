# qs 用法

qs是npm仓库所管理的包，可以通过npm install qs安装，因此我们可以直接通过require('qs')引用得到哦~。


qs.stringify()作用是将对象或者数组序列化成URL的格式。

```js
import { stringify } from 'qs'

let params = {a:1, b:2}
stringfy(params) // a=1&b=2
```
