#include "main_code.h"
#include "pc_libs.h"



void setup(void) {
  //Serial.begin(19200);
  mainSetup();
}

void loop() {
  mainLoop();
  // Serial.println(getRandomNumber(1, 100));
  // Serial.println(analogRead(A0));
  // delay(1000);

}


