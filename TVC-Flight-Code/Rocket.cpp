#include "Rocket.h"

Rocket::Rocket() {
  
}

void Rocket::padIdle() {
  // update acceleration for lift off check
  accels = imu.getAcceleration();
}

// FLIGHT TIME NEEDS TO BE CALCULATED IN ASCENT FUNCTION!!!
