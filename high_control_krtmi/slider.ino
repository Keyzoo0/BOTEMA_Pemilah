void setup_slider(){

pinMode(MOTORAS , OUTPUT );
pinMode(MOTORBS , OUTPUT );
pinMode(ENS , OUTPUT );
digitalWrite(ENS , HIGH );


}

void kinematik_slide(int slide_val){
  if(slide_val > 0){
    analogWrite(MOTORAS  , slide_val);
    analogWrite(MOTORBS  , 0);
  }else if(slide_val < 0){
    analogWrite(MOTORBS  , abs(slide_val));
    analogWrite(MOTORAS  , 0);
  }else{
    analogWrite(MOTORAS  , 0);
    analogWrite(MOTORBS  , 0);
    
  }
}