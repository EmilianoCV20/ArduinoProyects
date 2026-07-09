====================================================
LED_Serial – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
LED_Serial es un sketch simple para Arduino que permite controlar el LED integrado mediante comandos enviados por el puerto serial. El programa escucha caracteres recibidos por Serial y, dependiendo del valor leído, enciende o apaga el LED.

La aplicación sirve como práctica de:
- Lectura de datos desde el monitor serial.
- Control básico de salidas digitales.
- Manejo de caracteres y valores ASCII.
- Interacción simple entre el Arduino y el usuario.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/LED_Serial.ino  
    Contiene toda la lógica del proyecto:
    - Inicialización de la comunicación serial a 9600 baudios.
    - Configuración del LED integrado como salida.
    - Lectura de datos entrantes desde Serial.
    - Encendido del LED cuando se recibe el valor ASCII 97 ('a').
    - Apagado del LED cuando se recibe el valor ASCII 101 ('e').
    - Envío de respuesta por Serial indicando el dato recibido.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control del LED por Serial  
  - Si se recibe el carácter a, el LED integrado se enciende.  
  - Si se recibe el carácter e, el LED integrado se apaga.

• Lectura de bytes entrantes  
  - El sketch usa Serial.read() para obtener el valor recibido desde el monitor serial.

• Respuesta por monitor serial  
  - El programa imprime el valor recibido en formato decimal para depuración.

• Interacción directa  
  - El usuario puede controlar el LED desde el monitor serial del Arduino IDE.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino.
- LED integrado en la placa o LED externo conectado correctamente.
- Monitor serial del Arduino IDE.
- Conexión USB para comunicación serial.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Configuración serial a 9600 baudios  
• LED integrado o LED externo conectado al pin correspondiente  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:  
- Utiliza una lógica muy simple basada en dos comandos seriales.  

====================================================