#include "motormgr.h"

MotorMgr::MotorMgr(int mp, int ep):motorPin(mp),enablePin(ep){
  pinMode(motorPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(motorPin,LOW);
  digitalWrite(enablePin,LOW);    
}
void MotorMgr::step(int speedDelay){
  digitalWrite(motorPin,HIGH);
  delayMicroseconds(speedDelay);
  digitalWrite(motorPin, LOW);  
  delayMicroseconds(stepDelay);
  steps++;
}
float MotorMgr::currentSpeed(){
  uint32_t now = millis();
  if(now-lastSpeedTime>=DISPLAYDELAY){
    computeSpeed(now);
    lastSpeedTime=now;
  }
  return curSpeed;
}
void MotorMgr::computeSpeed(uint32_t now){
  uint32_t timeDelta=now-lastSpeedTime;
  uint32_t stepsDelta=steps-lastSteps;
  lastSteps=steps;
  curSpeed=stepsDelta*MMPS/timeDelta;  
}

void MotorMgr::enable(boolean value) const{
  digitalWrite(enablePin,value ? LOW : HIGH);
}
