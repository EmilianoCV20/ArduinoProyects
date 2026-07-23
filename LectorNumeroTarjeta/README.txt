====================================================
LectorNumeroTarjeta – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
LectorNumeroTarjeta es un proyecto para Arduino que utiliza un lector RFID con interfaz Wiegand para obtener el número de una tarjeta de acceso. El programa recibe los datos enviados por el lector, verifica que correspondan al formato Wiegand de 26 bits y extrae el número de la tarjeta para mostrarlo en el monitor serial.

La aplicación sirve como práctica de:
- Comunicación con lectores Wiegand.
- Recepción y procesamiento de datos binarios.
- Manejo de callbacks mediante la librería Wiegand.
- Conversión de datos recibidos a un número de identificación.
- Detección y reporte de errores de lectura.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/LectorNumeroTarjeta.ino  
    Contiene toda la lógica del proyecto:
    - Inicializa la comunicación serial.
    - Configura los pines D0 y D1 del protocolo Wiegand.
    - Inicializa la librería Wiegand.
    - Recibe datos mediante callbacks.
    - Procesa únicamente tarjetas con formato de 26 bits.
    - Extrae y muestra el número de tarjeta.
    - Reporta errores de lectura y datos recibidos.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Lectura mediante protocolo Wiegand  
  - Recibe la información enviada por un lector conectado a los pines D0 y D1.

• Validación del formato  
  - Verifica que la tarjeta utilice el formato estándar de 26 bits antes de procesarla.

• Obtención del número de tarjeta  
  - Elimina los bits de paridad y reconstruye el identificador de la tarjeta para mostrarlo por Serial.

• Manejo de errores  
  - Si ocurre un problema durante la lectura, muestra el tipo de error y los datos crudos recibidos para facilitar la depuración.


----------------------------------------------------
4. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - Wiegand
• Comunicación serial a 9600 baudios.
• Pines utilizados:
  - D0 → Pin 2
  - D1 → Pin 3

----------------------------------------------------
5. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Implementa comunicación mediante el protocolo Wiegand.
- Utiliza callbacks para el procesamiento de eventos.
- Realiza validación del formato recibido y manipulación de datos binarios para obtener el identificador de la tarjeta.


====================================================