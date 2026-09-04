====================================================
PuertoBluetooth – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
PuertoBluetooth es un sketch para Arduino que utiliza un módulo Bluetooth mediante SoftwareSerial para detectar cuando se recibe información y llevar un contador de mensajes recibidos. Cada vez que llega un dato, el contador aumenta y su valor se envía tanto al dispositivo Bluetooth como al monitor serial.

La aplicación sirve como práctica de:
- Comunicación serial mediante Bluetooth.
- Uso de SoftwareSerial.
- Detección de datos entrantes.
- Manejo de variables contador.
- Envío de información a través de dos puertos seriales.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/PuertoBluetooth.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de la librería SoftwareSerial.h.
    - Configuración de los pines RX y TX.
    - Inicialización de Bluetooth y Serial.
    - Detección de información recibida por Bluetooth.
    - Incremento del contador.
    - Envío del contador por Bluetooth y Serial.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Detección de datos Bluetooth
  - El programa comprueba continuamente si existen datos disponibles mediante bt.available().

• Contador de mensajes
  - Cada vez que se recibe información, la variable contador aumenta en uno.

• Envío de resultados
  - El valor del contador se envía tanto al módulo Bluetooth como al monitor serial.

• Temporización
  - Después de cada recepción se utiliza delay(2000) para esperar dos segundos antes de procesar nuevamente.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino.
- Módulo Bluetooth serial compatible con SoftwareSerial.
- Conexión del módulo:
  - RX → Pin 2
  - TX → Pin 3
- Monitor serial para observar el contador.
- Dispositivo Bluetooth capaz de enviar datos.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - SoftwareSerial  
• Módulo Bluetooth serial  
• Configuración de comunicación a 9600 baudios  
• Conexión física correcta entre Arduino y el módulo Bluetooth  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:  
- Implementa una comunicación Bluetooth sencilla mediante SoftwareSerial.
- Utiliza una variable contador para registrar eventos recibidos.
- La lógica es pequeña y no incorpora control de hardware, sensores, bases de datos ni estructuras complejas.

====================================================