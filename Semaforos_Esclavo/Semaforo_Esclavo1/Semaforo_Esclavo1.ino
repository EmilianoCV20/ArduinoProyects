#include <Wire.h>

// Definición de pines
const int pinVerde = 12;
const int pinAmarillo = 11;
const int pinRojo = 10;
const int pinGiro = 13;

void setup() {
  Wire.begin(1);
  Wire.onReceive(receivedEvent);

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinGiro, OUTPUT);
}

void loop() {
  delay(100);
}

void receivedEvent(int bytes) {
  int estado = Wire.read();
  
  // Apaga todos los LEDs antes de activar el correspondiente
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinGiro, LOW);
  
  // Activa el LED correspondiente al estado recibido
  switch (estado) {
    case 0:
      digitalWrite(pinGiro, HIGH); // LED de giro
      digitalWrite(pinRojo, HIGH);
      break;
    case 1:
      digitalWrite(pinVerde, HIGH); // Luz verde
      break;
    case 2:
      digitalWrite(pinAmarillo, HIGH); // Luz amarilla
      break;
    case 3:
      digitalWrite(pinRojo, HIGH); // Luz roja
      break;
  }
}


