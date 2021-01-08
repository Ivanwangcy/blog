# Timer 定时器

## 实现

利用高阶组件反向继承的特性，封装一个定时器组件，相当于工厂类，给每个传入的组件都增加了 定时器 属性，卸载后自动清除。

```js
const timer = (WrappedComponent) =>
    class extends WrappedComponent {
        setTimeout = (func, time) => {
            this.timeout_id = setTimeout(func, time);
        };

        setInterval = (func, time) => {
            this.interval_id = setInterval(func, time);
        };

        componentWillUnmount() {
            super.componentWillUnmount();

            clearInterval(this.interval_id);
            clearTimeout(this.timeout_id);
        }

        render() {
            return super.render();
        }
    };

export default timer;
```

## 用法

```js
import React, { Component } from "react";
import timer from "./timer";

class App extends Component {
    componentDidMount() {
        this.setTimeout(() => {
            console.log("====================================");
            console.log("App", 111);
            console.log("====================================");
        }, 500);
    }

    render() {
        return <div className="App">React Timer</div>;
    }
}

export default timer(App);
```

注意：不要过多使用定时器，会占用更多的内存，导致手机发热，耗电快。
