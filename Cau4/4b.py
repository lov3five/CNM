""" Thu thập dữ liệu ở khu vực C """
import RPi.GPIO as GPIO
import time


# Setmode BCM
GPIO.setmode(GPIO.BCM)
# Chân Pin cảm biến MQ135
MQ135_PIN = 4 # = 7 BOARD
RED_PIN = 17 # = 11 BOARD
# INPUT
GPIO.setup(MQ135_PIN, GPIO.IN) 
GPIO.setup(RED_PIN, GPIO.OUT)

while True:
    valueMQ135 = GPIO.input(MQ135_PIN)
    print('Value of MQ135: {valueMQ135}')
    if(valueMQ135 > 60):
        GPIO.output(RED_PIN, GPIO.HIGH)
        print("RED_LED turn ON")
    time.sleep(5)





