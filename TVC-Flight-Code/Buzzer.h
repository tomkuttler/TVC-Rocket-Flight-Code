/*
 * Piezo buzzer
 * 
 * Plays an alarm if no SD-Card is inserted into the Flight Controller or the on-board voltage is too low
 */

#include <Arduino.h>

#define BUZZER_PIN 36

class Buzzer {
  public:
    Buzzer();

    void noSDCardAlert();
    void tooLowOnBoardVoltageAlert();
};
