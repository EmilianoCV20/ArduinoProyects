====================================================
FocoBluetooth – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
FocoBluetooth es un sketch para Arduino que permite controlar el estado de un LED integrado mediante comandos recibidos por Bluetooth usando SoftwareSerial. El programa escucha caracteres enviados desde un módulo Bluetooth y, dependiendo del valor recibido, enciende o apaga el LED incorporado en la placa.

La aplicación sirve como práctica de:
- Comunicación serial mediante Bluetooth.
- Uso de SoftwareSerial para crear un puerto serie adicional.
- Control básico de salidas digitales.
- Recepción y procesamiento de comandos simples.
- Interacción entre Arduino, Bluetooth y monitor serial.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/FocoBluetooth.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de SoftwareSerial.h.
    - Creación del objeto BT en los pines 7 (RX) y 8 (TX).
    - Inicialización de Bluetooth y Serial en setup().
    - Configuración del LED integrado como salida.
    - Lectura de datos entrantes desde Bluetooth.
    - Activación o desactivación del LED según el comando recibido.
    - Envío de mensajes de depuración por el monitor serial.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control del LED por Bluetooth  
  - Si llega el carácter 'a', el LED integrado se enciende.  
  - Si llega el carácter 'e', el LED integrado se apaga.

• Uso de SoftwareSerial  
  - Permite comunicación Bluetooth en pines digitales distintos al puerto serial hardware.

• Mensajes de depuración  
  - El programa imprime por Serial el valor recibido en formato decimal.

• Interacción simple y directa  
  - El sketch responde inmediatamente a cada comando recibido por Bluetooth.

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
- Monitor serial para depuración.
- Aplicación o terminal Bluetooth que envíe caracteres simples.

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
- El proyecto implementa una lógica muy simple basada en dos comandos de control.  
- Utiliza comunicación Bluetooth y control digital

====================================================