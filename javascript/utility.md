#String.trim函数
```javascript
String.prototype.trim= function(){  
    // 用正则表达式将前后空格  
    // 用空字符串替代
    // 替换首尾空格
    return this.replace(/(^\s*)|(\s*$)/g, "");  
}
```
#对象深拷贝
```javascript
/*对象深拷贝*/
function clone(object){
    var key, newObject = object, isArray = object instanceof Array;
    if(object && (object instanceof Object || isArray)) {
        newObject = isArray ? [] : {};
        for(key in object){
            if(object.hasOwnProperty(key)){ // 是否为对象本身的属性, 过滤掉原型链上的属性
                newObject[key] = clone(object[key]);
            }
        }
    }
    return newObject;
}
```
