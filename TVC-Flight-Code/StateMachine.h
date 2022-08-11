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

#define LIFT_THRESHOLD -2   // Acceleration on vertical axis/x-axis (negative value = acceleration upwards) (in m/s^2)

// Calculated with a flight simulation in AeroVECTOR https://github.com/GuidodiPasquo/AeroVECTOR
#define TIME_TO_APOGEE 4     // Time from start until rocket reaches max apogee and parachute will be ejected (in s)
#define TIME_TO_LANDING 30   // Time from start until rocket lands (in s)

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
