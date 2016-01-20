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
    server_name  xxxx.xxx.com;

    location / {
        # root   D:/workspace/pdj_static_cdn/; # 到家 CDN
        root   D:/workspace; # 活动页 CDN
        autoindex on;
        autoindex_localtime on;
    }
    location /client {
        proxy_pass   http://XXX.XX.com/client;
        # proxy_pass   http://XXX.XX.com/client;
    }
}

# 预发布线上文件本地配置，上预发布之前（prepdjm，master分支提交之前或压缩完）先跑一遍这个
  server {
      listen       8001;
      server_name  localhost;

      location / {
          root   D:/workspace/pdj_h5_static/;
          index  index.php index.htm index.html;
      }

      error_page   500 502 503 504  /50x.html;
      location = /50x.html {
          root   html;
      }

      # proxy the PHP scripts to Apache listening on 127.0.0.1:80
      #
      location /client {
          # proxy_pass   http://xxx.xx.com/client; # 预发布环境
          proxy_pass   http://xxx.xx.com/client; # 线上环境
      }

      # pass the PHP scripts to FastCGI server listening on 127.0.0.1:90
      location ~ \.php$ {
          root           D:/workspace/pdj_h5_static/;
          fastcgi_pass   127.0.0.1:90;
          fastcgi_index  index.php;
          fastcgi_param  SCRIPT_FILENAME  $document_root$fastcgi_script_name;
          include        fastcgi_params;
      }
  }

  server {
    listen       8002;
    server_name  localhost;

    location / {
      root   D:/workspace/o2o-trade-static-activity-html/;
      index  index.php index.htm index.html;
      autoindex on;
            autoindex_localtime on;
    }
  }

  server {
       listen       8007;
       server_name  localhost;

       location / {
           #root   D:/workspace/m-html/branches/webapp/v1.1;
           root   D:/workspace/m-html/branches/webapp/v1.1/;
           index  index.html index.htm index.php;
       }

       # redirect server error pages to the static page /50x.html
       #
       error_page   500 502 503 504  /50x.html;
       location = /50x.html {
           root   html;
       }


     location /client {
       # proxy_pass http://XXX.XX.com/client;
       proxy_pass http://XXX.XX.com/client; # 第二套预发布

       # proxy_pass http://XXX.XX.com/client;
     }

     location ~ \.php$ {
       #root			D:/workspace/m-html/branches/webapp/v1.1;
       root			D:/workspace/m-html/branches/webapp/v1.1/;
       fastcgi_pass 	127.0.0.1:90;
       fastcgi_index	index.php;
       fastcgi_param	SCRIPT_FILENAME $document_root$fastcgi_script_name;
       include			fastcgi_params;
     }

   }
```
