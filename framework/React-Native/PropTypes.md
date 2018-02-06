## React 的 PropTypes 用法
```javascript
import PropTypes from 'prop-types'

propTypes: {
   // required

   requiredFunc: PropTypes.func.isRequired, // 函数类型必传
   requiredAny: PropTypes.any.isRequired,  // 任何类型

   // primitives, optional by default

   bool: PropTypes.bool,  //  布尔
   func: PropTypes.func, // 函数
   number: PropTypes.number, // 数字
   string: PropTypes.string // 字符串
 }
```
## PropTypes 的種類
```javascript
 PropTypes.array           // 数组类型

PropTypes.bool.isRequired // Boolean 且必要。

PropTypes.func            // 函数类型

PropTypes.number          // 数值型

PropTypes.object          // 对象型

PropTypes.string          // 字符串

PropTypes.node            // 任何相同类型的数组: numbers, strings, elements 等

PropTypes.element         // React 组件元素

PropTypes.instanceOf(XXX) // 某个对象的实例

PropTypes.oneOf(['foo', 'bar']) // 枚举值：其中一个字符串

PropTypes.oneOfType([PropTypes.string, PropTypes.array]) // 枚举类型：其中一种类型

PropTypes.arrayOf(PropTypes.string)  // 字符串型数组

PropTypes.objectOf(PropTypes.string) // 具有字符串属性的对象

PropTypes.shape({                          // 包含这些属性的对象

  color: PropTypes.string,
  fontSize: PropTypes.number
}); // shape 定义对象内部的格式和类型
PropTypes.any.isRequired  // 可以是任何格式，且必要。


// 自定義格式(當不符合的時候，會顯示Error)

// 不要用`console.warn` 或者 throw, 因为它在`oneOfType` 的情况下無效。


customPropType: function(props, propName, componentName) {
  if (!/^[0-9]/.test(props[propName])) {
    return new Error('Validation failed!');
  }
}

```
## react native 原生组件的属性类型
- View.proptypes.style
- Image.propTypes.style
