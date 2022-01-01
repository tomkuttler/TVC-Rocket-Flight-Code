#include "Rocket.h"

Rocket::Rocket() {
  
}

void Rocket::padIdle() {
  // update acceleration for lift off check
  acceleration = imu.getAcceleration();
}

void Rocket::ascent() {
  // update gyro values
  gyros = imu.getGyros();

  // calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;

  // TVC ALGORITHM
}

void Rocket::maxApogee() {
  // EJECT PARACHUTE
}

void Rocket::descent() {
  // calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;
}
