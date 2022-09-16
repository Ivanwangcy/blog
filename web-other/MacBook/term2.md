# term2

## 漂亮的命令行

1. 安装term2 [http://iterm2.com/](http://iterm2.com/)
2. 安装 oh-my-zsh [http://ohmyz.sh/](http://ohmyz.sh/)

```sh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

## term2+zsh 下 [git 操作别名](./oh-my-zsh.md)

## 显示和隐藏，Mac 隐藏文件

－ 显示Mac隐藏文件的命令：

```sh
defaults write com.apple.finder AppleShowAllFiles -bool true
```

－ 隐藏Mac隐藏文件的命令：

```sh
defaults write com.apple.finder AppleShowAllFiles -bool false
```

## 常用命令行

```sh
$ ls # 查看文件
$ ls -l # 文件信息列表
# 同上
$ ll

$ ls -a # 查看隐藏文件

$ rm -r <dir>  # 删除一个文件夹
$ mv -f # 移动一个文件

$ mkdir project # 创建目录
$ touch index.js # 创建一个空文件
$ mkdir -p dir/{aa,bb,cc,dd} # 创建新目录以及子目录结构

$ mkdir project && cd $_  # 创建目录后，再进入目录
$ mkdir -p src/{components,containers,styles,utils,views}\  # 使用 `\` 使命令折行，继续执行下一行命令
  && touch webpack.config.js # 创建一个目录结构

# 输入内容到文件
$ echo "body{ border: 1px solid red;}" > src/app.css

```sh
## 添加profiles 启动 `XX－Net` 代理软件
1. `cmd + O` 打开Profiles pane , click to Edit Profiles
2. create a profile : command -> /Applications/XX-Net-2.9.6/start.command
3. add shortcut key;
4. use shortcut key start command;
```
