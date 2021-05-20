//Variables LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
//variables de interrupcion
int band=0;
int band2=0;
//variables LEDS
int randm;
//variables del relog
int hors;
int mins;
//variables potenciometro
const int poth=0;
int leerpoth;
const int potm=1;
int leerpotm;
//variables de sensores
int pulsar1=A2;
int pulsar2=A3;
int pulsar3=A4;
int pulsar4=A5;
int btn1;
int btn2;
int btn3;
int btn4;

void setup() {
  //sensores
  pinMode(pulsar1,INPUT);
  pinMode(pulsar1,INPUT);
  pinMode(pulsar1,INPUT);
  pinMode(pulsar1,INPUT);
  
  // INTERRUPCIONES
  pinMode(2,INPUT);  
  pinMode(3,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),funcion,RISING);  
  attachInterrupt(digitalPinToInterrupt(3),funcion2,RISING);
  //COMUNICACION SERIAL
  Serial.begin(9600);
  // LCD  
  lcd.begin(16, 2);
  lcd.print("LAB2: Wilmer. F."); 
}

void loop() {
  if(band2==1){
    lcd.clear();
    SisOFF();
    Serial.print("apagado\n");
    Serial.print(band2);
  }
  if(band2==2){
    SisON();
    Serial.print("encendido\n");
    Serial.print(band2);
  }
  if(band==1)luces();
  if(band==2)cambiar();
  if(band==3)relog();
  if(band==4)alarmas();
  // MODOS
  /*a activacion 4 luces deforma aleatoria 
  con un mınimo de activaci´on de 20 minutos
  */
  
  
}


void funcion(){
  band=band+1;
}

void funcion2(){
  band2=band2+1;
}
void SisON(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SIST ON: MODO  0");
  delay(100);
}

void SisOFF(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SIST OF");
  delay(1000);
}


void luces(){
  if(band==1){
  Serial.print("MODO :");
  Serial.println(band);
  }
  lcd.clear();
  for(int l=20;l>0;l--){
  randm=random(10,13);
  digitalWrite(randm,HIGH); 
  delay(1000);
  digitalWrite(randm,LOW);
    lcd.setCursor(5, 0);    
    lcd.print("LEDS");
    lcd.setCursor(0,1);
    if(l<10)lcd.print("0");
    lcd.print(l);    
       
    Serial.print("LEDS\n");
    Serial.print(band);
  }
}
void relog(){
  if(band==2){
  Serial.print("MODO :");
  Serial.println(band);
  }
  //minutero
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("RELOJ");
  mins=mins+1;
  lcd.setCursor(3, 1);
  if(mins<10)lcd.print("0");
  lcd.print(mins);  
  //condicion para que el minutero regrese a 0 y horero avance 1
  if(mins==59){
    mins=0;
    hors=hors+1;
  }
  //horero    
  lcd.setCursor(0,1);
  if(hors<10)lcd.print("0");
  lcd.print(hors);
  lcd.setCursor(2,1);
  lcd.print(":");  
  //condicion del horero que regrese a 0 si ya es 23.
  if(hors==24){
    hors=0;
    mins=0;
  }
  delay(10);  
}
void cambiar(){
  
  if(band==3){
  Serial.print("MODO :");
  Serial.println(band);
  }
  
  leerpoth=analogRead(poth)/44;
  hors=leerpoth;  
  Serial.println(leerpoth);
  //horero 
  lcd.setCursor(0,1);
  if(hors<10)lcd.print("0");
  lcd.print(hors);
  lcd.setCursor(2,1);
  lcd.print(":");  
  //condicion del horero que regrese a 0 si ya es 23.
  if(hors==24){
    hors=0;
    mins=0;
  }
  
  
  leerpotm=analogRead(potm)/17.2;
  mins=leerpotm;
    //minutero
  lcd.setCursor(5, 0);
  lcd.print("RELOJ");
  mins=mins+1-1;
  lcd.setCursor(3, 1);
  if(mins<10)lcd.print("0");
  lcd.print(mins);  
  //condicion para que el minutero regrese a 0 y horero avance 1
 
  Serial.println(leerpotm);
  delay(1000);
  
}

void alarmas(){
  if(band==4){
  Serial.print("MODO :");
  Serial.println(band);
  }
  
  btn1=digitalRead(pulsar1);  //se asigna a la variable “boton” el valor del pin 12
  if(btn1==1)Serial.print("Sensor 1 activado\n"); // el led se enciende o no de acuerdo al valor del push button 
  
  
  btn2=digitalRead(pulsar2);  //se asigna a la variable “boton” el valor del pin 12
  if(btn2==1)Serial.print("Sensor 2 activado\n"); // el led se enciende o no de acuerdo al valor del push button 
 
  
  btn3=digitalRead(pulsar3);  //se asigna a la variable “boton” el valor del pin 12
  if(btn3==1)Serial.print("Sensor 3 activado\n"); // el led se enciende o no de acuerdo al valor del push button 

  
  btn4=digitalRead(pulsar4);  //se asigna a la variable “boton” el valor del pin 12
  if(btn4==1)Serial.print("Sensor 4 activado\n"); // el led se enciende o no de acuerdo al valor del push button 
  delay(1000);
  
}

