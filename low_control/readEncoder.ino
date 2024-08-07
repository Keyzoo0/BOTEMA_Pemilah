void readEncoder(){
       encoderValue[0] = encoderM1.read();
       encoderValue[1] = encoderM2.read();
       encoderValue[2] = encoderM3.read();
       encoderValue[3] = encoderM4.read(); 
       readRPM();
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
    //Serial.print(rpm[0]);Serial.print("\t");Serial.print(rpm[1]);Serial.print("\t");Serial.print(rpm[2]);Serial.print("\t");Serial.println(rpm[3]);
    encoderValue[0] = encoderM1.readAndReset();
    encoderValue[1] = encoderM2.readAndReset();
    encoderValue[2] = encoderM3.readAndReset();
    encoderValue[3] = encoderM4.readAndReset();
  for(int i = 0 ; i < 4 ; i++){
  encoderValue[i] = 0;
  }
  Serial.println();
 }
}