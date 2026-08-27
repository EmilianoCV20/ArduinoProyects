====================================================
MotorCarro_WEB_2 – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
MotorCarro_WEB_2 es un proyecto para Arduino que permite controlar un carro mediante una interfaz web utilizando Ethernet y una tarjeta SD. A diferencia de la versión anterior, esta implementación obtiene automáticamente la dirección IP mediante DHCP, en lugar de utilizar una IP fija.

La aplicación sirve como práctica de:
- Comunicación Ethernet mediante DHCP.
- Creación de un servidor web en Arduino.
- Lectura de páginas HTML desde una tarjeta SD.
- Control de motores mediante comandos HTTP.
- Manejo básico de errores y reconexión de la tarjeta SD.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MotorCarro_WEB_2.ino  
    Contiene toda la lógica del proyecto:
    - Configuración de Ethernet mediante una dirección MAC.
    - Obtención automática de IP mediante DHCP.
    - Inicialización y recuperación de la tarjeta SD.
    - Creación del servidor web en el puerto 80.
    - Procesamiento de solicitudes HTTP.
    - Control de los motores según los comandos recibidos.
    - Lectura y envío del archivo carroP.txt.
    - Funciones para avanzar, retroceder, girar y detener el carro.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Configuración automática de red
  - Utiliza Ethernet.begin(mac) para obtener una dirección IP mediante DHCP.
  - Muestra la dirección IP asignada en el monitor serial.

• Servidor web
  - Arduino crea un servidor HTTP en el puerto 80.
  - Los clientes pueden acceder mediante la dirección IP obtenida.

• Control del carro mediante HTTP
  - Los comandos recibidos permiten controlar el movimiento:
    - A → Avanzar.
    - R → Retroceder.
    - D → Giro hacia la derecha.
    - I → Giro hacia la izquierda.
    - N → Detener motores.

• Uso de tarjeta SD
  - La interfaz web se obtiene desde el archivo carroP.txt.
  - Si la tarjeta SD no está disponible, el programa intenta inicializarla nuevamente.

• Control de motores
  - Utiliza cuatro pines digitales para controlar dos motores mediante un puente H.

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
- Red local con servidor DHCP activo.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - SPI
  - Ethernet
  - SD
• Conexión Ethernet funcional.
• Servidor DHCP disponible en la red.
• Tarjeta SD con el archivo:
  - carroP.txt
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
- Integra Ethernet, DHCP, servidor web, tarjeta SD y control de motores.
- Implementa recuperación de la tarjeta SD cuando la inicialización falla.
- Procesa solicitudes HTTP y las convierte en acciones físicas sobre el carro.

====================================================