====================================================
SD_Prueba1.ino – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
SD_Prueba1.ino es un programa para Arduino que realiza una prueba básica de escritura sobre una tarjeta SD. El programa inicializa la tarjeta mediante la librería SD, crea o abre el archivo prueba.txt en modo escritura y almacena una cadena de texto dentro del archivo.

El programa sirve como práctica de:
- Uso de la librería SD para almacenamiento externo.
- Inicialización de una tarjeta SD.
- Apertura y escritura de archivos.
- Uso de comunicación serial para mostrar el estado del proceso.
- Manejo básico de errores durante el acceso a la tarjeta.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/SD_Prueba1.ino  
    Programa principal de Arduino.
    Contiene:
    - setup() — inicializa la comunicación serial y la tarjeta SD, abre prueba.txt y escribe información.
    - loop() — permanece vacío, ya que la prueba se ejecuta una sola vez al iniciar.

/prueba.txt  
    Archivo generado en la tarjeta SD.
    Contiene:
    Prueba 1, 2, 3...

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------

• Inicialización de comunicación serial:  
  - Utiliza Serial.begin(9600) para mostrar mensajes de diagnóstico.

• Inicialización de la tarjeta SD:  
  - SD.begin() verifica y prepara la tarjeta para su utilización.
  - Si falla, se muestra un mensaje de error por el puerto serial.

• Apertura del archivo:  
  - SD.open("prueba.txt", FILE_WRITE) abre el archivo en modo escritura.

• Escritura de información:  
  - archivo.println("Prueba 1, 2, 3...") almacena texto en la tarjeta SD.

• Cierre del archivo:  
  - archivo.close() libera el archivo después de realizar la escritura.

• Mensajes de estado:  
  - El monitor serial informa sobre el inicio, escritura, guardado y errores.

----------------------------------------------------
4. Recursos / Components necesarios
----------------------------------------------------

• Placa Arduino compatible con la librería SD.  
• Módulo o lector de tarjetas SD compatible con Arduino.  
• Tarjeta microSD/SD funcional.  
• Conexión SPI entre Arduino y el módulo SD.  
• Monitor Serial para visualizar los mensajes de diagnóstico.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------

• Arduino IDE o entorno compatible con Arduino.  
• Librería SPI.h.  
• Librería SD.h.  
• Tarjeta SD correctamente conectada y disponible.  
• Configuración SPI correspondiente a la placa utilizada.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------

Clasificación: Intermedio

Justificación:
- Introduce manejo de almacenamiento externo mediante una tarjeta SD.
- Utiliza librerías de hardware (SPI y SD) y operaciones sobre archivos.
- Incluye validación básica de errores durante la inicialización y apertura del archivo.

====================================================