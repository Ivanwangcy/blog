# Microsoft vscode editor

- `ctrl + ↑/↓` 向上/下移动当前行

## 插件

- Atom Keymap 使用 Atom 快捷键

### 常用插件  

- Power Mode 打字特效

- [Settings Sync](https://marketplace.visualstudio.com/items?itemName=Shan.code-settings-sync) 同步代码编辑器配置。备份上传到 github 账号（已废弃）

- :prettier

  - ctrl + alt + B 格式化当前文件;

- [GitLens](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens) 可以查看每一行的最新代码提交人

- [Markdown Preview Mermaid Support](https://marketplace.visualstudio.com/items?itemName=bierner.markdown-mermaid) 流程图预览插件

- [Image Preview](https://marketplace.visualstudio.com/items?itemName=kisstkondoros.vscode-gutter-preview) 可以显示图片缩略图，和鼠标悬停效果

- [Mintlify Doc Writer](https://marketplace.visualstudio.com/items?itemName=mintlify.document) 自动生成各种语言的注释 generate documentation

- [CodeMetrics](https://marketplace.visualstudio.com/items?itemName=kisstkondoros.vscode-codemetrics) 代码复杂度分析

## 命令行启动

> 提示：对于 Mac 用户，我们需要通过设置使您能够从终端内启动 VS Code. 首选运行 VS code 并打开命令面板（ `⇧⌘P` ），然后输入 `shell command` 找到: `Install ‘code' command in PATH` 。

## vscode 使用

按住 Alt 键，点击变量可以跳转到声明的位置或引用的文件。与 Atom 的 hyperclick 一样。

## 快捷键

### 项目管理

- `Ctrl + K Ctrl + O` 打开项目文件夹
- `Ctrl + K F` 关闭当前项目
- `Ctrl + Shift + P` 命令面板

### 视图操作

- `Ctrl + +/-` 放大或缩小视图
- `Ctrl + ↑/↓` 向上/下移动可视区域
- `Ctrl + c / Esc` 进入 Vim 模式

### 行操作

- `Alt + ↑/↓` 向上/下移动当前行
- `Shift + Alt + ↑/↓` 向上/下复制当前行

```sh
# 进入项目目录

$ code .
```

## 去除装饰器警告

在项目的根目录下创建一个 tsconfig.json 文件，并且里头的内容是：

```json
{
    "compilerOptions": {
        "experimentalDecorators": true,
        "allowJs": true
    }
}
```

京东内部的 AI 代码提示插件:

- jdt-AICode https://marketplace.visualstudio.com/items?itemName=comJdAICode.vscode-aicode
- Hibox
- JoyCoder

>> 参考：[Visual Studio Code 入门(译)
>> ](https://www.jianshu.com/p/3dda4756eca5)
