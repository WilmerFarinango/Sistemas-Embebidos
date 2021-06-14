/*
NOMBRE: Farinango Wilmer
RETO: 3
*/
import processing.serial.*;
Serial miPuerto;
color ColorCirculo = color(0, 255, 0);
void setup() {
  miPuerto = new Serial(this, "COM3", 9600);
  size(400, 600);
  background(#CCCCCC);
}
void draw() {
  textSize(20);
  fill(0);
  text("BIENVENIDO", 140, 100);
  fill(ColorCirculo);
  circle(200, 300, 300);
}
void mousePressed() {
  float Distancia = dist(mouseX, mouseY, 200, 300);
  if (Distancia<150) { 
    textSize(20);
    fill(0);
    text("PUSH BUTTON PRESIONADO", 70, 100);
    ColorCirculo=color(255, 0, 0);
  }
}
void mouseReleased() {
  textSize(20);
  fill(0);
  text("BUTTON NOPRESIONADO", 70, 100);
  ColorCirculo=color(0, 255, 0);
}
void serialEvent(Serial miPuerto) { 
  while (miPuerto.available()==1) {
    int dato = miPuerto.read(); 
    println(dato);
    if (dato=='1') {
      ColorCirculo=color(0, 255, 0);
    } else if (dato=='0') {
      ColorCirculo=color(255, 0, 0);
    }
  }
}
