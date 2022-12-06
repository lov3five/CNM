/*
  Author: @lov3five
    Device:
    - Arduino Uno R3
    - Gas sensor MQ135
    - 1 RED led, 1 GREEN led
    - 1 buzzer
    - 1 coder :v
*/
int RED_LED = 11; //Chân 11 Uno
int GREEN_LED = 12; //Chân 11 Uno
int BUZZER = 13; //Chân 13 Uno
int MQ_135 = A0; // Chân A0 Uno
int valueMQ135;

void setup() {
  //Setup tốc độ dữ liệu theo bit trên giây (baud) để truyền dữ liệu
  Serial.begin(9600);
  //INPUT
  pinMode(MQ_135, INPUT);
  //OUTPUT
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void blinkLed3s(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}

void loop() {
  //Mỗi 5s nhận dữ liệu từ cảm biến 
  delay(5000);
  
  valueMQ135 =  analogRead(MQ_135); //Đọc giá trị nhận từ cảm biến MQ135 và gán vào valueMQ135
  Serial.print("Gia tri MQ_135 = ");
  Serial.println(valueMQ135);
  
  //Nếu giá trị > 200 thì Led đỏ sáng 3s rồi tắt & còi kêu trong 5s rồi tắt
  if (valueMQ135 > 200) {
    digitalWrite(GREEN_LED, LOW);
    
    digitalWrite(BUZZER, HIGH);
    
    // Led đỏ nhấp nháy trong 3s
    blinkLed3s(RED_LED);

    //Còi kêu trong 5s (trừ 3s của LED thì còn 2s)
    delay(2000);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    //Led xanh sáng
    digitalWrite(GREEN_LED, HIGH);
  }
}
