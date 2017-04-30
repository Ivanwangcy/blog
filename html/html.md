
# 全称 Hyper Text Markup Language -- 超文本标记语言

## html 发展史
1991 html

1995 html2

1996 html3.2

1997 html4.0
1999 html4.01

2000 xhtml1.0
2001 xhtml1.1
2005 xhtml2.0

2008 Html5  * 开始

** 2014 HTML5 * 正式发布 ** 

## HTML 文档结构
* 文档声明 (html5 声明的简化)
```html
<!DOCTYPE html>
```
* 文档头部
```html
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1.0,user-scalable=no"/>
</head>
```
* 文档主体
```html
<body>主体内容</body>
```
* 根节点 html 可以设置语言属性<br>


## 标签语义化(用正确的标签描述页面)
* SEO(Seach Engine Optimization) 搜索引擎优化, 对搜索引擎友好
* 可访问性    良好的结构和语义你的网页内容自然容易被搜索引擎抓取
* 可读性  能从结构中分离出表达的意义

-----
主流浏览器都兼容HTML5的新标签，对于 IE8 及以下版本不认识 HTML5的新元素，可以使用 JavaScript 创建一个没用的元素来解决，例如：
```html
<script>document.createElement("header");</script>
```
，也可以使用shiv来解决兼容性问题。
 
# 
 #
