# RegExp 正则的扩展
## 正则表达式的构造函数
可以传递两个参数
```javascript
var regexp = new RegExp('xxx', 'i');
var regexp = new RegExp(/abc/, 'i');
```
# 过滤表情符号, 表情符号都是UTF-16中的4字节符号 例如:  `𠮷`
```javascript
var emojiReg = /^[^\uD800-\uDBFF]+$/; // 非表情符号, 过滤以D800开头-DBFF结尾的4字节字符
var emojiReg = /[\uD800-\uDBFF]+/gi; // 包含表情符号 -- 以D800开头-DBFF结尾的4字节字符
```

## 在线工具

* [https://regexper.com/](https://regexper.com/)
