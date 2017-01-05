//#ifndef (__AVR_ATmega1280__) || ndef(__AVR_ATmega2560__)
//#error "This library only supports Arduino Mega boards."
//#endif
#ifndef DRV8838MotorShield_h
#define DRV8838MotorShield_h

#include <Arduino.h>

class DRV8838MotorShield_h
{
  public:  
    // CONSTRUCTORS
    DRV8838MotorShield_h();
	// Default pin selection.
    DRV8838MotorShield_h(unsigned char DIR1, unsigned char SPEED1, unsigned char SLEEP1, unsigned char DIR2, 
                           unsigned char SPEED2, unsigned char SLEEP2); 
	// User-defined pin selection. 
    DRV8838MotorShield_h(unsigned char DIR1, unsigned char SPEED1, unsigned char SLEEP1, unsigned char DIR2, 
                           unsigned char SPEED2, unsigned char SLEEP2);
	
   
    // PUBLIC METHODS
    void init(); 
    void setM1Speed(int speed); 
    void setM2Speed(int speed); 
    void setSpeeds(int m1Speed, int m2Speed); .
    
  private:
    unsigned char mcDir1;
    unsigned char mcSpeed1;
    unsigned char mcSleep1;
    unsigned char mcDir2;
    unsigned char mcSpeed2;
    unsigned char mcSleep2;
    
    
};
#endif