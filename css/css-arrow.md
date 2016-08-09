# 使用 CSS 实现的箭头样式

## 实心箭头
```CSS
.arrow{
  border: 10px solid transparent;
  border-left-color: red;
  width: 0;
  height: 0;
}
```
## 线框箭头
```css
.arrow::before, .arrow::after{
  position: absolute;
  content: " ";
  border: 7px solid transparent;
  border-left-color: #47b34f;
  right: -15px;
}

.arrow::after{
  border-left-color: #fff;
  right: -13px;
}
```
## 气泡框

## 梯形
```CSS
.trapezoid {
  border-bottom: 100px solid red;
  border-left: 50px solid transparent;
  border-right: 50px solid transparent;
  height: 0;
  width: 100px;
}
```
