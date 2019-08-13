# wirinPi Lib Advantage Using in Motor Control.  
## 24BYJ48-Motor([BUY-Link](https://detail.tmall.com/item.htm?spm=a230r.1.14.137.472f69f3KMbosN&id=557446741238&ns=1&abbucket=15)) Introduction:  
1. Description:  
![Motor]()
24BYJ48-Motor has five wires.The Red wire is the common wire used to connect to the Power Suppy(5V).The Other coils used to drive the rotator running.  
* This is the basic circute:  
![Circute]()  
* Here the sequence of the wire to make it running:  
单双八拍，逆时针：A-AB-B-BC-C-CD-D-DA-A  
![Driver]()

| 线色 | 电极 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| :-----: | :-----: | :-----: | :------: | :------: | :------: | :------: | :------: | :-----: | :-----: |
| A | 蓝 | A | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| B | 粉 | A- | 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| C | 黄 | B | 0 | 0 | 0 | 1 | 1 | 1 | 0 | 0 |
| D | 橙 | B- | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 |

2. Features:  
* 4相5线减速步进电机  
* 相电阻：18欧  
* 电压：DC 5V  
* 步进角度：5.625 x 1/16  
* 减速比：64:1  
* 线长：11cm  
* 重量：28g  
## ULN2003-MotorDriver Introduction:  
![ULN2003]()  
1. Description:  
The ULx200xA devices are high-voltage, high-current Darlington transistor arrays. Each consists of seven NPN Darlington pairs that feature high-voltage outputs with common-cathode clamp diodes for switching inductive loads.  
The collector-current rating of a single Darlington pair is 500 mA. The Darlington pairs can be paralleled for higher current capability. Applications include relay drivers, hammer drivers, lamp drivers, display drivers (LED and gas discharge), line drivers, and logic buffers. For 100-V (otherwise interchangeable) versions of the ULx2003A devices, see the SLRS023 data sheet for the SN75468 and SN75469 devices.  
2. Features:  
* 500-mA-Rated Collector Current (Single Output)  
* High-Voltage Outputs: 50 V  
* Output Clamp Diodes  
* Inputs Compatible With Various Types of Logic  
* Relay-Driver Applications  
## The Python Code depend on RPi.GPIO Lib.  
```
import RPi.GPIO as GPIO
import time
import os 
print 'Raspberry GPIO initial...'
motor_pin_AP = 18 # GPIO_pin OK!
motor_pin_AN = 23 # GPIO_pin OK!
motor_pin_BP = 24 # GPIO_pin OK!
motor_pin_BN = 25 # GPIO_pin OK!

motor_speed = 0.0018 # 0.00055 0.0015
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(motor_pin_AP,GPIO.OUT)
GPIO.setup(motor_pin_AN,GPIO.OUT)
GPIO.setup(motor_pin_BP,GPIO.OUT)
GPIO.setup(motor_pin_BN,GPIO.OUT)
def motor_4line_2phase(step, direction):
    if direction == 'CW': # Clockwise direction
        for i in range(step):
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
    if direction == 'CCW': # Counter-clockwise direcion
        for i in range(step):
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
def Pin_Test():
    GPIO.output(motor_pin_AP,False)
    GPIO.output(motor_pin_AN,False)
    GPIO.output(motor_pin_BP,False)
    GPIO.output(motor_pin_BN,False)
    time.sleep(3)
    GPIO.output(motor_pin_AP,True)
    GPIO.output(motor_pin_AN,True)
    GPIO.output(motor_pin_BP,True)
    GPIO.output(motor_pin_BN,True)
    time.sleep(3)
while True:
    print 'Please choose a Mode:'
    Choice = input()
    while Choice == 'T' or Choice == 't':
        print 'Motor pin testing!'
        Pin_Test()
    while Choice == 'R' or Choice == 'r':
        print 'Motor Driver testing!'
        motor_4line_2phase(1000,'CW')
```  
## Homework  
使用wiringPi
## Reference:  
[分辨5线单极性步进电机接头](https://www.cnblogs.com/yuwl26/p/3314057.html)  
[步进电机24BYJ48定子线圈的原理](https://www.zhihu.com/question/53400260)
