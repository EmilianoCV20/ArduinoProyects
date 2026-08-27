#include <SoftwareSerial.h>
String a;
byte rx=2;
byte tx=3;
SoftwareSerial bt(rx,tx);
int contador = 0;
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  if (bt.available()){
    contador++;
    bt.println(contador);
    Serial.println(contador);
    delay(2000);
  }
}
