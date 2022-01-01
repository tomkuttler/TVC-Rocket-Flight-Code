#include "Rocket.h"

Rocket::Rocket() {

}

void Rocket::padIdle() {
  // Update acceleration for lift off check
  acceleration = imu.getAcceleration();
}

void Rocket::ascent() {
  // Update gyro values
  gyros = imu.getGyros();

  // Calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;

  // Calculate delta time
  currentTime = micros();
  deltaTime = (currentTime - previousTime) / 1000000.0f;

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
  // Calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;
}
