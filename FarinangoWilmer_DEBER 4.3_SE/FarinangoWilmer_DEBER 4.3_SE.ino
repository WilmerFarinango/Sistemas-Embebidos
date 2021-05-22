/*
  DEBER 4.3: Periféricos Especiales - Interrupciones
  Nombre: FARINANGO WILMER
  Fecha: 21-05-2021
  Docente: Ing. Pamela Godoy
*/

#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int segundos = 0;    //variables para los segundos
int minutos = 0;     //variables para los minutos
int horas = 0;       //variables para las horas
void setup() {
  lcd.begin(20, 4);            //incia la LCD
  MsTimer2::set(1000, reloj);  //configura el timer 2 a 1 segundo
  MsTimer2::start();
}
void loop() {
}
void reloj() {
  if (segundos < 60) {  //condición para los segundos
    segundos++;         //incrementar la variable
  } else {
    segundos = 0;
    if (minutos < 60) { //condición de minutos
      minutos++;        //incrementar la variable
    } else {
      minutos = 0;
      if (horas < 24) { //condición de horas
        horas++;        //incrementar la variable
      } else {
        horas = 0;
      }
    }
  }
  lcd.clear();          //borrar el anterior mensaje
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO - RELOJ");
  lcd.setCursor(0, 1);
  lcd.print("FARINANGO T. WILMER");
  lcd.setCursor(0, 2);
  lcd.print("Hora Min Seg");
  lcd.setCursor(1, 3);  //ubicación de LCD
  lcd.print(String(horas)+String(":"));  //mensaje de impresión en la LCD
  lcd.setCursor(4, 3);
  lcd.print(String(minutos)+String(":"));
  lcd.setCursor(7, 3);
  lcd.print(String(segundos));
}
