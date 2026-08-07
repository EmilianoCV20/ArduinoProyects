#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

// Dirección MAC para la obtención dinámica de IP
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
EthernetServer server(80);  // Puerto del servidor web

File webFile;
int chipSelect = 4;  // Pin para la SD
bool sdInicializada = false;

int motorA1 = 6;  // Pin para motor A (dirección 1)
int motorA2 = 7;  // Pin para motor A (dirección 2)
int motorB1 = 8;  // Pin para motor B (dirección 1)
int motorB2 = 9;  // Pin para motor B (dirección 2)

void setup() {
  Serial.begin(9600);

  // Intentar inicializar la tarjeta SD
  sdInicializada = SD.begin(chipSelect);
  if (!sdInicializada) {
    Serial.println("Error al inicializar la tarjeta SD.");
  } else {
    Serial.println("Tarjeta SD inicializada correctamente.");
  }

  // Configurar pines para motores
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  // Iniciar comunicación Ethernet mediante DHCP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Error al obtener configuración IP mediante DHCP.");
    while (true);  // Detener si no se puede obtener IP
  } else {
    Serial.print("Dirección IP asignada: ");
    Serial.println(Ethernet.localIP());
  }
  
  server.begin();  // Iniciar servidor web
  detenerMotores();
}

void loop() {
  // Verificar si la tarjeta SD está inicializada, intentar reiniciarla si no lo está
  if (!sdInicializada) {
    Serial.println("Reintentando inicializar la tarjeta SD...");
    sdInicializada = SD.begin(chipSelect);
    if (sdInicializada) {
      Serial.println("Tarjeta SD reiniciada correctamente.");
    } else {
      Serial.println("Error: No se pudo reiniciar la tarjeta SD.");
    }
  }

  EthernetClient client = server.available();  // Esperar por un cliente

  if (client) {
    boolean currentLineIsBlank = true;
    String request = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

        // Ejecutar comandos solo si se recibe un GET y la línea está en blanco
        if (c == '\n' && currentLineIsBlank) {
          if (request.indexOf("GET /A") != -1) {
            Serial.println("A");
            moverDerecha();
          } else if (request.indexOf("GET /R") != -1) {
            Serial.println("R");
            moverIzquierda();
          } else if (request.indexOf("GET /D") != -1) {
            Serial.println("D");
            moverDerechaIzquierda();
          } else if (request.indexOf("GET /I") != -1) {
            Serial.println("I");
            moverIzquierdaDerecha();
          } else if (request.indexOf("GET /N") != -1) {
            Serial.println("N");
            detenerMotores();
          }

          // Retardo después de ejecutar el comando
          delay(50);

          // Servir la página HTML si la SD está inicializada
          if (sdInicializada) {
            webFile = SD.open("carroP.txt");
            if (webFile) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: text/html");
              client.println("Connection: close");
              client.println();
              while (webFile.available()) {
                client.write(webFile.read());
              }
              webFile.close();
            }
          } else {
            client.println("HTTP/1.1 500 Internal Server Error");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
            client.println("<h1>Error: No se pudo acceder a la tarjeta SD.</h1>");
          }
          break;
        }

        // Resetea la línea actual
        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);       // Breve retardo al cerrar la conexión
    client.stop();  // Cerrar la conexión
  }
}

void detenerMotores() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void moverDerecha() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moverIzquierda() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverDerechaIzquierda() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverIzquierdaDerecha() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

