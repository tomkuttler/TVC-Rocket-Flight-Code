#include <Arduino.h>
#include <Wire.h>
#include "Rocket.h"

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
    bool liftOffCheck();
    bool maxApogeeCheck();
    bool landedCheck();
    
  private:
    Rocket rocket;
    State activeState;
};
