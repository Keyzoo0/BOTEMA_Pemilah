void setup_vacum(){
    pinMode(MOTORAV , OUTPUT);
    pinMode(MOTORBV , OUTPUT);
   
}

void vacumOn(){
   digitalWrite(MOTORAV , HIGH);
    digitalWrite(MOTORBV , LOW);

}

void vacumOff(){
      digitalWrite(MOTORAV , LOW);
       digitalWrite(MOTORBV , LOW);
}

void kinematik_vacum(int vacum_val ){
  Serial.println(vacum_val);
    if(vacum_val == 1)vacumOn();
    else if (vacum_val == 0) vacumOff();
}