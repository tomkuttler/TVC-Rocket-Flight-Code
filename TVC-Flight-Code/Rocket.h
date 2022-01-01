#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#include "IMU.h"

class Rocket {
  public:
    Rocket();
    Vector3 ypr; // roll, pitch and yaw in rad
    Vector3 gyros; // in rps, radians per second
    Vector3 acceleration; // in m/s^2 // x accel is vertical
    Vector3 orientation; // in Euler angles (deg)
    float flightTime = 0.0f; // in s
    float flightStartTime = 0.0f; // in ms
    void padIdle();
    void ascent();
    void maxApogee();
    void descent();
    void landed();

  private:
    IMU imu;
};
