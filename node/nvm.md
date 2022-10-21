# nvm 使用

使用nvm管理多个版本的 node.js (适用于Mac和Windows系统)。

想要成功的安装 nvm，Mac 系统下必须要先安装 Xcode 软件。

```sh
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.2/install.sh | bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash

```

## 常用命令

```sh
$nvm install --lts                   # Install the latest LTS version\

# 使用指定版本
$ nvm use 8.0
```



## 使用 Homebrew 安装

卸载 Node

```sh
brew uninstall --ignore-dependencies node 
brew uninstall --force node
```

安装 nvm

```sh
brew update 
brew install nvm 

mkdir ~/.nvm
vim ~/.zshrc 

# add the below lines to .zshrc
export NVM_DIR=~/.nvm
source $(brew --prefix nvm)/nvm.sh

# 更新配置文件
source ~/.zshrc

# 查看可用 node 版本
nvm ls
```

