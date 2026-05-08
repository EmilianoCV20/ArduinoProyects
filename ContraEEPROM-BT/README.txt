====================================================
ContraEEPROM-BT – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
ContraEEPROM-BT es un sketch para Arduino que implementa un sistema de control de acceso mediante contraseña almacenada en EEPROM, con entrada de comandos tanto por el puerto Serial como por Bluetooth usando SoftwareSerial. El programa permite encender o apagar un LED mediante una contraseña válida y también cambiar dicha contraseña de forma persistente.

La aplicación sirve como práctica de:
- Uso de EEPROM para almacenar datos persistentes.
- Comunicación serial por Bluetooth y por monitor serial.
- Lectura y procesamiento de cadenas de entrada.
- Control de un LED como salida de estado.
- Gestión básica de un flujo de autenticación con cambio de contraseña.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/ContraEEPROM-BT.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de las librerías EEPROM.h y SoftwareSerial.h.
    - Configuración de pines para Bluetooth con SoftwareSerial.
    - Inicialización del LED en el pin 13.
    - Lectura del estado almacenado en EEPROM.
    - Lectura de la contraseña guardada en EEPROM.
    - Procesamiento de comandos recibidos por Serial o Bluetooth.
    - Funciones para alternar el LED, guardar contraseña y leer contraseña desde EEPROM.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control de LED con contraseña  
  - El LED solo cambia de estado cuando la entrada coincide con la contraseña almacenada.

• Cambio de contraseña  
  - Al recibir el comando C, el sistema solicita una nueva contraseña y la guarda en EEPROM.

• Persistencia con EEPROM  
  - El estado del LED y la contraseña se conservan aun cuando Arduino se reinicia.

• Entrada dual  
  - La lógica acepta comandos desde el monitor serial y desde el módulo Bluetooth.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con EEPROM.
- Módulo Bluetooth serial compatible con SoftwareSerial.
- Conexión correcta de pines:
  - RX Bluetooth en pin 7
  - TX Bluetooth en pin 8
- LED conectado al pin 13.
- Monitor serial configurado a 9600 baudios.
- Alimentación adecuada del módulo Bluetooth.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - EEPROM
  - SoftwareSerial  
• Módulo Bluetooth serial  
• LED externo o el LED integrado en pin 13  
• Configuración correcta de velocidad serial: 9600 baudios  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Utiliza almacenamiento persistente en EEPROM, lo que añade complejidad frente a sketches básicos.  
- Integra dos canales de entrada (Serial y Bluetooth) con procesamiento de comandos.  

====================================================