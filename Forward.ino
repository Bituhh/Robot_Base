void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  while (Distance > currentDistance()) {
    digitalWrite(M1a , HIGH);
    digitalWrite(M1b , LOW);
    analogWrite(PWM1 , Speed);
    digitalWrite(M2a , HIGH);
    digitalWrite(M2b , LOW);
    analogWrite(PWM2 , Speed);
    if (Difference() >= errorMargin) {
      if(M1Pulse>M2Pulse){
      digitalWrite(M1a , LOW);
      digitalWrite(M1b , LOW);
      analogWrite(PWM1 , LOW);
      digitalWrite(M2a , HIGH);
      digitalWrite(M2b , LOW);
      analogWrite(PWM2 , Speed);
    }else{
      digitalWrite(M1a , HIGH);
      digitalWrite(M1b , LOW);
      analogWrite(PWM1 , Speed);
      digitalWrite(M2a , LOW);
      digitalWrite(M2b , LOW);
      analogWrite(PWM2 , LOW);
    }
  }
  stopBreak();
}


