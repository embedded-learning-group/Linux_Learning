# Learning to Blink Leds with Linux Thread Func.  
## What is thread in linux system?  
1. 是操作系统能够进行运算调度的最小单位。它被包含在进程之中，是进程中的实际运作单位。一条线程指的是进程中一个单一顺序的控制流，一个进程中可以并发多个线程，每条线程并行执行不同的任务。  
2. 同一进程中的多条线程将共享该进程中的全部系统资源，如虚拟地址空间，文件描述符和信号处理等等。
## What's the difference between process and thread?  
The CPU-procss and CPU-thread level structure in linux sys.  
![CPU-process-thread](https://cl.ly/b883fba228f6/CPU-procss&thread.jpg)  
For example there are three process named A/B/C.Every process-x create three threads[T1/T2/T3].  
We can find out that the process can communicate with another processes by mesg-pipe in this pic.  
Actruely,there are three motheds for processed to communicate  with each other([Process-Communicate](https://www.cnblogs.com/uestc-mm/p/7630154.html)):  
* Shared Memory Communicate.  
* Pipe Communicate.  
* Socket Communicate.  
* Mesg Communicate.  

If CPU just has only a single core,all the threads need to be executed one by one.  
In a simple operate-sys,all the threads being given the same time slice to execute.  
If there is some Priorities for every thread,we need to arrange diff time-slice for every threads.  
## How to Control the thread?  
![Thread](https://cl.ly/8b730c76444c/Thread%20alloc.jpg)  
## Coding with C(Leds ThreadControl).  
Step1. Coding  
***main.c:***  
***led.c:***  
***led.h:***  
***Makefile:***  
Step2. Compile the Code  
```
cd Thread_test
make
```  
Step3. Running  
`./binary 0 2 3`  
## Homework  
* 使用多线程编程函数pthread创建不同的线程，实现四个led灯的同时控制。  
* 扩展作业：尝试完成两个Motors电机的控制程序，通过多线程完成电机的同时运转。  
## Reference  
[Linux下C语言进程通讯编程](https://www.cnblogs.com/uestc-mm/p/7630154.html)  
[Linux下C语言的进程控制编程](https://www.cnblogs.com/uestc-mm/p/7630161.html)  
[C语言多线程pthread库相关函数说明](https://www.cnblogs.com/mq0036/p/3710475.html)
