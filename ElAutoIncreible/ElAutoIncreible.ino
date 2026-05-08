// C++ code
//
int LED = 13;
int LEDM = 4;
void setup()
{
  for (int i = LED; i>= LEDM ; i--) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  //IDA
  for (int i = LED; i >= LEDM; i--){
  	digitalWrite(i, HIGH);//Manda 5 volts
    digitalWrite(i+1, HIGH);
  	delay(200); // Espera por 200 milisegundos
  	digitalWrite(i, LOW); //Apagado
    digitalWrite(i+1, LOW);
  	delay(200); // Espera por 0.2 segundos
  }
  //Vuelta
  for (int i = LEDM; i <= LED; i++){
  	digitalWrite(i-1, HIGH);
  	digitalWrite(i, HIGH);//Manda 5 volts
  	delay(200); // Espera por 200 milisegundos
    digitalWrite(i-1, LOW);
  	digitalWrite(i, LOW); //Apagado
  	delay(200); // Espera por 0.2 segundos
  }
  
}
