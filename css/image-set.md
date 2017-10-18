## image-set
响应式图片处理，视网膜高清屏适配方案
```css
.img {
  background-image: url(img_2x.png);
  background-image: -webkit-image-set(
    url(img_2x.png) 2x,
    url(img_3x.png) 3x
  );
  
  background-image: image-set(
    url(img_2x.png) 2x,
    url(img_3x.png) 3x
  );
}
```
