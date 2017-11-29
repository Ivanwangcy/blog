## Object.freeze()
冻结函数，使引用类型变量不可变
## Freezing Objects
```js
var obj = {
  prop: function() {},
  foo: 'bar'
};

// New properties may be added, existing properties may be
// changed or removed
obj.foo = 'baz';
obj.lumpy = 'woof';
delete obj.prop;

// Both the object being passed as well as the returned
// object will be frozen. It is unnecessary to save the
// returned object in order to freeze the original.
var o = Object.freeze(obj);

o === obj; // true
Object.isFrozen(obj); // === true

// Now any changes will fail
obj.foo = 'quux'; // silently does nothing
// silently doesn't add the property
obj.quaxxor = 'the friendly duck';

// In strict mode such attempts will throw TypeErrors
function fail(){
  'use strict';
  obj.foo = 'sparky'; // throws a TypeError
  delete obj.quaxxor; // throws a TypeError
  obj.sparky = 'arf'; // throws a TypeError
}

fail();

// Attempted changes through Object.defineProperty;
// both statements below throw a TypeError.
Object.defineProperty(obj, 'ohai', { value: 17 });
Object.defineProperty(obj, 'foo', { value: 'eit' });

// It's also impossible to change the prototype
// both statements below will throw a TypeError.
Object.setPrototypeOf(obj, { x: 20 })
obj.__proto__ = { x: 20 }
```
## Freezing Arrays
```js
let a = [0];
Object.freeze(a); // The array cannot be modified now.

a[0]=1; // fails silently
a.push(2); // fails silently

// In strict mode such attempts will throw TypeErrors
function fail() {
  "use strict"
  a[0] = 1;
  a.push(2);
}

fail();
The object being frozen is immutable.  However, it is not necessarily constant. The following example shows that a frozen object is not constant (freeze is shallow).

obj1 = {
  internal: {}
};

Object.freeze(obj1);
obj1.internal.a = 'aValue';

obj1.internal.a // 'aValue'
```
## Deep Freeze
```js
// To do so, we use this function.
function deepFreeze(obj) {

  // Retrieve the property names defined on obj
  var propNames = Object.getOwnPropertyNames(obj);

  // Freeze properties before freezing self
  propNames.forEach(function(name) {
    var prop = obj[name];

    // Freeze prop if it is an object
    if (typeof prop == 'object' && prop !== null)
      deepFreeze(prop);
  });

  // Freeze self (no-op if already frozen)
  return Object.freeze(obj);
}

obj2 = {
  internal: {}
};

deepFreeze(obj2);
obj2.internal.a = 'anotherValue';
obj2.internal.a; // undefined
```
