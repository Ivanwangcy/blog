# nginx 配置PHP
```perl
# pass the PHP scripts to FastCGI server listening on127.0.0.1:9000
#
location ~ \.php$ {
      root           D:/php/www;
      fastcgi_pass   127.0.0.1:9000;
      fastcgi_index  index.php;
      fastcgi_param  SCRIPT_FILENAME  $document_root$fastcgi_script_name;
      include        fastcgi_params;
}
配置CDN，映射到本地代码
# cdn
server {
    listen       80;
    server_name  static-o2o.360buyimg.com;

    location / {
        # root   D:/workspace/pdj_static_cdn/; # 到家 CDN
        root   D:/workspace/o2o-trade-static-activity-cdn/; # 活动页 CDN
    }
}
```
