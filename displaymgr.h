#ifndef DISPLAYMGR_H
#define DISPLAYMGR_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class DisplayMgr{
  protected: 
    LiquidCrystal *lcd;
  public:
    DisplayMgr(int rs, int en, int d4, int d5, int d6, int d7);  // init the state and pins
    void displayFailure() const;
    void displayStart() const;
    void displaySpeed(float motorSpeed);
};
#endif
