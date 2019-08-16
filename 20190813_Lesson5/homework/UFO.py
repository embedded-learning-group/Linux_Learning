import RPi.GPIO as GPIO
import time
import os 
print 'Raspberry GPIO initial...'
motor_pin_AP = 18 # GPIO_pin OK!
motor_pin_AN = 23 # GPIO_pin OK!
motor_pin_BP = 24 # GPIO_pin OK!
motor_pin_BN = 25 # GPIO_pin OK!

motor_speed = 0.004 # 0.00055 0.0015
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(motor_pin_AP,GPIO.OUT)
GPIO.setup(motor_pin_AN,GPIO.OUT)
GPIO.setup(motor_pin_BP,GPIO.OUT)
GPIO.setup(motor_pin_BN,GPIO.OUT)

def motor_4line_2phase(step, direction):
    if direction == 'CW': # Clockwise direction
        for i in range(step):
            # print 'Step1'
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
            # print 'Step2'
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
            # print 'Step3'
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            # print 'Step4'
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed) 
           
    if direction == 'CCW': # Counter-clockwise direcion
        for i in range(step):

             # print 'Step2'
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            # print 'Step3'
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,True)
            GPIO.output(motor_pin_BN,False)
            time.sleep(motor_speed)
            #1
            GPIO.output(motor_pin_AP,True)
            GPIO.output(motor_pin_AN,False)
            GPIO.output(motor_pin_BP,False)
            GPIO.output(motor_pin_BN,True)
            time.sleep(motor_speed)
            # print 'Step4'
            GPIO.output(motor_pin_AP,False)
            GPIO.output(motor_pin_AN,True)
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
        motor_4line_2phase(50,'CW')
        motor_4line_2phase(50,'CCW')