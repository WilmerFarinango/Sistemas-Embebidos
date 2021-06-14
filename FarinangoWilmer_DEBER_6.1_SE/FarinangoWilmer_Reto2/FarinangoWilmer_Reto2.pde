/*
NOMBRE: Farinango Wilmer
RETO: 2
*/

color ColorCirculo = color(0, 255, 0);
int i=250; 
void setup() { 
  size(402, 402);
  background(#CCCCCC);
  textSize(15); 
  fill(0);
  text("Mantener el botón Presionado encender o apagar el LED", 30, 50);
  fill(#FF1000);
  ellipse(200, 200, 200, 200);
  textAlign(CENTER); 
  textSize(24); 
  fill(255);
  text("!Apagado¡", width/2, height/2);
  smooth();
}
void draw() {
}
void mousePressed() {
  float Distancia = dist(mouseX, mouseY, 200, 200);
  if (Distancia<100) { 
    if (mousePressed==true) {
      if ( mouseButton == RIGHT) {
        fill(#990000);
        ellipse(200, 200, 200, 200);
      }
    }
    if ( mouseButton == LEFT) {
      fill(#009900);
      ellipse(200, 200, 200, 200);
    }
  }
}

void mouseReleased() {
  float Distancia = dist(mouseX, mouseY, 200, 200);
  if (Distancia<100) { 
    if (mouseButton == RIGHT) {
      if (mousePressed==false) {
        fill(#00FF00);
        ellipse(200, 200, 200, 200); 
        textAlign(CENTER); 
        textSize(24); 
        fill(255);
        text("!Encendido¡", width/2, height/2);
        smooth();
        fill(#FF0000);
      }
    }
    if (mouseButton == LEFT) {
      if (mousePressed==false) {
        fill(#FF0000);
        ellipse(200, 200, 200, 200); 
        textAlign(CENTER); 
        textSize(24); 
        fill(255);
        text("!Apagado¡", width/2, height/2);
        smooth();
        fill(#FF0000);
      }
    }
  }
}
