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

## 卸载

卸载homebrew

下载 <https://raw.githubusercontent.com/Homebrew/install/master/uninstall> 并保存为 uninstall.rb，

再执行 ruby uninstall.rb

```sh

#!/usr/bin/ruby

STDERR.print <<EOS
Warning: The Ruby Homebrew uninstaller is now deprecated and has been rewritten in
Bash. Please migrate to the following command:
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)"

EOS

Kernel.exec "/bin/bash", "-c", '/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)"' + ' uninstall ' +  ARGV.join(" ")
```
