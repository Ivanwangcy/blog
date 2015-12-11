#RegExp 正则表达式
##过滤特殊字符
```javascript
 var reg = /^[\u4e00-\u9fa5\w\#\-\/\(\)（），。？]+$/; 包含汉字。。验证
// 验证特殊字符
if (input_blessing && !reg.test(input_blessing)) {
  msg('备注不可以输入特殊字符');
  return d.reject();
}
```
##中文匹配
```javascript
/^[\u4e00-\u9fa5]+$/
/^[\u4e00-\u9fa5]+$/.test("我是中文") // 不包含中文标点符号
-> true
```
