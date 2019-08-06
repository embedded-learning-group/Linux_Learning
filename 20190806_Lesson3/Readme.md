## First Lesson for Raspberry Pi to blink a led.
Step1. We need to install the GPIO and devcice Control library(wiringPi) firstly.  
这里是安装的基本步骤: [wiringPi Install](https://www.cnblogs.com/uestc-mm/p/6290521.html)  
Follow the steps to install the wiringPi.It's easyly to install the library.  
Step2. Learn the GPIO on the BCM MODE map.
![GPIO MAPPING]()
## Learn how to use the wiringPi Lib to Control the GPIO.  
1. wiringPiSetup(): The function is used to initial the wiringPi lib so that we can use it correctly.
2. pinMode(pinNumber, OUTPUT): This function is used to set the pin's mode to be OUTPUT,we also can change it into INPUT mode.
3. digitalWrite(pinNumber, 1): This function is used to set the pin's state,if set to be 1,the GPIO Pin OUTPUT HIGH.
4. delay(800): The delay function is use to set the time to sleep while the program is running.
Step3. Coding with the wiringPi Lib.
```
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    if (argc < 2)
    {
        printf("Usage example: ./led 4 \n");
        return 1;
    }
    int pinNumber = atoi(argv[1]);//字符串转整形函数atoi()函数
    printf("PinNumber is:%d\n",pinNumber);
    if (-1 == wiringPiSetup())
    {
        printf("Setup wiringPi failed!");
        return 1;
    }
    printf("The Code will begain to Running!\n");
    pinMode(pinNumber, OUTPUT); // set mode to output 
    while(1) 
    {
        digitalWrite(pinNumber, 1); // output a high level 
        delay(800);
        digitalWrite(pinNumber, 0); // output a low level 
        delay(800);
    }
    return 0;
}
```
Step3. Compile the C code into a executable binary file.
`gcc led.c -o led -lwiringPi`
Step4. Run your code.
## Homwork
用wiringPi库完成一个简单的流水灯的实现，可以控制不同颜色的彩灯来完成不同的跑马灯程序！其他类型的跑马灯可以自行扩展！
