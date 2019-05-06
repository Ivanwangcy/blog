# 使用 mac 连接到远程服务器

使用默认的 ssh 命令连接：
1、 ssh登录服务器
ssh -p端口号 username@服务器ip


```sh
# 端口号可以省略
$ ssh root@192.168.xx.xx
```

2、上传文件至服务器
```sh
# scp -P端口号 本地文件路径 username@服务器ip:目的路径
# 端口号可以省略
$ scp ~/node-v10.15.3-linux-x64.tar.xz root@192.168.200.240:~/

```
3、从服务器下载文件到本地

```sh
scp -P端口号 username@ip:路径 本地路径
```


4、 linux 服务器上安装 node :

```sh
$ wget https://npm.taobao.org/mirrors/node/v10.15.3/node-v10.15.3-linux-x64.tar.xz
```
