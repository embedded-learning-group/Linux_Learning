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
