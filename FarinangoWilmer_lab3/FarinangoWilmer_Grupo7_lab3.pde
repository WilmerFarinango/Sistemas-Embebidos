import processing.serial.*;
Serial myPort; 
int dato;

Jugador jugador1, jugador2;
Pelota pelota;
boolean ganador;
int puntajeMaximo;




void setup() {
  size(600, 400);

  myPort = new Serial(this, "COM7", 9600);
  jugador1 = new Jugador(1); //se crea jugador 1
  jugador2 = new Jugador(2); //se crea jugador 2

  pelota = new Pelota(1); //se crea la pelota
  ganador = false; //al inicio no hay ningun ganador

  puntajeMaximo = 3; //el puntaje que los jugadores deben de alcanzar para ganar
}

void draw() {
  if (myPort.available() > 0) {
    dato = myPort.read();
    println(dato);
  }


  background(0);

  //se pone  en pantalla los puntajes de cada jugador
  textSize(30);
  text(jugador1.getPuntos(), width/2 - 60, 40);
  text(jugador2.getPuntos(), width/2 + 30, 40);

  //Si aun no hay ganador, entonces se seguirá dibujando
  //el escenario
  if (ganador == false) {
    strokeWeight(2);
    stroke(255);

    for (int y = 0; y < height; y+= 10) {
      line(width/2, y, width/2, y+5);
    }
    pelota.mostrar();
    pelota.mover();
  }
  jugador1.mostrar();
  jugador1.mover();
  pelota.validarReboteJugador1(jugador1.getPosicion());

  jugador2.mostrar();
  jugador2.mover();
  pelota.validarReboteJugador2(jugador2.getPosicion());

  pelota.validarReboteParedes();
  validarPuntos();
  validarGanador();
}

void validarPuntos() {
  PVector posicionPelota = pelota.getPosicion();

  //Si la pelota sobrepasa el borde derecho
  //el jugador 1 gana un punto

  if (posicionPelota.x > width && jugador1.getPuntos() <= puntajeMaximo) {
    jugador1.setPuntos(1);
    //Cada que se marca un punto, la pelota
    //vuelve a iniciar en el centro y con direccion contraria
    pelota = new Pelota(-1);
  } 
  //Si la pelota sobrepasa el borde izquierdo
  //el jugador 2 gana un punto
  else if (posicionPelota.x < 0 && jugador2.getPuntos() <= puntajeMaximo) { 
    jugador2.setPuntos(1);
    //Cada que se marca un punto, la pelota
    //vuelve a iniciar en el centro y con direccion contraria
    pelota = new Pelota(1);
  }
  //Cuando se anuncia el ganador el juego se detiene
  //y si el usuario preciona cualquier tecla el juego 
  //se reinicia
  else if (ganador == true) {
    if (dato==5) {
      myPort.stop ();
      //myPort.clear ();
      setup();
    }
  }
}
void validarGanador() {
  //Al alcanzar el puntaje maximo el jugador gana
  if (jugador1.getPuntos() == puntajeMaximo) {
    text("Jugador 1 ha ganado la partida", 80, height/2);
    textSize(20);
    text("Presione cualquier tecla para volver a jugar", 95, height/2 + 30);
    ganador = true;
  } else if (jugador2.getPuntos() == puntajeMaximo) {
    text("Jugador 2 ha ganado la partida", 80, height/2);
    textSize(20);
    text("Presione cualquier tecla para volver a jugar", 95, height/2 + 30);
    ganador = true;
  }
}






class Jugador {
  PVector posicion, velocidad;
  int ancho, alto, numeroJugador, puntos;

  Jugador(int numeroJugador_) {
    numeroJugador = numeroJugador_;
    ancho = 20; //ancho del rectangulo del jugador
    alto = 100; //alto del rectangulo del jugador
    puntos = 0; //puntos del jugador

    //Si el jugador es el numero 1 la posicion de su rectangulo
    //se ajustará de acuerdo a la diferencia del ancho

    if (numeroJugador == 1) {
      posicion = new PVector(ancho/2, height/2);
    } else if (numeroJugador == 2) {
      posicion = new PVector(width - ancho/2, height/2);
    }
    //se asigna la velocidad por defecto de los jugadores
    velocidad = new PVector(0, 3);
  }


  //este metodo permite a los jugadores moverse
  void mover() {
    //Si el jugador 1 presiona la tecla w entonces...
    if (numeroJugador == 1 && dato == 1) {
      //Se moverá hacia arriba
      posicion.sub(velocidad);
    } 
    //Si el jugador 1 presiona la tecla s entonces...

    else if (numeroJugador == 1 && (dato == 2)) {
      //se moverá hacia abajo
      posicion.add(velocidad);
    }

    //Si el jugador 2 presiona la tecla UP entonces...
    if (numeroJugador == 2 && dato == 3) {
      //Se moverá hacia arriba
      posicion.sub(velocidad);
    } 
    //Si el jugador 2 presiona la tecla DOWN entonces...
    else if (numeroJugador == 2 && dato == 4) {
      //Se moverá hacia abajo
      posicion.add(velocidad);
    }

    //restriccion para las coordenadas Y de los jugadores
    //solo pueden estar tan arriba en y = alto/2 (segundo argumento)
    //pero solo tan abajo en y = el alto de la pantalla - alto/2 (tercer argumento)
    posicion.y = constrain(posicion.y, alto/2, height - alto/2);
  }

  //se dibuja el rectangulo del jugador
  void mostrar() {
    fill(255);
    noStroke();
    rectMode(CENTER);
    rect(posicion.x, posicion.y, ancho, alto);
  }

  PVector getPosicion() {
    return posicion;
  }

  //contador de puntos
  void setPuntos(int puntos_) {
    puntos += puntos_;
  }

  int getPuntos() {
    return puntos;
  }
}
class Pelota {
  PVector posicion, velocidad;
  int anchoJugador, altoJugador;

  Pelota(int direccion) {
    anchoJugador = 20;
    altoJugador = 100;

    //Se posiciona la pelota en el centro de la pantalla
    posicion = new PVector(width/2, height/2);
    //Se asigna la velocidad de la pelota aleatoriamente con un valor entre 4 y 5
    velocidad = new PVector(direccion*random(4, 5), random(4, 5));
  }

  //permite a la pelota moverse libremente
  void mover() {
    posicion.add(velocidad);
  }

  //dibuja la pelota de los jugadores
  void mostrar() {
    fill(255);
    noStroke();
    ellipse(posicion.x, posicion.y, 20, 20);
  }

  void validarReboteJugador1(PVector posicionJugador) {
    //Valor minimo en la que la pelota puede estar cerca 
    //del rectangulo del jugador 1 en su coordenada Y
    float min = posicionJugador.y - altoJugador/2;

    //Valor maximo en la que la pelota puede estar cerca 
    //del rectangulo del jugador 1 en su coordenada Y
    float max = posicionJugador.y + altoJugador/2;

    //si la coordena Y de la pelota está dentro del rango [min,max]
    //de la coordenada Y del jugador 1 y su coordena X es menor al 
    //ancho del rectangulo del jugador 1, quiere decir que está tocando
    //al rectangulo del jugador 1 entonces su velocidad en X irá en
    //direccion contraria (rebotará)
    if (posicion.x < anchoJugador && posicion.y > min && posicion.y < max) {
      velocidad.x *= -1;
    }
  }

  void validarReboteJugador2(PVector posicionJugador) {
    //Valor minimo en la que la pelota puede estar cerca 
    //del rectangulo del jugador 2 en su coordenada Y
    float min = posicionJugador.y - altoJugador/2;

    //Valor maximo en la que la pelota puede estar cerca 
    //del rectangulo del jugador 1 en su coordenada Y
    float max = posicionJugador.y + altoJugador/2;

    //si la coordena Y de la pelota está dentro del rango [min,max]
    //de la coordenada Y del jugador 2 y su coordena X es menor al 
    //ancho del rectangulo del jugador 2, quiere decir que está tocando
    //al rectangulo del jugador 2 entonces su velocidad en X irá en
    //direccion contraria (rebotará)
    if (posicion.x > width - anchoJugador && posicion.y > min && posicion.y < max) {
      velocidad.x *= -1;
    }
  }

  void validarReboteParedes() {
    //si la pelota sobrepasa de los bordes superior o inferior
    //rebotará cambiando la direccion de la velocidad en Y
    if (posicion.y > height) {
      velocidad.y *= -1;
    } else if (posicion.y < 0) {
      velocidad.y *= -1;
    }
  }

  PVector getPosicion() {
    return posicion;
  }
}
