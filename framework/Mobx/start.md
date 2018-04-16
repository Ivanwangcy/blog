# Mobx 状态管理框架

* 官方文档 [https://mobx.js.org/index.html](https://mobx.js.org/index.html)
* 官方文档-中文版 [http://cn.mobx.js.org/](http://cn.mobx.js.org/)

Mobx 使用了装饰器模式，使代码看起来更加简洁。

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
