## What is shell?
Shell是一种程序设计语言。作为命令语言，它交互式解释和执行用户输入的命令或者自动地解释和执行预先设定好的一连串的命令；作为程序设计语言，它定义了各种变量和参数，并提供了许多在高级语言中才具有的控制结构，包括循环和分支。  
在Linux操作系统中，shell是非常重要的一种脚本语言，一些连续性的指令的运行和处理都是需要使用到shell script来完成的！  
## Basic concept of Shell.Let's use the Shell.  
**Step1.** You need to master the basic command we learned in lesson1.Let review them and learn some cmd new!  
* cd dir: Means to change the current directory.(eg: cd ..;cd ./workspace;cd /Github)  
* mkdir dir_name: Means to create a new directory by mkdir command.(eg: mkdir workspace;mkdir homework)  
* vim file_name: Means to edit a file named file_name.If the file isn't exist,it will create a new file.(eg: vim main.c)  
* touch file_name: Used to create a new file.  
* cat file_name: Used to see the content of a file without open it.  
* cp dir_ori/file dir_des/file: Means to copy a file form dir_ori folder to dir_des folder.  
* mv dir_ori/file dir_des/file: Means to move a file form dir_ori folder to dir_des folder.  
* echo "Hello Ubuntu!": Used to show a line on the screen.  
* ifconfig: Means to show the internet status of the computer.  
* ps -h: Show the process running on your Raspberry.  
* chmod xxx file: Used to change the right of the user.  
* sudo: Use the super user's right to run a cmd or process.  
* sudo shutdown -s -t now: Power off the machine now.We can change the 'now' into other number(n) so that the system will shutdown n seconds later.   
* sync: When you have change the file edited just now, you'd better use the sync file to make it saved into your Hard disk.  
* apt-get install: Install a new application on your computer.  
* cal: Used to show the calendar.  
* ls -al: Show the content of the current direcory.  
* pwd: Show which folder you are in now.  
* man cmd: Show the user's Guide of the cmd.(eg: man ls)  
* rm file_name: remove the file named filename.
* tree: Show all the file and the folder under the current folder.  

**Step2.** Use a new shell file to run the command together.
1. 新建文件lesson2.sh  
`vim lesson2.sh`  
2. Insert the Baisc cmd to test the shell script.  
```
#!/bin/bash
echo "Hello World !"
touch ECHO.txt
echo "Hello,Ubuntu!" > ECHO.txt
ls -al
```
**Step3.** Save the shell file and change the executable right to it.  
`chmod +x ./test.sh`  # 使脚本具有执行权限  
`./test.sh`  # 运行脚本  
**Step4.** Senior use of the shell file.  
1. variable(变量)define(定义)：  
```
var=I am CodeMaster.   
echo $var
for file in $(ls /etc); do # 显示文件夹下面的所有文件
  echo $file
done
```  
2. if 判断语句的用法:  
```
param_n=0
echo 'param_n',$param_n
if [ $# != 0 ]
then
        param_n=$#
        echo "H","das",$param_n
fi
```  
3. for 循环语句：
```
for i in a b c d
do
        echo $i
done
```  
4. while 循环语句：  
```
count=0
while (( $count <= 4 ))
do
        echo 'The Count:' $count
        let "count++"
done
```  
5. 显示日期，日历并将其保存到cal.md文件中：  
```
echo $(date)
echo $(cal) > cal.md
```  
6. Shell 下的函数的使用：  
```
func()
{
        echo "Hello shell func!"
}
func
```  
## HomeWork  
使用shell的函数的功能，实现一个能够计算1到100求和的函数:add_1_to_100() 并打印出计算的时间.  
请将代码上传至Homework文件夹当中，同时保存运行的结果为result.png图片.
