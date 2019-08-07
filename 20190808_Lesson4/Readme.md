# Lesson4: Introduce the 42 Step Motor Control Demo.
## What is 42 Step Motor?
This Picture show all the params of the Stepper Motor.If you want see detailly,please Download the pic and check on the PC directly.  
![42-MotorStepper]()  
Now We need to intoduce the detail info of 42-Motor:  
Normally the 42-Motor have two group of wires(AC && BD),So we can see four interface of the motor. When we are going to control it,we should control the wires in one Group step by step. We should follow the Control steps:  
![Wire_Group]()

| A+ | A- | B+ | B- |
| :-----: | :----: | :----: | :----: |
| Wire-A | Wire-C | Wire-B | Wire-D |
| 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
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
## Reference  
* 51单片机直接控制42步进电机参考:  
[51-MicroProcessor-42Stepper](https://www.cnblogs.com/uestc-mm/p/5161668.html)  
* 使用protues软件仿真控制42步进电机:  
[Protues-42Stepper](http://www.51hei.com/bbs/dpj-57073-1.html)  
* 步进电机原理:  
[电机原理](https://blog.csdn.net/qq_38405680/article/details/80452583)  
## Homework(Important！)  
调整电机驱动脉冲的时间间隔，测量不同脉冲间隔条件下电机的转速情况，统计成表格，并标注出电机的抖动程度(1~10级别)，为后续使用电机的参数设置提前做好相应的准备。表格格式如下所示：  

| 脉冲间隔(ms) | 转速(rpm) | 抖动级别(G) |
| :-----: | :----: | :----: |
| 10 | 100 | 5 |
| 20 | 50 | 3 |
