## IconFont
创建图标字体库：
－ 使用美工做好的`PSD`文件；
－ 导入到 `Ai` 中；
－ 保存为 svg 格式；
－ 在线生成字体库；
- 推荐链接：[http://www.iconfont.cn/plus](http://www.iconfont.cn/plus), 这里有很多的开源字体供下载；
```css

```
## 字体文件格式跨域问题

```sh
# Nginx 服务器配置：
  location ~* \.(eot|ttf|woff|svg|otf)$ {
    add_header Access-Control-Allow-Origin *;
  }
```


http://fontello.com/
