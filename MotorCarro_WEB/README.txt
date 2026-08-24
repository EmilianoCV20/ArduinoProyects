====================================================
MotorCarro_WEB – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
MotorCarro_WEB es un proyecto para Arduino que permite controlar un carro mediante una interfaz web alojada directamente en el dispositivo. Utiliza Ethernet para crear un servidor web, una tarjeta SD para almacenar la página HTML y cuatro salidas digitales para controlar dos motores.

La aplicación sirve como práctica de:
- Creación de un servidor web con Arduino.
- Comunicación Ethernet con IP fija.
- Lectura de archivos HTML desde una tarjeta SD.
- Control de motores mediante comandos HTTP.
- Integración de red, almacenamiento y control de hardware.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MotorCarro_WEB.ino  
    Contiene toda la lógica del proyecto:
    - Configuración de Ethernet, IP, DNS, Gateway y máscara de subred.
    - Inicialización de la tarjeta SD.
    - Creación del servidor web en el puerto 80.
    - Recepción y procesamiento de solicitudes HTTP.
    - Control de los motores según el comando recibido.
    - Lectura y envío de la página carroP.txt desde la tarjeta SD.
    - Funciones para avanzar, retroceder, girar y detener el carro.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Servidor web integrado
  - Arduino crea un servidor HTTP utilizando EthernetServer en el puerto 80.
  - La dirección IP utilizada es 192.168.1.100.

• Control del carro mediante HTTP
  - Los comandos recibidos mediante solicitudes GET controlan los motores:
    - A → Avanzar.
    - R → Retroceder.
    - D → Giro hacia la derecha.
    - I → Giro hacia la izquierda.
    - N → Detener motores.

• Uso de tarjeta SD
  - La interfaz web se almacena en el archivo carroP.txt.
  - Arduino abre el archivo y lo envía al cliente mediante la respuesta HTTP.

• Control de motores
  - Utiliza cuatro pines digitales para controlar dos motores mediante un puente H.
  - Cada movimiento tiene una función independiente.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet y tarjeta SD.
- Shield o módulo Ethernet.
- Tarjeta SD.
- Archivo carroP.txt almacenado en la tarjeta SD.
- Dos motores DC.
- Puente H para controlar los motores.
- Fuente de alimentación adecuada para los motores.
- Red local compatible con la configuración IP utilizada.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - SPI
  - Ethernet
  - SD
• Puerto Ethernet funcionando correctamente.
• Tarjeta SD con el archivo:
  - carroP.txt
• Configuración de red:
  - IP: 192.168.1.100
  - Gateway: 192.168.1.1
  - DNS: 8.8.8.8
  - Subred: 255.255.255.0
• Pines utilizados:
  - Motor A1 → Pin 6
  - Motor A2 → Pin 7
  - Motor B1 → Pin 8
  - Motor B2 → Pin 9
  - Chip Select SD → Pin 4

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:
- Integra simultáneamente Ethernet, servidor web, tarjeta SD y control de motores.
- Procesa solicitudes HTTP para controlar físicamente el carro.
- Incluye manejo de errores básicos para la tarjeta SD.

====================================================