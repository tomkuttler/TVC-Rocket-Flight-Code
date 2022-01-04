#include "BMP.h"

BMP::BMP() {
  if (!bmp.begin()) {
    Serial.println("ERROR: BMP280 initialisation failed!");
  }

  // Default settings from datasheet
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

float BMP::readTemperature() {
  return bmp.readTemperature();
}

float BMP::readPressure() {
  return bmp.readPressure();
}

float BMP::readAltitude(float seaLevelhPa) {
  return bmp.readAltitude(seaLevelhPa);
}
