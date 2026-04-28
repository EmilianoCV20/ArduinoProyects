#include <EEPROM.h>
#include <SoftwareSerial.h>

byte rx=7;
byte tx=8;
SoftwareSerial BT(rx,tx);

int estado;
String letra;
String contrasena = "";
String nuevaContrasena = "";
bool cambiandoContrasena = false;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  
  // Leer el estado del LED de la EEPROM
  estado = EEPROM.read(0);
  if (estado == 1) {
    digitalWrite(13, HIGH);
  }
  
  // Leer la contraseña almacenada en EEPROM
  contrasena = leerContrasena();
}

void loop() {
  if (Serial.available() > 0) {
    letra = Serial.readString();
    procesarEntrada(letra);
  } 
  if (BT.available() > 0) {
    letra = BT.readString();
    procesarEntrada(letra);
  }
}

// Función para procesar la entrada tanto desde Bluetooth como desde el puerto serie
void procesarEntrada(String entrada) {
  entrada.trim();
  
  // Comenzar el proceso para cambiar la contraseña
  if (entrada == "C") {
    Serial.println("Introduce nueva contrasena:");
    BT.println("Introduce nueva contrasena:");
    cambiandoContrasena = true;
    nuevaContrasena = "";
  }
  // Almacenar la nueva contraseña
  else if (cambiandoContrasena) {
    nuevaContrasena = entrada;
    guardarContrasena(nuevaContrasena);
    contrasena = nuevaContrasena;
    Serial.println("Contrasena guardada");
    BT.println("Contrasena guardada");
    cambiandoContrasena = false;
  }
  // Alternar el estado del LED con la contraseña correcta
  else if (entrada == contrasena) {
    alternarLED();
  }
  else {
    Serial.println("Contrasena incorrecta.");
    BT.println("Contrasena incorrecta.");
  }
}

void alternarLED() {
  if (estado == 1) {
    digitalWrite(13, LOW);
    Serial.println("LED encendido");
    BT.println("LED encendido");
    estado = 0;
  } else {
    digitalWrite(13, HIGH);
    Serial.println("LED apagado");
    BT.println("LED apagado");
    estado = 1;
  }
  EEPROM.write(0, estado);
}

// Función para leer la contraseña almacenada en la EEPROM
String leerContrasena() {
  String contrasenaLeida = "";
  for (int i = 1; i < 11; i++) { // Contraseña de 10 caracteres
    char c = EEPROM.read(i);
    if (c == '\0') break;
    contrasenaLeida += c;
  }
  return contrasenaLeida;
}

// Función para guardar la nueva contraseña en EEPROM
void guardarContrasena(String nuevaContrasena) {
  for (int i = 1; i < 21; i++) {
    if (i <= nuevaContrasena.length()) {
      EEPROM.write(i, nuevaContrasena[i - 1]);
    } else {
      EEPROM.write(i, '\0');  // Fin de la cadena
    }
  }
}

