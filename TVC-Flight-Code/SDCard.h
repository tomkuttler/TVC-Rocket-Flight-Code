#include <SD.h>
#include <SPI.h>

class SDCard {
  public:
    SDCard();
    
    void logData(float flightTime, float gyroX, float gyroY, float gyroZ, float accelerationX, float accelerationY, float accelerationZ, float orientationX, float orientationY, float orientationZ, float temperature, float pressure, float altitude, float yServo, float zServo, float voltage, String state);
    
  private:
    const int chipSelect = BUILTIN_SDCARD;
};
