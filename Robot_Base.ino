// M1 is Left Motor.
// M2 is Right Motor.

//------------------ Constant-Variables---------------------
const int16_t pulseResolution = 64;
const int8_t wheelD = 60;
const int8_t errorMargin = 2;
const int8_t adjustVal = 3;

//------------------Changable-Variables---------------------
//int16_t powerConst;
//uint32_t timeInSecs;
uint16_t adjustSpeed;
uint32_t pulseDif;
uint8_t Speed = 50;

//------------------------Maths-----------------------------
const float wheelC = wheelD * M_PI;
const float DPP = wheelC / 64;  //DistancePerPulse
float averagePulse;

//-------------------------Motor-1--------------------------
const int8_t M1a = 8;
const int8_t M1b = 11;
const int8_t PWM1 = 9;
const int8_t M1InterruptA = 3;
const int8_t M1InterruptB = 7;

//-------------------------Motor-2--------------------------
const int8_t M2a = 13;
const int8_t M2b = 12;
const int8_t PWM2 = 10;
const int8_t M2InterruptA = 2;
const int8_t M2InterruptB = 4;
//------------------------Interrupt-------------------------
volatile int32_t M1Pulse = 0;
volatile int32_t M2Pulse = 0;

void setup() {
//-------------------------Motor-1--------------------------
  pinMode(M1a , OUTPUT);
  pinMode(M1b , OUTPUT);
  pinMode(PWM1 , OUTPUT);
  pinMode(M1InterruptA , INPUT_PULLUP);
  pinMode(M1InterruptB , INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(M1InterruptA) , M1Interrupt , CHANGE);

  //-------------------------Motor-2--------------------------
  pinMode(M2a , OUTPUT);
  pinMode(M2b , OUTPUT);
  pinMode(PWM2 , OUTPUT);
  pinMode(M2InterruptA , INPUT_PULLUP);
  pinMode(M2InterruptB , INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(M2InterruptA) , M2Interrupt , CHANGE);

  //-------------------------Others---------------------------
  Serial.begin(9600);
}

void loop() {
  

}
