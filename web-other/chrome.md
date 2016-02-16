# Chrome 浏览器
## `F11` 全屏浏览切换；
## 启用调试工具 （F12）
1. 菜单-> 更多工具-> 开发者工具；
2. 快捷键 `Ctrl+Shift+I`；
3. 快捷键 `F12`；
## 选择元素
1. 点亮第一个箭头图标，或者按快捷键 `Ctrl+Shift+C` 进行切换
## Device 手机模式
1. 点亮手机图标 或者按快捷键 `Ctrl+Shift+M` 进行切换
2. 选择设备（Device）
## Emulation 模拟经纬度和重力传感器
1. 下方点击 Emulation 模拟器面板
2. 勾选 Emulate geolocation coordinates (模拟地理位置坐标)
3. 填写需要模拟的经纬度 -> Lat (latitude 维度) ，Lon(longitude 经度)
4. 加速度设置 -> 分别设置α，β，γ
## Elements 元素
* 选择页面元素，定位当前元素并且可编辑；
* 右侧可编辑CSS样式；
## Network 网络
* 查看请求状态；
* 查看资源类型, 默认`XHR`请求；
* 选中其中一项可以查看请求入参与出参；
* 5项tab功能，不同方式查看请求；
## Throttling 网络慢速模拟(限制流量)
1. No throttling 下拉选框->选择网络或者自定义网络
## Sources 查看源文件
* 可以在JS脚本文件中加入断点；
## Resources 资源 查看本地存储，包括：Cookies, Storage, Cache
## Console 控制台
* 强大的JS脚步调试工具，可执行各种JS脚步；
* 控制台调试代码输出，console.log(), console.info(), console.error(), console.dir(), console.time(), console.timeEnd()等；

### log()
支持格式化输出。
### time()，timeEnd()
这两个方法用于计时，可以算出一个操作所花费的准确时间。
```javascript
console.time("Array initialize");

var array= new Array(1000000);
for (var i = array.length - 1; i >= 0; i--) {
    array[i] = new Object();
};

console.timeEnd("Array initialize");

// Array initialize: 1914.481ms
```
time方法表示计时开始，timeEnd方法表示计时结束。它们的参数是计时器的名称。调用timeEnd方法之后，console窗口会显示“计时器名称: 所耗费的时间”。
