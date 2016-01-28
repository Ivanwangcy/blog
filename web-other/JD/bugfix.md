# 工作中常见问题
## 无痕浏览
无痕模式下不支持sessionStorage 和 localStorage, 需要异常检测。
```javascript
var sessionStorageEnabled = false;
try{
    sessionStorage.setItem('1','1');
    sessionStorageEnabled = true;
} catch(e){ }
```
## tap 与 click

## 动态获取当前URL
```javascript
location.protocol + '//' + location.host + location.pathname + location.hash
```
## 相同view之间的跳转无效
```
#storeList/storetypeId:1,2
#storeList/storetypeId:6,13
```
解决方法：添加onhashchange方法，侦听hash值的变化。
## 页面计时器清零  
每一个含有计时器的页面，在页面离开的时候添加leave方法，清除计时器。
## 过滤表情符号（数据库不支持表情符号，前端处理）
```javascript
/**
 * [regEmoji 非表情符号验证正则表达式 表情符号为4字节字符，长度为2，从D800-DBFF开头的]
 * @type {RegExp}
 * (这些特殊字符为表情符号)返回 false
 * 其它文字都返回 true
 */
var regEmoji = /^[^\uD800-\uDBFF]+$/; //
```
## 手机默认将数字检测为电话号码
在 `head` 中增加如下标签，不识别电话号码
```
<meta name="format-detection" content="telephone=no" />
```
## 弹窗后禁止底部页面滚动
* 普通弹窗禁止底部页面滚动
```javascript
$(window).bind('touchmove', function (e) {
    e.preventDefault();
});
```
* 复购弹窗内部有滚动，禁止底部页面滚动
```javascript
if ($(".order-addresslist").height() <= $(".address-pop-cont").height()) {
    $(window).bind('touchmove', function (e) {
        e.preventDefault();
    });
} else {
    $(window).bind('touchmove', function (e) {
        var $element = $(e.target);
        if ($element.parents('.address-pop-cont').length <= 0) {
            e.preventDefault();
        }
    });
}
```
* 关闭弹窗后允许页面滚动
```javascript
$(window).unbind('touchmove');
```
