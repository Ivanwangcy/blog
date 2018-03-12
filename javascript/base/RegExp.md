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
## 正则分组 取词

`$_, $1, $2, $n`
```js
'abc'.replace(/(a)(\w+)/, '$2-$1')
```

## 正则分组 引用 `\(1-n)`
使用 `\(number)` 表示引用之前匹配过的正则分组。
```js
'2018-03-03'.match(/(\d{4})-(\d{2})-\2/)
// 第一个括号 代表 \1
// 第二个括号 代表 \2
// true
'2018-03-05'.match(/(\d{4})-(\d{2})-\2/)
// false
'2018-03-05'.match(/(\d{4})-(\d{2})-(\d{2})/)
// true
```
## 正则分组 - 命名分组
```js
// 使用 ?<分组名称>
'2018-03-03'.match(/(?<year>\d{4})-(?<month>\d{2})-(?<day>\d{2})/)

// 命名分组引用 \k<分组名称>
'2018-03-03'.match(/(?<year>\d{4})-(?<month>\d{2})-\k<month>/)
```
## 正则分组  捕获/不捕获

(?=) 正常的括号是捕获的
(?:) 不捕获分组(不在分组中显示) 不会放入这些里面 $1-$9

## 惰性&贪婪
1. 贪婪模式 -- 在匹配成功的前提下，尽可能多的去匹配
2. 惰性模式 -- 在匹配成功的前提下，尽可能少的去匹配
3. `/.*bbb/g`
3. `/.*?bbb/g` 惰性 多一个 `？`

## 示例
```js
/^\w(?:[-\w\.](?![-\.]))*\w@[-\w]+(\.\w+)+$/i.test('a.a@qq.com.cn');
```
