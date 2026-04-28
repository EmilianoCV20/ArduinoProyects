====================================================
appArduinoBluetooth – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
appArduinoBluetooth es un sketch para Arduino diseñado para establecer una comunicación serial entre el puerto Bluetooth y el monitor serial de la computadora. El programa funciona como un puente bidireccional: todo lo que recibe por Bluetooth se envía al puerto Serial, y todo lo que se escribe en el puerto Serial se transmite de regreso al módulo Bluetooth.

La aplicación sirve como práctica de:
- Comunicación serial con SoftwareSerial.
- Intercambio de datos entre dos interfaces seriales.
- Manejo básico de entradas y salidas en Arduino.
- Integración de módulos Bluetooth de bajo costo con placas Arduino.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Sketch principal (.ino)  
    Contiene toda la lógica del proyecto:
    - Inclusión de la librería SoftwareSerial.
    - Creación del objeto  BT  usando los pines 7 (RX) y 8 (TX).
    - Inicialización de BT.begin(9600) y Serial.begin(9600) en setup() .
    - Bucle principal loop()  que:
        • Lee datos disponibles desde Bluetooth y los escribe en Serial.  
        • Lee datos disponibles desde Serial y los escribe en Bluetooth.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Comunicación Bluetooth ↔ Serial  
  - El sketch actúa como puente entre el módulo Bluetooth y el monitor serial.

• Lectura y escritura bidireccional  
  - Si Bluetooth recibe datos, se reenvían a Serial.write().  
  - Si el monitor serial recibe datos, se reenvían a BT.write().

• Uso de SoftwareSerial  
  - Permite crear un puerto serial adicional en pines digitales, útil cuando la placa Arduino solo cuenta con un puerto hardware.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Una placa Arduino compatible.
- Un módulo Bluetooth serie compatible con SoftwareSerial.
- Conexión correcta de pines:
  - Pin 7 → RX del módulo Bluetooth
  - Pin 8 → TX del módulo Bluetooth
- Alimentación adecuada del módulo Bluetooth.
- Configuración del monitor serial a 9600 baudios.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería SoftwareSerial   
• Módulo Bluetooth serial  
• Conexión física correcta entre Arduino y el módulo Bluetooth  
• Monitor serial configurado a la misma velocidad: 9600 baudios

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:  
- Implementa únicamente lectura y reenvío de datos entre dos puertos seriales.  

====================================================