## Vue 2.0 jsx 用法
```javascript

// 属性和事件
var data = {
  attrs: {
    id: 'hello'
  },
  on: {
    click: function(e){
      console.log('click');
    }
  }
}

// h = this.$createElement h 参数是必需的
render(h) {
  return (
    <div on-click={this.handleClick} {...data}>{this.counter}, count is { this.evenOrOdd }</div>
  )
}

//  等价于
render(h){
  return h('div', {
    attr: {
      id: 'hello'
    }
  }, [this.text]);
}
```
## 支持 JSON 格式的 style
```javascript
// 样式
var styles = {
  fontSize: '16px',
  color: 'red',
  backgroundColor: 'blue'
};

render(){
  return <div style={styles}><div>
}
```
## 渲染列表
```javascript
// 渲染列表
render(h) {
  var todolist = this.todos.map((value) => {
    return <li>{value}</li>;
  });
  return (
    <ul>
    {todolist}
    </ul>
  );
}
```
