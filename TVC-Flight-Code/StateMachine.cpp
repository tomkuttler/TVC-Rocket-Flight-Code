#include "StateMachine.h"

StateMachine::StateMachine() {
  active_state = LAUNCH_PAD_IDLE; // default state
}

void StateMachine::stateMachineLoop() {
  switch (active_state) {
    case LAUNCH_PAD_IDLE:
      rocket.padIdle();
      // Detect lift off -> Ascent flight
      if (liftOffCheck()) {
        // Save the time of lift off
        rocket.flightStartTime = millis();
        active_state = ASCENT;
      }
      break;
    case ASCENT:
      // TVC active
      // Log Data
      // Detect max apogee -> Descent flight and eject Parachute
      if (maxApogeeCheck()) {
        active_state = DESCENT;
      }
      break;
    case DESCENT:
      // Log Data
      // Detect landing
      if (landedCheck()) {
        active_state = LANDED;
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
