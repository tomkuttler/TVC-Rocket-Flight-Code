#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>
#include "VectorDefinition.h"

class IMU {
  public:
    IMU();
    Vector3 getGyros();
    Vector3 getAcceleration();
    Vector3 getOrientation();
    
  private:
    Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire1);
    sensors_event_t angVelocityData;
    sensors_event_t linearAccelData;
    sensors_event_t orientationData;
};
