//Codigo c++
int motorA1 = 3; // Pin para controlar el motor A (dirección 1)
int motorA2 = 4; // Pin para controlar el motor A (dirección 2)
int motorB1 = 5; // Pin para controlar el motor B (dirección 1)
int motorB2 = 6; // Pin para controlar el motor B (dirección 2)

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == 'A') {
      moverDerecha();  // Adelante
    } else if (command == 'R') {
      moverIzquierda(); // Reversa
    } else if (command == 'D') {
      moverDerechaIzquierda(); // Motor A derecha y Motor B izquierda
    } else if (command == 'I') {
      moverIzquierdaDerecha(); // Motor A izquierda y Motor B derecha
    } else if (command == 'N') {
      detenerMotores();  // Detener o Neutral
    }
  }
}

void detenerMotores() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void moverDerecha() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moverIzquierda() {

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverDerechaIzquierda() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moverIzquierdaDerecha() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}
