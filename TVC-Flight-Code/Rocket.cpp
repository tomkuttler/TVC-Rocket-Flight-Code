#include "Rocket.h"

Rocket::Rocket() {
  // Attach and initialize servos
  yServo.attach(Y_SERVO_PIN);
  zServo.attach(Z_SERVO_PIN);

  yServo.write(90); // 90 = middle servo horn position, 90 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER (90 IS NOT THE EXACT MIDDLE POSITION)
  zServo.write(90); // 90 = middle servo horn position, 90 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER (90 IS NOT THE EXACT MIDDLE POSITION)
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

  // Check if the servo relative positions are greater than the max motor mount rotation
  // The motor mount can only be rotated 10 deg => the servos are allowed to rotate 30 deg
  if(yServoRelPosition > 30) {
    yServoRelPosition = 30;
  }
  else if(yServoRelPosition < -30) {
    yServoRelPosition = -30;
  }

  if(zServoRelPosition > 30) {
    zServoRelPosition = 30;
  }
  else if(zServoRelPosition < -30) {
    zServoRelPosition = -30;
  }

  // Set the position of the servos
  // To get the absolute position of the servo horns, the middle servo horn position is added to the relative orientation
  yServo.write(yServoRelPosition + 90); // 90 = middle servo horn position, 90 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER (90 IS NOT THE EXACT MIDDLE POSITION)
  zServo.write(zServoRelPosition + 90);

  // Save current time for next cycle
  previousTime = currentTime;
  
  // ----- TEST CODE -----
  // Print the angular velocity of the rocket on y and z axis and the relative servo orientation
  Serial.print("Gyros:");
  Serial.print(gyros.y);
  Serial.print(", ");
  Serial.print(gyros.z);
  Serial.print("Servo rel pos:");
  Serial.print(yServoRelPosition);
  Serial.print(", ");
  Serial.println(zServoRelPosition);
}

void Rocket::maxApogee() {
  // TODO: EJECT PARACHUTE
}

void Rocket::descent() {
  // Calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;
}
