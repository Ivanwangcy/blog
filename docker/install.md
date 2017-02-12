# 安装 docker for mac
## up and running
```sh

$ docker --version
$ docker-compose --version
$ docker-machine --version

# 运行 hello world
$ docker run hello-world

# 启动一个 nginx 服务器
$ docker run -d -p 80:80 --name webserver nginx
# 查看启动后 运行正常的 docker 服务器
$ docker ps
# CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS              PORTS                         NAMES
# db1ef849bd72        nginx               "nginx -g 'daemon off"   2 minutes ago       Up 2 minutes        0.0.0.0:80->80/tcp, 443/tcp   webserver

# 查看正在运行的 所有 docker
$ docker ps -a
```
## Build your own image
```sh
$ docker run docker/whalesay cowsay boo-boo
```
###
