====================================================
ISC_MAESTRO – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
ISC_MAESTRO es un proyecto para Arduino que implementa un dispositivo maestro utilizando la comunicación I2C mediante la librería Wire. Su función es enviar periódicamente un valor binario a un dispositivo esclavo para controlar el estado de una salida digital.

Este proyecto está diseñado para trabajar junto con los proyectos ISC_ESCLAVO_1 e ISC_ESCLAVO_2, formando una arquitectura básica de comunicación maestro-esclavo.

La aplicación sirve como práctica de:
- Comunicación I2C desde un dispositivo maestro.
- Envío de datos a dispositivos esclavos mediante direcciones I2C.
- Control remoto de salidas digitales.
- Alternancia automática de estados.
- Comunicación entre múltiples placas Arduino.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/ISC_MAESTRO.ino  
    Contiene la lógica del dispositivo maestro:
    - Inicializa la comunicación I2C mediante Wire.begin().
    - Envía el valor de la variable estado1 al esclavo con dirección 1.
    - Alterna automáticamente el valor enviado entre 0 y 1.
    - Incluye código comentado para controlar un segundo esclavo con dirección 2.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Inicialización como maestro I2C  
  - Utiliza Wire.begin() para configurar el Arduino como dispositivo maestro.

• Envío de datos al esclavo  
  - Envía un byte al dispositivo con dirección I2C 1 utilizando Wire.beginTransmission(), Wire.write() y Wire.endTransmission().

• Alternancia automática del estado  
  - Cambia el valor de estado1 entre 0 y 1 cada segundo, provocando el encendido y apagado alternado del dispositivo esclavo.

• Preparado para múltiples esclavos  
  - Incluye código comentado que permite controlar un segundo esclavo simplemente habilitando las instrucciones correspondientes.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Una placa Arduino configurada como maestro.
- Una o dos placas Arduino configuradas como esclavos.
- Conexiones I2C correctas:
  - SDA compartido.
  - SCL compartido.
- Resistencias pull-up en el bus I2C si son necesarias según el hardware utilizado.
- LEDs o dispositivos conectados a las salidas de los esclavos.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - Wire  
• Bus I2C correctamente cableado.
• Direcciones I2C compatibles con los esclavos:
  - Esclavo 1: 1
  - Esclavo 2: 2 (opcional)

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Implementa el rol de maestro dentro de una comunicación I2C.
- Utiliza correctamente las funciones de transmisión de datos de la librería Wire.
- Está diseñado para interactuar con múltiples dispositivos esclavos.


====================================================