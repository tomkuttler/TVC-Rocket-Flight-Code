#include <Arduino.h>
#include <Wire.h>
#include "IMU.h"

enum State {
  LAUNCH_PAD_IDLE,
  ASCENT,
  DESCENT,
  LANDED
};

class StateMachine {
  public:
    StateMachine();
    void stateMachineLoop();
    
  private:
    State active_state;
};
