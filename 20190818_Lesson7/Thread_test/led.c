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
