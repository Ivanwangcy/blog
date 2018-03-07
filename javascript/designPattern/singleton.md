# Singleton (单例) 模式

Singleton (单例) 模式被熟知的原因是因为它限制了类的实例化次数只能一次. 从经典意义上来说, Singleton 模式, 在该实例不存在的情况下, 可以通过一个方法创建一个类来实现创建类的新实例; 如果实例已经存在, 它会简单返回该对象的引用. Singleton 不同于静态类(或对象), 因为我们可以推迟它们的初始化, 这通常是因为它们需要一些信息, 而这些信息在初始化期间可能无法获得. 对于没有察觉到之前的引用的代码, 它们不会提供方便检索的方法. 这是因为它既不是对象, 也不是由一个 Singleton 返回的"类"; 它是一个结构. 思考一下闭包变量为何实际上并不是闭包, 而提供闭包的函数作用域是闭包. 在 JavaScript 中, Singleton 充当共享资源命名空间, 从全局命名空间中隔离出代码实现, 从而为函数提供单一访问点. 我们可以像如下这样实现一个 Singleton:

```js
var mySingleton = (function () {

  // 实例保持了 Singleton 的一个引用
  var instance;
  function init(){
    // Singleton
    // 私有方法和变量
    function privateMethod() {
      cosole.log("I am private");
    }
    var privateVariable = "I'm also private";
    var privateRandomNumber = Math.random();
    return {
        // 公有方法和变量
        publicMethod: function () {
          console.log("The public can see me!");
        },
        publicProperty: "I am also public",
        getRandomNumber: function () {
          return privateRandomNumber;
        }
    };
  };
  return {
    // 获取 Singleton 的实例, 如果存在就返回, 不存在就创建新实例
    getInstance: function () {
      if(!instance) {
        instance = init();
      }
      return instance;
    }
  };
})();

//错误的写法
var myBadSingleton = (function () {
  var instance;
  function init() {
      //Singleton
      var privateRandomNumber = Math.random();
      return {
        getRandomNumber: function () {
            return privateRandomNumber;
        }
      };
  };

  //实例
  return {
    //每次都创建新实例
    getInstance: function () {
      instance = init();
      return instance;
    }
  }
})();


var singleA = mySingleton.getInstance();
var singleB = mySingleton.getInstance();

console.log(singleA.getRandomNumber() === singleB.getRandomNumber()); // true

var badSingleA = myBadSingleton.getInstance();
var badSingleB = myBadSingleton.getInstance();

console.log(badSingleA.getRandomNumber() === badSingleB.getRandomNumber()); // false
```

值得注意的是类的静态实例 (对象) 和 Singleton 之间的区别: 当Singleton 可以作为一个静态的实例实现时, 它也可以延迟构建, 直到需要使用静态实例时, 无需使用资源或内存.

如果我们有一个可以直接被初始化的静态对象, 需要确保执行代码的顺序总是相同的 (例如: 在初始化期间 objCar 需要 objWheel 的情况), 当我们有大量的源文件时, 它并不能伸缩.

Singleton 和静态对象都是有用的, 但是我们不应该以同样的方式过度使用它们, 也不应该过度使用其他模式.   

在实践中, 当在系统中确实需要一个对象来协调其他对象时, Singleton 模式是很有用的. 在这里, 大家可以看到在这个上下文中模式的使用:

```js
//实际应用示例, 静态与单例模式使用
var singletonTester = (function(){

  function Singleton(options){
    options = options || {};

    //为Singleton 设置一些属性
    this.name = "SingletonName";
    this.pointX = options.pointX || 6;
    this.pointY = options.pointY || 10;
  }

  //实例持有者
  var instance;

  //静态方法和变量的模拟
  var _static = {
    name: "SingletonStaticName",

    //获取实例的方法, 返回 singleton 对象的 singleton 实例
    getInstance: function (options) {
      if(instance === undefined){
        instance = new Singleton(options);
      }
      return instance;
    }
  };

  return _static;
})();

var singletonTest = singletonTester.getInstance({
  pointX:100
});

//记录 pointX 的输出以便验证
console.log(singletonTest.name) // SingletonName
console.log(singletonTester.name) // SingletonStaticName
//输出: 100
console.log( singletonTest.pointX );
```

Singleton 很有使用价值, 通常当发现现在 JavaScript 中需要它的时候, 则表示我们可能需要重新评估我们的设计.

Singleton 的存在往往表明系统中的模块要么是系统紧密耦合, 要么是其逻辑过于分散在代码库的多个部分. 由于一系列的问题: 从隐藏的依赖到创建多个实例的难度, 底层依赖的难度等等, Singleton 的测试会更加困难.

## ES6 单例模式

实现起来超级简单。
```js
class Singleton {
  name = ''
}

export default new Singleton

// file A
import Singleton from './Singleton' // import 后指向同一个实例
Singleton.name = 'newNames'

// file B
import Singleton from './Singleton' // import 后指向同一个实例

console.log(Singleton.name) // 'newNames'

// Error 不能创建新实例 没有构造函数
let newInstance = new Singleton()
```
