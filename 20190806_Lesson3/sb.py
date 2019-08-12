from picamera.array import PiRGBArray
from picamera import PiCamera
import RPi.GPIO as GPIO
import time
import os

red_pin_light = 10
green_pin_light = 9

fucking_time = 0.8

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(red_pin_light,GPIO.OUT)
GPIO.setup(green_pin_light,GPIO.OUT)

def red_or_green_light(color):
    if color == '1':
        
        GPIO.output(red_pin_light,True)
        time.sleep(fucking_time)
        GPIO.output(green_pin_light,False)
        
    if color == '0':
        
        GPIO.output(green_pin_light,True)
        time.sleep(fucking_time)
        GPIO.output(red_pin_light,False)
        
        
           # time.sleep(x_motor_speed)
        
for i in range(1,50,1):
    if i%2==1:
        print (' red ')
        red_or_green_light('1')
        #time.sleep(fucking_time)
       
    else:
        print ('green')
        red_or_green_light('0')
        #time.sleep(fucking_time)
       

        #GPIO.output(x_motor_pin_EN,True)
   # if direction == 'right':
    #    print 'right',step
     #   GPIO.output(x_motor_pin_EN,False)
      #  GPIO.output(x_motor_pin_DIR,False)
       # for i in range(step):
            # print 'right circle!'
        #    GPIO.output(x_motor_pin_STEP,True)
         #   time.sleep(x_motor_speed)
          #  GPIO.output(x_motor_pin_STEP,False)
           # time.sleep(x_motor_speed)
        #GPIO.output(x_motor_pin_EN,Tr
