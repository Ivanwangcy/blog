# Atom 比较流行的Web前端开发编辑器
[Atom](https://atom.io/)它是一款开源的文本编辑器

安装简单, windows 版直接下载安装即可.其它平台可以使用源码安装.  


`Ctrl+Shift+P`打开命令面板可以查找所有命令.  
`Setting` 进入设置界面, 可以设置项目根目录. 或者直接使用快捷键`Ctrl+,`打开设置面板 -> install 菜单下搜索自己需要的插件和主题。  
## 设置主题, 可以选择已有的主题;
  atom-material-ui 爆款主题UI  
  atom-material-syntax 爆款搭配
## package 包管理, 常用的包
    * [autocomplete-emojis](https://atom.io/packages/autocomplete-emojis) 支持输入各种表情符号 🍎，🚗, 🐶
    * [Sync Settings](https://atom.io/packages/sync-settings) 搭配github，同步你的atom插件信息，配置信息，让你轻松实现一台电脑配置，多台电脑共享。
    * [Js Hyperclick](https://atom.io/packages/js-hyperclick) 按 cmd + mousedown jump to declaration or jump to import file, if without `hyperclick`, need to install [hyperclick](https://atom.io/packages/hyperclick)
    * [language-vue](https://atom.io/packages/language-vue) Vue 组件开发，.vue 文件支持
    * [atom-wx](https://atom.io/packages/atom-wx) 微信小程序语法高亮(atom-wx), 支持 wxml 文件和 wxss 文件
    * [wxapp](https://atom.io/packages/wxapp) 微信小程序自动补全
    * [git-time-machine](https://atom.io/packages/git-time-machine) 当前文件修改历史记录, Alt + T 开启历史记录(时间机器)
    * [Nuclide](https://atom.io/packages/nuclide)  React Native 开发工具
    * [language-babel](https://atom.io/packages/language-babel) ES6，jsx 语法 支持
    * [editorconfig](https://atom.io/packages/editorconfig) 统一编辑器配置
    * [linter-scss-lint](https://atom.io/packages/linter-scss-lint) scss 代码检查工具
    * [linter-eslint](https://atom.io/packages/linter-eslint) js 代码检查工具
    * linter 实时代码检查工具, 下面状态栏标记错误位置;
    * vim-mode vim 模式
    * ex-mode vim 模式扩展 增加 `:` 进入命令模式
    * atom-terminal  编辑器内嵌命令行
    * terminal-plus -- git 命令控制台插件(推荐使用);
    * Git-Plus git git命令 辅助操作插件 `Ctrl + Shift + H` 打开;
    * color-picker 取色器插件 `CTRL-ALT-C` 打开;
    * Minimap package 代码缩略图插件;
    * pigments 颜色显示插件 （必装）高亮显示文件, 样式颜色值显示;
    * atom-ternjs js代码提示很强大，高度定制化。
    * jshint 代码检查工具;
    * atomatigit 可视化git操作 -- 不喜欢用命令行的可以安装;
    * file-icons 给文件加上好看的图标。
    * activate-power-mode 动感十足的编辑模式 -- 动感编辑特效 'ctrl + alt + o' MacBook 通用
    * Highlight-selected 高亮选中部分
    * Docblockr 注释功能
    * emmet Emmet plugin Atom editor
    * Snippets package
    * Docblockr package


## Windows下快捷键汇总:
### 编辑器全局 Window 操作
* `Ctrl + ,`  打开设置面板  Ctrl + command Settings
* `Ctrl + \` 切换树形导航面板 显示/隐藏  Toggle Tree View
* `Ctrl + W` 关闭 当前窗口 close Tab
* `Alt + F4` 关闭编辑器
* `Ctrl + Alt + R` 重新载入编辑器 Reload Atom Editor
* `Ctrl + Shift + P` 打开命令面板
* `Ctrl + Shift + W` 关闭编辑器 等同于 `Alt + F4`
* `Ctrl + Shift + M` 编辑markdown文件时，打开markdown预览文件
* `Alt + number` 加数字键(面板索引)切换面板
* `Ctrl + Tab` 切换到上一个视图窗口
* `Ctrl + Shift + Tab` 切换到下一个视图窗口

### 视图操作
* `Ctrl + k left` 在左半视图中打开文件 `mac 使用 cmd 代替 Ctrl`
* `Ctrl + k down` 在下半视图中打开文件 `mac 同上`
* `Ctrl + k up` 在上半视图中打开文件 `mac 同上`
* `Ctrl + k right` 在右半视图中打开文件 `mac 同上`
* `Ctrl + W` 关闭当前视图  `mac 同上`
* `F11` 全屏模式
* `Ctrl/CMD + =` 放大当前视图
* `Ctrl/CMD + -` 缩小当前视图

### 基本操作
* `Ctrl + A` 全选
* `Ctrl + B` 查找当前打开的文件
* `Ctrl + C` 粘贴
* `Ctrl + D` 选择字符串 （按住Ctrl 再 +D 继续选择下个相同的字符串）
* `Ctrl + F` 当前选中的文本，当前文件查找/替换
* `Ctrl + E` 选中当前文本并查找/替换
* `Ctrl + G` 跳转至第几行, 输入数字,回车跳至指定行
* `Ctrl + J` 合并行（已选择需要合并的多行时）
* `Ctrl + L` 选择整行（按住Ctrl-继续选择下行）
* `Ctrl + K` Backspace 从光标处删除至行首
* `Ctrl + M` 光标移动至括号内开始或结束的位置
* `Ctrl + N` 新建窗口
* `Ctrl + P`   同Ctrl+T快速搜索项目中的文件
* `Ctrl + /` 注释整行（如已选择内容，同“Ctrl+Shift+/”效果）
* `Ctrl + Shift + C` 转换为 utf8

* `Ctrl + R` 搜索指定文件的函数标签，函数名称搜索，跳转至函数所在行

* `Ctrl + W ` 关闭当前编辑窗口
* `Ctrl + X` 删除当前行
* `Ctrl + Delete` 向后删除一个单词或一组文字
* `Ctrl + Backspace` 向前删除一个单词或一组文字
* `Ctrl + ↑` 向上移动行
* `Ctrl + ↓` 向下移动行
* `Tab 缩进` 自动完成
* `Shift + Tab` 去除缩进

* `Ctrl/CMD + Enter` 光标后插入行  向下插入行

* `Ctrl+F2` 设置书签
* `F2` 下一个书签
* `Shift+F2` 上一个书签
* `shift+鼠标右键` 列选择
* `Alt+F3` 选中文本按下快捷键，即可一次性选择全部的相同文本进行同时编辑
* `Alt+.` 闭合当前标签
* `F6` 检测语法错误
* `F9` 行排序(按a-z)

* `Ctrl+Shift+Enter` 光标前插入行 Ctrl+Shift+Enter 光标前插入行, 当前行之上插入行
* `Ctrl+Shift+[` 折叠代码      atom 中: Ctrl+Alt+[ 折叠代码
* `Ctrl+Shift+]` 展开代码      atom 中: Ctrl+Alt+] 展开代码
* `Ctrl+Shift+↑` 与上行互换
* `Ctrl+Shift+↓` 与下行互换
* `Ctrl+Shift+A` 选择光标位置父标签对儿
* `Ctrl+Shift+D` 复制光标所在整行，插入在该行之后
* `ctrl+shift+F` 在文件夹内查找，与普通编辑器不同的地方是sublime允许添加多个文件夹进行查找
* `Ctrl+Shift+K` 删除整行, 同Ctrl+X
* `Ctrl+Shift+L` 切换当前文件使用的编程语言


* `Ctrl+Shift+/` 注释已选择内容
* `Ctrl+PageDown 、Ctrl+PageUp` 文件按开启的前后顺序切换
* `Ctrl+鼠标左键` 可以同时选择要编辑的多处文本
* `Shift+鼠标右键`（或使用鼠标中键）可以用鼠标进行竖向多行选择
* `Alt+Shift+1~9`（非小键盘）屏幕显示相等数字的小窗口
* `Ctrl+Alt+↑` 向上选中多行同时编辑
* `Ctrl+Alt+↓` 向下选中多行同时编辑
* `Ctrl+Alt+M` 选中标签内部整块内容或者代码块内容
*
* `Ctrl+Alt+B` Atom 标准代码格式化

* `Ctrl+Shift+M` 选择括号内的内容（按住-继续选择父括号） , Atom 合并行, 当前整个代码块合并
* `F11` 全屏编辑

* `ctrl-shift-t, alt-shift-t`  命令窗口  安装 atom-terminal 插件
* `CTRL-ALT-C` to open it.  打开颜色选择器

* `Ctrl+Alt+←` 像左选中整个单词
* `Ctrl+Alt+→` 像右选中整个单词

## 块儿注释 安装 Docblockr Package

## 设置 Tab 类型 (Tab Type)

设置 Tab 类型, 有些编译工具无法识别 `tab` 字符, 统一把 tab 转换成 空格 `spaces` 的设置.  
Setting -> Editor -> Tab Type -> 选择 `soft`项;

## sync-settings

token:

- 586947f656c6be6f409ffe2fbe5b012cd8b8d87b
- f7a7ae799c5ebd924856da5eeda3d2d3f642e87b
- 814dcf56435fb21c23eef04c0793ecf2bf77462b

## 
