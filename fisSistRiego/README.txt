====================================================
fisSistRiego – Arduino
====================================================

Autor: Emiliano Cepeda   
Plataforma: Arduino / Embedded  
Lenguaje: C++ (Arduino Sketch)  

----------------------------------------------------
1. Overview
----------------------------------------------------
fisSistRiego es un sketch para Arduino que implementa un sistema de riego basado en lógica difusa (Fuzzy Inference System). El programa toma tres entradas principales: hora fija, humedad del suelo y temperatura ambiente mediante un sensor DHT11, y calcula una salida difusa que representa una recomendación de riego o duración de riego.

La aplicación sirve como práctica de:
- Sistemas de inferencia difusa en Arduino.
- Lectura de sensores analógicos y digitales.
- Uso de funciones de membresía triangulares y trapezoidales.
- Defuzzificación por centroide.
- Automatización de decisiones basada en condiciones ambientales.

----------------------------------------------------
2. Estructura de Archivos
----------------------------------------------------

/fisSistRiego.ino  
    Contiene toda la lógica principal del proyecto:
    - Inclusión de fis_header.h y DHT.h.
    - Configuración del sensor DHT11.
    - Lectura de humedad por entrada analógica.
    - Lectura de temperatura por sensor DHT11.
    - Evaluación del sistema difuso mediante fis_evaluate().
    - Impresión de valores de entrada y salida por Serial.
    - Definición completa de funciones de membresía, reglas, rangos y defuzzificación.

/fis_header.h  
    Archivo de soporte para el sistema difuso:
    - Definición de FIS_TYPE.
    - Resolución de la evaluación difusa.
    - Constantes FIS_MIN, FIS_MAX.
    - Tipos de función para membresías y operaciones sobre arreglos.

----------------------------------------------------
3. Funcionalidad Clave
----------------------------------------------------
• Sistema difuso de riego  
  - Procesa tres entradas: hora, humedad y temperatura.  
  - Evalúa reglas difusas para generar una salida numérica asociada a la duración o intensidad del riego.

• Lectura de sensores  
  - El sensor DHT11 obtiene la temperatura.  
  - La humedad se lee mediante una entrada analógica y se normaliza con map().

• Defuzzificación por centroide  
  - La salida del sistema se obtiene por el método del centroide para producir un valor continuo.

• Funciones de membresía  
  - Incluye funciones triangulares (fis_trimf) y trapezoidales (fis_trapmf) para modelar conjuntos difusos.

• Base de reglas extensa  
  - El sistema contiene múltiples reglas y conjuntos de membresía para tomar decisiones más precisas sobre el riego.

----------------------------------------------------
4. Recursos / Componentes necesarios
----------------------------------------------------
Para que el proyecto funcione correctamente se requiere:
- Placa Arduino compatible.
- Sensor DHT11 conectado al pin A1 según el código.
- Sensor de humedad conectado al pin A0.
- Salida de control conectada al pin 3 si se desea activar un actuador o relé.
- Archivo de soporte fis_header.h incluido en el proyecto.
- Monitor serial configurado a 9600 baudios.

----------------------------------------------------
5. Requerimientos
----------------------------------------------------
• Arduino IDE  
• Librería:
  - DHT  
• Archivo auxiliar:
  - fis_header.h  
• Conexión correcta de sensores analógicos y digitales  
• Monitor serial a 9600 baudios  

----------------------------------------------------
6. Nivel del Proyecto
----------------------------------------------------
Clasificación: Avanzado

Justificación:  
- Implementa un sistema de inferencia difusa completo con múltiples entradas, múltiples funciones de membresía y una gran cantidad de reglas.  
- Utiliza defuzzificación y soporte matemático especializado para tomar decisiones automáticas.  
- Integra sensores y lógica de control con una estructura más compleja que la de un proyecto básico o intermedio.  
- Es un ejemplo claro de aplicación práctica de control inteligente en Arduino.


====================================================