====================================================
appArduinoEthernetCarroBD – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
appArduinoEthernetCarroBD es un sketch para Arduino que integra control de motores, comunicación por Ethernet, lectura de temperatura con sensor DHT11 y almacenamiento de datos en una base de datos MySQL. Además, expone una pequeña interfaz web local para controlar el movimiento de un carro mediante botones HTML accesibles desde un navegador.

La aplicación sirve como práctica de:
- Conexión Ethernet con asignación de IP por DHCP.
- Comunicación con una base de datos MySQL desde Arduino.
- Lectura de sensores ambientales (DHT11).
- Control de motores mediante pines digitales.
- Creación de una interfaz web básica para control remoto del vehículo.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Sketch principal (.ino)  
    Contiene toda la lógica del proyecto:
    - Inclusión de librerías: Ethernet.h, MySQL_Connection.h, MySQL_Cursor.h, DHT.h.
    - Inicialización del sensor DHT11.
    - Configuración de red Ethernet y conexión a MySQL.
    - Creación de un servidor web en el puerto 80.
    - Lectura periódica de temperatura y envío a la base de datos.
    - Atención de clientes web para controlar el carro.
    - Funciones auxiliares para mover o detener los motores.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Conexión de red por Ethernet  
  - Se obtiene una IP mediante DHCP y se inicia un servidor web en el puerto 80.

• Lectura de temperatura con DHT11  
  - El sensor se inicializa en setup() y se consulta cada 30 segundos.

• Inserción de datos en MySQL  
  - La temperatura se inserta en la tabla TemperaturaHora junto con la fecha y hora actual.
  - La conexión se realiza mediante MySQL_Connection y MySQL_Cursor.

• Control web del carro  
  - El servidor responde con una página HTML simple que permite enviar comandos de movimiento.
  - Los comandos controlan el avance, retroceso, giros y detención de los motores.

• Control de motores  
  - Los pines motorA1, motorA2, motorB1 y motorB2 definen el movimiento del carro.
  - Se incluyen funciones para:
    - detenerMotores()
    - moverDerecha()
    - moverIzquierda()
    - moverDerechaIzquierda()
    - moverIzquierdaDerecha()

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet.
- Shield o módulo Ethernet compatible.
- Sensor DHT11 conectado al pin 3.
- Puente H o módulo de control de motores con conexiones:
  - motorA1 = pin 8
  - motorA2 = pin 9
  - motorB1 = pin 11
  - motorB2 = pin 12
- Base de datos MySQL accesible por red.
- Usuario, contraseña, base de datos e IP del servidor correctamente configurados.
- Navegador web para acceder a la interfaz de control.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - Ethernet
  - MySQL_Connection
  - MySQL_Cursor
  - DHT
• Módulo o shield Ethernet  
• Sensor DHT11  
• Servidor MySQL disponible en red  
• Conexión física correcta de motores y alimentación adecuada  
• Monitor serial configurado a 9600 baudios

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Integra múltiples subsistemas: red, base de datos, sensor ambiental y control de motores.  
- Incluye una interfaz web embebida y envío periódico de datos a MySQL.

====================================================