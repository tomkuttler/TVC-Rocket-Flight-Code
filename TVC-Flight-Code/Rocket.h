#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#include "IMU.h"
#include "PID.h"

#define Y_SERVO_PIN 3           // Y Servo (y axis labeled on IMU) = Y Servo (labeled on pcb)
#define Z_SERVO_PIN 2           // Z Servo (z axis labeled on IMU) = X Servo (labeled on pcb)

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
    // TEST PID VALUES !!! (NOT SUITABLE FOR REAL FLIGHT)
    PID yPID = PID(0.5f, 0.1f, 0.5f, 10.0f);
    PID zPID = PID(0.5f, 0.1f, 0.5f, 10.0f);

    Servo yServo;
    Servo zServo;
    
    unsigned long currentTime = 0.0;
    unsigned long previousTime = 0.0;
    float deltaTime = 0.0f;
};
