/*
NOMBRE: Farinango Wilmer
RETO: 1
*/
void setup () {
  size (500, 500);

  //size(100,100);
}
void draw () {
  background(#FF6600);
  stroke(51, 0, 204);
  strokeWeight(5);
  line(510, 505, 12, 10);
  stroke(51, 0, 204);
  strokeWeight(5);
  line(500, 0, 0, 500);
  stroke(#FFFFFF);
  strokeWeight(55);
  ellipse(250, 250, 350, 350);
  stroke(#00FF00);
  strokeWeight(5);
  ellipse(250, 250, 300, 300);
  fill(#FF0000);
  ellipse(250, 250, 295, 295);
  stroke(0, 0, 0);
  strokeWeight(18);
  line(0, 0, 500, 0);
  stroke(0, 0, 0);
  strokeWeight(18);
  line(0, 0, 0, 500);
  stroke(0, 0, 0);
  strokeWeight(18);
  line(500, 0, 500, 500);
  stroke(0, 0, 0);
  strokeWeight(18);
  line(500, 500, 0, 500);
}
