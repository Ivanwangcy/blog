# 用 python 开启本地服务器

测试页面时，有时需要一个服务器，贫穷的girl买不起服务器，可以用python在本地启一个本地的服务器，方法如下：

1.第一步，装个python

已经装好了，这里就不讲了，哈哈哈哈

2.第二步，查看自己python的版本，如下：
```sh
python -V

Python 2.7.16
```

3.第三步，开启服务器，如果是3.x版本，则运行python -m http.server命令；如果是2.x版本，则运行python -m SimpleHTTPServer.如下：

```sh
python -m http.server
/usr/bin/python: No module named http
MacBook-Pro:~ xx$ python -m SimpleHTTPServer
Serving HTTP on 0.0.0.0 port 8000 ...
```
更多详情，查看这里[mdn本地服务器设置](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/set_up_a_local_testing_server)
