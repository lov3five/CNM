""" 
Khu vực B 
Thu thập dữ liệu theo dõi chuyển động và có cảnh báo led đỏ nhấp nháy
"""
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
PIR_PIN = 4 # = 7 BOARD
RED_PIN = 17 # = 11 BOARD
#Left : 5V
#Middle: OUT
#Right: GND
GPIO.setup(PIR_PIN, GPIO.IN)
GPIO.setup(RED_PIN, GPIO.OUT)

def blinkLed(pin, duration):
     GPIO.output(pin, GPIO.HIGH)
     time.sleep(duration/2)
     GPIO.output(pin, GPIO.LOW)
     time.sleep(duration/2)

while True:
        time.sleep(0.1) 
        if GPIO.input(PIR_PIN)==1 :
            print (GPIO.input(PIR_PIN))
            print ("Motion detected!!!")
            blinkLed(RED_PIN, 1)
        elif GPIO.input(PIR_PIN)==0:
            print ("No motion.")
            GPIO.output(RED_PIN,GPIO.LOW)
            