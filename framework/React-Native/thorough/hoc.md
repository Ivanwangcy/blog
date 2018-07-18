# 高阶组件

高阶组件就是包裹了其他 React Component 的组件。作用是接收组件作为参数返回新的组件。

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

withTimer(WrappedComponent)
```