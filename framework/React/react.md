# React.js
## 虚拟DOM
```javascript
// 创建
var title = <h1>Hello World!</h1>;

var names = ['Alice', 'Emily', 'Kate'];
// 传参
var listItem = <div>
  {
    names.map(function(name){
      return <div>Hello, {name}!</div>;
    })
  }
</div>;
```
## Hello World!
```html
<script type="text/babel">
  React.render(
    <h1>Hello, world!</h1>,
    document.getElementById('example')
  );
</script>
```
## 自定义 Dom 元素
```javascript
var HelloMessage = React.createClass({
  render: function() {
    return <h1>Hello {this.props.name}</h1>
  }
})
```
