""" Thu thập dữ liệu ở khu vực C """
import RPi.GPIO as GPIO
import time

# Setmode BCM
GPIO.setmode(GPIO.BCM)
# Chân Pin cảm biến MQ135
MQ135_PIN = 4
RED_PIN = 17 # = 11 BOARD
# INPUT
GPIO.setup(MQ135_PIN, GPIO.IN) # = 7 BOARD
GPIO.setup(RED_PIN, GPIO.OUT)



