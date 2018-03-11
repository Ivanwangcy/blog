# RegExp 正则表达式
## 过滤特殊字符
```javascript
 var reg = /^[\u4e00-\u9fa5\w\#\-\/\(\)（），。？]+$/; 包含汉字。。验证
// 验证特殊字符
if (input_blessing && !reg.test(input_blessing)) {
  msg('备注不可以输入特殊字符');
  return d.reject();
}
```
## 中文匹配
```javascript
/^[\u4e00-\u9fa5]+$/
/^[\u4e00-\u9fa5]+$/.test("我是中文") // 不包含中文标点符号
-> true
```
## 工作中常用正则表达式
```javascript
var myPattern:RegExp = /[\u4e00-\u9fa5]+/gi;  //汉字匹配表达式

var myPattern:RegExp =new RegExp( '\\W'+str +'\\W', "i");  //字符串变量匹配, 匹配所有单词

new RegExp( '\\s'+value +'\\s', "gi");  //匹配空白符隔开的单词

myPattern =new RegExp( "\\b" + str +"\\b", "gi"); //匹配单词

var myPattern:RegExp = /(\w+)\'(\w+)*/gi;  //单词匹配 (带'单词)

var reg = /^[^\uD800-\uDBFF]+$/; // 过滤表情符号，表情符号是以 D800 开头 -  DBFF 结尾的4字节字符

/**
 * [regEmoji 非表情符号验证正则表达式 表情符号为4字节字符，长度为2，从D800-DBFF开头的]
 * @type {RegExp}
 * 😘😁😜😆😍 (这些特殊字符为表情符号)返回 false
 * 其它文字都返回 true
 */
var regEmoji = /^[^\uD800-\uDBFF]+$/; //
```
## app 端特殊字符过滤(Android)：
```JavaScript
var reg = "^[A-Za-z\\d\\u4E00-\\u9FA5\\p{P}‘’“”\\s]+$"; \p{P}标点符号等特殊字符， JavaScript中无效（不支持？）
```
## 正则 引用 `\(1-n)`
使用 `\(number)` 表示引用之前匹配过的正则分组。
```js
'2018-03-03'.match('(\d{4})-(\d{2})-\2')
// 第一个括号 代表 \1
// 第二个括号 代表 \2
// true
'2018-03-05'.match('(\d{4})-(\d{2})-\2')
// false
'2018-03-05'.match('(\d{4})-(\d{2})-(\d{2})')
// true
```
