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
