import sys
import urllib3 
from time import sleep
import Adafruit_DHT as dht
import RPi.GPIO as GPIO
# Setmode BCM
GPIO.setmode(GPIO.BCM)
# Mã API
myAPI = '19CQPMBCIMS6TMDS'
# URL của ThingSpeak dùng để gửi dữ liệu
baseURL = 'https://api.thingspeak.com/update?api_key=%s'%myAPI
http = urllib3.PoolManager()

DHT_PIN = 22 
RED_PIN = 14
YELLOW_PIN = 15
GREEN_PIN = 18
BUZZER_PIN = 27

GPIO.setup(DHT_PIN, GPIO.IN)
GPIO.setup(RED_PIN, GPIO.OUT)
GPIO.setup(YELLOW_PIN, GPIO.OUT)
GPIO.setup(GREEN_PIN, GPIO.OUT)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

while True:
        humi, temp = dht.read_retry(dht.DHT11, DHT_PIN)
        print("Temperature: {}*C  Humidity: {}%".format(temp, humi))
        if (temp <= 18):
            GPIO.output(RED_PIN, GPIO.LOW)
            GPIO.output(YELLOW_PIN, GPIO.LOW)
            GPIO.output(BUZZER_PIN, GPIO.LOW)
            GPIO.output(GREEN_PIN, GPIO.HIGH)
            
        elif (temp > 18) and (temp <= 24):
            GPIO.output(GREEN_PIN, GPIO.LOW)
            GPIO.output(RED_PIN, GPIO.LOW)
            GPIO.output(BUZZER_PIN, GPIO.LOW)
            GPIO.output(YELLOW_PIN, GPIO.HIGH)
        else:
            GPIO.output(GREEN_PIN, GPIO.LOW)
            GPIO.output(YELLOW_PIN, GPIO.LOW)
            GPIO.output(RED_PIN, GPIO.HIGH)
            GPIO.output(BUZZER_PIN, GPIO.HIGH)
        # Nếu có dữ liệu từ cảm biến
        if isinstance(humi, float) and isinstance(temp, float):
            # Làm tròn đến 2 chữ số thập phân
            humi = '%.2f' % humi
            temp = '%.2f' % temp
        # Gửi dữ liệu lên ThingSpeak
            conn = http.request('POST',
                baseURL + '&field1=%s&field2=%s' % (temp, humi))
            #print(conn.data)
        # Đóng kết nối
            conn.close()
        else:
            print('Error')
#Lấy dữ liệu mỗi 2s
        sleep(2)
   
