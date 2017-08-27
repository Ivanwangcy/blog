# 新增和删除的标签

## 新增:
结构标签 最重要的, 标签更具语义化
表单标签
媒体标签
其他功能标签

## 删除:
可以用css代替的标签
不在使用frame
只有个别浏览器支持的标签
其他不常用的标签

### 新增的结构标签

#### section 标签
表示页面中的内容区块, 比如章节, 页眉,页脚或页面的其他部分, 可以和h1,h2...结合起来使用, 表示文档结构.
例: HTML5中<section>...</section>HTML4中<div>...</div>

#### article 标签
表示页面中一块与上下文不相关的独立内容, 比如一篇文章.

#### aside 标签
表示article标签内容之外的, 与article标签内容相关的辅助信息.

#### header 标签
表示页面中一个内容区块或整个页面的标签;

#### hgroup 标签
表示对整个页面或页面中的一个内容区块的标题进行组合.

#### footer 标签
表示整个页面或页面中一个内容区块的脚注. 一般来说, 他会包含作者的姓名, 创建日期, 作者的联系方式等信息;

#### nav 标签
表示页面中导航链接的部分.

#### figure 标签
表示一般独立的流内容, 一般表示文档主体流内容中的一个独立元素. 使用fagurecation标签为figure添加标题;

# 新增和删除的属性

## 新增:
表单属性
链接属性
其他属性

### 新增的主要属性:
html 新增 manifest 属性 定义离线应用的;
meta 新增 charset="utf-8";
script 增加 async(异步执行) 异步加载属性, defer(推迟执行) 下载完不执行, 等页面下载完了才执行;
超链接增加 media 属性;
列表 增加 reversed 倒序显示;
### 新增内联样式区块;例如:  
iframe seamless 属性 , 无边框, 无边距;
iframe srcdoc 属性 当srcdoc出现后, 页面内容 src属性 被替换成 srcdoc内容, srcdoc 覆盖了src;
iframe sandbox 属性, 禁止内嵌页面提交内部表单, 禁止内嵌页面执行JavaScript脚本, 与外部不是相同源, 默认为异源, 有4个属性值分别可以定义禁止类型;
### 新增的全局属性:(适用于所有标签)
data-<yourvalue> 自定义属性, 可用于存储数据, dataset中获取;
hidden  隐藏标签
spellcheck 拼写检测
tabindex tab键切换顺序
contenteditable 内容可以编辑
designMode (js 属性) 全局可编辑(开启/关闭) window.document.designMode = 'on';  // off

## 删除的属性:
可以使用css替换的属性
多余属性
其他属性

## dataset
html5有 dataset , 所有自定义属性以data-开头；

*语义化标签*
# #
# 
 #
