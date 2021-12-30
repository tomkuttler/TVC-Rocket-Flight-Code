#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>

#include "VectorDefinition.h"

enum State {
  LAUNCH_PAD_IDLE,
  ASCENT,
  DESCENT,
  LANDED
};

State active_state;

// Sensors

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire1);

void setup() {
  // Sensor setup
  Wire.begin();
  Wire.setClock(400000);
  if(!bno.begin()) {
    Serial.println("ERROR: BNO055 initialisation failed!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  switch (active_state) {
    case LAUNCH_PAD_IDLE:
      // Detect lift off -> Ascent flight
      if (true) {
        active_state = ASCENT;        
      }
      break;
    case ASCENT:
      // TVC active
      // Log Data
      // Detect max apogee -> Descent flight and eject Parachute
      if (true) {
        active_state = DESCENT;
      }
      break;
    case DESCENT:
      // Log Data
      // Detect landing
      if (true) {
        active_state = LANDED;
      }
      break;
    case LANDED:
      // Do nothing
      break;
  }
}
