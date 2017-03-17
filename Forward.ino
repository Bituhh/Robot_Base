void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  adjustM1Speed = Speed;
  adjustM1Speed = constrain(adjustM1Speed , 0 , 255);
  adjustM2Speed = Speed;
  adjustM2Speed = constrain(adjustM2Speed , 0 , 255);
  //  Distance += currentDistance();
  while (Distance > currentDistance()) {
    digitalWrite(M1a , HIGH);
    digitalWrite(M1b , LOW);
    analogWrite(PWM1 , adjustM1Speed);
    digitalWrite(M2a , HIGH);
    digitalWrite(M2b , LOW);
    analogWrite(PWM2 , Speed);
    if (Difference() > errorMarginSmall) {
      if (Difference() > errorMarginLarge) {
        if (findDistance(M1Pulse) < findDistance(M2Pulse)) {
          adjustM2Speed--;
        } else {
          adjustM2Speed++;
        }
      } else {
        if (findDistance(M1Pulse) > findDistance(M2Pulse)) {
          adjustM1Speed--;
        } else {
          adjustM1Speed++;
        }
      }
    }
  }
  stopBreak();
}
