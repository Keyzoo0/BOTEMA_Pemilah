//=================== Motor PG36 maka Set Frekuensi PWM ke divisor 1============== 
void setPwmFrequency(int pin, int divisor) {
/*
jika menurunkan pwm pin 2 , 13 maka akan menurunkan peforma 
1 	 31372.55 Hz    <- PG36 Frekuensi PWM
2	   3921.16  Hz
3	   490.20    Hz   <--DEFAULT Diecimila bootloader
4	   122.55    Hz
5	   30.610    Hz	

*/

  byte mode;
      switch(divisor) {
      case 1: mode = 0x01; break;
      case 2: mode = 0x02; break;
      case 3: mode = 0x03; break;
      case 4: mode = 0x04; break;
      case 5: mode = 0x05; break;
      case 6: mode = 0x06; break;
      case 7: mode = 0x07; break;
      default: return;
      }
      
        switch(pin) {	  
      case 2:  TCCR3B = TCCR3B  & 0b11111000 | mode; break;
      case 3:  TCCR3B = TCCR3B  & 0b11111000 | mode; break;
      case 4:  TCCR0B = TCCR0B  & 0b11111000 | mode; break;
      case 5:  TCCR3B = TCCR3B  & 0b11111000 | mode; break;
      case 6:  TCCR4B = TCCR4B  & 0b11111000 | mode; break;
      case 7:  TCCR4B = TCCR4B  & 0b11111000 | mode; break;
      case 8:  TCCR4B = TCCR4B  & 0b11111000 | mode; break;
      case 9:  TCCR2B = TCCR0B  & 0b11111000 | mode; break;
      case 10: TCCR2B = TCCR2B  & 0b11111000 | mode; break;
      case 11: TCCR1B = TCCR1B  & 0b11111000 | mode; break;  
      case 12: TCCR1B = TCCR1B  & 0b11111000 | mode; break;  
      case 13: TCCR0B = TCCR0B  & 0b11111000 | mode; break;
      default: return;
    }

}

//======================== Forward Inverse Kinematic =============================

void initialize_motor(){
pinMode(MOTOR1A,OUTPUT); 
pinMode(MOTOR1B,OUTPUT); 
pinMode(MOTOR2A,OUTPUT); 
pinMode(MOTOR2B,OUTPUT); 
pinMode(MOTOR3A,OUTPUT); 
pinMode(MOTOR3B,OUTPUT); 
pinMode(MOTOR3A,OUTPUT); 
pinMode(MOTOR3B,OUTPUT);
pinMode(MOTOR4A,OUTPUT); 
pinMode(MOTOR4B,OUTPUT); 
pinMode(ENA1,OUTPUT);
pinMode(ENA2,OUTPUT);
pinMode(ENA3,OUTPUT);
pinMode(ENA4,OUTPUT);
pinMode(IS1,OUTPUT);
pinMode(IS2,OUTPUT);
pinMode(IS3,OUTPUT);
pinMode(IS4,OUTPUT);

setPwmFrequency(MOTOR1A,1); 
setPwmFrequency(MOTOR1B,1); 
setPwmFrequency(MOTOR2A,1); 
setPwmFrequency(MOTOR2B,1); 
setPwmFrequency(MOTOR3A,1); 
setPwmFrequency(MOTOR3B,1); 
setPwmFrequency(MOTOR3A,1); 
setPwmFrequency(MOTOR3B,1);
setPwmFrequency(MOTOR4A,1); 
setPwmFrequency(MOTOR4B,1); 

}


    
void kinMotor(int x, int y, int th) {
  int teta = LengthAlpha*d2r(th) / 2 ;
  pwm[3] = lambda * (cos(d2r(315))*x + sin(d2r(315))*y + teta);
  pwm[2] = lambda * (cos(d2r(225))*x + sin(d2r(225))*y + teta);
  pwm[1] = lambda * (cos(d2r(135))*x + sin(d2r(135))*y + teta);
  pwm[0] = lambda * (cos(d2r(45))*x + sin(d2r(45))*y + teta);
  
  for(int i = 0 ; i < 4 ; i++){
    Serial.print("PWM" + String(i) + " : ");
    Serial.print(pwm[i]);
    Serial.print(" | ");
  } Serial.println();

  set_pwm(M1, pwm[0]);
  set_pwm(M2, pwm[1]);
  set_pwm(M3, pwm[2]);
  set_pwm(M4, pwm[3]);
  
}


void set_pwm(byte _chann, int _val) {
  switch (_chann) {
    case M1:
      if (_val > 0){
      analogWrite(MOTOR1A, _val);
      analogWrite(MOTOR1B, 0);
      digitalWrite(ENA1 , HIGH);
      }else if(_val < 0 ){
      analogWrite(MOTOR1A, 0);
      analogWrite(MOTOR1B, abs(_val));
      digitalWrite(ENA1 , HIGH);
      }else{
      digitalWrite(ENA1 , LOW);
      }
      break;
    
    case M2:
      if (_val > 0){
      analogWrite(MOTOR2A, _val);
      analogWrite(MOTOR2B, 0);
      digitalWrite(ENA2 , HIGH);
      }else if(_val < 0 ){
      analogWrite(MOTOR2A, 0);
      analogWrite(MOTOR2B, abs(_val) );
      digitalWrite(ENA2 , HIGH);
      }else{
      digitalWrite(ENA2 , LOW);
      }
      break;

    case M3:
      if (_val > 0){
      analogWrite(MOTOR3A, _val);
      analogWrite(MOTOR3B, 0);
      digitalWrite(ENA3 , HIGH);
      }else if(_val < 0 ){
      analogWrite(MOTOR3A, 0);
      analogWrite(MOTOR3B, abs(_val) );
      digitalWrite(ENA3 , HIGH);
      }else{
      digitalWrite(ENA3 , LOW);
      }
      break;

    case M4:
      if (_val > 0){
      analogWrite(MOTOR4A, _val);
      analogWrite(MOTOR4B, 0);
      digitalWrite(ENA4 , HIGH);
      }else if(_val < 0 ){
      analogWrite(MOTOR4A, 0);
      analogWrite(MOTOR4B, abs(_val) );
      digitalWrite(ENA4 , HIGH);
      }else{
      digitalWrite(ENA4 , LOW);
      }
      break;
  
      }
}

void ForwardInverseKinematic(){
    
    atanVal = atan2(z , 0);
    atanVal = (atanVal * 180 / PI);
    kinMotor(y, -x, (atanVal*-1) * 100);
}


