#include "StateMachine.h"

StateMachine::StateMachine() {
  activeState = LAUNCH_PAD_IDLE; // default state
}

void StateMachine::stateMachineLoop() {
  switch (activeState) {
    case LAUNCH_PAD_IDLE:
      rocket.padIdle();
      // Detect lift off -> Ascent flight
      if (liftOffCheck()) {
        // Save the time of lift off
        rocket.flightStartTime = millis();
        activeState = ASCENT;
      }
      break;
    case ASCENT:
      // TVC active
      // Log Data
      rocket.ascent();
      // Detect max apogee -> Descent flight and eject Parachute
      if (maxApogeeCheck()) {
        rocket.maxApogee();
        activeState = DESCENT;
      }
      break;
    case DESCENT:
      rocket.descent();
      // Log Data
      // Detect landing
      if (landedCheck()) {
        activeState = LANDED;
      }
      break;
    case LANDED:
      // Do nothing
      break;
  }
}

// Check if rocket has launched by looking at the acceleration on vertical axis (x-axis)
bool StateMachine::liftOffCheck() {
  if(rocket.acceleration.x < 2){
    return true;    
  }
  return false;
}

// Check if rocket has reached apogee by looking at the time it takes to reach apogee
bool StateMachine::maxApogeeCheck() {
  if (rocket.flightTime > 5) {
    return true;
  }
  return false;
}

// Check if rocket has landed by looking at the time it takes to land
bool StateMachine::landedCheck() {
  if (rocket.flightTime > 30) {
    return true;
  }
  return false;
}
