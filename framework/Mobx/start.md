# Mobx 状态管理框架

简单、可扩展的状态管理

* 官方文档 [https://mobx.js.org/index.html](https://mobx.js.org/index.html)
* 官方文档-中文版 [http://cn.mobx.js.org/](http://cn.mobx.js.org/)

## 安装与使用

###安装: 

```sh
npm install mobx --save
```

### React 绑定库:

```sh
npm install mobx-react --save 
```
### 使用：

```sh
import { action, observable, computed } from 'mobx';

```

### Mobx 使用了装饰器模式，使代码看起来更加简洁。

```js
import {action, observable, computed} from 'mobx'


class Store {
  @observable let a = {}


  @action function() {

  }


  @computed function() {
    return xx;
  }
}
```
### React 组件注入状态

以React Native 为例

```sh
import { inject, observer } from 'mobx-react/native';

@inject('store')
@observer
export default class extends Component {
}
```

