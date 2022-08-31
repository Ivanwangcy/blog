# 使用 svg 实现一个圆角三角形

```html
<html>
  <head>
    <style>
      .triangle {
          fill: #0f0;
          stroke: #0ff;
          stroke-width: 30;
      }
    </style>
  </head>
  <body>
    <svg  width="250" height="250" viewBox="-50 -50 300 300">
      <polygon class="triangle" stroke-linejoin="round" points="100,0 0,200 200,200"/>
    </svg>
  </body>
</html>
```

参考链接：<https://www.cnblogs.com/coco1s/p/15009605.html>
