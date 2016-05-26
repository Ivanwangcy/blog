# jsx syntax sugar 语法糖
1. 以xml格式定义元素；如：
```javascript
<div>Hello World!</div>
```
2. class与属性名使用驼峰式命名；
class=>className, font-size=>fontSize
```javascript
<div
  className="container"
  style={{fontSize: '15px', backgroundColor: 'blue'}}>
</div>

```
3. 组合自定义组件，需要外层包装；composing components
```javascript
<div><Comment /><CommentList /></div>
```
4. 无状态组件简写方式 stateless functional component
```javascript
/**
 * [HelloWorld stateless functional component 无状态组件 简化写法]
 * @method HelloWorld
 * @param  {[type]}   props [传入的属性]
 */
function HelloWorld (props) {
  return (
    <div>Hello {props.name}</div>
  );
}

```
