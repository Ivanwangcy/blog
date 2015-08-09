#PHP进阶
##数组:
```php
$arr = array(); // 空数组

<?php
//创建一个索引数组，索引数组的键是“0”，值是“苹果”
$fruit = array("苹果","香蕉","菠萝");
print_r($fruit); // 输出数组
foreach($fruit as $val){
    echo $val; // foreach 循环取值
}
?>
```
###数组赋值:
```php
$arr = array('0'=>'苹果');
$arr = array();$arr[0]='苹果';
```
###索引数组:
```php
$fruit = array(

    '0'=>"苹果",

    '1'=>"香蕉",

    '2'=>"菠萝"

); 
```
###关联数组: 
```php
$fruit = array(

    'apple'=>"苹果",

    'banana'=>"香蕉",

    'pineapple'=>"菠萝"

); 
```
##函数:
```php
function say()
{
    echo 'hello world';
}

say();//在这里调用函数
```
###函数的参数:
```php
function sum($a, $b) {
    echo $a + $b;
}

sum(1,2);//在这里调用函数计算1+2的值
```
###函数返回值: 
```php
function sum($a, $b) {
    return $a+$b;
}
$c = sum(1, 2);//在这里调用函数取得返回值
```
###可变函数
```php
function func() {
    echo 'my function called.';
}
$name = 'func';

$name();//调用可变函数
```
###内置函数

内置函数指的是PHP默认支持的函数，PHP内置了很多标准的常用的处理函数，包括字符串处理、数组函数、文件处理、session与cookie处理等。
```php
$str = '苹果很好吃。';
$str = str_replace('苹果', '香蕉', $str);//请将变量$str中的苹果替换成香蕉
echo $str;
```
