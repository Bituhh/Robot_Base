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

int16_t compareM1() {
  int16_t x = M1Pulse - M2Pulse;
  if (x > errorMargin) {
    return true;
  } else {
    return false;
  }
}
int16_t compareM2() {
  int16_t x = M2Pulse - M1Pulse;
  if (x > errorMargin) {
    return true;
  } else {
    return false;
  }
}

int16_t baseC() {
  float baseR = 58;
  float baseC = 2 * baseR * M_PI;
  int16_t val = round(baseC);
  return val;
}

int findDistance(int32_t item) {
  int32_t findDistance = round(item * DPP);
  return findDistance;
}

