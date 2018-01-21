#include "displaymgr.h"

DisplayMgr::DisplayMgr(int rs, int en, int d4, int d5, int d6, int d7){
  lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);  // init the state and pins
  lcd->begin(16, 2);
}

void DisplayMgr::displayFailure() const{
  // Print a failure message on the LCD.
  lcd->print("Speedonator2000");
  lcd->setCursor(0, 1);
  lcd->print("We're fucked!");
  while(1);
}

void DisplayMgr::displayStart() const{
  delay(1000);
  // Print a start message on the LCD.
  lcd->print("Speedonator2000");
  for(int i=0;i<3;i++){
    delay(500);
    lcd->setCursor(i, 1);
    lcd->print(".");
  }
}

void DisplayMgr::displaySpeed(float motorSpeed){
  static float lastSpeed = 0;
  if(lastSpeed!=motorSpeed){
  // Print the speed on the LCD.
    lcd->setCursor(0, 1);
    lcd->print("                ");
    lcd->setCursor(0, 1);
    lcd->print("mm/s : " + String(round(motorSpeed)));
    lastSpeed = motorSpeed; 
  }
}
