const int btn1 = 13;
const int btn2 = 12;
const int btn3 = 11;
const int btn4 = 10;
const int btn5 = 9;
const int btn6 = 8;
int valor = 1;
void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn6, INPUT);
}
void loop() {
  if (digitalRead(btn1) == LOW) {
    delay(200);
    Serial.write(valor);
  }
  if (digitalRead(btn2) == LOW) {
    delay(200);
    Serial.write(2);
  }
  if (digitalRead(btn3) == LOW) {
    delay(200);
    Serial.write(3);
  }
  if (digitalRead(btn4) == LOW) {
    delay(200);
    Serial.write(4);
  }
  if (digitalRead(btn5) == LOW) {
    delay(200);
    Serial.write(5);
  }
  if (digitalRead(btn6) == LOW) {
    delay(200);
    Serial.write(6);
  }

}
