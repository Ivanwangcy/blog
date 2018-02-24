# 初识linux的一些常用命令
## 下面记录下暂时学的一些常用命令：
```sh
$ shutdown -h now    # 现在马上关机
$ shutdown -r now   # 现在重新启动
$ reboot    # 现在重新启动
$ su -    # 如果当前是普通用户，则输入这条命令切换到管理员用户(root)，如果要切换到其他用户则敲入  su - 用户名 如:　　su - xiaoluo
$ logout    # 从当前用户注销(如果是在图形界面的终端的话，则是输入  exit  命令来退出当前用户)
$ cd    # 切换目录【如：cd / 表示切换到linux的根目录！！(/)表示根目录】
$ pwd    # 显示用户当前在哪个路径下的命令 (这个命令用的特别多，在命令行里如果不知道当前所处文件夹，可以输入该命令 pwd
```

## 接着是创建用户、删除用户的用户管理命令：
```bash
$ useradd 用户名  #【添加一个用户】 如：useradd xiaoluo
$ passwd 用户名   # 【给指定的用户名修改密码】 如：passwd xiaoluo
$ userdel 用户名   # 【删除一个用户，但是该用户在home文件下的子文件夹会保留】 如：userdel xiaoluo
$ userdel -r 用户名  #  【删除一个用户，并且删除连同该用户在home文件夹下的子文件夹】 如：userdel -r xiaoluo
```
说到linux，在这里必须的提一下linux下面的一个著名编辑器--vi编辑器。。。这个编辑器相信做过linux开发的人都再熟悉不过了，在windows平台上甚至有类似于vi编辑器的软件(gvim编辑器)。至于vi编辑器的更多介绍及使用技巧，请点击http://baike.baidu.com/view/908054.htm查看
下面就简单的以一个例子来初步了解vi编辑器的使用。(用vi编辑器创建一个Hello.js 程序，并且编译、运行)
步骤：  
- ①在命令行提示符里面敲入    vi Hello.js  
- ②输入    i 【进入到编辑状态】  
- ③敲入     esc【进入到命令行输入状态】  
- ④敲入     : 【这样就可以输入命令了。】  
- ⑤敲入   wq【保存并退出】， q！【不保存并退出】  
- ⑥ls    【查看当前目录的文件名】  ls -l 【查看当前目录详细文件信息】  

以上只是一个用vi编辑器编写的简单例子，在linux系统中，只要拥有文件权限，就都可以用vi编辑器对其进行编辑
上面例子又出现了一个新的命令 ls ，所以现在又得来介绍一些常用命令了：
```bash
$ ls #【列出文件和目录】 如：ls /home (列出home下面的所有文件和目录)
$ ls -l #【列出的文件和目录以长列表显示】 如：ls -l /home 等同命令 ：ll
$ ls -a #【列出隐藏的文件和目录】 如：ls -a /home
$ mkdir #【建立目录】 如：mkdir xiaoluo
$ rmdir #【删除空目录】 如：rmdir xiaoluo(只能删除空目录，如果该目录下还有其它文件则该命令无效)
$ touch #【建立空文件】 如：touch Test.java
```
接下来也是一些常用的命令：
```bash
$ cp #【复制命令】 如：cp /home/Test.java / (将home路径下的Test.java文件复制到根目录下)
$ cp -r dir1 dir2 #【-r表示递归，将dir1代表的文件夹及里面的文件复制到dir2路径那里】
$ cp -r dir/dir* ../../dir2/ # 将dir 目录下所有 已dir开头的文件或文件夹，复制到 dir2 下面
```
如：cp -r /home/xiaoluo /(将home下的xiaoluo文件夹复制到根目录下)
```bash
$ mv #【移动文件和改文件名】 如：mv /home/Test.java /(表示将home下的Test.java文件移动到根目录下)
$ mv /Test.java /Hello.java # (表示将Test.java文件名改成Hello.java)
$ rm # 【删除文件和目录】 如：rm /Test.java (将根目录下的Test.java删除)【注：如果该文件是个文件夹则删除不了】
$ rm -rf * #【(-r表示递归、f表示强制删除)删除所有内容，包括目录和文件夹】 如：rm -rf /home/xiaoluo(强制删除home下的xiaoluo文件夹)

$ ln #【建立符号链接，类似于windows中的快捷方式(需root权限或相应用户权限)】
$ ln -s # 源目标 目的目标    如：ln -s /etc/inittab /inittab(这样就会在根目录下建立一个inittab链接，该链接指向了etc目录下的inittab文件)

$ more #【显示文件内容，带分页】
$ less #【显示文件内容，带分页】 如果我们的一个文件里面有很多内容，就可以使用more命令给其分页
```
如：more /etc/prelink.conf  (给etc下面的prelink.conf文件内容进行分页显示)

```sh
| # 【管道命令】 【这个命令在linux系统中用的很多】 ( | 这个命令的作用就是将 | 前面的那个命令的结果交给 | 后面的那个命令来处理)
# 如：ls /etc | more (|前面那个命令是显示出etc文件夹下的所有文件及目录，|后面那个命令就是以分页形式显示，
# 所以这个命令的意思就是 以分页来显示出etc目录下的所有文件和目录)

grep # 【在文本中查询内容】 这条命令用的非常多 如：grep"xiaoluo" /home/Test.txt (在Test.txt文件中查询出包含有xiaoluo的那行文本信息)
 # 如果需要显示出所查文本所在行数则使用： grep -n "xiaoluo" /home/Test.txt(查询出Test.txt文件中xiaoluo该信息所在行数以及改行所有文本)
find #【搜索文件及目录】 如：find /home -name Test.java (在home文件夹下或者home中所有的子文件夹下查找名字为Test.java的文件)

# 重定向命令【> 、>>、<】
# 如：ls -l /etc> a.txt (将etc下面的列表信息写入到a.txt文件中【覆写】，如果之前不存在a.txt文件，则创建a.txt文件然后将信息写进去，
# 如果存在a.txt文件，则会覆盖掉之前的信息)
$ ls -al /etc>> aa.txt # (将etc下面的列表信息追加到aa.txt文件信息后面)
# 从文件中输入信息 aaa < bbb
```

差点忘了一条很重要的命令：   
【cat、vi】(cat命令只能查看文件，vi命令既可以查看文件又可以修改文件，对于一些关键文件我们一般使用cat命令查看)
如：cat /etc/profile (只是查看该文件里的内容)　　　　vi /etc/profile (查看、并且可以修改该文件里的内容)
后续的博文会继续记录学习Linux系统的点点滴滴，将会补充更多的Linux常用命令。


分类: Linux
标签: linux, CentOS, OS X

## Mac查看端口占用情况
```sh
$ lsof -i:3000
```
