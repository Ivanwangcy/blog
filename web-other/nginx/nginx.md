nginx 配置PHP
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
```
