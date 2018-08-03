# 高阶组件

高阶组件就是包裹了其他 React Component 的组件。作用是接收组件作为参数返回新的组件。

## 属性劫持

高级组件可以拦截组件属性，进行扩展或者其它操作。

```js
// 定时器示例
export default function withTimer(WrappedComponent) {
  return class extends React.Component{
    state = {
      time: new Date()
    }

    componentDidMount() {
      this.timerID = setInterval(() => {
        this.tick()
      }, 1000)
    }

    componentWillUnmount() {
      clearInterval(this.timerID)
    }

    tick() {
      this.setState({
        time: new Date()
      })
    }

    render() {
      return <WrappedComponent time={this.state.time} {...this.props} />
    }
  }
}

// 其它地方可以调用，相当于类工厂
withTimer(WrappedComponent)
```

## 组件增强中间件

```js
import React, { Component } from 'react';
import { AppState } from 'react-native';

export default function withAppStateRefresh(WrappedComponent) {
  return class extends Component {

    static propTypes = {
      refreshCurrentPage: PropTypes.func
    }

    componentDidMount() {
      AppState.addEventListener('change', this._handleAppStateChange);
    }

    _handleAppStateChange = nextAppState => {
      let {refreshCurrentPage} = this.props;
      if (!nextAppState.match(/inactive|background/) && refreshCurrentPage) {
        // alert('刷新页面');
        refreshCurrentPage();
      }
    }

    componentWillUnmount = () => {
      AppState.removeEventListener('change', this._handleAppStateChange);
    };

    render() {
      return <WrappedComponent {...this.props} />;
    }
  };
}
```