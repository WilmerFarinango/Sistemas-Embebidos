#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
String cod; //Codigo de usuario dado por el docente
String u; // Nombre ususario dado por el doente
String nam[4];// areglo de 4 
boolean arrayt[4]={false, false, false, false};// todo el arreglo queda en falso
int cont=0; //contador
int btn=7; // btn para imprimir
void setup() {
  
 pinMode(btn,INPUT);  // estrada de pin 7
 lcd.begin(16,2);// lcd
 Serial.begin(9600);// activamos velicidad del serial
 Serial.println("Ingrese Su Contrasena: ");

}

void loop(){
    if(Serial.available()>0){ // detecta si ingresadatos en comunicacion serial
      cod = Serial.readString(); //leer dato
      u = Serial.println(cod); //Imprimir la contraseña
      //validar los caracteres
      nam[cont] = cod;
      cont++;
      if(cod == "ad102344"){
        u = " Ariel Davalos";
        arrayt[0]=true;
        Serial.println("Registro Correcto");
        }else if(cod=="dc774235" ){
          u = " Damian Cervantes";
          arrayt[1]=true;
          Serial.println("Registro Correcto");
        }else if(cod == "ca543187"){
          u= " Carlos Benavides";
            arrayt[2]=true;
            Serial.println("Registro Correcto");
        }else if(cod=="wf931005"){
          u = " Wilmer Farinango";
            arrayt[3]=true;
          Serial.println("Registro Correcto");           
        }else{
          u = "Usuario no registrado";
          Serial.println("El usuario no posee registro");
        }
        //creamos 2 dor anidados para imprimir los resultados
        for (int j=0; j<2;j++){//controla la posicion de "bienvenidos"
          for(int i=-12;i<16;i++){//cntrola la poscion de los usuarios
            lcd.setCursor(i,0);
            lcd.print("Bienvenido");
            lcd.setCursor(i,1);
            lcd.print(u);//imprime usuario
            delay(100);
            lcd.clear();            
          }
        }
    }
}
//creamos una lase para imprimir con el boton del pin 7
void lectura(){
  if (arrayt[0]==true){
    Serial.println("Ariel Davalos registrado");
  }else{
    Serial.println("Ariel Davalos no se registro");
  }
  if (arrayt[1]==true){
    Serial.println("Damian Cervantes registrado");
  }else{
    Serial.println("Damian Cervantes no se registro");
  }  
  if (arrayt[2]==true){
    Serial.println("Carlos Benavides registrado");
  }else{
    Serial.println("Carlos Benavides no se registro");
  }  
  if (arrayt[3]==true){
    Serial.println("Wilmer Farinango registrado");
  }else{
    Serial.println("Wilmer Farinango no se registro");
  } 
  }
