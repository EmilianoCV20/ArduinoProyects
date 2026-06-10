====================================================
ISC_ESCLAVOS – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
ISC_ESCLAVOS es un proyecto para Arduino que implementa dos dispositivos esclavos en comunicación I2C usando la librería Wire. Cada esclavo recibe un valor enviado por un maestro y lo utiliza para encender o apagar una salida digital distinta. El primer esclavo controla el pin 13 y el segundo esclavo controla el pin 12.

La aplicación sirve como práctica de:
- Comunicación I2C maestro-esclavo con Arduino.
- Recepción de datos mediante eventos (Wire.onReceive).
- Control de salidas digitales a partir de información recibida.
- Uso de múltiples placas esclavas con direcciones distintas.
- Separación lógica en dos sketches muy similares para cada esclavo.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/ISC_ESCLAVO_1.ino  
    Contiene la lógica del primer esclavo:
    - Inicializa I2C con dirección 1 mediante Wire.begin(1).
    - Configura el pin 13 como salida.
    - Registra la función recievedEvent como callback de recepción.
    - Lee un byte recibido por I2C y lo muestra por Serial.
    - Escribe el valor recibido en el pin 13.

/ISC_ESCLAVO_2.ino  
    Contiene la lógica del segundo esclavo:
    - Inicializa I2C con dirección 2 mediante Wire.begin(2).
    - Configura el pin 12 como salida.
    - Registra la función recievedEvent como callback de recepción.
    - Lee un byte recibido por I2C y lo muestra por Serial.
    - Escribe el valor recibido en el pin 12.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Comunicación I2C con dos esclavos  
  - Cada sketch responde a una dirección distinta en el bus I2C.

• Recepción por evento  
  - Wire.onReceive(recievedEvent) permite ejecutar código automáticamente cuando llega un dato.

• Control de salidas digitales  
  - El valor recibido se asigna directamente a un pin de salida:
    - Esclavo 1 → pin 13  
    - Esclavo 2 → pin 12

• Depuración por Serial  
  - Cada esclavo imprime el valor recibido para verificar el funcionamiento de la comunicación.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Dos placas Arduino configuradas como esclavos.
- Una placa maestra Arduino adicional que envíe los datos.
- Conexiones I2C correctas:
  - SDA y SCL compartidos entre maestro y esclavos.
- Resistencias pull-up en el bus I2C si son necesarias según el hardware usado.
- LEDs o circuitos conectados a los pines 13 y 12.
- Monitor Serial para depuración.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - Wire  
• Mismo bus I2C para maestro y esclavos  
• Direcciones I2C correctamente definidas:
  - Esclavo 1: 1  
  - Esclavo 2: 2  
• Monitor serial a 9600 baudios  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Implementa comunicación I2C real entre maestro y esclavos.  
- Usa callbacks de recepción y control de salidas en función de datos entrantes.  

====================================================