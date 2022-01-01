#include "IMU.h"

IMU::IMU() {
  Wire.begin();
  Wire.setClock(400000);
  if (!bno.begin()) {
    Serial.println("ERROR: BNO055 initialisation failed!");
  }
}

Vector3 IMU::getGyros() {
  bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  return angVelocityData.gyro;
}

Vector3 IMU::getAcceleration() {
  bno.getEvent(&linearAccelerationData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  Vector3 Vector(linearAccelerationData.acceleration.x, linearAccelerationData.acceleration.y, linearAccelerationData.acceleration.z);
  return Vector;
}

Vector3 IMU::getOrientation() {
  bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  return orientationData.orientation;
}
