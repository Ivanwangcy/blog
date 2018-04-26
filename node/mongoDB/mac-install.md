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

```
