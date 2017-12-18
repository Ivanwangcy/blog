# CSS3 伸缩盒

## 新旧伸缩盒兼容模式
```CSS
.parent{
  display: -webkit-box;
  display: flex;
}
.sub{
  display: block;
  -webkit-box-flex: 1;
  flex: 1;
}
``` 
###布局方式水平 居中
```CSS
 div {

   /* 垂直方向布局, 从上到下依次排列布局 */
   flex-direction: column;

   /* 水平方向布局 从左到右排列 */
   flex-direction: row;
 }
```
## 空间分配
```css
  div {
    /* 两端对齐排列，相同的间隙 */
    justify-content: space-between;

    /* 居中排列 */
    justify-content: center;

    /* 纵向居中排列 */
    align-items: center;
  }
```
## 综合应用
中间自适应，两端对齐，垂直居中
```CSS
.box {
  /* 盒模型对象 */
  display: -webkit-box;
  display: flex;

  /* 垂直布局样式 */
  -webkit-box-align: center;
  align-items: : center;

  /* 水平布局样式 */
  -webkit-box-pack: justify;
  justify-content: : space-between;
}

.box .midChild {
  -webkit-box-flex: 1;
  flex: 1;
}
```
