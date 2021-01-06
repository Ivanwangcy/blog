# Chrome 浏览器开发者工具

## 打开方式启用调试工具 （F12）

1. 菜单-> 更多工具-> 开发者工具；
2. 按 `F12`或者 `Ctrl + Shift + i`（PC 端）/`Alt + Command + i`(Mac 平台)；
3. 在一个页面元素上，打开右键菜单，选择 -> "审查元素"。

打开“开发者工具”以后，可以看到在顶端有两种模式和十个面板选项卡可供选择，分别是：

-   选择元素图标，开启后进入页面元素审查模式；
-   移动设备模式图标，开启后可以模拟常用移动设备；
-   Elements：用来调试网页的 HTML 源码和 CSS 代码；
-   Resources：查看网页加载的各种资源文件（比如代码文件、字体文件、css 文件等），以及在硬盘上创建的各种内容（比如本地缓存、Cookie、Local Storage 等）。
-   Network：查看网页的 HTTP 通信情况。
-   Sources：调试 JavaScript 代码。
-   Timeline：查看各种网页行为随时间变化的情况。
-   Profiles：查看网页的性能情况，比如 CPU 和内存消耗。
-   Audits：提供网页优化的建议。
-   Console：用来运行 JavaScript 命令。
-   Emulation：模拟器选项卡，配置移动设备的各种选项；
-   Rendering：页面渲染

## 切换审查模式 Inspect

1. 点亮第一个箭头图标，或者按快捷键 `Ctrl+Shift+C` 进行切换;
2. 右键 "审查元素"；

## 切换手机模式 Device

1. 点亮手机图标 或者按快捷键 `Ctrl+Shift+M` 进行切换
2. 选择设备（Device）

## Elements 元素

-   选择页面元素，定位当前元素并且可编辑；
-   右侧可编辑 CSS 样式；

## Network 网络

-   查看请求状态；
-   查看资源类型, 默认`XHR`请求；
-   选中其中一项可以查看请求入参与出参；
-   5 项 tab 功能，不同方式查看请求；
-   勾选 Preserve log，页面跳转其他 URL 可以保留当前网络请求记录；

## Throttling 网络慢速模拟(限制流量)

1. No throttling 下拉选框->选择网络或者自定义网络

## Sources 查看源文件

-   可以在 JS 脚本文件中加入断点；
-   基于压缩过的代码可以进行格式化；
-   压缩的 JS 代码可以使用 SourceMap 进行代码还原，有助于线上调试；

## Resources 资源 查看本地存储，包括：Cookies, Storage, Cache

## Console 控制台

-   强大的 JS 脚步调试工具，可执行各种 JS 脚步；
-   控制台调试代码输出，console.log(), console.debug(), console.info(), console.warn(), console.error(), console.dir(), console.table(), console.count(), console.time(), console.timeEnd()等；

### log(), debug(), info(), warn(), error() 区别

用法相同，都支持格式化输出。

-   info() 有 蓝色 i 图标 :information_source:；
-   warn() 有 黄色叹号图标 :heavy_exclamation_mark:；
-   error() 有 红色错误图标 :x:；

自定义格式化输出，增加样式：

```
      console.log(
        `%c vue-devtools %c Detected Vue v2.5.21 %c`,
        'background:#35495e ; padding: 1px; border-radius: 3px 0 0 3px;  color: #fff',
        'background:#41b883 ; padding: 1px; border-radius: 0 3px 3px 0;  color: #fff',
        'background:transparent'
      )
```

### time()，timeEnd()

这两个方法用于计时，可以算出一个操作所花费的准确时间。

```javascript
console.time("Array initialize");

var array = new Array(1000000);
for (var i = array.length - 1; i >= 0; i--) {
    array[i] = new Object();
}

console.timeEnd("Array initialize");

// Array initialize: 1914.481ms
```

time 方法表示计时开始，timeEnd 方法表示计时结束。它们的参数是计时器的名称。调用 timeEnd 方法之后，console 窗口会显示“计时器名称: 所耗费的时间”。

## Emulation 模拟器 -> 模拟经纬度和重力感应

[![geo](/images/geographic.png)](/images/geographic.png)

### Device 设备选项

1. 下方点击 Emulation 模拟器面板；
2. 勾选 Emulate geolocation coordinates (模拟地理位置坐标)
3. 填写需要模拟的经纬度 -> Lat (latitude 维度) ，Lon(longitude 经度)
4. 加速度设置 -> 分别设置 α，β，γ

## Rendering 监控渲染过程

1. Enable paint flashing 高亮显示渲染与重绘过程；
2. Show layer border 显示页面层级边框；
3. Show FPS meter 显示每秒帧数；
4. Show scroling perf issues 显示滚动性能问题

## 新版 google 安装插件的方法

打开扩展程序，开启开发模式，将下载好的 crx 文件拖入，如果报错，将 crx 文件扩展名改成 zip 即可。

## 常用的 google 插件

-   谷歌访问助手 可以访问 google gmail 等 （强力推荐）
