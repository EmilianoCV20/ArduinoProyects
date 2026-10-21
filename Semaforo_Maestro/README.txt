====================================================
Semaforo_Maestro.ino – Arduino
====================================================

Autor: Emiliano Cepeda
Plataforma: Arduino
Lenguaje: C++ (Arduino Sketch)

----------------------------------------------------
1. Overview
----------------------------------------------------
Semaforo_Maestro.ino es un programa para Arduino que implementa el control maestro de un sistema de semáforos mediante comunicación I2C. El dispositivo maestro envía secuencias de estados a cuatro dispositivos esclavos identificados con las direcciones 1, 2, 3 y 4, coordinando sus cambios con intervalos de dos segundos.

El programa sirve como práctica de:
- Comunicación I2C mediante la librería Wire.
- Arquitectura maestro-esclavo entre dispositivos Arduino.
- Transmisión de datos a direcciones específicas.
- Control secuencial de estados.
- Coordinación temporal mediante delay().

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Semaforo_Maestro.ino
    Programa principal del dispositivo maestro.
    Contiene:
    - setup() — inicializa la comunicación I2C como maestro.
    - loop() — envía secuencias de estados a los cuatro dispositivos esclavos.
    - Ciclos for — recorren los estados que se transmiten a cada grupo de esclavos.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------

• Inicialización de comunicación I2C:
  - Wire.begin() configura el Arduino como dispositivo maestro.

• Control de los esclavos 1 y 2:
  - Envía los estados del 0 al 3 a las direcciones I2C 1 y 2.
  - Ambos esclavos reciben el mismo estado en cada iteración.
  - Cada estado permanece durante aproximadamente 2 segundos antes de continuar.

• Control del esclavo 3:
  - Envía los estados del 0 al 2 a la dirección I2C 3.
  - Introduce un intervalo de 2 segundos entre transmisiones.

• Control del esclavo 4:
  - Envía los estados del 0 al 2 a la dirección I2C 4.
  - Cada estado se transmite con un intervalo de 2 segundos.

• Transmisión de datos:
  - Wire.beginTransmission() inicia una transmisión hacia la dirección del esclavo.
  - Wire.write(estado) envía el valor del estado.
  - Wire.endTransmission() finaliza la transmisión.

• Ejecución continua:
  - Al terminar las secuencias, loop() vuelve a comenzar el proceso indefinidamente.

----------------------------------------------------
4. Recursos / Components necesarios
----------------------------------------------------

• Un Arduino configurado como maestro.
• Cuatro dispositivos Arduino configurados como esclavos I2C.
• Circuitos de semáforo conectados a los dispositivos esclavos, con sus LED y resistencias correspondientes.
• Conexiones I2C compartidas: SDA, SCL y GND común.
• Direcciones I2C de los esclavos configuradas como 1, 2, 3 y 4.
• Resistencias pull-up para SDA y SCL, si no están disponibles en los módulos o dispositivos utilizados.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------

• Arduino IDE o entorno compatible con Arduino.
• Librería Wire.h, incluida normalmente en el entorno Arduino.
• Dispositivos esclavos con código compatible que interprete los estados recibidos.
• Conexiones I2C y niveles eléctricos compatibles entre los dispositivos.
• Pines SDA y SCL conectados según la placa utilizada.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------

Clasificación: Intermedio

Justificación:
- Implementa comunicación I2C entre un maestro y cuatro dispositivos esclavos.
- Coordina secuencias de estados en varios dispositivos mediante transmisiones dirigidas.
- Utiliza ciclos, variables de estado y retardos para organizar el funcionamiento temporal.

====================================================