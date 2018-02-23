大标题
==
中标题
---
补空行, 下面增加一条线

---
图标:ok:

# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

使用两个空格一个回车来换行，或者使用&lt;br&gt;  
普通文本  
多行文本*倾斜* **加粗** ~~删除线~~
<br> 换行

`高亮`
[文字链接](https://github.com/Ivanwangcy "悬停显示")
<br>
## 无序列表:
* listitem
* listitem
* listitem
    * childitem
        * childitem

<br>

## 有序列表:
1. 封装
2. 继承
3. 多态

<br>加图片
![baidu](http://www.baidu.com/img/bdlogo.gif "百度logo")

## 链接
<http://www.baidu.com>

## 邮箱
<wcy5211678@163.com>

---
> 块引用
>> 子区块
>>> 子区块
>>>> 子区块
>>>>> 子区块

## 代码
---
```java
public static void main(String[] args){
  System.out.println("Hello world!");//Java
}
```
---
```javascript
(function(){
  console.info("Hello world!");//javascript
}());
```
---
```bash
$ npm install jquery --save # 安装jQuery
```
## 绘制表格
| Tables | Are | Cool |
| ------ |:---:| ----:|
| col 3 is | right-aligned | $1600 |
| col 2 is | centered | $12 |
| zebra stripes | are neat | $1 |
## 绘制流程图
### 序列表
```sequence
    Alice->John: Hello John, how are you?
    loop every minute
        John-->Alice: Great!
    end
```
```sequenceDiagram
Note left of 购物车: 购物车去结算进入商城结算
购物车-->结算页: 商超结算
Note right of 秒杀详情页: 立即下单进入秒杀结算
秒杀详情页-->>结算页: 秒杀结算
Note left of 单品详情页: 立即下单进入单品结算
单品详情页->>结算页: 单品结算
结算页->侧边栏: 查看商品详情
结算页->侧边栏: 修改支付方式
```
