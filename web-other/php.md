#PHP笔记

##输出语句: echo
###输出字符串: (单引号 ' 或者双引号 ")
```php
<?php echo "Hello world!"; ?>
<?php echo 'Hello world!'; ?>
```
###连接字符串: (使用 . 连接字符串)
 ```php
 <?php  echo 'Hi '."imooc! ".'Welcome to imooc! '."Hello world!";?>
 ```
*. 和 .=*

###输出表达式: 
```php
<?php echo 1+1; ?>
```
###输出多条语句: 使用 ; 分号隔开
```php
 <?php 
    echo "欢迎同学们！";
    echo "Welcome" . " to imooc!";
    echo 1+2+3+4+5;
    ?>
```
##注释: // 必须在 <?php ?> 之间
```php   
    <?php 
    // PHP 注释语句
    echo "欢迎同学们！";
    echo "Welcome" . " to imooc!";
    echo 1+2+3+4+5;
    ?>
```
##变量:
```php
<?php
    $var = "大家来学PHP";
    echo $var;
    echo "<br />";
    $var = "学PHP上慕课网";
    echo $var;
?>
```
##函数: 
```php
var_dump($n); // 输出变量类型
memory_get_usage(); //内存使用情况
unset($var); // 注销定义,变量值为NULL;
date_default_timezone_set('asia/shanghai'); // 设置时区
```
##双引号支持标量类型输出: (单引号会普通输出)
```php
$love = "I love you!"; 
$string1 = "慕课网,$love";
```
###字符串Heredoc结构形式: 
```php
$string1 = <<<GOD
我有一只小毛驴，我从来也不骑。
有一天我心血来潮，骑着去赶集。
我手里拿着小皮鞭，我心里正得意。
不知怎么哗啦啦啦啦，我摔了一身泥.
GOD;
```
##特殊类型: 
###特殊类型 -- 资源: 
```php
//首先采用“fopen”函数打开文件，得到返回值的就是资源类型。
$file_handle = fopen("/data/webroot/resource/php/f.txt","r");
if ($file_handle){
    //接着采用while循环（后面语言结构语句中的循环结构会详细介绍）一行行地读取文件，然后输出每行的文字
    while (!feof($file_handle)) { //判断是否到最后一行
        $line = fgets($file_handle); //读取一行文本
        echo $line; //输出一行文本
        echo "<br />"; //换行
    }
}
fclose($file_handle);//关闭文件
```
###特殊类型 -- 空类型: 
```php
$var; 未赋值, $var = null, $var = NULL, unset($var);
```
##常量: 
```php
$p = "PII";
define("PI", 3.1415926);
define($p, 3.14);
```
###常量有什么用呢？
常量主要功效是可以避免重复定义，篡改变量值。在我们进行团队开发时，或者代码量很大的时候，对于一些第一次定义后不改变的量，如果我们使用变量，在不知情的情况下，使用同一变量名时，变量值就会被替换掉，从而会引发服务器执行错误的任务。
此外，使用常量还能提高代码的可维护性。如果由于某些原因，常量的值需要变更时候，我们只需要修改一个地方。例如在做计算中，起初我们取圆周率为3.14，于是很多计算中我们都使用3.14进行计算，当要求计算精度提高，圆周率需要取3.142的时候，我们不得不修改所有使用3.14的代码，倘若代码量比较多时，不仅工作量大，还可能遗漏。

###认识一下系统常量

系统常量是PHP已经定义好的常量，我们可以直接拿来使用，常见的系统常量有：
（1）__FILE__ :php程序文件名。它可以帮助我们获取当前文件在服务器的物理位置。
（2）__LINE__ :PHP程序文件行数。它可以告诉我们，当前代码在第几行。
（3）PHP_VERSION:当前解析器的版本号。它可以告诉我们当前PHP解析器的版本号，我们可以提前知道我们的PHP代码是否可被该PHP解析器解析。
（4）PHP_OS：执行当前PHP版本的操作系统名称。它可以告诉我们服务器所用的操作系统名称，我们可以根据该操作系统优化我们的代码。
```php
echo __FILE__;
echo "<br />";
echo __LINE__;
echo "<br />";
echo PHP_VERSION;
echo "<br />";
echo PHP_OS;
echo "<br />";
```
###常量取值 constant 函数:
```php
$p = "PI";
constant($p);
```
###判断常量是否被定义:
```php
define("PI1",3.14);
$p = "PI1";
$is1 = defined($p);
$is2 = defined("PI2");
```
##PHP赋值运算符:
```php
$b = $a; // 普通赋值
 $c = &$a; // 引用赋值
```
##PHP中的三元运算符

(“?:”)三元运算符也是一个比较运算符，对于表达式(expr1)?(expr2):(expr3)，如果expr1的值为true，则此表达式的值为expr2，否则为expr3。








