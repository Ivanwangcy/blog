# Nginx 代理

## 反向代理配置

```sh
     location ~/api/ {
                proxy_pass http://xx.xxx.xx.com/;
                proxy_redirect / /api/;
        }
```

## history 路由 nginx 配置

当你在 post 路由下刷新页面时，nginx 会返回 404。这是什么原因呢？因为我们没有告诉 nginx 找不到某个文件时该怎么做。root 指定了 / 对应的单页静态资源目录，从而使 url 映射到 dist 目录下。

这个配置可以让你项目的 css，js 被顺利加载，但是碰到上面的 URL，nginx 就不知所措了。因为我们的 dist 文件夹下面并没有 post 这个文件或者文件夹，所以 nginx 会给你个 404 页面。try_files 就是为了解决这个问题的，try_files 语法如下：

```sh
    location / {
        root /page/;
        index index.htm;
        try_files $uri $uri/ /index.html;
    }
```

以上面的 <http://www.example.com/post> 为例，$uri 会匹配到 post，nginx 发现 dist 目录下下面没有 post 这个文件，也没有 post 这个文件夹，所以最后会返回 dist 目录下的 index.html。这样，index.html 被浏览器加载之后，前端路由就会工作，将用户需要的资源加载出来。而我们 build 出来的 css，js 文件，由于可以被 nginx 正确找到，则不会受到影响。

> > [history 路由模式下的 nginx 配置](https://www.cnblogs.com/imgss/p/11703422.html)
