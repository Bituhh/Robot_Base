void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  adjustSpeed = Speed;
  adjustSpeed = constrain(adjustSpeed , 0 , 255);
  distanceTo += currentDistance();
  while (Distance > currentDistance()) {
    if ((findDistance(M1Pulse) - findDistance(M2Pulse)) > errorMargin) {
      adjustSpeed--;
      analogWrite(PWM1 , adjustSpeed);
    } else if ((findDistance(M1Pulse) - findDistance(M2Pulse)) > -errorMargin) {
      adjustSpeed++;
      analogWrite(PWM1 , adjustSpeed);
    }
    digitalWrite(M1a , HIGH);
    digitalWrite(M1b , LOW);
    analogWrite(PWM1 , adjustSpeed);
    digitalWrite(M2a , HIGH);
    digitalWrite(M2b , LOW);
    analogWrite(PWM2 , Speed);
  }
  stopBreak();
}

