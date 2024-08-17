#include "variabel.h"

//=========================Main Program====================================
void setup(){
  Serial.begin(9600);
  initialize_motor();
  setupLift();
}

void loop(){
  readSerial();
  ForwardInverseKinematic();
  kinematikLift(l);
}
