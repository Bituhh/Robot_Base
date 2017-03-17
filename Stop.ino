void stopBreak() {
  digitalWrite(M1a , HIGH);
  digitalWrite(M1b , HIGH);
  analogWrite(PWM1 , LOW);
  digitalWrite(M2a , HIGH);
  digitalWrite(M2b , HIGH);
  analogWrite(PWM2 , LOW);
  delay(100);
}
void stopNoBreak() {
  digitalWrite(M1a , LOW);
  digitalWrite(M1b , LOW);
  analogWrite(PWM1 , LOW);
  digitalWrite(M2a , LOW);
  digitalWrite(M2b , LOW);
  analogWrite(PWM2 , LOW);
  delay(100);
}

