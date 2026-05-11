#include <Ethernet.h>
#include <SPI.h> 

byte mac[] = {0xAB, 0xBC, 0xBE, 0xEF, 0xFE, 0xED}
void setup() {
  Ethernet.begin(mac);
  Serial.begin(9600);
  delay(2000);
  if(Ethernet.begin(mac==0))
  {
    Serial.println("Error de inicializacion")
  } 
  else 
  {
    Serial.println("La direccion IP es: " + Ethernet.localIP());
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
