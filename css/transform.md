# transform 变换效果

## 3D 变换
想实现3D的效果，设置元素的样式，如下：
```css
.container{
  -webkit-transform-style: preserve-3d;
  transform-style: preserve-3d;
}
```
## 透视/景深效果
```css
.container{
  -webkit-perspective: 700px;
  perspective: 700px;
}
```
## 变换函数
```css
.container{
  /* 旋转角度 */
  -webkit-transform: rotate(90deg);
  transform: rotate(90deg);
  /*缩放比例*/
  -webkit-transform: scale(2);
  transform: scale(2);

  /* 垂直方向，移动自身一半的距离 */
  -webkit-transform: translateY(-50%);
  transform: translateY(-50%);
}
```
