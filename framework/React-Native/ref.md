# 使用 ref 时的注意事项

 ref 改为`回调函数`的方式去使用和字符串的方式相比：  

使用字符串的模式下，如果存在以下场景：若 this.refs.someDom 是一个独立的 dom 元素，此时组件进行卸载，因为 this.refs 是字符串引用，那么无法知道 someDom 的卸载时机，也就无法合理的销毁 this.refs.someDom。如果使用回调函数就可以解决这个问题，因为组建卸载时会触发回调函数，那么就可以在此时把 someDom 销毁掉。

## Ref 使用的方式

* String Refs (legacy method)
* Callback Refs
* React.createRef (from React 16.3)

## React.createRef  （16.3 +）

```js
class MyComponent extends React.Component {
  constructor(props) {
    super(props);

    this.inputRef = React.createRef();
  }

  render() {
    return <input type="text" ref={this.inputRef} />;
  }

  componentDidMount() {
    this.inputRef.current.focus();
  }
}
```