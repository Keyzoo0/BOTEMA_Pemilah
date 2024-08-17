void setup_vertical() {

  pinMode(MOTORAVB, OUTPUT);
  pinMode(MOTORBVB, OUTPUT);
 pinMode(ENVB, OUTPUT);
  digitalWrite(ENVB , HIGH);
}

void kinematik_vertical(int ver_val) {
  if (ver_val > 0) {
    analogWrite(MOTORAVB, ver_val);
    analogWrite(MOTORBVB, 0);
  } 
  else if(ver_val < 0) {
    analogWrite(MOTORBVB, abs(ver_val));
    analogWrite(MOTORAVB, 0);
  } else {
    analogWrite(MOTORAVB, 0);
    analogWrite(MOTORBVB, 0);
  }
}