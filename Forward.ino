void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  Distance += currentDistance();
  while (Distance > currentDistance()) {
    if (Difference() < errorMarginSmall) {
      adjustM1Speed = Speed;
      adjustM1Speed = constrain(adjustM1Speed , 0 , 255);
      adjustM2Speed = Speed;
      adjustM2Speed = constrain(adjustM2Speed , 0 , 255);
      digitalWrite(M1a , HIGH);
      digitalWrite(M1b , LOW);
      analogWrite(PWM1 , adjustM1Speed);
      digitalWrite(M2a , HIGH);
      digitalWrite(M2b , LOW);
      analogWrite(PWM2 , adjustM2Speed);
      Serial.println("Constant");
    } else {
      if (M1Pulse > M2Pulse) {
        adjustM1Speed -= adjustVal;
        analogWrite(PWM1 , adjustM1Speed);
        Serial.println("M1");
      } else {
        adjustM2Speed -= adjustVal;
        analogWrite(PWM2 , adjustM1Speed);
        Serial.println("M2");
      }
    }
  }
  stopBreak();
}
