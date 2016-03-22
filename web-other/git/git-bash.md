# git 控制台
## 安装
1. 下载 `Git-2.5.2.2-64-bit.exe` shell 客户端;
2. 右键菜单多出 `git bash here`;

```bash
git --version  // 查看git版本
```
这个终端比 `github客户端` 自带的好用，界面好看一些；当然也可以直接使用github客户端。

## 在 GitHub 上打开 git 终端
* git右上角设置 -> options 选择默认的 shell(命令行解释器)
* -> Git Bash(和上面安装的相同会有版本区别，两个版本会同时存在用哪个都可以)
* 右键点击添加的git项目 -> open in Git Shell

## 在 Atom 编辑器中嵌入 git bash
1. 安装package terminal-plus -- git 命令控制台插件(推荐使用);
2. 配置包选项 -> Then in package options
  * Shell Override: C:\Program Files\Git\bin\bash.exe
  * Shell Arguments: -l -i  

## bash 常用命令
### 查看当前目录
```bash
$ pwd # 显示/d/workspace/blog, 其中/d/相当于D:\，
```

### 列出当前文件夹下的所有文件
```bash
$ ls # 查看当前文件
$ ls -l # 列表方式查看文件
```

### 清空和退出
```bash
# 清空内容
$ clear
# 退出控制台
$ exit
```
