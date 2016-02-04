# 函数扩展
## 设置函数参数的默认值
*应该为函数的尾参数设置默认值*
```javascript
function log(x, y = 'World') {
  console.log(x, y);
}

log('Hello') // Hello World
log('Hello', 'China') // Hello China
log('Hello', '') // Hello
```
