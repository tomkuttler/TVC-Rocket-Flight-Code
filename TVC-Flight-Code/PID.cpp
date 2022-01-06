/*
 * PID Controller, inspired by https://gist.github.com/bradley219/5373998
 */

#include "PID.h"

PID::PID(float Kp, float Ki, float Kd, float saturation) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->saturation = saturation;
}

float PID::update(float input) {
  // Calculate delata time
  currentTime = micros();
  deltaTime = (currentTime - previousTime) / 1000000.0f;

  // Calculate error
  error = setpoint - input;

  // Integral term
  errorIntegral += error * deltaTime;

  // Derivative term
  errorDerivative = (error - errorLastCycle) / deltaTime;

  // Calculate total output
  output = Kp * error + Ki * errorIntegral + Kd * errorDerivative;

  // Save current error and time for next cycle
  errorLastCycle = error;
  previousTime = currentTime;

  // Check if output is in saturation
  if (output > saturation) {
    output = saturation;
  } else if (output < -saturation) {
    output = -saturation;
  }

  return output;
}
