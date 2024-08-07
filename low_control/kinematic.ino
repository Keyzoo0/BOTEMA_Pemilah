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

void computePosition(){ // forward kinematic
  float xdot = 0, ydot = 0, thdot = 0;
  xdot = r_wheel * ((cos(th)*(cos(d2r(45.))*rpm[0] + cos(d2r(135.)) * rpm[1] + cos(d2r(-135.)) * rpm[2] + cos(d2r(-45.))* rpm[3])) + (sin(th)*(sin(d2r(45))*rpm[0] + sin(d2r(135)) * rpm[1] + sin(d2r(-135)) * rpm[2] + sin(d2r(-45))* rpm[3])));
  ydot = r_wheel * ((-sin(th)*(cos(d2r(45.))*rpm[0] + cos(d2r(135.)) * rpm[1] + cos(d2r(-135.)) * rpm[2] + cos(d2r(-45))* rpm[3])) + (cos(th)*(sin(d2r(45))*rpm[0] + sin(d2r(135)) * rpm[1] + sin(d2r(-135)) * rpm[2] + sin(d2r(-45))* rpm[3])));
  thdot = r_wheel * LengthAlpha * (rpm[0] + rpm[1] + rpm[2] + rpm[3]);
  // odometry scale
  xdot = xdot * scale[0];
  ydot = ydot * scale[1];
  thdot = thdot * scale[2];
  // update position
  xpos = xpos + xdot*ts;
  ypos = ypos + ydot*ts;
  th = th + thdot*ts;
  if(th > 180)th=th-360;
  else if(th < -180)th=th+360;
  //Serial.print(xpos);Serial.print("\t");Serial.print(ypos);Serial.print("\t");Serial.println(th);
  //Serial.print(xdot);Serial.print("\t");Serial.print(ydot);Serial.print("\t");Serial.println(thdot);
  //Serial.print(encoderValue[0]);Serial.print("\t");Serial.print(encoderValue[1]);Serial.print("\t");Serial.print(encoderValue[2]);Serial.print("\t");Serial.println(encoderValue[3]);
}

void computeSpeed(){ // inverse kinematic
  float error_x = 0, error_y = 0, error_th = 0, gain = 0, error_norm1 = 0, error_norm2 = 0, xstars = 0, ystars = 0, thstars=0;
  xstars = xstar[counter];
  ystars = ystar[counter];
  thstars = thstar[counter];
  error_x = xstars - xpos;
  error_y = ystars - ypos;
  error_th = thstars - th;
  error_norm1 = sqrt(error_x*error_x + error_y*error_y);
  error_norm2 = sqrt(error_x*error_x + error_y*error_y + error_th * error_th);
  if(error_norm1 < 0.4){
    gain = 0;
    if(++counter>limitcounter)counter=limitcounter;
    else Serial.println("sampai");
  }
  else if(error_norm1<0.7)gain = lamdaNear;
  else gain = lamdaFar;
  pwm[0] = (1/r_wheel)*gain*(cos(d2r(45.)) * (cos(th) * error_x - sin(th) * error_y)) + (sin(d2r(45.)) * (sin(th) * error_x + cos(th) * error_y )) + (LengthAlpha * error_th);
  pwm[1] = (1/r_wheel)*gain*(cos(d2r(135.)) * (cos(th) * error_x - sin(th) * error_y)) + (sin(d2r(135.)) * (sin(th) * error_x + cos(th) * error_y )) + (LengthAlpha * error_th);
  pwm[2] = (1/r_wheel)*gain*(cos(d2r(-135.)) * (cos(th) * error_x - sin(th) * error_y)) + (sin(d2r(-135.)) * (sin(th) * error_x + cos(th) * error_y )) + (LengthAlpha * error_th);
  pwm[3] = (1/r_wheel)*gain*(cos(d2r(-45.)) * (cos(th) * error_x - sin(th) * error_y)) + (sin(d2r(-45.)) * (sin(th) * error_x + cos(th) * error_y )) + (LengthAlpha * error_th);
  Serial.print(xpos);Serial.print("\t");Serial.print(ypos);Serial.print("\t");Serial.print(th);
  Serial.print("\t");Serial.print(xstars);Serial.print("\t");Serial.print(ystars);Serial.print("\t");Serial.print(thstars);
  Serial.print("\t");Serial.print(pwm[0]);Serial.print("\t");Serial.print(pwm[1]);Serial.print("\t");Serial.print(pwm[2]);Serial.print("\t");Serial.print(pwm[3]);
  Serial.print("\t");Serial.print(gain);Serial.print("\t");Serial.print(error_norm1);Serial.print("\t");Serial.print(error_x);Serial.print("\t");
  Serial.print(error_y);Serial.print("\t");Serial.print(error_th);Serial.print("\t");Serial.println(counter);
  if(pwm[0]>200)pwm[0]=200;
  else if(pwm[0]<-200)pwm[0]=-200;
  //else if(pwm[0]<50 && pwm[0]>0)pwm[0]=50;
  //else if(pwm[0]<0 && pwm[0]>-50)pwm[0]=-50;
  if(pwm[1]>200)pwm[1]=200;
  else if(pwm[1]<-200)pwm[1]=-200;
  //else if(pwm[1]<50 && pwm[1]>0)pwm[1]=50;
  //else if(pwm[1]<0 && pwm[1]>-50)pwm[1]=-50;
  if(pwm[2]>200)pwm[2]=200;
  else if(pwm[2]<-200)pwm[2]=-200;
  //else if(pwm[2]<50 && pwm[2]>0)pwm[2]=50;
  //else if(pwm[2]<0 && pwm[2]>-50)pwm[2]=-50;
  if(pwm[3]>200)pwm[3]=200;
  else if(pwm[3]<-200)pwm[3]=-200;
  //else if(pwm[3]<50 && pwm[3]>0)pwm[3]=50;
  //else if(pwm[3]<0 && pwm[3]>-50)pwm[3]=-50;
 
  //setPWM
  set_pwm(M1, pwm[0]);
  set_pwm(M2, pwm[1]);
  set_pwm(M3, pwm[2]);
  set_pwm(M4, pwm[3]);
}
    
void kinMotor(int x, int y, int th) {
  pwm[3] = lambda * (cos(d2r(315))*x + sin(d2r(315))*y + LengthAlpha*d2r(th));
  pwm[2] = lambda * (cos(d2r(225))*x + sin(d2r(225))*y + LengthAlpha*d2r(th));
  pwm[1] = lambda * (cos(d2r(135))*x + sin(d2r(135))*y + LengthAlpha*d2r(th));
  pwm[0] = lambda * (cos(d2r(45))*x + sin(d2r(45))*y + LengthAlpha*d2r(th));
  
  // printPWM();
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
      analogWrite(MOTfloatOR1B, abs(_val));
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

// void ForwardInverseKinematic(){
    
//     atanVal = atan2(z , 0);
//     atanVal = (atanVal * 180 / PI);
//     kinMotor(y, -x, (atanVal*-1) * 100);
// }


