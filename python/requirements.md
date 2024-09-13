# requirements

```sh
pip freeze > requirements.txt
```
我们为什么要使用requirements.txt呢？

主要使用目的：

任何应用程序通常需要设置安装所需并依赖一组类库来满足工作要求。要求文件是指定和一次性安装包的依赖项具体一整套方法。

requirements.txt文件格式：

requests==1.2.0 
Flask==0.10.1
1
2
这样我们就可以安装requirements.txt依赖

pip install -r requirements.txt
1
方法一：

```sh
pip freeze > requirements.txt
```

查看源文件
pip的freeze命令用于生成将当前项目的pip类库列表生成 requirements.txt 文件：

如果要安装requirements.txt中的类库内容，那么你可以执行

```sh
pip install -r requirements.txt
```

方法二：

使用 pipreqs 用于生成 requirements.txt 文件可以根据需要导入的任何项目

为什么不使用pip的Freeze命令呢？

pip的freeze命令保存了保存当前Python环境下所有类库包，其它包括那些你没有在当前项目中使用的类库。 （如果你没有的virtualenv）。

pip的freeze命令只保存与安装在您的环境python所有软件包。

但有时你只想将当前项目使用的类库导出生成为 requirements.txt；

使用方法：pipreqs 加上当前路径即可。

```sh
pip install pipreqs
pipreqs .
```
