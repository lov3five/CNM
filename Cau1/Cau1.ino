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

void loop() {
  //Đèn đỏ, đèn vàng tắt
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);

  //Đèn xanh sáng 6s
  Serial.println("GREEN_LED turn on");
  digitalWrite(GREEN_PIN, HIGH);
  delay(6000); //6s

  //Đèn đỏ,  đèn xanh tắt
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);

  //Đèn vàng sáng 3s
  Serial.println("YELLOW_LED turn on");
  digitalWrite(YELLOW_PIN, HIGH);
  delay(3000); //3s

  //Đèn vàng, đèn xanh tắt
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);

  //Đèn đỏ sáng 4s
  Serial.println("RED_LED turn on");
  digitalWrite(RED_PIN, HIGH);
  delay(4000); //4s

}
