#include <EEPROM.h>
int estado;
String letra;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  estado = EEPROM.read(0);
  if(estado == 1){
    digitalWrite(13,HIGH);
  }

}

void loop() {
  if(Serial.available() > 0){
    letra = Serial.readString();
    letra.trim();
    if(letra == "S") {
      digitalWrite(13,0);
      Serial.println("Encendido");
      EEPROM.write(0,0);
    }
    if(letra == "N") {
      digitalWrite(13,HIGH);
      Serial.println("Apagado");
      EEPROM.write(0,1);
    }
  }
}