====================================================
ChecadorTarjeta – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
ChecadorTarjeta es un sketch para Arduino orientado a la conexión de red mediante Ethernet y a la ejecución de consultas sobre una base de datos MySQL. El programa inicializa una dirección MAC, establece conexión con un servidor remoto y ejecuta una consulta SQL para recorrer los resultados obtenidos en una tabla de usuarios.

La aplicación sirve como práctica de:
- Configuración de Ethernet en Arduino.
- Conexión a una base de datos MySQL desde un microcontrolador.
- Ejecución de consultas SQL simples.
- Lectura de filas de resultados mediante cursor.
- Manejo básico de clientes y comunicación con un servidor de datos.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Sketch principal (.ino)  
    Contiene toda la lógica del proyecto:
    - Inclusión de librerías para Ethernet y MySQL.
    - Declaración de la dirección MAC y la IP del servidor.
    - Creación del cliente Ethernet y la conexión MySQL.
    - Inicialización de la red en setup().
    - Ejecución de una consulta SQL en loop().
    - Recorrido de filas devueltas por la consulta.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Conexión a Ethernet  
  - Se inicializa la red usando una dirección MAC fija.

• Conexión a MySQL  
  - Se crea una conexión contra un servidor MySQL usando usuario y contraseña.

• Consulta SQL  
  - El sketch ejecuta SELECT * FROM user para leer registros de la tabla.

• Recorrido de resultados  
  - Se usa un cursor para recuperar filas devueltas por la consulta y contar resultados.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet.
- Módulo o shield Ethernet.
- Servidor MySQL accesible por red.
- Base de datos y tabla user existentes en el servidor.
- Credenciales válidas de acceso a la base de datos.
- Conexión física correcta y configuración de red adecuada.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - Ethernet
  - MySQL_Connection
  - MySQL_Cursor  
• Conectividad de red funcional  
• Servidor MySQL disponible  
• Tabla SQL existente para la consulta  
• Configuración de la MAC y del servidor correctamente definida  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Integra Ethernet y acceso a base de datos MySQL 
- Incluye consulta SQL y lectura de resultados con cursor.  


====================================================