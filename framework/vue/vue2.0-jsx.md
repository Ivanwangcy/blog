## Vue 2.0 jsx 用法
```javascript
// 属性和事件
var data = {
  counter: 10, // 数据
  currentValue: "",
  attrs: {
    id: 'hello'
  },
  on: {
    click: function(e){ // 事件名称与DOM事件一致
      console.log('click');
    }
  },
  computed: {
    evenOrOdd (){ // 计算函数，通常用于返回新数据
      return this.counter % 2 == 0 ? 'Even' : 'Odd';
    }
  },
  methods: {
    handleClick() { // 另一种事件处理方式，没有返回值
      console.log(this.counter, this.props);
      this.counter++;
    }
  },
  watch: {
    currentValue(value){
      // 获取 DOM 元素
      this.$refs.input.value = value // 双向绑定
    }
  },
  hook: { // 钩子 ， 插入DOM时调用
    insert: () => {
      console.log('insert dom')
    }
  }

// h = this.$createElement h 参数是必需的
render(h) {
  return (
    <div on-click={this.handleClick} {...data}>{this.counter}, count is { this.evenOrOdd }</div>
    <input ref='input' value={this.currentValue}/>
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
## JSX 样式 ， 支持 JSON 格式的 styles 对象
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
## 条件判断 使用三元表达式
```javascript
{/* 条件使用三元操作符 */}
{ this.footer ? <span>&copy;copyright.</span> : "" }
```
## jsx 注释语法
```javascript
{/* 注释内容 */}
```
## 动态添加类名
```javascript
class={{ a: true, b: true , c: false}}

```
## 行内样式
```javascript
style={{fontSize: '15px'}}
```
