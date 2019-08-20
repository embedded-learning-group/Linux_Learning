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
```
#include <stdio.h>
#include <pthread.h>
#include "led.h"
extern int led1_pin;
extern int led2_pin;
extern int led3_pin;
extern int led4_pin;
int main(int argc,char *argv[])
{
    pthread_t t1,t2,t3;
    int pinList[nMAX] = {led1_pin,led2_pin,led3_pin,led4_pin};
    led_init(pinList,nMAX);
    pthread_create(&t1,NULL,led_blink,&led1_pin);
    pthread_create(&t2,NULL,led_blink,&led2_pin);
    pthread_create(&t3,NULL,led_blink,&led3_pin);
    while(1){
        delay(800);
        led_on(led4_pin);
        delay(800);
        led_off(led4_pin);
    }
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    return 0;
}
```  
***led.c:***  
```
#include "led.h"

int led1_pin = 0;
int led2_pin = 1;
int led3_pin = 2;
int led4_pin = 3;

int led_init(int *pinNum,int n)
{
    int i=0;
    if(-1 == wiringPiSetup()){
        printf("Setup wiringPi failed!\n");
        return 0;
    }
    if(n > nMAX){
        printf("To many leds needed!Nothing did.\n");
        return 0;
    }
    for(i=0;i<n;i++){
        pinMode(pinNum[i], OUTPUT);
        digitalWrite(pinNum[i],0);
    }
    printf("Led Initial Finished.\n");
    return 1;
}

void* led_blink(void* pinNum)
{
    printf("Start Blinking...\n");
    int* pin = (int*)pinNum;
    while(1)
    {
        digitalWrite(*pin,0);
        printf("Pin-%d:ON\n",*pin);
        delay(800);
        digitalWrite(*pin,1);
        printf("Pin-%d:OFF\n",*pin);
        delay(800);
    }
}

void led_on(int pinNum)
{
    digitalWrite(pinNum,0);
    printf("Pin-%d:ON\n",pinNum);
}

void led_off(int pinNum)
{
    digitalWrite(pinNum,1);
    printf("Pin-%d:OFF\n",pinNum);
}
``` 
***led.h:***  
```
#ifndef _LED_H
#define _LED_H
#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"
#define nMAX 4

int led_init(int *pinNum,int n);
void* led_blink(void* pinNum);
void led_on(int pinNum);
void led_off(int pinNum);
#endif
```  
***Makefile:***  
```
binary:main.o led.o
        gcc -o binary main.o led.o -lwiringPi -lpthread
main.o:main.c led.h
        gcc -c main.c -lwiringPi -lpthread
led.o:led.c
        gcc -c led.c -lwiringPi
clean:
        rm main.o led.o binary
```  
Step2. Compile the Code  
```
cd Thread_test
make
```  
Step3. Running  
`./binary`  
## Homework  
* 使用多线程编程函数pthread创建不同的线程，实现四个led灯的同时控制。  
* 扩展作业：尝试完成两个Motors电机的控制程序，通过多线程完成电机的同时运转。  
## Reference  
[Linux下C语言进程通讯编程](https://www.cnblogs.com/uestc-mm/p/7630154.html)  
[Linux下C语言的进程控制编程](https://www.cnblogs.com/uestc-mm/p/7630161.html)  
[C语言多线程pthread库相关函数说明](https://www.cnblogs.com/mq0036/p/3710475.html)  
[pthread 使用入门](https://www.jianshu.com/p/88fdd500cf44)  
[Linux多线程学习总结](https://www.cnblogs.com/luoxn28/p/6087649.html)
