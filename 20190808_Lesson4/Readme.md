# Lesson4: Introduce the 42 Step Motor Control Demo.
## What is 42 Step Motor?
This Picture show all the params of the Stepper Motor.If you want see detailly,please Download the pic and check on the PC directly.  
![42-MotorStepper](https://github.com/embedded-learning-group/Linux_Learning/blob/master/20190808_Lesson4/src_1450336973.jpg)  
Now We need to intoduce the detail info of 42-Motor:  
Normally the 42-Motor have two group of wires(AC && BD),So we can see four interface of the motor. When we are going to control it,we should control the wires in one Group step by step. We should follow the Control steps:  
![Wire_Group](https://github.com/embedded-learning-group/Linux_Learning/blob/master/20190808_Lesson4/Stepper-Motor.png)

| A+ | A- | B+ | B- |
| :-----: | :----: | :----: | :----: |
| Wire-A | Wire-C | Wire-B | Wire-D |
| 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
## How to Control Step motor by motor Driver?
You can see the detail introduce at this Web Site: [A4988-MotorDriver](https://www.pololu.com/product/1182)  
This product is a carrier board or breakout board for Allegro’s A4988 DMOS Microstepping Driver with Translator and Overcurrent Protection; we therefore recommend careful reading of the [A4988 datasheet (1MB pdf)](https://www.pololu.com/file/0J450/A4988.pdf) before using this product. This stepper motor driver lets you control one [bipolar stepper motor](https://www.pololu.com/category/87/stepper-motors) at up to 2 A output current per coil (see the Power Dissipation Considerations section below for more information). Here are some of the driver’s key features:
* Simple step and direction control interface  
* Five different step resolutions: full-step, half-step, quarter-step, eighth-step, and sixteenth-step  
* Adjustable current control lets you set the maximum current output with a potentiometer, which lets you use voltages above your stepper  motor’s rated voltage to achieve higher step rates  
* Intelligent chopping control that automatically selects the correct current decay mode (fast decay or slow decay)  
* Over-temperature thermal shutdown, under-voltage lockout, and crossover-current protection  
* Short-to-ground and shorted-load protection  

Connecting Circute:  
![connect-pic](https://github.com/embedded-learning-group/Linux_Learning/blob/master/20190808_Lesson4/connect.jpg)    
Step (and microstep) size:  

| MS1 | MS2 | MS3 | Microstep Resolution |
| :-----: | :----: | :----: | :----: |
| Low | Low | Low | Full step |
| High | Low | Low | Half step |
| Low | High | Low | Quarter step |
| High | High | Low | Eighth step |
| High | High | High | Sixteenth step |
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
