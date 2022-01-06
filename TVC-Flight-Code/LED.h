/*
 * Common Anode LED
 * 
 * Changes color according to the state the Flight Controller is currently in
 * 
 * STATE           | COLOR
 * ----------------|--------
 * LAUNCH_PAD_IDLE |
 * ASCENT          |
 * DESCENT         |
 * LANDED          |
 */

#include <Arduino.h>

#define R_LED 41
#define G_LED 40
#define B_LED 39

class LED {
  public:
    LED();
    void red();
    void green();
    void blue();
    void purple();
    void off();     
};
