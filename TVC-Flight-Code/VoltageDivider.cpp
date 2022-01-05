#include "VoltageDivider.h"

VoltageDivider::VoltageDivider() {
  
}

float VoltageDivider::getBoardVoltage() {
  int voltageDividerValue = analogRead(VOLTAGEDIVIDER_PIN);

  //        R1 + R2
  // Vin = --------- * Vout
  //          R2
             
  float voltage = ((1000000 + 89000)/89000)*(voltageDividerValue * (5.0 / 1023.0));
  return voltage;
}
