## Object.assign 合并对象属性
基本用法，如果浏览器实现了可以直接使用。
```javascript
Object.assign({a:1}, {b:3}, {a:5, b: 4, c:8})
// Object {a: 5, b: 4, c: 8}
```
兼容实现，引用外来库文件，安装：
```sh
$ npm install --save object-assign
```
node环境下使用：
```javascript
const objectAssign = require('object-assign');

objectAssign({foo: 0}, {bar: 1});
//=> {foo: 0, bar: 1}

// multiple sources
objectAssign({foo: 0}, {bar: 1}, {baz: 2});
//=> {foo: 0, bar: 1, baz: 2}

// overwrites equal keys
objectAssign({foo: 0}, {foo: 1}, {foo: 2});
//=> {foo: 2}

// ignores null and undefined sources
objectAssign({foo: 0}, null, {bar: 1}, undefined);
//=> {foo: 0, bar: 1}
objectAssign({foo: 0}, null, {bar: 1}, {foo:undefined});
//=> {foo: undefined, bar: 1}
```
## 自己实现，兼容性处理
```javascript
function toObject(val) {
  if(val === null || val === undefined){
    throw new TypeError('Object.assign cannot be called with null and undefined')
  }

  return Object(val)
}
function objectAssign(target, source){
  var to = toObject(target),
    from;
  for(var s = 1; s < arguments.length; s++){
    from = Object(arguments[s])

    for (var key in from) {
      // if (from.hasOwnProperty(key)) {
      if (hasOwnProperty.call(from, key)) { // 同上
        to[key] = from[key]
      }
    }
  }
}
```
