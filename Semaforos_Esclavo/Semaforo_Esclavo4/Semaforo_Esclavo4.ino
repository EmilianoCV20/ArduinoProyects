#include <Wire.h>

// Definición de pines
const int pinVerde = 12;
const int pinAmarillo = 11;
const int pinRojo = 10;

void setup() {
  Wire.begin(4);
  Wire.onReceive(receivedEvent);

  // Configura los pines como salida
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinRojo, OUTPUT);
}

void loop() {
  delay(100);
}

// Función que se llama cuando se reciben datos desde el maestro
void receivedEvent(int bytes) {
  int estado = Wire.read();
  
  // Apaga todos los LEDs antes de activar el correspondiente
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinRojo, LOW);
  
  // Activa el LED correspondiente al estado recibido
  switch (estado) {
    case 0:
      digitalWrite(pinVerde, HIGH); // Luz verde
      break;
    case 1:
      digitalWrite(pinAmarillo, HIGH); // Luz amarilla
      break;
    case 2:
      digitalWrite(pinRojo, HIGH); // Luz roja
      break;
  }
}

