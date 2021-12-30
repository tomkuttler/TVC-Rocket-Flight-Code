#include <Arduino.h>
#include <Wire.h>

enum State {
  LAUNCH_PAD_IDLE,
  ASCENT,
  DESCENT,
  LANDED
};

State active_state;

void setup() {
  // put your setup code here, to run once:

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
