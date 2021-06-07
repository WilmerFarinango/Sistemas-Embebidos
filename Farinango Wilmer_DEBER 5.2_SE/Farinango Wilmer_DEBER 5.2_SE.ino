/*
   DEBER 5.2: SOLUCIONAR PROBLEMAS DEL CODIGO 23
   NOMBRE: Farinango Wilmer

   UNIDAD V: FUNCIONES ESPECIALES
   CÓDIGO 23: MANEJO DE MODOS SLEEP
   OJETIVO: Realizar un control de modos sleep por medio de interrupciones
   MODO SLEEP Y DE AHORRO DE BATERÍA
    Cosumo es de 100-500mA
    Ahorro de bateria es hasta 10mA
   Librerias: avr/sleep.h
              avr/power.h
*/
/*          librerias para usar         */
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include<EEPROM.h>
/*         Variables                    */
int dato;     // intrada de interrupcion, esta almacena los datos.
int on = 0;   // variable de entrada iniciada en 0
void(*resetFunc) (void) = 0; // es la funcion de reseteo(metodo dentro de otro metodo)
/*        configuracion/ programa       */
void setup() {
  Serial.begin(9600);              // Seria a 9600 baudios
  dato = EEPROM.read(0);          // asigna un valor a la variable
  Serial.println("CONFIGURACION");// imprimre en serial
  if (dato == 0) {                //si dato==0
    set_sleep_mode(SLEEP_MODE_STANDBY);// reduce el consumo a 0.84 mA
    sleep_enable();               // Activa modo sleep
    wdt_enable(WDTO_8S);          // se habilita en 8 segundos
    EEPROM.write(0, 1);           // Se escribe el dato en la memoria
  }
  else {
    sleep_disable();              // si fato == 1 se desabilita el modo sleep
    EEPROM.write(0, 0);           // escribe en memoria en la posicion 0 un dato "0"
    MsTimer2::set(10000, tiempo); // configura timer 2 a un segundo
    MsTimer2::start();            // se inicializa



  }
  attachInterrupt(0, encender, LOW);// interrupcion por el pin 2 me diante un boton
}
void loop() {
  if (dato == 0) {                // Si dato == 0
    Serial.println("DORMIDO ");// imprime Modo Dormido si dato ==0
    delay(200);                    // 200milisegundos de espera
    sleep_mode();                  // se activa el modo sleep
  }
  else {
    Serial.println("DESPIERTO ");
    delay(1000);
  }
}
void tiempo() {                  // metodo de tiempo para entrar al modo sleep
  Serial.println("TIEMPO DORMIDO");
  delay(4000);                  // 4000milisegundos de espera
  sleep_mode();                 // se activa el modo sleep
}

void encender () {              // metodo de enceder
  resetFunc();                  // resetea con la funcion
}
