====================================================
EEPROM – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
EEPROM es un sketch básico para Arduino que permite controlar el estado de un LED mediante comandos enviados por el monitor serial y guardar dicho estado en la memoria EEPROM para mantenerlo incluso después de reiniciar la placa.

La aplicación sirve como práctica de:
- Uso de memoria EEPROM en Arduino.
- Comunicación serial básica.
- Lectura de comandos desde el monitor serial.
- Persistencia de datos entre reinicios.
- Control de salidas digitales.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/EEPROM.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de la librería EEPROM.h.
    - Configuración del pin 13 como salida.
    - Lectura del estado almacenado en EEPROM.
    - Recepción de comandos desde Serial.
    - Encendido y apagado del LED.
    - Escritura del estado en EEPROM.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Persistencia del estado del LED  
  - El estado del LED se almacena en la dirección 0 de la EEPROM.

• Control por comandos seriales  
  - El usuario puede enviar:
    - "S" para encender.
    - "N" para apagar.

• Recuperación automática del estado  
  - Al iniciar Arduino, el programa revisa la EEPROM y restaura el estado guardado anteriormente.

• Comunicación serial  
  - Se usa el monitor serial a 9600 baudios para enviar y recibir mensajes.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con EEPROM.
- LED conectado al pin 13 o uso del LED integrado.
- Cable USB para programación y comunicación serial.
- Monitor serial del Arduino IDE.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - EEPROM  
• Configuración serial a 9600 baudios  
• LED conectado correctamente al pin 13  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:  
- El proyecto utiliza lógica simple basada en comandos seriales.  
- Implementa persistencia básica usando EEPROM.  

====================================================