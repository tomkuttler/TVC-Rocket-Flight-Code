#include "Rocket.h"

Rocket::Rocket() {
  // Attach and initialize servos
  yServo.attach(Y_SERVO_PIN);
  zServo.attach(Z_SERVO_PIN);
  parachuteServo.attach(PARACHUTE_SERVO_PIN);

  yServo.write(Y_SERVO_MIDDLE);
  zServo.write(Z_SERVO_MIDDLE);
  parachuteServo.write(PARACHUTE_CLOSED);

  // Check on-board voltage
  if(voltageDivider.getBoardVoltage() < MIN_VOLTAGE) {
    Serial.println("Error: on-board voltage too low");
    while (true) {
      // on-board voltage to low, so stay stuck here
    }
  }
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

  // Convert the relative orientation in rad to deg
  yPIDoutput = yPIDoutput * RAD2DEG;
  zPIDoutput = zPIDoutput * RAD2DEG;

  // Convert the PID output (orientation of motor mount) to servo position (relative orientation of servo horn)
  float yServoRelPosition = yPIDoutput * SERVO_RATIO;
  float zServoRelPosition = zPIDoutput * SERVO_RATIO;

  // Check if the servo relative positions are greater than the max motor mount rotation
  // The motor mount can only be rotated 10 deg => the servos are allowed to rotate 30 deg
  if(yServoRelPosition > MAX_SERVO_ROTATION) {
    yServoRelPosition = MAX_SERVO_ROTATION;
  }
  else if(yServoRelPosition < -MAX_SERVO_ROTATION) {
    yServoRelPosition = -MAX_SERVO_ROTATION;
  }

  if(zServoRelPosition > MAX_SERVO_ROTATION) {
    zServoRelPosition = MAX_SERVO_ROTATION;
  }
  else if(zServoRelPosition < -MAX_SERVO_ROTATION) {
    zServoRelPosition = -MAX_SERVO_ROTATION;
  }

  // Set the position of the servos
  // To get the absolute position of the servo horns, the middle servo horn position is added to the relative orientation
  yServo.write(yServoRelPosition + Y_SERVO_MIDDLE);
  zServo.write(zServoRelPosition + Z_SERVO_MIDDLE);

  // Save current time for next cycle
  previousTime = currentTime;

  // ----- DATA LOGGING -----
  acceleration = imu.getAcceleration();
  orientation = imu.getOrientation();

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float altitude = bmp.readAltitude(SEA_LEVEL_PRESSURE);
  
  sdCard.logData(flightTime, gyros.x, gyros.y, gyros.z, acceleration.x, acceleration.y, acceleration.z, orientation.x, orientation.y, orientation.z, temperature, pressure, altitude, yServoRelPosition + Y_SERVO_MIDDLE, zServoRelPosition + Z_SERVO_MIDDLE, "ASCENT");

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
  // Eject Parachute
  parachuteServo.write(PARACHUTE_EJECT);

  // Set servos to middle position
  yServo.write(Y_SERVO_MIDDLE);
  zServo.write(Z_SERVO_MIDDLE);
}

void Rocket::descent() {
  // Calculate flight time in s
  flightTime = (millis() - flightStartTime) / 1000.0f;

  // ----- DATA LOGGING -----
  acceleration = imu.getAcceleration();
  orientation = imu.getOrientation();

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float altitude = bmp.readAltitude(SEA_LEVEL_PRESSURE);
  
  sdCard.logData(flightTime, gyros.x, gyros.y, gyros.z, acceleration.x, acceleration.y, acceleration.z, orientation.x, orientation.y, orientation.z, temperature, pressure, altitude, Y_SERVO_MIDDLE, Z_SERVO_MIDDLE, "DESCENT");

}
