# python 环境

macOS Monterey 需要恢复安装 Python 2.7

## 问题描述

MacBook Pro 的操作系统升级到了最新版本的 macOS Monterey 12.3以后，移除了随系统发行的 Python 2.7。更新系统启动之后，发现部分 App 启动即崩溃。

## 因分析

检查系统启动时，发现链接器找不到python2.7，造成了 App 无法启动。

Reason: tried: '/System/Library/Frameworks/Python.framework/Versions/2.7/Python' (no such file), '/Library/Frameworks/Python.framework/Versions/2.7/Python' (no such file)

## 解决方案

我们需要手动安装 Python2.7，安装后问题解决。

下载地址： <https://www.python.org/ftp/python/2.7.18/python-2.7.18-macosx10.9.pkg>

> <https://blog.csdn.net/mjgwf/article/details/124245782>