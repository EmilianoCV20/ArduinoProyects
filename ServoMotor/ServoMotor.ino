#include <Servo.h>
Servo servo1;

int valor = 0;
int limite = 0;

void setup() {
  servo1.attach(3, 500, 2500);
  Serial.begin(9600);
  //Serial.println("Introduce el limite del servo (0-180): ");
}

void loop() {
  // Si hay datos disponibles en el puerto serial
  if (Serial.available()) {
    limite = Serial.readString().toInt();
    Serial.print("Limite establecido en: ");
    Serial.println(limite);
    valor = 0;
  }

  // Mover el servo de 10 en 10 hasta el límite
  servo1.write(valor);
  delay(700);

  if (valor < limite) {
    valor = valor + 10;
  } else {
    valor = 0;
  }
}


