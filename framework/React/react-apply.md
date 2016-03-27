# React.js 入门
## basic 创建 React 对象
```javascript
var ExampleApplication = React.createClass({
  render: function() {
    var message = "React has bean successfully running:" + this.props.name;
    return React.DOM.p(null, message);
  }
});

var ExampleApplicationFactory = React.createFactory(ExampleApplication);

ReactDOM.render(
  ExampleApplicationFactory({name: "哈哈"}),
  document.getElementById('container')
)
```
## 虚拟DOM jsx/babel 使用ReactDOM.render()渲染
```javascript
// 创建 JSX 组件
var title = <h1>Hello World!</h1>;

var names = ['Alice', 'Emily', 'Kate'];
// 传参
var listItem = <div>
  {
    names.map(function(name){
      //raw format of JSX -- React.createElement('div', {className: 'title'}, 'Hello world!');
      return <div className="title">Hello, {name}!</div>;

    })
  }
</div>;
```
## Hello World! 使用 `type="text/babel"` jsx语法糖
```html
<script type="text/babel">
  ReactDOM.render(
    <h1 className="title">Hello, world!</h1>,
    document.getElementById('example') // a raw DOM element
  );
</script>
```
## 自定义 Dom 元素
```javascript
/************************************************************************************
 * 自定义组件，获取自定义属性
 *  React 实例化组件不是真实的DOM节点
 *  自定义组件以大写字母开头
 *  	-- while custom React component names begin with an uppercase letter.
 ************************************************************************************/


var HelloMessage = React.createClass({
  render: function() {
    return <h1>Hello {this.props.name}</h1>
  }
})
// 使用
<HelloMessage name="John"/>

// 自定义结构
var NotesList = React.createClass({
  render: function() {
    return (
      <ol>
      {
        this.props.children.map( function(child){
            return <li>{child}</li>;
          } )
      }
      </ol>
    );
  }
})
// 渲染 React component 组件到DOM中
ReactDOM.render(
  <NotesList>
    <span>Hello</span>
    <span>world</span>
  </NotesList>, // of raw React.createElement(NotesList, null);
  document.body
)
```
# 常见错误
1. Invariant Violation: \_registerComponent(...): Target container is not a DOM element. 父元素没找到，确保执行代码前页面中存在此元素；初始化时，注意js文件的加载顺序。
