====================================================
MotorCarro_BT_Velocidad – Arduino
====================================================

Autor: Emiliano Cepeda
Plataforma: Arduino / Embedded
Lenguaje: C++ (Arduino Sketch)

----------------------------------------------------
1. Overview
----------------------------------------------------
MotorCarro_BT_Velocidad es un proyecto para Arduino que permite controlar un carro mediante comunicación Bluetooth utilizando un módulo HC-05/HC-06. Además del control de dirección, incorpora tres niveles de velocidad para cada movimiento mediante señales PWM aplicadas al puente H.

El sistema también implementa un mecanismo de seguridad que detiene automáticamente los motores cuando deja de recibir comandos durante un tiempo determinado, evitando movimientos no deseados por pérdida de comunicación.

La aplicación sirve como práctica de:
- Comunicación Bluetooth con Arduino.
- Control de motores DC mediante puente H.
- Control de velocidad utilizando PWM (analogWrite).
- Manejo de comunicación serial por software.
- Implementación de temporizadores con millis().

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MotorCarro_BT_Velocidad.ino
    Contiene toda la lógica del proyecto:
    - Configuración del módulo Bluetooth mediante SoftwareSerial.
    - Inicialización de los pines de dirección y velocidad.
    - Recepción de comandos Bluetooth.
    - Control de dirección y velocidad de ambos motores.
    - Sistema de seguridad por timeout.
    - Funciones de movimiento del vehículo.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control mediante Bluetooth
  - Recibe comandos enviados desde una aplicación móvil mediante un módulo HC-05/HC-06.

• Tres niveles de velocidad
  - Control de velocidad utilizando PWM sobre los pines ENA y ENB:
    - Baja → PWM = 85
    - Media → PWM = 170
    - Alta → PWM = 255

• Control de movimiento
  - Comandos disponibles:
    - A, 2, 3 → Avanzar (baja, media y alta velocidad).
    - R, 4, 5 → Reversa (baja, media y alta velocidad).
    - D, 6, 7 → Giro a la derecha (baja, media y alta velocidad).
    - I, 8, 9 → Giro a la izquierda (baja, media y alta velocidad).
    - N → Detener motores.

• Sistema de seguridad
  - Si durante 500 ms no se recibe ningún comando Bluetooth, los motores se detienen automáticamente.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Arduino Uno o compatible.
- Módulo Bluetooth HC-05 o HC-06.
- Puente H (L298N, L293D o similar).
- Dos motores DC.
- Fuente de alimentación para los motores.
- Chasis de carro (opcional).
- Cables de conexión.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE
• Librería:
  - SoftwareSerial
• Módulo Bluetooth configurado a 9600 baudios
• Puente H con entradas PWM (ENA y ENB)
• Alimentación adecuada para el puente H y los motores

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Implementa comunicación Bluetooth inalámbrica.
- Controla dirección y velocidad de dos motores mediante PWM.
- Incorpora un sistema de seguridad basado en tiempo de espera (millis()).
- Integra múltiples funciones de control sobre un vehículo móvil utilizando hardware externo.

----------------------------------------------------
7. Explicaciones
----------------------------------------------------
• Los valores PWM (85, 170 y 255) representan aproximadamente el 33%, 66% y 100% de la velocidad máxima.
• El timeout de 500 ms ayuda a detener el vehículo si se pierde la comunicación Bluetooth.
====================================================