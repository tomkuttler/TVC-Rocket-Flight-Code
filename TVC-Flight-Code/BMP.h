#include <Adafruit_BMP280.h>
#include <Wire.h>

class BMP {
  public:
    BMP();
    
    float readTemperature();
    float readPressure();
    float readAltitude(float seaLevelhPa);

  private:
    Adafruit_BMP280 bmp;
};
