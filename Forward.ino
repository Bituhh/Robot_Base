void Forward(int16_t Speed, int16_t Distance) {
  Speed = map(constrain(Speed , 0 , 100), 0 , 100, 0, 200);
  Distance += currentDistance();
  adjustM1Speed = Speed += adjustVal;
  adjustM2Speed = Speed;
  while (Distance > currentDistance()) {
    if (compareM1() == true) {
      if (adjustM1Speed < Speed + 30) {
        if (adjustM1Speed > Speed - 30) {
          for (adjustM1Speed; compareM1() == true ; adjustM1Speed--) {
            analogWrite(PWM1 , adjustM1Speed);
            Serial.println("M1");
          }
        } else {
          for (adjustM2Speed; compareM1() == true ; adjustM2Speed++) {
            analogWrite(PWM2 , adjustM2Speed);
            Serial.println("  M2++");
          }
        }
      } else {
        for (adjustM2Speed; compareM1() == true ; adjustM2Speed++) {
          analogWrite(PWM2 , adjustM2Speed);
          analogWrite(PWM1 , adjustM1Speed--);
          Serial.println("M2++");
          
        }
      }      
    } else if (compareM2() == true) {
      if (adjustM2Speed < Speed + 30) {
        if (adjustM2Speed > Speed - 30) {
          for (adjustM2Speed; compareM2() == true ; adjustM2Speed--) {
            analogWrite(PWM2 , adjustM2Speed);
            Serial.println("M2");
          }
        } else {
          for (adjustM1Speed; compareM2() == true ; adjustM1Speed++) {
            analogWrite(PWM1 , adjustM1Speed);
            Serial.println("  M1++");
          }
        }
      } else {
        for (adjustM1Speed; compareM2() == true ; adjustM1Speed++) {
          analogWrite(PWM1 , adjustM1Speed);
          analogWrite(PWM2 , adjustM2Speed--);
          Serial.println("M1++");
        }
      }
    } else {
      digitalWrite(M1a , HIGH);
      digitalWrite(M1b , LOW);
      analogWrite(PWM1 , adjustM1Speed);
      digitalWrite(M2a , HIGH);
      digitalWrite(M2b , LOW);
      analogWrite(PWM2 , adjustM2Speed);
      Serial.println("Constant");
    }
  }
  stopBreak();
}
