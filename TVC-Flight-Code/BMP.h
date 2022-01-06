/*
 * Barometric Pressure & Altitude Sensor BMP280
 * https://www.adafruit.com/product/2651
 * 
 * Outputs the following data: temperature, athmospheric pressure and altitude (which is calculated with the pressure at sea level)
 */

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
