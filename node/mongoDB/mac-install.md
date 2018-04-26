# 在 macOS 上安装 MongoDB 社区版

可以通过 [MongoDB 下载中心](https://www.mongodb.com/download-center)或使用比较流行的 macOS 软件包管理器 [Homebrew](https://brew.sh/) 下载 MongoDB 社区版。

从MongoDB 3.6开始，MongoDB二进制文件 mongod 和 mongos 默认绑定到本地主机。

## 手动安装 MongoDB 社区版

* 下载所需的MongoDB版本的二进制文件。[下载地址](https://www.mongodb.com/download-center?jmp=nav#community)，或者使用curl 命令下载压缩包。

```sh
curl -O https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.4.tgz
```

* 从下载的压缩包中提取文件。例如，从系统shell中，可以通过tar命令提取：

```sh
tar -zxvf mongodb-osx-ssl-x86_64-3.6.4.tgz
```

* 将提取的文件夹复制到目标目录(MongoDB将运行的位置)。

```sh
# 进入 /usr/local 目录
$ cd /usr/local

# 创建 mongodb 目录
sudo mkdir -p mongodb

# 复制解压后的文件到 mongodb 目录
sudo cp -R -n mongodb-osx-ssl-x86_64-3.6.4/ mongodb
```

安装完成后，我们把 MongoDB 的二进制命令文件目录（安装目录/bin）添加到 PATH 路径中，将以下行添加到 shell 的rc文件（例如〜/ .bashrc，如果使用 zsh 终端， `.zshrc`）中：

```sh
export PATH=/usr/local/mongodb/bin:$PATH
```

## 使用 brew 安装

* 先更新一下 Homebrew’s package 的资源库：

```sh
brew update

# 安装 最新版本的 MongoDB
brew install mongodb

# 安装 MongoDB 的最新开发版本
brew install mongodb --devel
```

## 运行 MongoDB

* 创建一个数据存储目录

```sh
# 使用 MongoDB 的默认目录结构
sudo mkdir -p /data/db
```

* 开启 MongoDB 服务器

```sh
mongod
```

* 确认 MongoDB 已经成功启动

```sh
# 控制台输出如下内容表示启动成功
[initandlisten] waiting for connections on port 27017
```

## 开始使用 MongoDB

```sh
mongo --host 127.0.0.1:27017
```

进入后可进行 CRUD 操作，使用 Ctrl + C 停止使用 MongoDB。