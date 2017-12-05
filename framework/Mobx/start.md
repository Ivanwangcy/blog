## Mobx 状态管理框架
- 官方文档 [https://mobx.js.org/index.html](https://mobx.js.org/index.html)
- 官方文档-中文版 [http://cn.mobx.js.org/](http://cn.mobx.js.org/)
```js
import {inject, observable, computed} from 'mobx-react/native'


class Store {
  @observable let a = {}


  @action function() {

  }


  @computed function() {
    return xx;
  }
}

```
