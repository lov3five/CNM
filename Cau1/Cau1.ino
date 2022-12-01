/*
  Author: lov3five
*/
int GREEN_PIN = 11;
int RED_PIN = 12;
int YELLOW_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  Serial.println("GREEN_LED turn on");
  digitalWrite(GREEN_PIN, HIGH);
  delay(6000); //6s

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("YELLOW_LED turn on");
  digitalWrite(YELLOW_PIN, HIGH);
  delay(3000); //3s

  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("RED_LED turn on");
  digitalWrite(RED_PIN, HIGH);
  delay(4000); //4s

}
