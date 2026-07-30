====================================================
MotorCarro – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
MotorCarro es un proyecto para Arduino que permite controlar el movimiento de un carro de dos motores de corriente directa mediante comandos enviados por el puerto serial. Dependiendo del carácter recibido, el programa controla el sentido de giro de cada motor para avanzar, retroceder, girar o detener el vehículo.

La aplicación sirve como práctica de:
- Control de motores DC mediante Arduino.
- Manejo de puentes H para inversión de giro.
- Recepción de comandos por comunicación serial.
- Implementación de movimientos básicos de un robot móvil.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MotorCarro.ino  
    Contiene toda la lógica del proyecto:
    - Configuración de los pines de control de ambos motores.
    - Inicialización de la comunicación serial.
    - Lectura de comandos desde el puerto serial.
    - Control de avance, reversa, giros y detención.
    - Implementación de funciones independientes para cada movimiento.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Control por puerto serial  
  - Recibe comandos desde el monitor serial para controlar el movimiento del carro.

• Movimientos disponibles  
  - A → Avanzar.
  - R → Retroceder.
  - D → Giro hacia la derecha.
  - I → Giro hacia la izquierda.
  - N → Detener ambos motores.

• Control independiente de motores  
  - Cada motor puede girar en ambos sentidos mediante dos pines de control.

• Funciones separadas  
  - Cada movimiento está implementado en una función independiente, facilitando el mantenimiento del código.

----------------------------------------------------
4. Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino.
- Dos motores de corriente directa.
- Módulo puente H (L298N, L293D o similar).
- Fuente de alimentación para los motores.
- Monitor serial del Arduino IDE.
- Chasis de carro (opcional).

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Comunicación serial a 9600 baudios.
• Pines utilizados:
  - Motor A:
    - IN1 → Pin 3
    - IN2 → Pin 4
  - Motor B:
    - IN3 → Pin 5
    - IN4 → Pin 6

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Implementa el control de dos motores de forma independiente.
- Utiliza comunicación serial para recibir comandos en tiempo real.

====================================================