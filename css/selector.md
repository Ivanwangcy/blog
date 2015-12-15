# CSS  选择器分类
1. 简单选择器
  * 标签选择器
  * 类选择器
  * id选择器
  * 通配符选择器   * 选择所有元素
  * 属性选择器  
    * [att]   [disabled]{/*属性声明*/}  拥有此属性
    * [att=val] [type=button]{/*属性声明*/} 拥有属性,对应的值相等
    * [att~=val] [class~=sports]{color:blue;} 属性值包含或等于val
    * [att|=val] 属性值等于val或以val开头用连接符"-"分隔的字符串
    * [att^=val] 以val开头的属性值,如果val是符号或者包含空格 需要加 双引号 "" 如:[href^="#"]{}
    * [att$=val] 以val结尾的属性值
    * [att*=val] 属性值包含val
  * 伪类选择器
      * a:link 选择页面上所有连接, href必须有值得元素 只能用在a标签
      * a:visited 访问过的链接元素 只能用在 a标签
      * a:hover 鼠标经过, 可以应用到其它标签上
      * a:active 鼠标点击的 可以用到其它标签上
      * :enabled  可用状态
      * :disabled  不可用状态
      * :checked  选中状态
      * li:first-child 第一个li标签,父元素的第一个子元素，并且是li标签
      * li:lash-child 最后一个li标签
      * li:nth-child(even) 偶数项的li标签
      * li:nth-child(odd) 奇数项
      * li:nth-child(3n+1) 1 4 7 10 ...
      * li:nth-last-child(3n+1) 从后往前算
      * only-child 选择只有一个子元素的标签
      * dd:first-of-type 第一个这种类型的标签 第一个dd
      * dt:last-of-type 最后一个dt
      * dd:nth-of-type(even) 偶数个dd元素
      * dt:nth-last-of-type(2n) 倒数的加2隔开, 1 2 4 6 8
      * span:only-of-type  只有这个span类型的标签, span 是父类的唯一类型
      * 下列不常用的:
        * :empty 没有子元素的标签
        * :root html根标签
        * :not()  参数是简单选择器, 不包含指定选择器的标签
        * :tartget 被锚点的目标元素
        * :lang()
      * 几个简单选择器可以组合在一起使用
        *  img[src$=jpg]{} 选择img标签,src以jpg结尾的img标签
        * \#banner:hover{} id为banner hover状态 鼠标经过
2. 伪元素选择器 :: (为了区分伪类选择器使用"::"双冒号)
    * ::first-letter{color:red;}   为第一个字母设置特殊样式
    * ::first-line{color:red;}  伪元素选择器可以为第一行文字设置特殊样式
    * ::before{content:"before";} 与content联合使用, 把content属性值插入到之前
    * ::after{content:"after";}  把content属性值插入到之后
    * ::selection 应用于被用户选中的内容;
3. 组合选择器
    * 后代选择器  .main h2{} 类main 下面的所有后代 h2 标签 包含 子代的子代等
    * 子选择器 .main>h2{} 类main 下属子代的 h2 标签
    * 兄弟选择器
    * h2+p{color:red;} 选择直接前面(相邻的)是h2标签的  p  标签
    * h2~p{color:red;} 选择前面同级别标签有h2的 p 标签 (不需要是紧邻的)
    * 选择器分组
      * h1,h2,h3{color:gray;} 选择列出的标签,统一样式
    * 继承
      * body{font-family:"Microsoft Yahei";} 所有子元素使用微软雅黑, 所有子元素继承这个样式
      * 可继承属性 color, font, text-align, list-style
      * 非继承属性 background, border, position
      * 在API文档中查看是否可继承: inherited  yes|no

## **注意: 超链接(a标签) 样式顺序: L-V-H-A **
```css
a:link{}
a:visited{}
a:hover{}
a:active{}
```
## css选择器中:first-child与:first-of-type的区别

### :first-child选择器是css2中定义的选择器，从字面意思上来看也很好理解，就是第一个子元素。比如有段代码：

p:first-child  匹配到的是p元素,因为p元素是div的第一个子元素；

h1:first-child  匹配不到任何元素，因为在这里h1是div的第二个子元素，而不是第一个；

span:first-child  匹配不到任何元素，因为在这里两个span元素都不是div的第一个子元素；



### 然后，在css3中又定义了:first-of-type这个选择器，这个跟:first-child有什么区别呢？还是看那段代码：

p:first-of-type  匹配到的是p元素,因为p是div的所有类型为p的子元素中的第一个；

h1:first-of-type  匹配到的是h1元素，因为h1是div的所有类型为h1的子元素中的第一个；

span:first-of-type  匹配到的是第三个子元素span。这里div有两个为span的子元素，匹配到的是它们中的第一个。



### 所以，通过以上两个例子可以得出结论：
:first-child 匹配的是某父元素的第一个子元素，可以说是结构上的第一个子元素。

:first-of-type 匹配的是某父元素下相同类型子元素中的第一个，比如 p:first-of-type，就是指所有类型为p的子元素中的第一个。这里不再限制是第一个子元素了，只要是该类型元素的第一个就行了。

同样类型的选择器 :last-child  和 :last-of-type、:nth-child(n)  和  :nth-of-type(n) 也可以这样去理解。

# CSS 优先级
* a = 行内元素                       1000
* b = ID选择器的数量                 100
* c = 类, 伪类和属性选择器的数量      10
* d = 标签选择器和伪元素选择器的数量  1

# CSS 层叠
* 相同属性: 优先级高的会覆盖优先级低的;
* 相同属性且优先级相同: 后面的覆盖前面的;
* 不同的属性会合并;

# 改变优先级
1. 改变先后顺序, 同级别时改变顺序来覆盖其他样式
2. 提升选择器优先级, 增加选择器级别
3. !important  增加优先级, 可以覆盖后面的样式;最后有这个方法,前面的都不行时再用
