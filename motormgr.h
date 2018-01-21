#ifndef MOTORMGR_H
#define MOTORMGR_H

#include <Arduino.h>

#define DISPLAYDELAY (250)
#define MMPS (72)


class MotorMgr{
  protected: 
    const int motorPin,
              enablePin,
              stepDelay = 5;
    unsigned int steps = 0,
                 lastSteps = 0;

    float lastSpeedTime = 0;     
    void computeSpeed(uint32_t now);
    float curSpeed;
  public:
    MotorMgr(int mp, int ep);  // init the state and pins
    void step(int speedDelay);  //
    float currentSpeed();
    void enable(boolean value) const;    
};
#endif
