#include <Wire.h>
byte estado1 = 0;
//byte estado2 = 1;

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(1);
  Wire.write(estado1);
  Wire.endTransmission();
  delay(1000);


  //Wire.beginTransmission(2);
  //Wire.write(estado2);
  //Wire.endTransmission();
  //delay(1000);

  estado1 = (estado1 == 0) ? 1 : 0;
  //estado2 = (estado2 == 0) ? 1 : 0;
}
