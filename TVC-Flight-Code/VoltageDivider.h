#include <Arduino.h>

#define VOLTAGEDIVIDER_PIN 38

class VoltageDivider {
  public:
    VoltageDivider();
    float getBoardVoltage();
};
