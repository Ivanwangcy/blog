#字符串操作

##去除字符串首尾的空格

PHP中有三个函数可以去掉字符串的空格
trim去除一个字符串两端空格。
rtrim是去除一个字符串右部空格，其中的r是right的缩写。
ltrim是去除一个字符串左部空格，其中的l是left的缩写。
例子如下：
```php
echo trim(" 空格 ")."<br>";
echo rtrim(" 空格 ")."<br>";
echo ltrim(" 空格 ")."<br>";
```
##获取字符串的长度

php中有一个神奇的函数，可以直接获取字符串的长度，这个函数就是strlen()。
```php
//获取字符串长度
$love='I love you雨';
echo strlen($love); // 13
echo mb_strlen($love, "UTF8");//结果：11，此处的UTF8表示中文编码是UTF8格式，中文一般采用UTF8编码
```
##字符串的截取

php中有非常多的字符串处理函数，其中就有字符串截取函数。
###1、英文字符串的截取函数substr()
函数说明：substr(字符串变量,开始截取的位置，截取个数）
例如：
```php
$str='i love you';
//截取love这几个字母
echo substr($str, 2, 4);//为什么开始位置是2呢，因为substr函数计算字符串位置是从0开始的，也就是0的位置是i,1的位置是空格，l的位置是2。从位置2开始取4个字符，就是love。
```
###2、中文字符串的截取函数mb_substr()
函数说明：mb_substr(字符串变量,开始截取的位置，截取个数, 网页编码）
```php
$str='我爱你，中国';

//截取中国两个字

echo mb_substr($str, 4, 2, 'utf8');//为什么开始位置是4呢，和上一个例子一样，因为mb_substr函数计算汉字位置是从0开始的，也就是0的位置是我,1的位置是爱，4的位置是中。从位置4开始取2个汉字，就是中国。中文编码一般是utf8格式
```
##查找字符串

如果有一个字符串`$str = 'I want to study at imooc';`，怎么样找到其中的imooc在哪个位置呢？
查找字符串，我们需要用到PHP的查找字符串函数strpos();
函数说明：strpos(要处理的字符串, 要定位的字符串, 定位的起始位置[可选])
例子：
```php
$str = 'I want to study at imooc';
$pos = strpos($str, 'imooc');
echo $pos;//结果显示19，表示从位置0开始，imooc在第19个位置开始出现
```
##替换字符串

如果有一个字符串`$str = 'I want to learn js';`，怎么样将js字符替换成你想学的php字符呢？
替换字符串，我们需要用到PHP的替换函数`str_replace()`
函数说明：`str_replace(要查找的字符串, 要替换的字符串, 被搜索的字符串, 替换进行计数[可选])`
例子：
```php
$str = 'I want to learn js';
$replace = str_replace('js', 'php', $str);
echo $replace;//结果显示I want to learn php
```



