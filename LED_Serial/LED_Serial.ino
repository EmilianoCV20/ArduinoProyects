// C++ code

int incomingByte = 0;	// for incoming serial data

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
  	incomingByte = Serial.read();
    
    if(incomingByte == 97) {
  		digitalWrite(LED_BUILTIN, HIGH);
  		delay(1000);
    }
    
    
  	if(incomingByte == 101) {
  		digitalWrite(LED_BUILTIN, LOW);
  		delay(1000);
    }
    
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
	}
}
