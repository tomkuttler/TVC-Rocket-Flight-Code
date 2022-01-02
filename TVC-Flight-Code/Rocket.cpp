#include "Rocket.h"

Rocket::Rocket() {

}

void Rocket::padIdle() {
  // Update acceleration for lift off check
  acceleration = imu.getAcceleration();
}

void Rocket::ascent() {
  // Calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;

  // ----- TVC ALGORITHM -----
  // Calculate delta time
  currentTime = micros();
  deltaTime = (currentTime - previousTime) / 1000000.0f;

  // Update gyro values
  gyros = imu.getGyros();

  // Integrate angular velocity for relative orientation (roll, pitch and yaw) in rad
  relativeOrientation += gyros * deltaTime;

  // Send the yaw and pitch to their respective PID Controller and recieve output
  float yPIDoutput = yPID.update(relativeOrientation.y);
  float zPIDoutput = zPID.update(relativeOrientation.z);

  // Convert the PID output (orientation of motor mount) to servo position (relative orientation of servo horn)
  float yServoRelPosition = yPIDoutput * 3; // 3 = servo to motor mount ratio, 3 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER
  float zServoRelPosition = zPIDoutput * 3;

  // Save current time for next cycle
  previousTime = currentTime;
  
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
