# scss 入门
面向对象的CSS, 像写代码一样写css样式。
## 嵌套样式
```css
.content{
  font-size: 18px;
  .title{
    color: red;
  }
  &.checked {
  
  }
}
```
## 混合

## 定义变量
```scss
$themeColor: red;

body{
  color: $themeColor;
}
```

## 导入样式
```scss
@import "style.scss"
```

## 注释
单行注释跟JavaScript语言中的注释一样，使用又斜杠（//），但单行注释不会输入到CSS中。

```scss
/*
 正常css注释
 */

// 双斜杆单行注释

```

## 函数
