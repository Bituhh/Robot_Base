void M1Interrupt() {
//  if (digitalRead(M1InterruptA) != digitalRead(M1InterruptB)) {
    M1Pulse++;
//  }
}

void M2Interrupt() {
//  if (digitalRead(M2InterruptA) == digitalRead(M2InterruptB)) {
    M2Pulse++;
//  }
}

int32_t currentDistance() {
  averagePulse = M1Pulse + M2Pulse;
  averagePulse = averagePulse / 2;
  int32_t distance = round(averagePulse * DPP);
  return distance;
}
int32_t M1Distance(){
  float x = M1Pulse * DPP;
  int32_t M1Distance = round(x);
  return M1Distance;
}
int32_t M2Distance(){
  float x = M2Pulse *DPP;
  int32_t M2Distance = round(x);
  return M2Distance;
}

int16_t Difference(){
  int16_t x = M1Pulse - M2Pulse;
  int16_t Dif = abs(x);
  return Dif;
}
int16_t baseC() {
  float baseR = 58;
  float baseC = 2 * baseR * M_PI;
  int16_t val = round(baseC);
  return val;
}
int findDistance(int32_t item){
  int32_t findDistance = item * DPP;
  return findDistance; 
}

