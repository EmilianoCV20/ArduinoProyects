#include <Wire.h>
int pinSalida = 12;

void setup() {
  Wire.begin(2);
  pinMode(pinSalida, OUTPUT);
  Wire.onReceive(recievedEvent);
  Serial.begin(9600);
}

void loop() {
  delay(3000);
}

void recievedEvent(int esclavo) {
  int estado = 0;
  if (Wire.available() == 1) {
    estado = Wire.read();
    Serial.println(estado);
  }
  digitalWrite(pinSalida, estado);
}

