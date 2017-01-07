//This was only written and tested on the Mega2560 board. 
//use at your own discretion
#ifndef DRV8838MotorShield_h
#define DRV8838MotorShield_h

#include <Arduino.h>

class DRV8838MotorShield
{
  public:  
    // default constructor. See cpp for pin definitions. 
    DRV8838MotorShield(); 
	// User-defined pin selection. 
    DRV8838MotorShield(unsigned char DIR1, unsigned char SPEED1, unsigned char SLEEP1, unsigned char DIR2, 
                           unsigned char SPEED2, unsigned char SLEEP2);
	
   
    // PUBLIC METHODS
    void init(); 
    void setM1Speed(int speed); 
    void setM2Speed(int speed); 
    void setSpeeds(int m1Speed, int m2Speed); 
    void setSpeeds(int iSpeed);
    void sleep() {digitalWrite(mcSleep1Pin, 0); digitalWrite(mcSleep2Pin, 0);}
    void wake()  {digitalWrite(mcSleep1Pin, 1); digitalWrite(mcSleep2Pin, 1);}
    void flipM1() {mbFlipM1 = true;}
    void flipM2() {mbFlipM2 = true;}
  private:
    unsigned char mcDir1Pin;
    unsigned char mcSpeed1Pin;
    unsigned char mcSleep1Pin;
    unsigned char mcDir2Pin;
    unsigned char mcSpeed2Pin;
    unsigned char mcSleep2Pin;
    bool mbFlipM1;  //flip the directions if running opposite expectations
    bool mbFlipM2;
    bool mbDir1PinState;
    bool mbDir2PinState;
};
#endif