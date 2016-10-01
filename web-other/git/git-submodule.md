# git submodule 命令

## 添加一个 submodule 项目
```sh
$ git submodule add https://github.com/auth0-blog/nodejs-jwt-authentication-sample.git server
# Cloning into 'server'...
# remote: Counting objects: 80, done.
# remote: Total 80 (delta 0), reused 0 (delta 0), pack-reused 79
# Unpacking objects: 100% (80/80), done.
# Checking connectivity... done.
$ git status
# On branch master
# Your branch is up-to-date with 'origin/master'.
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
# 	new file:   .gitmodules
# 	new file:   server

```

## 克隆一个包含子项目的项目
方法一，先下载主项目再下载子项目。
```sh
$ git clone https://github.com/xxx/MainProject.git server
$ cd server
# 此时子项目是空的， 需要执行下面的命令下载子项目
$ git submodule init
$ git submodule update
```
方法二 增加 `--recursive` 参数， 下载主项目时，同时自动下载所有子项目。
```sh
$ git clone --recursive https://github.com/chaconinc/MainProject

```
## 更新子项目 submodule
```sh
$ git submodule update --remote server
```
