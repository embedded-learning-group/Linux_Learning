## How to use the github?(怎么使用GitHub呢？)  
1. What's github?(什么是GitHub？)  
* Git是一个开源的分布式版本控制系统，可以有效、高速地处理从很小到非常大的项目版本管理。  
* Git是Linus Torvalds为了帮助管理Linux内核开发而开发的一个开放源码的版本控制软件。  
2. How to download the github on your PC?(如何下载github在PC上？)  
[Window install Git Bash](https://www.cnblogs.com/smuxiaolei/p/7484678.html)  
[Linux install Git](https://www.linuxidc.com/Linux/2018-05/152610.htm)  
* You also can follow my command to install git:  
`sudo apt-get install git`  
* Check if git is install successfully:  
`git --version`  
3. Config the local git's usename and the pass word so that you can connect to the github server.  
git config --global user.name "github-username"  
git config --global user.email "email-address"  
4. Coding under your PC.  
Step1. Create a new folder to include your Projrct.  
`mkdir workspace`  
Step2. Change the dir into workspace.  
`cd workspace`  
Step3. Init the folder to be a new repositry.  
`git init`  
Step4. Connect the remote repositry and local repositry.  
`git git remote add origin git@github.com:embedded-learning-group/Linux_Learning.git`  
Step5. Clone the Code from the github.  
`git clone git@github.com:embedded-learning-group/Linux_Learning.git`  
Step6. Now the Linux_Learning folder is there. Let's Coding.  
* 创建文件夹：`mkdir homework`  
* 切换到homework文件夹下并创建C文件夹：`mkdir C`  
* 新建mian.c文件开始编程：`vim main.c`  
* 编译main.c文件：`gcc main.c -o main`  
* 执行main可执行文件：`./main`  
* 将运行正确的结果截图保存在当前文件夹(图片名称result.png)：/homework/result.png  
5. Upload the file to github so that the teacher could see you code.
* Step1. Show the status of the Folder(repositry).  
`git status`  
* Step2. Add the file have been changed just now.  
`git add *`  
* Step3. Add what change you have make to the Code.  
`git commit -m "What you have changed just now."`  
* Step4. Upload it to the master code.  
`git push`  
## Github Command Learning.  
[参考廖雪峰的Github教程](https://www.liaoxuefeng.com/wiki/896043488029600)  
1. git clone git@github.com:embedded-learning-group/Linux_Learning.git  从Github服务器下载代码文件  
2. git status  用来查看当前文件夹下面的文件的状态信息(repositry仓库状态)  
3. git add   用来添加被修改文件到预备上传区  
4. git commit -m ""  将待上传的修改后的文件打上标签，方便知道大概修改的内容  
5. git push  上传代码  
6. git diff  获取当前修改的代码和之前代码的区别  
7. git log  查看都有哪些用户修改了当前的代码  
## Homework  
* 查阅资料深入了解github分布式相关概念，写300字关于github分布式概念的word，提交到Homework文件夹当中，并通过Github上传以方便批阅。  
* 在Homework文件夹下面创建C文件夹，在这个文件夹下编程，实现1到100的等差数列求和并将代码以及运行成功的结果图片保存上传至Github。  
* 任何问题可以直接在issue中向我提问，我会及时回复！
