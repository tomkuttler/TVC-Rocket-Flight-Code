/*
 * Voltage divider
 * 
 * Calculates the on-board voltage by using a voltage divider connected to an analoge input pin of the Teensy 4.1
 */

#include <Arduino.h>

#define VOLTAGEDIVIDER_PIN 38

class VoltageDivider {
  public:
    VoltageDivider();
    float getBoardVoltage();
};
