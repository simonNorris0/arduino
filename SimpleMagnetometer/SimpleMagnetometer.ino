#include "Arduino_BMI270_BMM150.h"
float x, y, z, ledvalue;

void setup() {
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    while (1);
  }
}

void loop() {
  // read magnetic field in all three directions
  IMU.readMagneticField(x, y, z);

  if (x < 0)
    ledvalue = -(x);
  else
    ledvalue = x;

  analogWrite(LED_BUILTIN, ledvalue);
  delay(500);
}
