# require函数详解

## 路径

相对路径之当前目录：./xxx/xxx.js 或 ./xxx/xxx。
相对路径之上级目录：../xxx/xxx.js 或 ../xxx/xxx。
绝对路径：F:/xxx/xxx.js 或 /xxx/xxx.js 或 /xxx/xxx。

## require函数语法

## require(路径.扩展名)：
如果 路径.扩展名 存在
执行加载 并 返回
否则
抛出异常
require(路径)：
如果 路径.js 存在
执行加载 并 返回
如果 路径.node 存在
执行加载 并 返回
如果 路径/package.json 存在
执行加载(package.json 中 main属性对应的路径) 并 返回
如果 路径/index.js 存在
执行加载 并 返回
如果 路径/index.node 存在
执行加载 并 返回
抛出异常
## require(模块名字)：
如果 模块名字是系统模块
执行加载 并 返回
如果 require(./node_modules/模块名字) 能加载到模块  //参考require(路径)的介绍
执行加载 并 返回
如果 require(../node_modules/模块名字) 能加载到模块  //参考require(路径)的介绍
执行加载 并 返回
沿着目录向上逐级执行require(上级目录/node_modules/模块名字)，如果能加载到模块  //参考require(路径)的介绍
执行加载 并 返回
抛出异常
代码示例

文件结果

## require_study.js中的代码
复制代码
 1 require('module_1_1.js');
 2 require('module_1_2');
 3 require('../node_modules/module_2_1.js');
 4 require('../node_modules/module_2_2');
 5 require('../package_2_1');
 6 require('package_3_1');
 7 require('./node_modules/package_3_2');
 8 require('module_3_1');
 9 require('/node_study/level1/level2/level3/node_modules/module_3_1');
10 require('module_3_2');
11 require('/node_study/level1/level2/level3/package_3_3');
12 require('./package_3_4');
13 require('./module_3_3');
14 require('same_name_module');
15 require('same_name_package');
16 require('same_name_module_and_package');
复制代码
输出结果
复制代码
 1 module_1_1.js
 2 module_1_2.js
 3 module_2_1.js
 4 module_2_2.js
 5 package_2_1
 6 package_3_1
 7 package_3_2
 8 module_3_1.js
 9 module_3_2.js
10 package_3_3
11 package_3_4
12 module_3_3.js
13 same_name_module.js in leaf
14 same_name_package in leaf
15 same_name_module_and_package.js in leaf module
复制代码
 代码下载：http://yunpan.cn/QWIiPxdZdW8RG
备注

刚接触NodeJs，还没有深入学习其API，包括我对require的理解，也不一定正确，欢迎批评和指正。关于require(模块名字)，应该有一个全局查找路径，今晚我再查查资料。
这篇文章说的更详细，早知官方有文章，我就不写了，文章地址：http://nodejs.org/api/modules.html。

框架地址：http://happy.codeplex.com
博客地址：http://www.cnblogs.com/happyframework
分类: NodeJs
