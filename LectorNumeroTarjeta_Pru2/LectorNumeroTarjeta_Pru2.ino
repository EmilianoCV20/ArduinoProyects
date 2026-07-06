#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <Wiegand.h>

#define PIN_D0 2
#define PIN_D1 3
#define PIN_RELE 5

// Configuración Ethernet
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverDB(129, 80, 227, 204); // IP del servidor MySQL
char usuario[] = "user1";
char pass[] = "1234";
char db_name[] = "Arduino";

EthernetClient client;
MySQL_Connection conn((Client *)&client);

Wiegand wiegand;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");

  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, HIGH); // Relé apagado por defecto

  // Iniciar Ethernet en modo DHCP
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Fallo al obtener IP mediante DHCP. Verifica conexión.");
    return;
  }
  conectarBD();

  wiegand.onReceive(receivedData, "Datos recibidos:");
  wiegand.onReceiveError(receivedDataError, "Error al leer tarjeta:");
  wiegand.begin(Wiegand::LENGTH_ANY, false);
}

void loop() {
  wiegand.flush();
  wiegand.setPin0State(digitalRead(PIN_D0));
  wiegand.setPin1State(digitalRead(PIN_D1));
}

void receivedData(uint8_t* data, uint8_t bits, const char* message) {
  Serial.print(message);
  Serial.print(" ");
  Serial.print(bits);
  Serial.println(" bits");

  if (bits == 26) {
    // Imprimir datos crudos para depuración
    Serial.print("Datos crudos: ");
    for (uint8_t i = 0; i < (bits + 7) / 8; i++) { // Convertir bits a bytes
      Serial.print(data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    // Combinar exactamente 26 bits (3 bytes + 2 bits adicionales)
    uint32_t rawData = 0;
    for (uint8_t i = 0; i < 4; i++) { // Hasta 4 bytes para manejar bits residuales
      rawData = (rawData << 8) | data[i];
    }

    // Extraer los 24 bits significativos (ignorar bits de paridad)
    uint32_t cardNumber = (rawData >> 1) & 0xFFFFFF;

    // Imprimir datos interpretados
    Serial.print("Datos en hexadecimal (24 bits significativos): ");
    Serial.println(cardNumber, HEX);

    Serial.print("Número de tarjeta (Decimal): ");
    Serial.println(cardNumber);

    // Comprobar en la base de datos
    if (comprobarDatosBD(cardNumber)) {
      activarRele();
    } else {
      Serial.println("Tarjeta no válida.");
      Serial.println("");
    }
  } else {
    Serial.println("Formato no compatible.");
    Serial.println("");
  }
}

void receivedDataError(Wiegand::DataError error, uint8_t* rawData, uint8_t rawBits, const char* message) {
  Serial.print(message);
  Serial.print(" ");
  Serial.println(Wiegand::DataErrorStr(error));
}

void conectarBD() {
  Serial.println("Conectando a la base de datos...");
  if (conn.connect(serverDB, 3306, usuario, pass)) {
    Serial.println("Conexión establecida.");
    MySQL_Cursor cur(&conn);
    char use_db[64];
    sprintf(use_db, "USE %s", db_name);
    cur.execute(use_db);
  } else {
    Serial.println("Error al conectar a la base de datos.");
  }
}

bool comprobarDatosBD(uint32_t numeroTarjeta) {
  if (!conn.connected()) {
    Serial.println("Conexión perdida. Reintentando...");
    conectarBD();
    if (!conn.connected()) {
      Serial.println("No se pudo restablecer la conexión a la base de datos.");
      return false;
    }
  }

  char query[128];
  sprintf(query, "SELECT numTarjeta FROM TarjetasRegistradas WHERE numTarjeta='%lu'", numeroTarjeta);

  MySQL_Cursor cur(&conn);
  if (!cur.execute(query)) {
    Serial.println("Error al ejecutar la consulta SQL.");
    return false;
  }

  column_names *cols = cur.get_columns();
  if (!cols) {
    Serial.println("Error al leer columnas de la base de datos.");
    return false;
  }

  row_values *row = cur.get_next_row();
  if (row) {
    Serial.print("Número de tarjeta encontrado en la base de datos: ");
    Serial.println(row->values[0]);
    return true;
  } else {
    Serial.println("Número de tarjeta no encontrado.");
    return false;
  }
}

void activarRele() {
  Serial.println("Tarjeta válida. Activando relé.");
  digitalWrite(PIN_RELE, LOW);
  delay(5000);
  digitalWrite(PIN_RELE, HIGH);
  Serial.println("");
}
