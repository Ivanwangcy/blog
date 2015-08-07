# Backbone Model 模型创建

```javascript
      // 模型的3种赋值方法
      var Team = Backbone.Model.extend({
        defaults: {
          name: "aaa" // 设置默认值
        }
      });
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
