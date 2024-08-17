#include "variabel.h"

void setup() {
  setup_serial();
  setup_vacum();
  setup_slider();
  setup_vertical();
}

void loop() {
  readSerial();
  kinematik_vacum(z);
  kinematik_vertical(y);
  kinematik_slide(x);
}
 