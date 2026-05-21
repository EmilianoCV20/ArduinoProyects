====================================================
ElAutoIncreible – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
ElAutoIncreible es un sketch para Arduino que simula el efecto visual de las luces frontales del automóvil de la serie “Knight Rider” (El Auto Increíble) utilizando una secuencia de LEDs encendidos y apagados de forma continua.

La aplicación sirve como práctica de:
- Uso de ciclos for.
- Control de múltiples salidas digitales.
- Secuencias de iluminación con LEDs.
- Manejo de retardos con delay().
- Animaciones básicas con hardware Arduino.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/ElAutoIncreible.ino  
    Contiene toda la lógica del proyecto:
    - Declaración de pines para LEDs.
    - Configuración de pines como salida en setup().
    - Secuencia de recorrido de LEDs hacia adelante y hacia atrás en loop().

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Inicialización automática de pines  
  - Los pines desde el 13 hasta el 4 se configuran automáticamente como salidas mediante un ciclo.

• Efecto visual tipo “Knight Rider”  
  - Los LEDs se encienden en secuencia desde un extremo al otro y luego regresan.

• Animación continua  
  - El patrón se ejecuta indefinidamente dentro de loop().

• Control de tiempo  
  - Se utiliza delay(200) para controlar la velocidad del efecto.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino.
- LEDs conectados desde el pin 4 hasta el pin 13.
- Resistencias limitadoras para cada LED.
- Protoboard y cables de conexión.
- Alimentación mediante USB o fuente externa.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• LEDs conectados correctamente  
• Resistencias para protección de LEDs  
• Configuración adecuada de pines digitales  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico

Justificación:   
- Es un proyecto clásico de iniciación para practicar secuencias visuales y control de hardware básico.

====================================================