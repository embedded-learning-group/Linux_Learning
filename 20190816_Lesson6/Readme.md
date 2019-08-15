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
1. Coding C main.c.  
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
2. Compile main.c directly.  
`gcc main.c -o main -lwiringPi`  
3. Run Binary.  
`./main 0`  
## Writing The Makfile.  
1. 一个工程中的源文件不计数，其按类型、功能、模块分别放在若干个目录中，makefile定义了一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作，因为makefile就像一个Shell脚本一样，其中也可以执行操作系统的命令。  
2. makefile带来的好处就是——“自动化编译”，一旦写好，只需要一个make命令，整个工程完全自动编译，极大的提高了软件开发的效率。make是一个命令工具，是一个解释makefile中指令的命令工具，一般来说，大多数的IDE都有这个命令，比如：Delphi的make，Visual C++的nmake，Linux下GNU的make。可见，makefile都成为了一种在工程方面的编译方法。  
3. Compile the wiringPi file and lib.  
  ```
  CC=gcc
  main:main.c
      $CC wiringPi_Test.c -o main -lwiringPi
  clean:
      rm main
  ```  
4. Makefile深入实战演练.  
* The File Structure:  
![File_sructure](https://cl.ly/61f4edbfced8/FileStructure_Lesson6.png)  
If there is some function we need in the other c file,we need to link the file together with our main.c file.  
* The Code Content:  

  ***main.c:***  
  ```
  #include <stdio.h>
  #include "mymath.h"
  int main(void)
  {
      int Add1=10,Add2=20,Res=0;
      Res = sum(Add1,Add2);
      printf("%d + %d = %d\n",Add1,Add2,Res);
      return 0;
  }
  ```  
  ***mymath.c:***  
  ```
  #include "mymath.h"
  int sum(int a,int b)
  {
    return a+b;
  }
  ```  
  ***mymath.h:***  
  ```
  #ifndef _MYMATH_H
  #define _MYMATH_H
  #include <stdio.h>
  int sum(int a,int b);
  #endif
  ```  
* Here the makefile content:  
  ```
  CC=gcc
  binary:mymath.o main.o
	  $(CC) -o binary mymath.o main.o
  mymath.o:mymath.c mymath.h
  	  $(CC) -c mymath.c
  main.o:main.c
	  $(CC) -c main.c
  clean:
	  rm main.o mymath.o binary
  ```  
## Reference.  
[引脚对照表](https://blog.csdn.net/ylzmm/article/details/89396530)  
[树莓派B+ RPi & wringPi Lib install](https://www.cnblogs.com/uestc-mm/p/6290521.html)  
[树莓派风扇自动控制启动+调速](https://www.cnblogs.com/uestc-mm/p/7598178.html)  
[Makefile教程](https://blog.csdn.net/haoel/article/details/2886)
