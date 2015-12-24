# 文字超出范围显示省略号
## 单行显示省略号
```css
.test .ellipsis p{
  overflow:hidden;
  width:200px;
  white-space:nowrap;
  text-overflow:ellipsis;
}
```
## 多行显示省略号
```css
.artist-ellipsis{
  overflow: hidden;
  display: -webkit-box;
  -webkit-line-clamp: 3; /*最大行数为3行*/
  -webkit-box-orient: vertical; /*垂直方向*/
  text-overflow: ellipsis; }
```
## 盒模式
