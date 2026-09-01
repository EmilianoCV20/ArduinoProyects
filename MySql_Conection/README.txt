====================================================
MySql_Conection – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
MySql_Conection es un sketch para Arduino que establece una conexión Ethernet con un servidor MySQL y ejecuta una instrucción SQL para insertar un registro en una tabla de la base de datos. El programa utiliza la librería MySQL_Connection para establecer la conexión y MySQL_Cursor para ejecutar la consulta.

La aplicación sirve como práctica de:
- Conexión de Arduino a una red Ethernet.
- Comunicación con un servidor MySQL.
- Ejecución de consultas SQL desde Arduino.
- Inserción de información en una base de datos.
- Control de ejecución mediante una bandera para realizar la consulta una sola vez.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/MySql_Conection.ino  
    Contiene toda la lógica del proyecto:
    - Inclusión de las librerías Ethernet.h, MySQL_Connection.h y MySQL_Cursor.h.
    - Configuración de la dirección MAC y parámetros de red.
    - Configuración de la dirección del servidor MySQL.
    - Definición de usuario, contraseña y base de datos.
    - Declaración de una consulta INSERT para almacenar datos.
    - Inicialización de Ethernet y conexión con MySQL.
    - Ejecución de la consulta únicamente una vez mediante la variable bandera.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Conexión Ethernet
  - El Arduino obtiene una configuración de red mediante Ethernet.begin(mac).
  - La dirección IP asignada se muestra por el monitor serial.

• Conexión a MySQL
  - Se establece comunicación con el servidor MySQL en el puerto 3306.
  - Utiliza las credenciales definidas en el sketch.

• Inserción de datos
  - Ejecuta una consulta SQL para insertar un valor de temperatura y una ubicación en la tabla Arduino.Temperatura.

• Ejecución única
  - La variable bandera evita que la consulta SQL se ejecute repetidamente dentro de loop().

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible con Ethernet.
- Shield o módulo Ethernet.
- Conexión de red disponible.
- Servidor MySQL accesible desde la red.
- Base de datos Arduino.
- Tabla Temperatura.
- Usuario de MySQL con permisos para realizar operaciones INSERT.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librerías:
  - Ethernet
  - MySQL_Connection
  - MySQL_Cursor  
• Servidor MySQL accesible por red.  
• Puerto MySQL 3306 disponible.  
• Credenciales válidas de acceso a la base de datos.  
• Monitor serial a 9600 baudios.  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Intermedio

Justificación:  
- Integra comunicación Ethernet con acceso directo a una base de datos MySQL.
- Ejecuta una consulta SQL de inserción desde un microcontrolador.
- Utiliza objetos de conexión y cursor para administrar la comunicación con el servidor.

====================================================