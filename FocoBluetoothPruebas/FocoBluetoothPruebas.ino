#include <SoftwareSerial.h>
//SoftwareSerial bt(rx,tx);
SoftwareSerial BT(7,8);
int incomingByte = 0;

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  if (BT.available() > 0) {
    incomingByte = BT.read();

    if(incomingByte == 'a') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
    }

    if(incomingByte == 'e') {
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    BT.print("I received: ");
    BT.println(incomingByte, DEC);
  }
}

