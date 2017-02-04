# String.trim函数
```javascript
String.prototype.trim= function(){  
    // 用正则表达式将前后空格  
    // 用空字符串替代
    // 替换首尾空格
    return this.replace(/(^\s*)|(\s*$)/g, "");  
}
```
# 对象深拷贝
```javascript
/*对象深拷贝*/
function clone(object){
    var key, newObject = object, isArray = object instanceof Array;
    if(object && (object instanceof Object || isArray)) {
        newObject = isArray ? [] : {};
        for(key in object){
            if(object.hasOwnProperty(key)){ // 是否为对象本身的属性, 过滤掉原型链上的属性(继承的属性)
                newObject[key] = clone(object[key]);
            }
        }
    }
    return newObject;
}
```
# 识别标准类型和内置对象类型
```javascript
function type(object){
      //不能直接使用 object.toString() 方法, 要调用Object原型方法
      //toString 之后得到的结果是这样 [object number] ,需要截取第9位开始和后2位结束
      //小写输出
    return Object.prototype.toString.call(object).slice(8,-1).toLowerCase();
  }
```
# 字符串驼峰替换(两种方式)
```javascript
var name = "account-name-name";
// 第一种方法
// name.replace(/([a-z]+)(\-)([a-z])/g,);
name.replace(/\-([a-z])/g,function($,$1){
  return $1.toUpperCase();
});
// 第二种方法
name.replace(/\-([a-z])/g,RegExp.$1.toUpperCase());
```
#  参数查询
