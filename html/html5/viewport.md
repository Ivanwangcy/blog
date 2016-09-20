# HTML5之viewport使用参数介绍

互联网发展越来越快，各种技术层出不穷，其中各种设备的显示尺寸分辨率大小不一，这也是目前我们前端人员比较纠结的问题：如何一次开发，在不同的界面都能友好显示呢！  

幸好HTML5中Viewport的出现了！Viewport的出现让我们开发出来的应用或页面在不同大小的设备上都能统一友好显示！  


## viewport 语法介绍：
```html
 <!-- html document  -->
 <meta name=”viewport”
content=”
height = [pixel_value | device-height] ,
 width = [pixel_value | device-width ] ,
 initial-scale = float_value ,
 minimum-scale = float_value ,
 maximum-scale = float_value ,
 user-scalable = [yes | no] ,
 target-densitydpi = [dpi_value | device-dpi | high-dpi | medium-dpi | low-dpi],
 minimal-ui
”
/>
```
## 参数解释：
width——控制 viewport 的大小，可以指定的一个值或者特殊的值，如 device-width 为设备的宽度（单位为缩放为 100% 时的 CSS 的像素）。

height——和 width 相对应，指定高度

- target-densitydpi——一个屏幕像素密度是由屏幕分辨率决定的，通常定义为每英寸点的数量（dpi）。Android支持三种屏幕像素密度：低像素密度，中像素密度，高像素密度。一个低像素密度的屏幕每英寸上的像素点更少，而一个高像素密度的屏幕每英寸上的像素点更多。Android Browser和WebView默认屏幕为中像素密度。


- 下面是 target-densitydpi 属性的取值范围  
  - device-dpi: 使用设备原本的 dpi 作为目标 dp。 不会发生默认缩放。

  - high-dpi: 使用hdpi 作为目标 dpi。 中等像素密度和低像素密度设备相应缩小。

  - medium-dpi: 使用mdpi作为目标 dpi。 高像素密度设备相应放大， 像素密度设备相应缩小。 这是默认的target density.

  - low-dpi: 使用mdpi作为目标 dpi。中等像素密度和高像素密度设备相应放大。

  -  value: 指定一个具体的dpi 值作为target dpi. 这个值的范围必须在70–400之间。
```html
<!-- html document -->
 <meta name=”viewport” content=”target-densitydpi=device-dpi” />
 <meta name=”viewport” content=”target-densitydpi=high-dpi” />
 <meta name=”viewport” content=”target-densitydpi=medium-dpi” />
 <meta name=”viewport” content=”target-densitydpi=low-dpi” />
 <meta name=”viewport” content=”target-densitydpi=200″ />
 ```  
为了防止Android Browser和WebView 根据不同屏幕的像素密度对你的页面进行缩放，你可以将viewport的target-densitydpi 设置为 device-dpi。当你这么做了，页面将不会缩放。相反，页面会根据当前屏幕的像素密度进行展示。在这种情形下，你还需要将viewport的width定义为与设备的width匹配，这样你的页面就可以和屏幕相适应。

- initial-scale——初始缩放。即页面初始缩放程度。这是一个浮点值，是页面大小的一个乘数。例如，如果你设置初始缩放为“1.0”，那么，web页面在展现的时候就会以target density分辨率的1:1来展现。如果你设置为“2.0”，那么这个页面就会放大为2倍。

- maximum-scale——最大缩放。即允许的最大缩放程度。这也是一个浮点值，用以指出页面大小与屏幕大小相比的最大乘数。例如，如果你将这个值设置为“2.0”，那么这个页面与target size相比，最多能放大2倍。

- user-scalable——用户调整缩放。即用户是否能改变页面缩放程度。如果设置为yes则是允许用户对其进行改变，反之为no。默认值是yes。如果你将其设置为no，那么minimum-scale 和 maximum-scale都将被忽略，因为根本不可能缩放。  

所有的缩放值都必须在0.01–10的范围之内。

- 例：1.设置屏幕宽度为设备宽度，禁止用户手动调整缩放
```html
<meta name=”viewport” content=”width=device-width,user-scalable=no” />
```
- 例:2.设置屏幕密度为高频，中频，低频自动缩放，禁止用户手动调整缩放
```html
<meta name="viewport" content="width=device-width,target-densitydpi=high-dpi,initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0, user-scalable=no"/>
```
## minimal-ui
iOS 7.1的Safari为meta标签新增minimal-ui属性，在网页加载时隐藏地址栏与导航栏
```html
<meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,minimal-ui">
```
