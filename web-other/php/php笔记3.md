#PHP进阶
#类和对象
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









