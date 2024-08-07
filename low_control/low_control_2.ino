#include "variabel.h"

//=========================Main Program====================================
void setup() {
  Serial.begin(9600);
  initialize_motor();
  init_timer();
  // EncoderInit();
}

void loop() {
  readSerial();
  //pwm[1] = -1;pwm[0] = -1;
  //pwm[2] = 1;pwm[3] = 1;
  readEncoder ();
  if(ovf == true){
    computeSpeed();
    computePosition();
    ovf = false;
  }
  //ForwardInverseKinematic();
}
