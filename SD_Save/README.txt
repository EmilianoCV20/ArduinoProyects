====================================================
SD_Save.ino – Arduino
====================================================

Autor: Emiliano Cepeda
Plataforma: Arduino
Lenguaje: C++ (Arduino Sketch)

----------------------------------------------------
1. Overview
----------------------------------------------------
SD_Save.ino es un programa para Arduino que permite guardar información de texto en una tarjeta SD. El programa inicializa la comunicación serial, verifica el acceso a la tarjeta, abre el archivo prueba.txt en modo escritura y almacena una cadena de texto.

El programa sirve como práctica de:
- Uso de las librerías SD y SPI.
- Inicialización y acceso a tarjetas SD.
- Creación y escritura de archivos de texto.
- Manejo de archivos mediante la clase File.
- Supervisión del proceso mediante comunicación serial.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/SD_Save.ino
    Programa principal de Arduino.
    Contiene:
    - setup() — inicializa la comunicación serial, monta la tarjeta SD y escribe información en el archivo.
    - loop() — permanece vacío, ya que la operación se ejecuta una sola vez al iniciar.

/prueba.txt
    Archivo almacenado en la tarjeta SD.
    Recibe la línea de texto:
    Prueba 1, 2, 3...

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------

• Inicialización serial:
  - Serial.begin(9600) configura la comunicación a 9600 baudios.
  - while(!Serial) espera la conexión serial cuando la placa lo requiere.

• Inicialización de la tarjeta SD:
  - SD.begin() intenta inicializar la tarjeta.
  - Si falla, muestra un mensaje de error y detiene el resto de las instrucciones de setup().

• Apertura del archivo:
  - SD.open("prueba.txt", FILE_WRITE) abre el archivo para escritura.
  - Si el archivo no existe, la librería normalmente lo crea.
  - Si ya existe, la escritura se realiza al final del archivo.

• Escritura de información:
  - archivo.println("Prueba 1, 2, 3...") agrega el texto seguido de un salto de línea.

• Cierre del archivo:
  - archivo.close() cierra el archivo después de la escritura.

• Manejo de errores:
  - Comprueba si la tarjeta SD se inicializa correctamente y si el archivo se abre.
  - Informa el resultado mediante mensajes en el monitor serial.

----------------------------------------------------
4. Recursos / Components necesarios
----------------------------------------------------

• Placa Arduino compatible con la librería SD.
• Módulo lector de tarjetas SD.
• Tarjeta SD funcional y correctamente formateada.
• Conexiones SPI entre Arduino y el módulo SD.
• Cable USB para programación y comunicación serial.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------

• Arduino IDE o entorno compatible con Arduino.
• Librería SPI.h.
• Librería SD.h.
• Tarjeta SD insertada y correctamente conectada.
• Configuración de pines SPI y selección de dispositivo compatible con la placa utilizada.
• Monitor Serial configurado a 9600 baudios.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------

Clasificación: Intermedio

Justificación:
- Implementa almacenamiento persistente mediante escritura en una tarjeta SD.
- Utiliza librerías de hardware y operaciones de apertura, escritura y cierre de archivos.
- Incluye comprobaciones básicas de errores y mensajes de diagnóstico.

====================================================