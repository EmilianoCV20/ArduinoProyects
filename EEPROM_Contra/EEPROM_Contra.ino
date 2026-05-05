#include <EEPROM.h>

int estado;
String letra;
String contrasena = "";
String nuevaContrasena = "";
bool cambiandoContrasena = false;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
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
    letra.trim();
    
    // Comenzar el proceso para cambiar la contraseña
    if (letra == "C") {
      Serial.println("Introduce nueva contraseña:");
      cambiandoContrasena = true;
      nuevaContrasena = "";
    }
    //Almacenar la nueva
    else if (cambiandoContrasena) {
      nuevaContrasena = letra;
      guardarContrasena(nuevaContrasena);
      contrasena = nuevaContrasena;
      Serial.println("Contraseña guardada.");
      cambiandoContrasena = false;
    }
    // Alternar el estado del LED con la contraseña correcta
    else if (letra == contrasena) {
      alternarLED();
    }
    else {
      Serial.println("Contraseña incorrecta.");
    }
  }
}

void alternarLED() {
  if (estado == 1) {
    digitalWrite(13, HIGH);
    estado = 0;
  } else {
    digitalWrite(13, LOW);
    estado = 1;
  }

  EEPROM.write(0, estado);
}

// Función para leer la contraseña almacenada en la EEPROM
String leerContrasena() {
  String contrasenaLeida = "";
  for (int i = 1; i < 11; i++) { //Contraseña de 10 Cracateres
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
      EEPROM.write(i, nuevaContrasena[i-1]);
    } else {
      EEPROM.write(i, '\0'); //Cierra la cadena
    }
  }
}

