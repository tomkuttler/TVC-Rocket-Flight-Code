/*
 * TVC-Flight-Code
 * 
 * @version 0.7
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
