====================================================
Rele.ino – Arduino
====================================================

Autor: Emiliano Cepeda  
Plataforma: Arduino  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
Rele.ino es un programa básico para Arduino que controla una salida digital utilizando el LED integrado de la placa como indicador. El programa alterna el estado de la salida cada segundo, generando un parpadeo continuo.

El programa sirve como práctica de:
- Configuración de pines digitales mediante pinMode().
- Control de salidas digitales mediante digitalWrite().
- Uso de retardos con delay().
- Implementación del ciclo principal loop().

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/Rele.ino  
    Programa principal de Arduino.
    Contiene:
    - setup() — configura LED_BUILTIN como salida.
    - loop() — enciende y apaga la salida cada segundo.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------

• Configuración de salida digital:  
  - LED_BUILTIN se establece como OUTPUT.

• Activación de la salida:  
  - digitalWrite(LED_BUILTIN, HIGH) enciende el LED integrado.

• Desactivación de la salida:  
  - digitalWrite(LED_BUILTIN, LOW) apaga el LED integrado.

• Temporización:  
  - Se utiliza delay(1000) para mantener cada estado durante 1 segundo.

• Funcionamiento continuo:  
  - El proceso se repite indefinidamente dentro de loop().

----------------------------------------------------
4. Recursos / Components necesarios
----------------------------------------------------

• Placa Arduino compatible con LED_BUILTIN.  
• LED integrado de la placa.  
• No requiere componentes externos ni módulos adicionales.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------

• Arduino IDE o entorno compatible con Arduino.  
• Placa Arduino correctamente configurada en el entorno de desarrollo.  
• Soporte para la constante LED_BUILTIN.

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------

Clasificación: Básico

Justificación:
- Utiliza únicamente configuración y control básico de una salida digital.
- La lógica está limitada a una secuencia de encendido, espera, apagado y espera.

====================================================