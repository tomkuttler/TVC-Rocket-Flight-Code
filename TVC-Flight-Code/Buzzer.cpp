#include "Buzzer.h"

Buzzer::Buzzer() {
  
}

void Buzzer::noSDCardAlert() {
  int slide = 5000;
  for (int i = 0; i <= 120; i++) {
    tone(BUZZER_PIN, slide); delay(10); noTone(BUZZER_PIN);
    slide = slide - 40;
  }
  noTone(BUZZER_PIN);
}

void Buzzer::tooLowOnBoardVoltageAlert() {
  for(int i = 0; i < 1000; i++) {    
    tone(BUZZER_PIN, 2000);
    delayMicroseconds(i);
    noTone(BUZZER_PIN);
    delayMicroseconds(i);    
  }
  noTone(BUZZER_PIN);
}
