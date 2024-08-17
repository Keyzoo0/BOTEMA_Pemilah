void setupLift(){
  pinMode(motorBL, OUTPUT);
  pinMode(motorAL , OUTPUT);
  pinMode(ENL, OUTPUT);
  digitalWrite(ENL , HIGH);
}


void kinematikLift(int lift_val){
  if(lift_val > 0){
  analogWrite(motorAL , lift_val);
  analogWrite(motorBL , 0);
  }
  else if(lift_val < 0){
  analogWrite(motorAL , 0);
  analogWrite(motorBL , abs(lift_val));
  }else{
  analogWrite(motorAL , 0);
  analogWrite(motorBL , 0);
  }
}