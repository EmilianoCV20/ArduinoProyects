====================================================
FocoBluetoothPruebas – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
FocoBluetoothPruebas es un sketch para Arduino que permite controlar el LED integrado mediante comandos recibidos por Bluetooth usando SoftwareSerial, y además devuelve por Bluetooth y por el monitor serial el valor recibido. El programa funciona como una prueba de comunicación bidireccional entre Arduino y un módulo Bluetooth.

La aplicación sirve como práctica de:
- Comunicación serial mediante Bluetooth.
- Uso de SoftwareSerial para crear un puerto serie adicional.
- Control básico de salidas digitales.
- Lectura y respuesta a comandos simples.
- Envío de retroalimentación tanto al monitor serial como al dispositivo Bluetooth.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/FocoBluetoothPruebas.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de SoftwareSerial.h.
    - Creación del objeto BT en los pines 7 (RX) y 8 (TX).
    - Inicialización de Bluetooth y Serial en setup().
    - Configuración del LED integrado como salida.
    - Lectura de comandos entrantes desde Bluetooth.
    - Encendido o apagado del LED según el carácter recibido.
    - Envío del valor recibido por Serial y por Bluetooth para pruebas.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control del LED por Bluetooth  
  - Si llega el carácter 'a', el LED integrado se enciende.  
  - Si llega el carácter 'e', el LED integrado se apaga.

• Comunicación bidireccional  
  - El sketch responde al comando recibido enviando el mismo valor por Serial y por Bluetooth.

• Uso de SoftwareSerial  
  - Permite comunicación Bluetooth usando pines digitales 7 y 8.

• Prueba de enlace Bluetooth  
  - El código funciona como test para verificar que el módulo Bluetooth recibe y devuelve datos correctamente.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino.
- Módulo Bluetooth compatible con SoftwareSerial.
- Conexión correcta de pines:
  - RX Bluetooth en pin 7
  - TX Bluetooth en pin 8
- Uso del LED integrado o un LED externo conectado correctamente.
- Monitor serial para observar la información recibida.
- Aplicación o terminal Bluetooth para enviar caracteres simples.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - SoftwareSerial  
• Módulo Bluetooth serial  
• Configuración serial a 9600 baudios  
• Conexión física correcta entre Arduino y el módulo Bluetooth  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:   
- Es un ejercicio introductorio adecuado para probar comunicación bidireccional y control remoto básico con Arduino.

====================================================