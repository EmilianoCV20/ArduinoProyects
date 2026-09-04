#include <SPI.h>
#include <SD.h>
File archivo;

void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Iniciando SD...");
  if(!SD.begin()){
    Serial.println("ERROR! No se pudo Iniciar");
    return;
  }
  Serial.println("Iniciado");
  archivo = SD.open("prueba.txt",FILE_WRITE);
  if(archivo) {
    Serial.println("Probando");
    archivo.println("Prueba 1, 2, 3...");
    archivo.close();
    Serial.println("Guardado");
  } else {
    Serial.println("ERROR!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
