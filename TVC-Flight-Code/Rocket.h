#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#include "IMU.h"
#include "BMP.h"
#include "PID.h"

#define Y_SERVO_PIN 3               // Y Servo (y axis labeled on IMU) = Y Servo (labeled on pcb)
#define Z_SERVO_PIN 2               // Z Servo (z axis labeled on IMU) = X Servo (labeled on pcb)

// 90 = middle servo horn position, 90 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER (90 IS NOT THE EXACT MIDDLE POSITION)
#define Y_SERVO_MIDDLE 90           // Y Servo horn vertical position (motor mount is vertical)
#define Z_SERVO_MIDDLE 90           // Z Servo horn vertical position (motor mount is vertical)

// 3 = servo to motor mount ratio, 3 is a ROUGH ESTIMETE, NEEDS TO BE EVALUATED CLOSER
#define SERVO_RATIO 3               // Servo horn to motor mount ratio (if horn is turned 1 deg, motor mount will turn 3 deg)
#define MAX_SERVO_ROTATION 30       // Motor mount can only be rotated 10 deg => the servos are allowed to rotate 30 deg

#define PARACHUTE_SERVO_PIN 5       // Parachute Servo = Servo 3 (labeled on pcb)
#define PARACHUTE_CLOSED 0          // Position of the parachute servo before ejection (in deg)
#define PARACHUTE_EJECT 175         // Position of the parachute servo after ejection (in deg)

#define DEG2RAD 0.01745329251f      // Convert degrees to radians by multiplying with this number
#define RAD2DEG 57.2957795131f      // Convert radians to degrees by multiplying with this number

#define SEA_LEVEL_PRESSURE 1013.25  // Standard atmospheric pressure at sea level (in hPa)

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
    BMP bmp;
    
    // TEST PID VALUES !!! (NOT SUITABLE FOR REAL FLIGHT)
    PID yPID = PID(0.5f, 0.1f, 0.5f, 10.0f);
    PID zPID = PID(0.5f, 0.1f, 0.5f, 10.0f);

    Servo yServo;
    Servo zServo;
    Servo parachuteServo;
    
    unsigned long currentTime = 0.0;
    unsigned long previousTime = 0.0;
    float deltaTime = 0.0f;
};
