# WiringPi Users Guide  
I have already make a new image with the wiringPi installed.  
You can backup the image with the wiringPi Lib.  
If you want create a new image with wiringPi,Please just use this Image file.  
## The difference between RPi.GPIO(BCM/BOARD) and wiringPi Mapping mothed.  
Show in the Picture.  
![GPIO Mapping](https://cl.ly/ef406ca9be9d/Raspberry_GPIO_Mapping.png)
For Example the GPIO-Name:GPIO.0:  
* RPi.GPIO: PinNum=17 <---> GPIO.setmode(GPIO.BCM) or PinNum=11 <---> GPIO.setmode(GPIO.BOARD)  
* WiringPi: PinNum=0  
## Coding On The RaspberryPi.  
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
## Writing The Makfile.  

```
led.c -o led -lwiringPi
```  
## Reference.  
[引脚对照表](https://blog.csdn.net/ylzmm/article/details/89396530)  
[树莓派B+ RPi & wringPi Lib install](https://www.cnblogs.com/uestc-mm/p/6290521.html)  
[树莓派风扇自动控制启动+调速](https://www.cnblogs.com/uestc-mm/p/7598178.html)  
