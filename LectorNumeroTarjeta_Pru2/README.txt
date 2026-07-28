====================================================
LectorNumeroTarjeta_Pru2 – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
LectorNumeroTarjeta_Pru2 es un proyecto para Arduino que combina un lector RFID mediante protocolo Wiegand, conexión Ethernet y una base de datos MySQL. El sistema recibe el número de una tarjeta, lo consulta en la base de datos y, si está registrada, activa un relé durante 5 segundos.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/LectorNumeroTarjeta_Pru2.ino  
    Contiene toda la lógica del proyecto:
    - Lectura de tarjetas mediante Wiegand.
    - Conexión Ethernet mediante DHCP.
    - Conexión y consultas a una base de datos MySQL.
    - Comprobación del número de tarjeta.
    - Activación de un relé cuando la tarjeta es válida.
    - Reporte de errores y datos mediante Serial.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Lectura de tarjeta  
  - Utiliza los pines D0 y D1 para recibir datos del lector Wiegand.
  - Procesa tarjetas con formato de 26 bits.

• Consulta en MySQL  
  - Obtiene el número de tarjeta y lo busca en la tabla "TarjetasRegistradas".
  - Si encuentra el número, la tarjeta es considerada válida.

• Control del relé  
  - Una tarjeta válida activa el relé conectado al pin 5.
  - El relé permanece activo durante 5 segundos y posteriormente se desactiva.

• Conexión Ethernet  
  - Obtiene la dirección IP mediante DHCP.
  - Utiliza la red para comunicarse con el servidor MySQL.

----------------------------------------------------
4. Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet.
- Lector RFID compatible con Wiegand.
- Tarjeta RFID compatible con Wiegand de 26 bits.
- Módulo Ethernet.
- Módulo relé.
- Servidor MySQL accesible mediante la red.
- Base de datos "Arduino.
- Tabla "TarjetasRegistradas".

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - Ethernet
  - MySQL_Connection
  - MySQL_Cursor
  - Wiegand
• Comunicación serial a 9600 baudios.
• Pines utilizados:
  - D0 → Pin 2
  - D1 → Pin 3
  - Relé → Pin 5
• Conexión Ethernet mediante DHCP.
• Servidor MySQL configurado.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Producción/Avanzado

Justificación:
- Integra lectura RFID mediante Wiegand, comunicación Ethernet, consultas MySQL y control físico mediante relé.
- Implementa validación de tarjetas y recuperación de la conexión con la base de datos.
- Combina hardware, comunicación de red y almacenamiento de información en un solo sistema.

====================================================