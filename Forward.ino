void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  adjustM1Speed = Speed;
  adjustM1Speed = constrain(adjustM1Speed , 0 , 255);
  adjustM2Speed = Speed;
  adjustM2Speed = constrain(adjustM2Speed , 0 , 255);
  Distance += currentDistance();
  while (Distance > currentDistance()) {
    if (Difference() < errorMarginSmall) {
      digitalWrite(M1a , HIGH);
      digitalWrite(M1b , LOW);
      analogWrite(PWM1 , adjustM1Speed);
      digitalWrite(M2a , HIGH);
      digitalWrite(M2b , LOW);
      analogWrite(PWM2 , adjustM2Speed);
      Serial.println("Constant");
    } else {
      if (M1Pulse > M2Pulse) {
        adjustM1Pulse -= adjustVal;
        analogWrite(PWM1 , adjustM1Speed);
        adjustM1Pulse += adjustVal;
//        if (adjustM1Speed <= (Speed-40)) {
//          adjustM2Speed += 2;
//          adjustM1Speed++;
//          Serial.println("adjustM2Speed1++++++");
//          Serial.println(adjustM2Speed);
//          analogWrite(PWM2 , adjustM2Speed);
//          adjustM2Speed--;
//        } else {
//          adjustM1Speed--;
//          Serial.println("adjustM1Speed1--");
//          Serial.println(adjustM1Speed);
//          analogWrite(PWM1 , adjustM1Speed);
//        }
//        delay(5);
      } else {
        adjustM2Pulse -= adjustVal;
        analogWrite(PWM2 , adjustM1Speed);
        adjustM2Pulse += adjustVal;
//        if (adjustM1Speed >= (Speed+30)) {
//          adjustM2Speed -= 2;
//          adjustM1Speed--;
//          Serial.println("adjustM2Speed2------");
//          Serial.println(adjustM2Speed);
//          analogWrite(PWM2 , adjustM2Speed);
//          adjustM2Speed++;
//        } else {
//          adjustM1Speed++;
//          Serial.println("adjustM1Speed2++");
//          Serial.println(adjustM1Speed);
//          analogWrite(PWM1 , adjustM1Speed);
//        }
//        delay(5);
      }
    }
  }
  stopBreak();
}
