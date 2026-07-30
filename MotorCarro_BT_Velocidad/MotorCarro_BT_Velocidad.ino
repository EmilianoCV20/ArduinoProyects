//Codigo c++
#include <SoftwareSerial.h>

byte rx = 7;
byte tx = 8;
SoftwareSerial BT(rx, tx);

int motorA1 = 3;  // Pin para controlar el motor A (dirección 1)
int motorA2 = 4;  // Pin para controlar el motor A (dirección 2)
int motorB1 = 5;  // Pin para controlar el motor B (dirección 1)
int motorB2 = 6;  // Pin para controlar el motor B (dirección 2)

int ENA = 9; //Pin que controla la velocidad del motor A
int ENB = 10; //Pin que controla la velocidad del motor B

unsigned long lastCommandTime = 0;
const unsigned long commandTimeout = 500;

void setup() {
  // Configurar los pines de los motores como salidas
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  BT.begin(9600);
  detenerMotores();
}

void loop() {

  if (BT.available() > 0) {
    char command = BT.read();
    lastCommandTime = millis();

    if (command == 'A') {
      analogWrite(ENA, 85);
      analogWrite(ENB, 85);
      moverDerecha(); //Avanzar
    } else if (command == '2') {
      analogWrite(ENA, 170);
      analogWrite(ENB, 170);
      moverDerecha();
    } else if (command == '3') {
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      moverDerecha();
    } 
    
    else if (command == 'R') {
      analogWrite(ENA, 85);
      analogWrite(ENB, 85);
      moverIzquierda();  // Reversa
    } else if (command == '4') {
      analogWrite(ENA, 170);
      analogWrite(ENB, 170);
      moverIzquierda();
    } else if (command == '5') {
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      moverIzquierda();
    } 
    
    else if (command == 'D') {
      analogWrite(ENA, 85);
      analogWrite(ENB, 85);
      moverDerechaIzquierda();  // Motor A derecha y Motor B izquierda
    } else if (command == '6') {
      analogWrite(ENA, 170);
      analogWrite(ENB, 170);
      moverDerechaIzquierda();
    } else if (command == '7') {
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      moverDerechaIzquierda();
    } 
    
    else if (command == 'I') {
      analogWrite(ENA, 85);
      analogWrite(ENB, 85);
      moverIzquierdaDerecha();  // Motor A izquierda y Motor B derecha
    } else if (command == '8') {
      analogWrite(ENA, 170);
      analogWrite(ENB, 170);
      moverIzquierdaDerecha();
    } else if (command == '9') {
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      moverIzquierdaDerecha();
    } 
    
    else if (command == 'N') {
      analogWrite(ENA, 50);
      analogWrite(ENB, 50);
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