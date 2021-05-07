// variables: numéricas enteras (int), decimales (float), caracteres (chart)
 #define led1 8          // uso de #define, es una variable que no se puede alterar su valor, no existe una depuración de errores 
 int led2 = 9;           // se puede considerar como una variable normal, no es muy recomendable    
 const int led3 = 10;    // variable constante, es la recomendable 
 
void setup() {
 pinMode(led1,OUTPUT);   //  pin 8  salida
 pinMode(led2,OUTPUT);   //  pin 9  salida
 pinMode(led3,OUTPUT);   //  pin 10 salida
}

void loop() {
 digitalWrite(led1,HIGH);  //5v to pin8
 delay(800);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led1,LOW);  //envía 0v al pin8
 delay(800);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led2,HIGH);  //envía 5v al pin9
 digitalWrite(led3,LOW);  //envía 0v al pin10
 delay(800);               //se detiene el microcontrolador por 400ms
 digitalWrite(led3,HIGH);  //envía 5v al pin10
 digitalWrite(led2,LOW);  //envía 0v al pin9
 delay(800);               //se detiene el microcontrolador por 400ms
}
