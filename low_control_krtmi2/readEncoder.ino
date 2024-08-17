
void EncoderInit()
{
   
   previousMillis = millis();
  attachInterrupt(digitalPinToInterrupt(HALL_A[0]), updateEncoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(HALL_A[1]), updateEncoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(HALL_A[2]), updateEncoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(HALL_A[3]), updateEncoder4, RISING);
}


void updateEncoder1()
{
  encoderValue[0];
}


void updateEncoder2()
{
  encoderValue[1];
}


void updateEncoder3()
{
  encoderValue[2];
}


void updateEncoder4()
{
  encoderValue[3];
}

void readRPM(){
   currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    // Revolutions per minute (RPM) =
    // (total encoder pulse in 10ms / motor encoder output) x 6000s
    rpm[0] = (float)(encoderValue[0] * 6000 / ENCODEROUTPUT);
    rpm[1] = (float)(encoderValue[1] * 6000 / ENCODEROUTPUT);
    rpm[2] = (float)(encoderValue[2] * 6000 / ENCODEROUTPUT);
    rpm[3] = (float)(encoderValue[3] * 6000 / ENCODEROUTPUT);
    //reset encoder value
    for(int i = 0 ; i < 4 ; i++)encoderValue[i] = 0;

    // Memanggil fungsi linearisasi dan control PID motor
		if (linear == true) {
			for (int i = 0; i < 4; i++) {
				linearisasi(i);
			}
			controlPID();
		} else {
			for (int i = 0; i < 4; i++) {
				pwm[i] = set[i];
			}
		}

  }
}