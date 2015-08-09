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
