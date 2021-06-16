/*
 Interfaz grafica - PROYECTO FINAL
 integrantes: 
 Ulcualngo Pablo
 Farinango Wilmer
 */


import processing.serial.*;
Serial port;
int dato;
int dato1;
int n=0;
int dato3=0;
PImage img;
PImage img2;
PImage img3;

void setup () {
  size(720, 640);
  background(255);
  port= new Serial(this, "COM5", 9600);
  img = loadImage("limpio.jpg");
  img2 = loadImage("Contaminado.png");
  img3 = loadImage("fondo.png");
  port.bufferUntil('\n');
}

void draw() {
  fill(255);
  strokeWeight(3);
  img3.resize(640, 640);
  image(img3, 40, 6);

  //cuadro titulo
  stroke (250, 1, 1); //color borde rojo
  strokeWeight (0); //grosor 5
  fill(#E9502B);// color relleno
  rect (50, 20, 620, 130, 15);// rectangulo redondeado

  // cuando principal
  stroke (25); //color borde rojo
  strokeWeight (1); //grosor 5
  fill(#15B09F);// color relleno
  rect(50, 200, 630, 200, 10);// rectangulo redondeado

  textSize(25);
  fill(255);
  text("PROYECTO FINAL", 150, 60);
  textSize(20);
  fill(0);
  text("Integrantes: ", 85, 85);
  text("- Farinango Wilmer", 85, 105);
  text("- Ulcuango Pablo", 85, 125);
  // cuadro de texto mq135
  fill(255);
  strokeWeight(0);
  rect(70, 260, 180, 80, 10);
  // cuadro de texto mq7
  fill(255);
  strokeWeight(0);
  rect(275, 260, 180, 80, 10);
  // cuadro de texto tipo de aire
  fill(255);
  strokeWeight(0);
  rect(480, 260, 180, 80, 10);

  textSize(18);
  fill(255);
  text("SENSOR MQ 135", 90, 240);

  textSize(18);
  fill(255);
  text("SENSOR MQ 7", 300, 240);

  textSize(18);
  fill(255);
  text("TIPO DE AIRE", 500, 240);

  textSize(18);
  fill(0);
  text(dato, 130, 310);
  text(dato1, 340, 310);

  if (dato3==2) {
    text("Aire limpio", 490, 310);
    img.resize(450, 200);
    image(img, 140, 420);
  } else if (dato3==1) {
    text("Aire contaminado", 490, 310);
    img2.resize(450, 200);
    image(img2, 140, 420);
  }
}

void serialEvent(Serial port) {
  dato=port.read();
  if (dato<70) {
    dato1=dato*(333/65);
    dato3=2;
  } else {
    dato1=dato*(356/79);
    dato3=1;
  }
}
