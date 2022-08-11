/*
 * TVC-Flight-Code
 * 
 * This is the source code for a software implementation of thrust vector control (TVC) for model rockets. 
 * The software consists of a state machine and PID control loops to adjust the orientation of the rocket during its powered ascent.
 * 
 * @version 0.9
 * @author Tom Kuttler
 * @GitHub https://github.com/tomkuttler/TVC-Rocket-Flight-Code
 */

#include "StateMachine.h"

StateMachine *stateMachine;

void setup() {
  stateMachine = new StateMachine();
}

void loop() {
  stateMachine->stateMachineLoop();
}
