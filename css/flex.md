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
## 布局方向
```CSS
 div {
   /* 水平方向布局 */
   flex-direction: column;
   /* 垂直方向布局 */
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
