import urllib3 # dùng để mở các URL
from time import sleep
import Adafruit_DHT as dht # Thư viện của cảm biến DHT11
import RPi.GPIO as GPIO
# Setmode BCM
GPIO.setmode(GPIO.BCM)
# Mã API
myAPI = '19CQPMBCIMS6TMDS'
# URL của ThingSpeak dùng để gửi dữ liệu
baseURL = 'https://api.thingspeak.com/update?api_key=%s'%myAPI
http = urllib3.PoolManager()
DHT_PIN = 4 # = 7 BOARD


while True:
        humi, temp = dht.read_retry(dht.DHT11, DHT_PIN)
        print("Temperature: {}*C  Humidity: {}%".format(temp, humi))
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
   
