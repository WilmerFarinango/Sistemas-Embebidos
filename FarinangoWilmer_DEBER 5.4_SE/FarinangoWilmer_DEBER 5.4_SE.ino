/*
   CAPÍTULO 5: FUNCIONES ESPECÍFICAS
   PROGRAMA 25: Creación de funciones en RTOS
   OBJETIVO: Ejecutar tareas directamente en el Kernel del uC.
   NOMBRE: Farinango Wilmer
*/

#include <Arduino_FreeRTOS.h> // librería de RTOS

// Definimos los pines para los leds
#define RED 6
#define YELLOW 7
#define GREEN 8
//objeto del gestor tareas
typedef int TaskProfiler;
//definir las tareas
TaskProfiler redLEDProfiler;
TaskProfiler yellowLEDProfiler;
TaskProfiler greenLEDProfiler;
//------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  Serial.println("El funcionamiento del semaforo es el siguiente: ");
  Serial.println("       Verde:   Autos pasan ON 10S");
  Serial.println("       Naranja: Autos advertencia a parar ON 5S");
  Serial.println("       Rojo:    Autos paran ON 10S");
  //crear las rutinas de cada tarea
  xTaskCreate(yellowLedControllerTask, "Yellow LED Task", 100, NULL, 1, NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
  xTaskCreate(redLedControllerTask, "Red LED Task", 100, NULL, 3, NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
  xTaskCreate(greenLedControllerTask, "Green LED Task", 100, NULL, 2, NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
  vTaskStartScheduler ();
}
//------------------------------------------------------------------------------------------------------

void yellowLedControllerTask (void *pvParameters) {
  pinMode(7, OUTPUT);
  while (1) {
    digitalWrite(7, LOW);
    vTaskDelay( 10000 / portTICK_PERIOD_MS );
    Serial.print(portTICK_PERIOD_MS);
    digitalWrite(7, HIGH);
    vTaskDelay( 5000 / portTICK_PERIOD_MS );
    digitalWrite(7, LOW);
    vTaskDelay( 20000 / portTICK_PERIOD_MS );
    digitalWrite(7, HIGH);
    vTaskDelay( 5000 / portTICK_PERIOD_MS );
  }
}
void greenLedControllerTask (void *pvParameters) {
  pinMode(GREEN, OUTPUT);
  while (2) {
    digitalWrite(6, HIGH);
    vTaskDelay( 10000 / portTICK_PERIOD_MS );
    digitalWrite(6, LOW);
    vTaskDelay( 15000 / portTICK_PERIOD_MS );
  }
}

void redLedControllerTask(void *pvParameters) { //
  pinMode(RED, OUTPUT);
  while (3) {
    digitalWrite(8, LOW);    //
    vTaskDelay( 15000 / portTICK_PERIOD_MS );
    digitalWrite(8, HIGH);
    vTaskDelay( 10000 / portTICK_PERIOD_MS );
    digitalWrite(8, LOW);
    vTaskDelay( 15000 / portTICK_PERIOD_MS );
    digitalWrite(8, HIGH);
    vTaskDelay( 10000 / portTICK_PERIOD_MS );
  }
}
void loop() {
}
