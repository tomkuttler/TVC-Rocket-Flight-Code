/*
 * State Machine
 * 
 * The code is divided into four states:
 * 
 * LAUNCH_PAD_IDLE
 *   Check the acceleration of the rocket on vertical axis
 * ASCENT
 *   Thrust vector controle is active
 *   Flight data is logged to SD-Card    ‾\
 * DESCENT                                 | Eject parachute
 *   Flight data is logged to SD-Card   <-/
 * LANDED
 *   No active code (computer waiting to be turned off)
 */

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
