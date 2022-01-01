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

  // TODO: TVC ALGORITHM

  //----- TEST CODE -----
  // Print the angular velocity of the rocket on y and z axis
  Serial.print(gyros.y);
  Serial.print(", ");
  Serial.println(gyros.z);
}

void Rocket::maxApogee() {
  // TODO: EJECT PARACHUTE
}

void Rocket::descent() {
  // calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;
}
