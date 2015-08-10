#PHP进阶
##类和对象
类是面向对象程序设计的基本概念，通俗的理解类就是对现实中某一个种类的东西的抽象， 比如汽车可以抽象为一个类，汽车拥有名字、轮胎、速度、重量等属性，可以有换挡、前进、后退等操作方法。

```php
定义一个类
class Car {
    var $name = '汽车';
    function getName() {
        return $this->name;
    }
}

//实例化一个car对象
$car = new Car();
$car->name = '奥迪A6'; //设置对象的属性值
echo $car->getName();  //调用对象的方法 输出对象的名字
```
##定义类的方法

方法就是在类中的function，很多时候我们分不清方法与函数有什么差别，在面向过程的程序设计中function叫做函数，在面向对象中function则被称之为方法。
同属性一样，类的方法也具有public，protected 以及 private 的访问控制。
访问控制的关键字代表的意义为：
public：公开的
protected：受保护的
private：私有的

###使用关键字static修饰的，称之为静态方法，静态方法不需要实例化对象，可以通过类名直接调用，操作符为双冒号::。
```php
class Car {
    public static function getName() {
        return '汽车';
    }
​}
echo Car::getName(); //结果为“汽车”
```
##构造函数和析构函数

###PHP5可以在类中使用*__construct()*定义一个构造函数，具有构造函数的类，会在每次对象创建的时候调用该函数，因此常用来在对象创建的时候进行一些初始化工作。
```php
class Car {
   function __construct() {
       print "构造函数被调用\n";
   }
}
$car = new Car(); //实例化的时候 会自动调用构造函数__construct，这里会输出一个字符串
```
在子类中如果定义了__construct则不会调用父类的__construct，如果需要同时调用父类的构造函数，需要使用parent::__construct()显式的调用。
```php
class Car {
   function __construct() {
       print "父类构造函数被调用\n";
   }
}
class Truck extends Car {
   function __construct() {
       print "子类构造函数被调用\n";
       parent::__construct();
   }
}
$car = new Truck();
```
###同样，PHP5支持析构函数，使用*__destruct()*进行定义，析构函数指的是当某个对象的所有引用被删除，或者对象被显式的销毁时会执行的函数。
```php
class Car {
   function __construct() {
       print "构造函数被调用 \n";
   }
   function __destruct() {
       print "析构函数被调用 \n";
   }
}
$car = new Car(); //实例化时会调用构造函数
echo '使用后，准备销毁car对象 \n';
unset($car); //销毁时会调用析构函数
```
当PHP代码执行完毕以后，会自动回收与销毁对象，因此一般情况下不需要显式的去销毁对象。

##Static静态关键字

静态属性与方法可以在不实例化类的情况下调用，直接使用类名::方法名的方式进行调用。静态属性不允许对象使用->操作符调用。

##对象继承

继承是面向对象程序设计中常用的一个特性，汽车是一个比较大的类，我们也可以称之为基类，除此之外，汽车还分为卡车、轿车、东风、宝马等，因为这些子类具有很多相同的属性和方法，可以采用继承汽车类来共享这些属性与方法，实现代码的复用。

```php
class Car {
    public $speed = 0; //汽车的起始速度是0
    
    public function speedUp() {
        $this->speed += 10;
        return $this->speed;
    }
}
//定义继承于Car的Truck类
class Truck {
    public function speedUp() {
        $this->speed += 60;
        return $this->speed;
    }
}

$car = new Truck();
$car->speedUp();
echo $car->speed;
```
##重载

PHP中的重载指的是动态的创建属性与方法，是通过魔术方法来实现的。属性的重载通过__set，__get，__isset，__unset来分别实现对不存在属性的赋值、读取、判断属性是否设置、销毁属性。
```php
class Car {
    public $speed = 10;

    //在这里使用重载实现speedDown方法
    public function __call($name, $args) {
        if($name == 'speedDown') {
            $this->speed -= 10;
        }
    }
}
$car = new Car();
$car->speedDown(); //调用不存在的speedDown方法
echo $car->speed;
```
##对象的高级特性

对象比较，当同一个类的两个实例的所有属性都相等时，可以使用比较运算符==进行判断，当需要判断两个变量是否为同一个对象的引用时，可以使用全等运算符===进行判断。
```php
class Car {
    public $name = 'car';
    
    public function __clone() {
        $obj = new Car();
        $obj->name = $this->name;
    }
}
$a = new Car();
$a->name = 'new car';
$b = clone $a;
if ($a == $b) echo '==';   //true
if ($a === $b) echo '==='; //false

$str = serialize($a); //对象序列化成字符串
echo $str.'<br>';
$c = unserialize($str); //反序列化为对象
var_dump($c);
```





