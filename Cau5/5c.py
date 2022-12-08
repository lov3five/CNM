""" 

"""
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
PIR_PIN = 4 # = 7 BOARD
BUZZER_PIN = 27 # = 11 BOARD
#Left : 5V
#Middle: OUT
#Right: GND
GPIO.setup(PIR_PIN, GPIO.IN)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

while True:
        time.sleep(0.1) 
        if GPIO.input(PIR_PIN)==1 :
            print (GPIO.input(PIR_PIN))
            print ("Motion detected!!!")
            GPIO.output(BUZZER_PIN,GPIO.HIGH)
        elif GPIO.input(PIR_PIN)==0:
            print ("No motion.")
            GPIO.output(BUZZER_PIN,GPIO.LOW)
            