#include <EEPROM.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
const int btn = A3;
const byte filas = 4;
const byte columnas = 4;
byte pinesFilas[]  = {7, 6, 5, 4};
byte pinesColumnas[] = {3, 2, A5, A4};
char teclas[4][4] = {
  {'1', '2', '3', 'W'},
  {'4', '5', '6', 'D'},
  {'7', '8', '9', 'F'},
  {'*', '0', '#', 'I'}
};
Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);
int direccion = 0;
char tecla_presionada;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  pinMode(A3,INPUT);
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(2, 0);
  lcd.print("WILMER FARINANGO");
  EEPROM.get(direccion, tecla_presionada);
  Serial.println("Farinango Wilmer");
  Serial.println();
}
void loop() {

  char tecla_presionada = teclado1.getKey();
  if (tecla_presionada)  {
    EEPROM.put(direccion, tecla_presionada);
    lcd.setCursor(0, 1);
    lcd.print(String("Dir:") + String(direccion) + String(" Tecla: ") + String(tecla_presionada));
    if (btn == HIGH) {
        for (int i = 0; i <= 5; i++) {
          char dato = EEPROM.read(i);
          Serial.println(String(i) + String(dato));
        }
      }
      direccion++;
    }
  }
