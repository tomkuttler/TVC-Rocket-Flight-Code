#include <Arduino.h>

#define BUZZER_PIN 36

class Buzzer {
  public:
    Buzzer();

    void noSDCardAlert();
    void tooLowOnBoardVoltageAlert();
};
