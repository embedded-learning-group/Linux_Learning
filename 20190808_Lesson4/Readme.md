# Lesson4: Introduce the 42 Step Motor Control Demo.
## What is 42 Step Motor?
## How to Control Step motor by motor Driver?
## Coding on the RaspberryPi to control the Step Motor.
```
from picamera.array import PiRGBArray
from picamera import PiCamera
import RPi.GPIO as GPIO
import time
import os 

x_motor_pin_DIR = 15
x_motor_pin_STEP = 14
x_motor_pin_EN = 17

x_motor_speed = 0.008

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(x_motor_pin_DIR,GPIO.OUT)
GPIO.setup(x_motor_pin_STEP,GPIO.OUT)
GPIO.setup(x_motor_pin_EN,GPIO.OUT)

def motor_control(direction,step):
    if direction == 'left':
        print 'left',step
        GPIO.output(x_motor_pin_EN,False)
        GPIO.output(x_motor_pin_DIR,True)
        for i in range(step):
            # print 'left circle'
            GPIO.output(x_motor_pin_STEP,True)
            time.sleep(x_motor_speed)
            GPIO.output(x_motor_pin_STEP,False)
            time.sleep(x_motor_speed)
        GPIO.output(x_motor_pin_EN,True)
    if direction == 'right':
        print 'right',step
        GPIO.output(x_motor_pin_EN,False)
        GPIO.output(x_motor_pin_DIR,False)
        for i in range(step):
            # print 'right circle!'
            GPIO.output(x_motor_pin_STEP,True)
            time.sleep(x_motor_speed)
            GPIO.output(x_motor_pin_STEP,False)
            time.sleep(x_motor_speed)
        GPIO.output(x_motor_pin_EN,True)

def Motor_PowerOff(Motor):
    if Motor == 'x':
        GPIO.output(x_motor_pin_EN,True)
    if Motor == 'y':
        GPIO.output(y_motor_pin_AP,False)
        GPIO.output(y_motor_pin_AN,False)
        GPIO.output(y_motor_pin_BP,False)
        GPIO.output(y_motor_pin_BN,False)
motor_control('left',1000)
motor_control('right',1000)
```
## Homework
