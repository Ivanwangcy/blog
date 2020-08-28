# Nginx代理

## history 路由 nginx 配置

```sh

    location / {
        root /page/;
        index index.htm;
        try_files $uri $uri/ /index.html;
    }
```





>> [history路由模式下的nginx配置](https://www.cnblogs.com/imgss/p/11703422.html)
