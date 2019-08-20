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
