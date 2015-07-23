#element.children实现浏览器兼容版
```javascript
/**
 * 自定义 Element 元素的方法 (Element和HTMLDocument等, 它们不是构造函数, 它们有原型对象, 可以使用自定义对象来扩展它)
 * [if 在不包含此属性的浏览器中模拟Element.children属性
 * 由于是Element子节点是类动态数组, 实时更新不能用传统的for循环,
 * 如: for (var i = 0; i < element.childNodes.length; i++)//不建议使用]
 * @param  {[无]} !document.documentElement.children [description]
 * @return {[Array]} [返回的是静态的数组, 而不是实时的NodeList/HTMLCollection对象, 无法达到原生效果]
 */
  if(!document.documentElement.children){
    //给 Element 添加原型属性 children "__defineGetter__"非标准的Getter方法,但是浏览器几乎都适用
    Element.prototype.__defineGetter__("children",function(){
      var kids = [];
      for(var child = this.firstChild; child != null; child = child.nextSibling){//
        if(child.nodeType === 1) kids.push(child);
      }
      return kids;//
    });
  }
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
