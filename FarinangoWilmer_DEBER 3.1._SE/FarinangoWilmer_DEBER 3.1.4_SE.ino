////////////////////////////////MAESTRO////////////////////////////
#include <Wire.h>
int cont = 0;

void setup() {
  Serial.begin(9600);// inicializamos la comunicación serial
  Serial.println("Bienvenidos "); //Mensaje a Monitor Serial
  Serial.println("Ordenes: PRESIONE CUALQUIER TECLA");//Mensaje por Monitor Serial
  delay(100); //Los retardos son necesarios en la practica para mejorar desempeño
}
void loop() {
  if (Serial.available()) { //Si la comunicacion serial es utilizable, pregunta aqui.
    char c = Serial.read(); // Se lee el monitor serial y esperando solo un carac
    Serial.println(" ");
    Serial.println("TECLA ALEATORIA PRESIONADA");
    delay(100);
    cont++;
    if (cont == 1) { // ACTIVA EL 1ER ESCLAVO
      Serial.println("ESCLAVO 1 ENCENDIDO");
      Wire.beginTransmission(1);// configuracion del esclavo con direccion
      Wire.write(c);           // envio de mensaje
      Wire.endTransmission();     // fin de la comunicacion
      delay(100);
    }
    else if (cont == 2) { //ACTIVA EL 2DO ESCLAVO
      Serial.println("ESCLAVO 2 ENCENDIDO");
      Wire.beginTransmission(2);// configuracion del esclavo con direccion
      Wire.write(c);           // envio de mensaje
      Wire.endTransmission();     // fin de la comunicacion
      delay(100);
    }
    else if (cont == 3) { //ACTIVA EL 3ER ESCLAVO
      Serial.println("ESCLAVO 3 ENCENDIDO");
      Wire.beginTransmission(3);// configuracion del esclavo con direccion
      Wire.write(c);           // envio de mensaje
      Wire.endTransmission();     // fin de la comunicacion
      delay(100);
      cont = 0;
    }
    else {
    }
  }
}
