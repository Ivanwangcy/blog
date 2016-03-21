# GitHub 客户端（window 桌面版）
GitHub 开源的知识宝库
1. 登录
2. 导入或创建git项目
3. 安装 git for windows 可选;
  * 勾选 Run Git from the Windows Command Prompt -> 使 git 命令支持 Windows 命令行;
  * checkout as-ls, commit as-ls -> checkout 和 commit 都使用 windows 风格;
## git 仓库列表常用功能
1. 项目右键 Open in Git Shell --> 打开 git 命令行;
2. 项目右键 Open in Explorer --> 打开项目文件夹;
3. gitHub 项目 Open in GitHub --> 使用默认浏览器打开项目网址;
4. 右键 Remove --> 在Github中移除项目(保留项目源文件);

## git 版本控制常用功能
1. 点击右上方 Sync 按钮 拉取远程仓库最新代码;
2. History 历史操作, Revert 回滚当前版本;
3. Change 本地修改操作, Discard changes 撤销修改;

## 使用 Atom 编辑器操作 Git 和 GitHub 项目

### 安装命令行插件 terminal-plus
1. 安装插件 -> Install https://atom.io/packages/terminal-plus;
2. 配置包选项 -> Then in package options
  * Shell Override: C:\Program Files\Git\bin\bash.exe
  * Shell Arguments: -l -i  
*Use git >= 2.7.3 for windows, bash starts up much faster.*
