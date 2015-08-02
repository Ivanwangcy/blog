#element.children实现浏览器兼容版
```javascript
/**
 * 自定义 Element 元素的方法 (Element和HTMLDocument等, 它们不是构造函数, 
 * 它们有原型对象, 可以使用自定义对象来扩展它)
 * [if 在不包含此属性的浏览器中模拟Element.children属性
 * 由于是Element子节点是类动态数组, 实时更新不能用传统的for循环,
 * 如: for (var i = 0; i < element.childNodes.length; i++)//不建议使用]
 * @param  {[无]} !document.documentElement.children [description]
 * @return {[Array]} [返回的是静态的数组, 而不是实时的NodeList/HTMLCollection对象, 无法达到原生效果]
 */
  if(!document.documentElement.children){
    // 给 Element 添加原型属性 children "__defineGetter__"非标准的Getter方法,但是浏览器几乎都适用
    Element.prototype.__defineGetter__("children",function(){
      var kids = [];
      for(var child = this.firstChild; child != null; child = child.nextSibling){//
        if(child.nodeType === 1) kids.push(child);
      }
      return kids;//
    });
  }
```
#window.getComputedStyle IE兼容实现
```javascript
    // if(!window.getComputedStyle) IE兼容实现
    function currentStyle(element){
      return element.currentStyle || window.getComputedStyle(element);
    }

    // 获取指定样式属性值
    function getStyle(element, cssPropertyName){
      return (element.currentStyle || window.getComputedStyle(element))[cssPropertyName];
    }
```
#getElementsByClassName浏览器兼容实现
```javascript
      /**
      * 实现getElementsByClassName方法，浏览器兼容
      */
      function getElementsByClassName(element, names){
        if(element.getElementsByClassName){
          return element.getElementsByClassName(names);
        }else{
          var elements = element.getElementsByTagName("*");
          var result = [],
              tempElement,
              nameArr = names.replace(/(^\s*)|(\s*$)/g, "").split(" "),
              flag,
              elementClassName;
          for(var i = 0; tempElement = elements[i]; i++){
            elementClassName = " " + tempElement.className + " ";
            flag = true;
            for(var j = 0; j < nameArr.length; j++){
              if(nameArr[j] && elementClassName.indexOf(" " + nameArr[j] + " ") === -1){
                flag = false;
                break;
              }
            }
            if(flag){
              result.push(tempElement);
            }
          }
          return result;
        }
      }
      var example = document.getElementById("example");
      console.info(getElementsByClassName(example, "aaa")); // 运行结果为包含id为p1, id为p2的元素列表
      console.info(getElementsByClassName(example, " aaa ")); // 运行结果为包含id为p1, id为p2的元素列表
      console.info(getElementsByClassName(example, "aa")); //[]
      console.info(getElementsByClassName(example, "aaabbb")); //[]
      console.info(getElementsByClassName(example, "bbb ccc"));// 运行结果为包含id为p3的元素列表
      console.log(getElementsByClassName(example, "ccc bbb"));// 运行结果为包含id为p3的元素列表
```
#事件监听兼容性实现
```javascript 
  var addEvent = document.addEventListener ?
          function(elem, type, listener, useCapture) {
              elem.addEventListener(type, listener, useCapture);
            } :
          function(elem, type, listener, useCapture) {
              elem.attachEvent('on' + type, listener);
            };
```
#dataset 自定义属性, 兼容实现
```javascript
      function dataset(user){
        var attributes = user.attributes;
        var datasetObj = {};
        for(var i = 0, attribute; attribute = attributes[i]; i++) {
          if(attribute.name.indexOf("data-") === 0){
            var attributeName = attribute.name.split("data-")[1];
            var humpName =attributeName.indexOf("-") === -1 ? attributeName : 
                              attributeName.replace(/\-([a-z])/g,
                                  function($,$1){
                                      return $1.toUpperCase();
                                  });
            datasetObj[humpName] = attribute.value;
          }
        }
        return datasetObj;
      }
```
#Object.create的兼容实现
```javascript
// Object.create的兼容实现 :
 
Object.create = null; // 置空create方法, 来测试下面的兼容实现
if(!Object.create || typeof Object.create !== "function"){
  Object.create = function(obj){
    // console.info(obj);
    if(!obj) return {}; // 如果无参数, 或者参数为null和undefined直接返回一个 Object 对象;
    if(typeof obj !== "object"){
      throw new TypeError("Object prototype may only be an Object or null: " + obj);
    }
    function Fn(){}
    Fn.prototype = obj;
    return new Fn();
  }
}
  var a = Object.create({x: 1, y: 2});
    alert(a.x);
```
#兼容低版本浏览器的bind方法的代码实现
```javascript
    Function.prototype.bind = null;
      /**
       * [if 如果没有bind方法,创建一个bind方法]
       * @param  {[type]} !Function.prototype.bind [description]
       * @return {[type]}                          [description]
       */
    if(!Function.prototype.bind){
      Function.prototype.bind = function(obj){
        if(typeof this !== "function"){
          // bind 函数的调用者必须是一个函数
          throw new TypeError( typeof this + " is not a function!");
        }
        var self = this,// 保存调用bind的函数
            
        // 保存调用时的参数 且 需要给self传递的参数, arguments[0] == obj 绑定的新函数
        selfParams = Array.prototype.slice.call(arguments, 1),        
            
        bridge = function(){}, // 如果用new来调用bind的返回函数,需要继承self原型,转接到bindFn
        bindFn = function(){// 创建新函数
        return self.apply(this instanceof bridge && obj ? this : obj || window,
            selfParams.concat(Array.prototype.slice.call(arguments)));
        };

        bridge.prototype = this.prototype;
        bindFn.prototype = new bridge();
        return bindFn;
      }
    }
    
      function move(x, y) {
          this.x += x;
          this.y += y;
      }
      var point = {x:1, y:2};
      var pointmove = move.bind(point, 2, 2);
      pointmove(); // {x:3, y:4}
      console.info(point);
      pointmove(); // {x:3, y:4}
      console.info(point);
  ```
