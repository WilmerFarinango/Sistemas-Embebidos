#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,9,8,7,6); // LDC 1 activado
LiquidCrystal lcd2(5,4,3,2,A5,A4);// LDC 2 activado
int analogPin=A0;  // activamos el pin analogo A0
int analogPin_1=A1;// activamos el pin analogo A1
// colocamos variables del LCD1
int conversor;
float voltaje;
int dutty;
// interruptores
int sw1=A2;
int btn1=A3;
// Variables LCD2
int conversor_1;
float voltaje_2;

void setup() {
  lcd.begin(16,2);// lcd 1
  lcd2.begin(16,2);//lcd 2
  Serial.begin(9600);  
}

void loop() {
  if(digitalRead(sw1)==LOW){// si sw1 esta en bajo, por defencto eesta en alto
  conversor=analogRead(analogPin);// leemos el dato que entrega el potenciometro
  voltaje=(conversor*5)/1023;// operamos, para que quede en terminos de 0 a 5v
  dutty=conversor/4;// dividmos /4
  analogWrite(11,dutty);//llamamos para controlar la velocidad del motor
  // imprimir en pantalla los datos
  lcd.setCursor(0,0);
  lcd.print("CAD");
  lcd.setCursor(5,0);
  lcd.print(conversor);
  Serial.println(conversor);
  lcd.setCursor(0,1);
  lcd.print("V");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  Serial.println(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PMW");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);
  lcd.clear();
  }
  
  if(digitalRead(btn1)==LOW){ //si el boton esta en low, presionamos y activamos en high
  conversor_1=analogRead(analogPin_1);
  voltaje_2=(conversor_1*5)/1023;
  dutty=conversor_1/4;
  analogWrite(10,dutty);
   // imprimir en pantalla los datos
  lcd2.setCursor(0,0);
  lcd2.print("CAD");
  lcd2.setCursor(5,0);
  lcd2.print(conversor_1);
  Serial.println(conversor_1);
  lcd2.setCursor(0,1);
  lcd2.print("V");
  lcd2.setCursor(3,1);
  lcd2.print(voltaje_2);
  Serial.println(voltaje_2);
  lcd2.setCursor(9,1);
  lcd2.print("PMW");
  lcd2.setCursor(13,1);
  lcd2.print((dutty*100)/255);
  delay(300);
  lcd2.clear();
  }
}


  
  
