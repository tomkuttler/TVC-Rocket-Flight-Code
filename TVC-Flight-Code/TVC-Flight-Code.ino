#include "StateMachine.h"

StateMachine *stateMachine;

void setup() {
  stateMachine = new StateMachine();
}

void loop() {
  stateMachine->stateMachineLoop();
}
