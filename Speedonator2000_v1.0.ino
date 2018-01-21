#include "motormgr.h"
#include "pot.h"
#include "displaymgr.h"

// Motor pin:
const int motorPin = 51,       // motor output pin
          motorEnablePin = 45;  // motor enable output pin

// LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// input pin for the potentiometer
const int potPin = A0;    

// Global variables
MotorMgr *m;
Pot *p;
DisplayMgr *d;

void setup() {
  d = new DisplayMgr(rs, en, d4, d5, d6, d7);
  if(d==NULL){
    while(1);
  }
  m = new MotorMgr(motorPin, motorEnablePin);
  if(m==NULL){
    d->displayFailure();
  }
  p = new Pot(potPin);
  if(p==NULL){
    d->displayFailure();
  }
  Serial.begin(9600);
  d->displayStart();
  m->enable(false);
}

boolean isInitialized(int potReading){
  static boolean result = false;
  result = result ||(potReading == MAXPOTVALUE);
  return result;
}

void loop(){
  int mDelay = p->read();
  if(isInitialized(mDelay)){
    if(mDelay != MAXPOTVALUE){ 
      m->enable(true);
      m->step(mDelay);  
    }
    else{
      m->enable(false);
    }
  }
  d->displaySpeed(m->currentSpeed());
}
