# Backbone 简单介绍 -- Backbone 入门
## 基本使用
* 直接创建对象
* 给构造函数添加实例方法和静态方法
* 继承操作
* 自定义事件
* 数据与服务器
* 路由与历史管理
* 事件委托
* 前端模板

## Backbone 引用及依赖库
```html
    <script src="lib/underscore.js" charset="utf-8"></script>
    <script src="lib/zepto.js" charset="utf-8"></script>
    <script src="lib/backbone.js" charset="utf-8"></script>
```
## Backbone 与 requireJS
...
## Backbone Model 模型创建

```javascript
      // 模型的3种赋值方法
      var Team = Backbone.Model.extend({
        defaults: {
          name: "aaa" // 设置默认值
        }
      });

      // 模型实例化和 get/set 方法
      var team0 = new Team();
      console.log(team0.get("name")); // aaa

      // 实例化时传值
      var team1 = new Team({
        name: "newname"
      });
      console.log(team1.get("name")); // newname

      // set 方法传值
      team1.set({
        name: "setname",
        age: 19
      });

      console.log(team1.get("name")); // setname
      console.log(team1.get("age")); // 19
```      
## 模型的事件处理程序, set() 触发change事件, -- 使用 set() 提升封装原则
```javascript
    var Team = Backbone.Model.extend({
      initialize: function(){
        this.bind("change", this.changeHandler);
      },
      changeHandler:function(){
        alert("changed name value to: " + this.get("name"));
      }
    });

    var team1 = new Team();
    team1.set({name: "Hello"}); // 只有 set 函数才会触发 change 事件 成功 alert
```
