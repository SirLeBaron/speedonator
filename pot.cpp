#include "pot.h"

Pot::Pot(int p) : pin(p) {
  pinMode(pin, INPUT);
  for(int i = 0; i < VECSIZE; i++){
    valueVec[i] = 0;
  }  
}

int Pot::read(){
  float newVal = analogRead(pin);
  curReading += (newVal - valueVec[curVal])/VECSIZE;
  valueVec[curVal] = newVal;
  curVal = (curVal+1) % VECSIZE;
  return round(curReading);
}
