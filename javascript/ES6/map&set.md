# Map and Set 集合对象
和其他语言的Map或者Dictionary很像， 为了弥补 Object 对象和 Array 对象的不足，ES6 新增了两个实用的对象 `Map` 和 `Set`.
## Map 对象
map可以使用其它类型作为 key . (函数，布尔值，数值，字符串等都可以当键)， 如下：
```javascript
var map = new Map(); // 创建 空的 Map
var map = new Map([[1,"one"],[2, "two"],[3, "three"]]); // 创建一个带参数的 Map
map.set(4, "four");// 添加 key=>value -- Map {1 => "one", 2 => "two", 3 => "three", 4 => "four"}
map.has(4); // true 是否包含key
map.get(4); // "four" 获取值 value
map.delete(4); // true 成功删除 key
map.delete(4); // false 删除 key 失败，没有这个 key
map.has(4); // false
map.get(4); // undefined

Map {1 => 10, function => true, true => "true", "trace" => function} // 值也可以是任何类型
```
- 注意：
  - 由于一个key只能对应一个value，所以，多次对一个key放入value，后面的值会把前面的值冲掉；
  - 字符串的 key 和 数字的 key 相等 (`==`)，也可以同时存在, 它是全等(`===`)判断的；
## Set 对象
Set 是 key 的集合，不允许重复, 与 Map 的 key 类似，也有对应的方法，增加值使用 add(key)。
```javascript
var set = new Set(); // 空 Set 集合
var set = new Set([1,2,3]);
set.add(4); // 添加元素
set.delete(4); // 删除元素
set.has(4);
```
## 遍历 Map 和 Set
```javascript
for (let k of m) {
    console.log(k);
}
```
