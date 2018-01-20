#include <SimpleTimer.h>
#include <LiquidCrystal.h>

//set debug to 1 to enable serial printing
int debug = 1;

SimpleTimer timer;

// set pin numbers:
const int motorPin = 51;       // motor1 output pin
const int motorEnablePin = 45;  // motor enable output pin


// LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

double mmps = 0;         // variable for displaying speed
int difference = 0;     
long steps = 0;               // step count
long steps2 = 0;  

// motor speed settings. the higher the values the slower the motor runs and vice versa
double speedDelay = 115;    // motor step signal duration in microseconds   
double motorSignalOff = 5;      // delay between motor step signals in microseconds
int displays = 0;          // nonii
int runState = 0;              // noniiiii
int motorRunState = 1;              // noniii
int motorState = 0;            // noniiiiii
int potPin = 0;    // input pin for the potentiometer
int val = 1023;    //

void setup() {
  pinMode(motorPin, OUTPUT);   // set the motor pin as OUTPUT
  pinMode(motorEnablePin, OUTPUT);   // set the motor pin as OUTPUT    
  digitalWrite(motorEnablePin, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Speedonator2000");
  lcd.setCursor(8, 1);
  lcd.print(" mm/sec");  
  timer.setInterval(250, displaySpeed);
}

// display speed on lcd
void displaySpeed() {
  difference = steps-steps2;
  mmps = 4 * 1800*difference /25000;  //an algorithm drawn from the hat
  lcd.setCursor(0, 1);
  lcd.print("        ");
  lcd.setCursor(0, 1);
  lcd.print(mmps);
  steps2=steps;
}

void runMotor()
{
  digitalWrite(motorPin, HIGH);
  delayMicroseconds(val);
  digitalWrite(motorPin, LOW);
  delayMicroseconds(motorSignalOff);
  steps++;
}

void loop(){
  while(steps < 250000){
    timer.run();
    val = analogRead(potPin);
    if(val==1023){
      runState=1;
    }
    if(runState==1){
      runMotor();
    }
  }
  if(motorRunState==1){
    uint32_t ts2 = millis();
    runState=0;
    steps=0;
    steps2=0;
    digitalWrite(motorEnablePin, HIGH);
  }
}
