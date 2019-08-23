#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
    if (argc < 6)
    {
        printf("Usage example: ./led 4 \n");
        return 1;
    }
    int pinNumber1,pinNumber2,pinNumber3,pinNumber4;
    pinNumber1 = atoi(argv[1]);//字符串转整形函数atoi()函数
    pinNumber2 = atoi(argv[2]);
    pinNumber3 = atoi(argv[3]);
    pinNumber4 = atoi(argv[4]);
    printf("PinNumber is:%d,%d,%d,%d\n",pinNumber1,pinNumber2,pinNumber3,pinNumber4);
    if (-1 == wiringPiSetup())
    {
        printf("Setup wiringPi failed!");
        return 1;
    }
    printf("The Code will begain to Running!\n");
   
    pinMode(pinNumber1, OUTPUT); // set mode to output
    pinMode(pinNumber2, OUTPUT);
    pinMode(pinNumber3, OUTPUT);
    pinMode(pinNumber4, OUTPUT);
    
    int i;
    int steP=50;
    int fucking_time=atoi(argv[5]);
    printf("the speed:%d\n",fucking_time);
    
    for(i=0;i<=steP;i++)
    {   
        digitalWrite(pinNumber1, 0); // output a low level
        digitalWrite(pinNumber2, 1); // output a high level
        digitalWrite(pinNumber3, 0); // output a low level
        digitalWrite(pinNumber4, 1); // output a high level
        delay(fucking_time);
        
        digitalWrite(pinNumber1, 1); 
        digitalWrite(pinNumber2, 0); 
        digitalWrite(pinNumber3, 0);
        digitalWrite(pinNumber4, 1); 
        delay(fucking_time);
        
        digitalWrite(pinNumber1, 1); 
        digitalWrite(pinNumber2, 0); 
        digitalWrite(pinNumber3, 1);
        digitalWrite(pinNumber4, 0); 
        delay(fucking_time);
        
        digitalWrite(pinNumber1, 0); 
        digitalWrite(pinNumber2, 1); 
        digitalWrite(pinNumber3, 1);
        digitalWrite(pinNumber4, 0); 
        delay(fucking_time);
    }
    return 0;
}
