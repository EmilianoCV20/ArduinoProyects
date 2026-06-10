#include <Wiegand.h>

#define PIN_D0 2
#define PIN_D1 3

Wiegand wiegand;

void setup() {
  Serial.begin(9600);
  Serial.println("Lector listo...");

  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);

  wiegand.onReceive(receivedData, "Datos recibidos:");
  wiegand.onReceiveError(receivedDataError, "Error al leer tarjeta:");
  wiegand.begin(Wiegand::LENGTH_ANY, false); // Desactivar validación // Aceptar cualquier longitud
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
  Serial.print(" bits / ");

  // Validar que los datos sean de 26 bits
  if (bits == 26) {
    uint32_t cardNumber = 0;
    for (int i = 1; i < 4; i++) { // Ignorar el bit de paridad inicial y solo usar 3 bytes
      cardNumber = (cardNumber << 8) | data[i];
    }
    // Eliminar el bit de paridad final (último bit)
    cardNumber >>= 1;

    Serial.print("Número de tarjeta: ");
    Serial.println(cardNumber);
  } else {
    Serial.println("Formato no compatible.");
  }
}

void receivedDataError(Wiegand::DataError error, uint8_t* rawData, uint8_t rawBits, const char* message) {
  Serial.print(message);
  Serial.print(" ");
  Serial.print(Wiegand::DataErrorStr(error));
  Serial.print(" - Datos crudos: ");
  Serial.print(rawBits);
  Serial.print(" bits / ");
  uint8_t bytes = (rawBits + 7) / 8;
  for (int i = 0; i < bytes; i++) {
    Serial.print(rawData[i] >> 4, 16);
    Serial.print(rawData[i] & 0xF, 16);
  }
  Serial.println();
}


