/////////////////////////////////////ESCLAVO_1/////////////////////////////////////
#include <Wire.h>
int cont = 0;
void setup() {
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
}

void receiveEvent(int bytes) {     // evento I2C
  while (Wire.available()) { // VERIFICA SI EXISTE UN MENSAJE
    cont++;
    Serial.print("Mensaje recibido: ");
    Serial.println(cont);
    int c = Wire.read();
   // Serial.println(c);
   ledprender();
  }
}
void ledprender() {
  for (int i = 13; i > 10; i--) {
    Serial.print("led encendido: ");
    Serial.println(i);
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
