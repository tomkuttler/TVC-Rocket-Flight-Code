#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#include "IMU.h"

class Rocket {
  public:
    Rocket();
    Vector3 ypr; // roll, yaw and pitch in rad
    Vector3 gyros; // in rps, radians per second
    Vector3 accels; // in m/s^2 // x accel is vertical
    Vector3 orientation; // in Euler angles (deg)
}
