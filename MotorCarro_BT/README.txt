====================================================
MotorCarro_BT – Arduino
====================================================

Autor: Emiliano Cepeda
Plataforma: Arduino / Embedded
Lenguaje: C++ (Arduino Sketch)

----------------------------------------------------
1. Overview
----------------------------------------------------
MotorCarro_BT es un proyecto para Arduino que controla el movimiento de un carro mediante comunicación Bluetooth utilizando un módulo HC-05/HC-06 y la librería SoftwareSerial. El sistema recibe comandos enviados desde un dispositivo móvil y acciona dos motores de corriente directa mediante un puente H.

El proyecto implementa un mecanismo de seguridad que detiene automáticamente los motores cuando deja de recibir comandos durante un tiempo determinado, evitando que el vehículo continúe en movimiento por pérdida de comunicación.

La aplicación sirve como práctica de:
- Comunicación Bluetooth con Arduino.
- Control de motores DC mediante puente H.
- Manejo de puertos seriales por software.
- Implementación de temporizadores usando millis().
- Sistemas de seguridad mediante timeout de comunicación.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MotorCarro_BT.ino
    Contiene toda la lógica del proyecto:
    - Configuración del módulo Bluetooth mediante SoftwareSerial.
    - Inicialización de los pines de control de los motores.
    - Recepción de comandos Bluetooth.
    - Control de movimiento del carro.
    - Implementación del temporizador de seguridad.
    - Funciones para cada dirección de movimiento.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control por Bluetooth
  - Recibe comandos desde un dispositivo móvil utilizando SoftwareSerial.

• Movimientos del carro
  - Comandos disponibles:
    - A → Avanzar.
    - R → Reversa.
    - D → Giro hacia la derecha.
    - I → Giro hacia la izquierda.
    - N → Detener motores.

• Sistema de seguridad
  - Si no se reciben comandos durante 500 ms, el carro se detiene automáticamente.

• Control independiente de motores
  - Cada motor es controlado mediante dos pines digitales para definir su sentido de giro.

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
• Puente H correctamente conectado
• Alimentación adecuada para los motores

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Implementa comunicación Bluetooth en tiempo real.
- Controla dos motores con distintas combinaciones de movimiento.
- Utiliza temporización con millis() para implementar un mecanismo de seguridad.
- Integra comunicación inalámbrica y control de hardware en un mismo proyecto.

====================================================