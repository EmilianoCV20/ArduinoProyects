#include <SPI.h>
#include <SD.h>
File archivo;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(4)) {
    Serial.println("ERROR!");
    return;
  }
  archivo = SD.open("pagina.txt");
  if (archivo) {
    Serial.println("PRUEBA.TXT");
    while (archivo.available()) {
      Serial.write(archivo.read());
    }
    archivo.close();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
