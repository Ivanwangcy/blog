# HomeBrew OS X 不可或缺的软件管理器
## 安装 Homebrew
```sh
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
## brew 常用命令
```sh
$ brew --version  # 查看版本
$ brew update # 更新 Homebrew 自身

# 升级 ruby
$ brew upgrade ruby
```

## 使用 homebrew 安装 `node`
```sh
$ brew install node
```
## 查找可安装的软件
```sh
$ brew search --desc <keyword>
```

## tree 命令 输出目录结构
```sh
$ brew install tree

# -d 只显示文件夹目录
# 前 3 级目录
$ tree -d -L 3
```

## 帮助文档
```sh
$ brew help
$ man brew
$ brew doctor # 修复
```
