#include <SoftwareSerial.h>
SoftwareSerial BT(7,8);
void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()>0)
  {
    Serial.write(BT.read());
  }
  if(Serial.available()>0)
  {
    BT.write(Serial.read());
  }

}
