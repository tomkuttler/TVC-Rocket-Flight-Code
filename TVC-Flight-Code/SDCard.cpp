#include "SDCard.h"

SDCard::SDCard() {
  if(!SD.begin(chipSelect)) {
    Serial.println("Error: The SD card failed to initialize, or is not present!");
  }

  File dataFile = SD.open("datalog.CSV", FILE_WRITE);

  // Write top description line
  dataFile.println("flightTime, gyros.x, gyros.y, gyros.z, acceleration.x, acceleration.y, acceleration.z, orientation.x, orientation.y, orientation.z, temperature, pressure, altitude, yServo orientation, zServo orientation, state");
  dataFile.close();
}

void SDCard::logData(float flightTime, float gyroX, float gyroY, float gyroZ, float accelerationX, float accelerationY, float accelerationZ, float orientationX, float orientationY, float orientationZ, float temperature, float pressure, float altitude, float yServo, float zServo, String state) {
  // Create file (or open it if it already exists)
  File dataFile = SD.open("datalog.CSV", FILE_WRITE);

  // If the file is available, write to it
  if (dataFile) {
    dataFile.print(flightTime);
    dataFile.print(",");
    dataFile.print(gyroX);
    dataFile.print(",");
    dataFile.print(gyroY);
    dataFile.print(",");
    dataFile.print(gyroZ);
    dataFile.print(",");
    dataFile.print(accelerationX);
    dataFile.print(",");
    dataFile.print(accelerationY);
    dataFile.print(",");
    dataFile.print(accelerationZ);
    dataFile.print(",");
    dataFile.print(orientationX);
    dataFile.print(",");
    dataFile.print(orientationY);
    dataFile.print(",");
    dataFile.print(orientationZ);
    dataFile.print(",");
    dataFile.print(temperature);
    dataFile.print(",");
    dataFile.print(pressure);
    dataFile.print(",");
    dataFile.print(altitude);
    dataFile.print(",");
    dataFile.print(yServo);
    dataFile.print(",");
    dataFile.print(zServo);
    dataFile.print(",");
    dataFile.println(state);
    
    dataFile.close();
  } else {
    // If the file can not be opened, pop up an error message
    Serial.println("Error: Can not open datalog.txt");
  }
}
