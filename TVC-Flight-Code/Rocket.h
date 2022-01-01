#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#include "IMU.h"

class Rocket {
  public:
    Rocket();
    
    // Angular Velocity Vector
    // Three axis of rotation speed in radians per second (rad/s)
    Vector3 gyros;

    // Acceleration Vector
    // Three axis of acceleration (gravity + linear motion) in m/s^2
    Vector3 acceleration;

    // Absolute Orientation Vector
    // Three axis orientation data based on a 360° sphere (Euler Vector in deg)
    Vector3 orientation;

    // Relative Orientation Vector
    // Three axis orientation data (roll, pitch and yaw) in rad
    Vector3 relativeOrientation;
    
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
