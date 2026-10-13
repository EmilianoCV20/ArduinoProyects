#include <Wire.h>

void setup() {
  Wire.begin();
}

void loop() {
  // Semáforo para Esclavo 1 y Esclavo 2
  for (int estado = 0; estado < 4; estado++) {
    Wire.beginTransmission(1); // Envía a Esclavo 1
    Wire.write(estado);
    Wire.endTransmission();
    
    Wire.beginTransmission(2); // Envía a Esclavo 2
    Wire.write(estado);
    Wire.endTransmission();
    
    delay(2000);
  }
  
  // Semáforo para Esclavo 3
  for (int estado = 0; estado < 3; estado++) {
    Wire.beginTransmission(3); // Envía a Esclavo 3
    Wire.write(estado);
    Wire.endTransmission();
    
    delay(2000);
  }
  
  // Semáforo para Esclavo 4
  for (int estado = 0; estado < 3; estado++) {
    Wire.beginTransmission(4); // Envía a Esclavo 4
    Wire.write(estado);
    Wire.endTransmission();
    
    delay(2000);
  }
}


