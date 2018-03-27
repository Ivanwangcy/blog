## 旧弹性伸缩盒 布局模式

## 弹性盒布局

### display: -webkit-box; 旧盒模型

```css
  /*父容器使用*/
 .class {
   display: -webkit-box;
   -webkit-box-align: center;  // 盒内元素垂直居中
   -webkit-box-pack: justify;
 }
  /*子容器使用*/
  .son {
    display: -webkit-box;
    -webkit-box-align: center;  // 盒内元素垂直居中
  }

. {
    -webkit-box-flex: 1;
  }


```

### display: flex; 新盒模型
