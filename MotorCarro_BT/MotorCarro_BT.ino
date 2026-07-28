//Codigo c++
#include <SoftwareSerial.h>

byte rx=7;
byte tx=8;
SoftwareSerial BT(rx,tx);

int motorA1 = 3; // Pin para controlar el motor A (dirección 1)
int motorA2 = 4; // Pin para controlar el motor A (dirección 2)
int motorB1 = 5; // Pin para controlar el motor B (dirección 1)
int motorB2 = 6; // Pin para controlar el motor B (dirección 2)

unsigned long lastCommandTime = 0;
const unsigned long commandTimeout = 500; //2000

void setup() {
  // Configurar los pines de los motores como salidas
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  BT.begin(9600);
  detenerMotores();
}

void loop() {

  if (BT.available() > 0) {
    char command = BT.read();
    lastCommandTime = millis();

    if (command == 'A') {
      moverDerecha();  // Avanzar
    } else if (command == 'R') {
      moverIzquierda(); // Reversa
    } else if (command == 'D') {
      moverDerechaIzquierda(); // Motor A derecha y Motor B izquierda
    } else if (command == 'I') {
      moverIzquierdaDerecha(); // Motor A izquierda y Motor B derecha
    } else if (command == 'N') {
      detenerMotores();  // Detener o Neutral
    } 
  }
  
  if (millis() - lastCommandTime > commandTimeout) {
    detenerMotores();
  }

}

void detenerMotores() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void moverDerecha() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moverIzquierda() {

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverDerechaIzquierda() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverIzquierdaDerecha() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}