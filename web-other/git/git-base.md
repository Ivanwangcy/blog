# git笔记 常用命令总结
## 配置信息
```bash
$ git config --global user.name "John Doe"    //配置用户名

$ git config --global user.email johndoe@example.com    //配置邮箱
$ git config --global credential.helper store   //保存密码
```
## 查看配置信息
```bash
$ git config --list        //查看全部配置信息, 重复的变量名采用最后一个

$ git config user.name        //查看指定的配置信息, 直接输入变量名
```
## 获取帮助
```bash
$ git help <verb>         //比如要学习 config -> git help config
```

## Git 仓库

### 从当前目录初始化仓库
```bash
$ git init
```
### 文件跟踪和提交
```bash
# 加入暂存区
$ git add *.c        //(git add .)  当前所有文件加入暂存区
$ git add README        //

# 提交
$ git commit -m 'initial project version'        //提交文件
$ git commit -a -m 'initial project version'        //提交文件, 跳过暂存直接提交(-a)

Change the previous commit
$ git commit --amend -m "Add an author/email comment" // 修改前一次提交

# 克隆仓库
$ git clone git://github.com/schacon/grit.git        // 如果想要用其它名称, 在最后可以定义新建的目录名, 如下:
$ git clone git://github.com/schacon/grit.git mygrit
```
### 保存密码
```bash
$ git config --global credential.helper store  //保存密码
```
### 检查文件状态
```bash
$ git status
```
### 配置信息
```bash
$ git config --global --list  //查看配置信息
```
### 删除文件
```bash
$ git rm grit.gemspec  删除文件
$ git rm --cached readme.txt 删除文件版本记录, 仅保留本地文件
```
### 移动文件
```bash
$ git mv file_from file_to  文件改名
```

### 查看提交历史
```bash
$ git log
$ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"  定义历史记录格式的别名, 以后只需 git lg 即可
```
### 撤销操作
#### 修改最后一次提交
```bash
$git commit --amend    提交时忘了暂存某些修改, 可以先补上暂存操作，然后再运行--amend 提交：

$ git commit -m 'initial commit'
$ git add forgotten_file
$ git commit --amend
```
**上面的三条命令最终得到一个提交，第二个提交命令修正了第一个的提交内容。**


### 取消已经暂存的文件
```bash
$ git reset HEAD benchmarks.rb  取消暂存 benchmarks.rb 文件, 变回已修改未暂存的状态;
```
### 取消对文件的修改
```bash
$ git checkout -- benchmarks.rb  抛弃文件的修改命令, 还原回最后提交的(或修改前的)版本(已添加到缓存区的改动，以及新文件，都不受影响。)
```
### 别名
### 撤销与回滚
```bash
$ git reset --hard 可以回退到某个提交
$ git revert 可以撤销某个提交，撤销会产生一个新的提交
```
