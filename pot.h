#ifndef POT_H
#define POT_H

#include <Arduino.h>
#define MAXPOTVALUE (1023)
#define VECSIZE (100)
class Pot{
  protected: 
    const int pin;
    int valueVec[VECSIZE],
        curVal = 0;    
    float curReading = 0;
  public:
    Pot(int p); // initialize the state and pin
    int read();  // return the rounded analog value
};
#endif
