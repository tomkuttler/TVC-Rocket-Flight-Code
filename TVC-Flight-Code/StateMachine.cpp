#include "StateMachine.h"

StateMachine::StateMachine() {
  active_state = LAUNCH_PAD_IDLE; // default state
}

void StateMachine::stateMachineLoop() {
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
