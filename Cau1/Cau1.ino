/*
  Author: lov3five
*/
//Khai báo chân Pin các đèn LED
int GREEN_PIN = 11;
int RED_PIN = 12;
int YELLOW_PIN = 13;

void setup() {
  //Setup tốc độ dữ liệu theo bit trên giây (baud) để truyền dữ liệu
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
}

void ledLight(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration*1000);
  digitalWrite(pin, LOW);
}

void loop() {
  //Đèn xanh sáng 6s
  ledLight(GREEN_PIN, 6);
  //Đèn vàng sáng 3s
  ledLight(YELLOW_PIN, 3);
  //Đèn đỏ sáng 4s
  ledLight(RED_PIN, 4);
 
  delay(4000); //4s

}
