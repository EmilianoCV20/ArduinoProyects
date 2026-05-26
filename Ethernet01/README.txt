====================================================
Ethernet01 – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
Ethernet01 es un sketch para Arduino diseñado para inicializar la interfaz Ethernet, obtener una dirección IP y mostrar el resultado por el monitor serial. El proyecto sirve como ejemplo básico de configuración de red en Arduino utilizando la librería Ethernet junto con SPI.

La aplicación sirve como práctica de:
- Inicialización de red Ethernet.
- Uso de la librería SPI como soporte para Ethernet.
- Verificación de conexión y obtención de IP.
- Comunicación básica con el monitor serial.
- Manejo inicial de errores de configuración de red.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Ethernet01.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de las librerías Ethernet.h y SPI.h.
    - Declaración de la dirección MAC.
    - Inicialización de Ethernet en setup().
    - Inicio de la comunicación serial.
    - Validación del arranque de Ethernet.
    - Impresión de la dirección IP asignada.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Inicialización Ethernet 
  - Se configura la red usando una dirección MAC fija.

• Obtención de IP 
  - El sketch intenta iniciar Ethernet y luego muestra la IP asignada por DHCP.

• Salida por Serial 
  - Se envían mensajes al monitor serial para indicar si la inicialización fue exitosa.

• Base para proyectos de red 
  - El código puede servir como punto de partida para servidores web, comunicación con bases de datos o control remoto.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet.
- Módulo o shield Ethernet.
- Cable de red conectado a un router o servidor DHCP.
- Monitor serial del Arduino IDE.
- Alimentación adecuada para la placa y el módulo Ethernet.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - Ethernet
  - SPI  
• Hardware Ethernet compatible  
• Conexión de red funcional  
• Monitor serial a 9600 baudios  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Básico
  
- Realiza una configuración inicial de red sin lógica adicional compleja.   
- Es un ejercicio introductorio para comprender la conexión Ethernet en Arduino.


====================================================