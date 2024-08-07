ISR(TIMER5_OVF_vect){
  ovf = true; 
  TCNT5 = tcntReset;
}

void init_timer(){
  TCCR5A = 0;
  TCCR5B = (0 << CS52) | (1 << CS51) | (1 << CS50);
  TIMSK5 = (1 << TOIE5);
  TCNT5 = tcntReset;
}

float d2r(int degree){
  float radians = degree * 0.0174533;
  return radians;
}
