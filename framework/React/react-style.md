# react 组件， 样式声明
## 行内样式
使用对象字面量，属性名使用驼峰命名。
```html
<div style={{color: 'red', fontSize: '30px'}}></div>
```
## 增加类名
jsx 类名格式使用 className
```html
<div className='container'></div>
```
## json 对象格式的样式
```javascript
let transparentBg = {
  background: 'transparent'
}

let space = {
  marginTop: '25px'
}

export default {
  transparentBg,
  space
} ;
```
