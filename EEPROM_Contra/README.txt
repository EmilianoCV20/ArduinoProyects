====================================================
EEPROM_Contra – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
EEPROM_Contra es un sketch para Arduino que implementa un sistema de control de un LED mediante contraseña almacenada en EEPROM. El programa permite leer una contraseña guardada previamente, cambiarla mediante comandos seriales y alternar el estado del LED cuando el usuario introduce la contraseña correcta.

La aplicación sirve como práctica de:
- Uso de memoria EEPROM para persistencia de datos.
- Entrada y procesamiento de texto desde el Monitor Serial.
- Gestión básica de autenticación mediante contraseña.
- Control de salidas digitales en Arduino.
- Manejo de estados internos con variables auxiliares.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/EEPROM_Contra.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de la librería EEPROM.h.
    - Lectura del estado del LED desde EEPROM al iniciar.
    - Lectura de la contraseña almacenada en EEPROM.
    - Recepción de comandos desde Serial.
    - Cambio de contraseña cuando se envía el comando C.
    - Alternancia del estado del LED cuando la contraseña es correcta.
    - Funciones auxiliares para leer y guardar la contraseña.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Persistencia del estado del LED  
  - El estado del LED se guarda en la dirección 0 de la EEPROM.

• Contraseña almacenada en EEPROM  
  - La contraseña se recupera al iniciar el Arduino mediante la función leerContrasena().

• Cambio de contraseña  
  - Al enviar "C" por el Monitor Serial, el sistema solicita una nueva contraseña y la almacena en EEPROM.

• Control por contraseña  
  - Si la entrada coincide con la contraseña guardada, el LED cambia de estado.

• Uso de funciones auxiliares  
  - alternarLED() controla el cambio de estado y guarda el valor en EEPROM.  
  - guardarContrasena() escribe la nueva contraseña en la memoria persistente.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con EEPROM.
- LED conectado al pin 13 o uso del LED integrado.
- Monitor Serial del Arduino IDE.
- Conexión USB para programación y comunicación serial.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - EEPROM  
• Monitor serial configurado a 9600 baudios  
• LED conectado correctamente al pin 13  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Incluye uso de EEPROM para persistencia y manejo de una contraseña.  
- Introduce control por comandos seriales y lógica de autenticación sencilla.

====================================================