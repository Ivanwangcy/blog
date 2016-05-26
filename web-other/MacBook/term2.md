## 漂亮的命令行
1. 安装term2 [http://iterm2.com/](http://iterm2.com/)
2. 安装 oh-my-zsh [http://ohmyz.sh/](http://ohmyz.sh/)
```sh
$ sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```
## 显示和隐藏，Mac 隐藏文件
－ 显示Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles -bool true
－ 隐藏Mac隐藏文件的命令：defaults write com.apple.finder AppleShowAllFiles -bool false
## 常用命令行
```sh
$ ls # 查看文件
$ ls -l # 文件信息列表
# 同上
$ ll

$ ls -a # 查看隐藏文件

$ rm -r <dir>  # 删除一个文件夹
$ mv -f # 移动一个文件
```
## 添加profiles 启动 `XX－Net` 代理软件
1. `cmd + O` 打开Profiles pane , click to Edit Profiles
2. create a profile : command -> /Applications/XX-Net-2.9.6/start.command
3. add shortcut
4. use shortcut key start command;
