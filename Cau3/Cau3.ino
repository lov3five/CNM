/*
  Author: @lov3five
  Câu 3
*/
//Thư viện DHT
#include <dht.h>
//Khai báo hằng số chân Pin của DHT = A0
#define DHT_PIN A0
dht DHT;

int YELLOW_PIN = 11;
int GREEN_PIN = 12;
int RED_PIN = 13;
int BUZZER_PIN = 9;

void setup() {
  Serial.begin(9600);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(DHT_PIN, INPUT);

  //Setup tắt mặc định
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  //Dùng read11 của thư viện DHT đọc đầu vào
  DHT.read11(DHT_PIN);

  //Dùng temperature của thư viện DHT để đọc dữ liệu nhiệt độ
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print(" Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("*C  ");

  if (DHT.temperature < 20) {
    //Led Xanh sáng
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  } else if ((DHT.temperature >= 20) && (DHT.temperature <= 25)) {
    //Led vàng sáng
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
  } else {
    //Led đỏ sáng
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }
  //Time lấy mẫu
  delay(4000);
}
