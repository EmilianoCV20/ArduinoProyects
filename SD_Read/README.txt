====================================================
SD_Read – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
SD_Read es un programa para Arduino que permite leer y mostrar por el monitor serial el contenido de un archivo de texto almacenado en una tarjeta SD. El programa inicializa la tarjeta, abre el archivo pagina.txt, lee sus datos secuencialmente y los transmite mediante comunicación serial.

El programa sirve como práctica de:
- Acceso a tarjetas SD mediante las librerías SD y SPI.
- Apertura y lectura de archivos.
- Recorrido secuencial de datos con un ciclo while.
- Uso de available() y read() para procesar contenido.
- Transmisión de caracteres mediante el puerto serial.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/SD_Read.ino
    Programa principal de Arduino.
    Contiene:
    - setup() — inicializa la comunicación serial, monta la tarjeta SD, abre el archivo y muestra su contenido.
    - loop() — permanece vacío, ya que la lectura se realiza una sola vez al iniciar.

/pagina.txt
    Archivo de texto almacenado en la tarjeta SD.
    Su contenido se lee y se muestra en el monitor serial.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------

• Inicialización serial:
  - Serial.begin(9600) configura la comunicación serial a 9600 baudios.

• Inicialización de la tarjeta SD:
  - SD.begin(4) inicializa la tarjeta utilizando el pin digital 4 como selección de dispositivo (CS).
  - Si la inicialización falla, se muestra ERROR! y se interrumpe la ejecución de setup().

• Apertura del archivo:
  - SD.open("pagina.txt") abre el archivo para lectura.

• Lectura secuencial:
  - archivo.available() comprueba si quedan datos por leer.
  - archivo.read() obtiene un byte del archivo.
  - Serial.write() transmite cada byte al monitor serial.

• Cierre del archivo:
  - archivo.close() cierra el archivo después de terminar la lectura.

• Visualización del contenido:
  - Se muestra el mensaje PRUEBA.TXT antes de imprimir los datos del archivo.
  - El nombre mostrado en el monitor serial es distinto del archivo que se abre: pagina.txt.

----------------------------------------------------
4. Componentes necesarios
----------------------------------------------------

• Placa Arduino compatible con la librería SD.
• Módulo lector de tarjetas SD.
• Tarjeta SD con el archivo pagina.txt.
• Conexiones SPI entre Arduino y el módulo SD.
• Monitor Serial para visualizar el contenido leído.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------

• Arduino IDE o entorno compatible con Arduino.
• Librería SPI.h.
• Librería SD.h.
• Tarjeta SD correctamente conectada y formateada.
• Archivo pagina.txt disponible en la raíz de la tarjeta.
• Pin CS conectado al pin digital 4, según la configuración del programa.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------

Clasificación: Intermedio

Justificación:
- Implementa lectura de archivos desde un medio de almacenamiento externo.
- Integra comunicación serial para mostrar información leída desde la tarjeta.

====================================================