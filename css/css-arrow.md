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
<<<<<<< HEAD

## 梯形
```CSS
.trapezoid {
  border-bottom: 100px solid red;
  border-left: 50px solid transparent;
  border-right: 50px solid transparent;
  height: 0;
  width: 100px;
=======
```css

/*箭头居中*/
.container{
  border: 1px solid #e8e8e8;
  border-radius: 3px;
  background: #fafafa;
  position: relative;
}

.container::before, .container::after{
  border: 10px solid transparent;
  border-left-width: 1px;
  border-right-color: #fafafa;
  position: absolute;
  content: " ";
  left: -10px;
  -webkit-transform: translateY(-50%);
  transform: translateY(-50%);
}

.container::before{
  left: -11px;
  border-right-color: #e8e8e8;
>>>>>>> ced11a76b866c46e3c3bce88612b356628180f75
}
```
