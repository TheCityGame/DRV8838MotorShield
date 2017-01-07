#include "DRV8838MotorShield.h"

// Constructors ////////////////////////////////////////////////////////////////
DRV8838MotorShield::DRV8838MotorShield()
{
  mcDir1Pin = 7;
  mcSpeed1Pin = 8;
  mcSleep1Pin = 9;
  mcDir2Pin = 10;
  mcSpeed2Pin = 11;
  mcSleep2Pin = 12;
  mbDir1PinState = true;  //Set the directions to true. If your motor spins
  mbDir2PinState = true;  //opposite your intent, use the FLIP settings. 
  mbFlipM1 = false;
  mbFlipM2 = false;   
}

//user defined pins with a typical constructor. 
DRV8838MotorShield::DRV8838MotorShield(unsigned char DIR1, unsigned char SPEED1, unsigned char SLEEP1, unsigned char DIR2, 
                           unsigned char SPEED2, unsigned char SLEEP2)
{
  mcDir1Pin = DIR1;
  mcSpeed1Pin = SPEED1;
  mcSleep1Pin = SLEEP1;
  mcDir2Pin = DIR2;
  mcSpeed2Pin = SPEED2;
  mcSleep2Pin = SLEEP2;
}

//Call in setup to initialize pins. 
void DRV8838MotorShield::init()
{
  pinMode(mcDir1Pin, OUTPUT);
  pinMode(mcSpeed1Pin, OUTPUT);
  pinMode(mcSleep1Pin, OUTPUT);
  pinMode(mcDir2Pin, OUTPUT);
  pinMode(mcSpeed2Pin, OUTPUT);
  pinMode(mcSleep2Pin, OUTPUT);
  digitalWrite(mcSleep2Pin, 1);
  digitalWrite(mcSleep1Pin, 1);
  mbDir1PinState = true;
  mbDir2PinState = true;
  mbFlipM1 = false;
  mbFlipM2 = false;
}
// Set speed for motor 1, speed is a number between 0 and 255
//negative speeds run the motor backward.
void DRV8838MotorShield::setM1Speed(int speed)
{
  mbDir1PinState = true;
  if (speed < 0)
  {
    speed = -speed;  
    mbDir1PinState = !mbDir1PinState;
  }
  if (speed > 255)  // Max PWM 
    speed = 255;
  if (mbFlipM1) 
  {
    digitalWrite(mcDir1Pin, !mbDir1PinState);
  }
  else 
  {
    digitalWrite(mcDir1Pin, mbDir1PinState);
  }
  analogWrite(mcSpeed1Pin,speed); 
}

// Same for motor 2
void DRV8838MotorShield::setM2Speed(int speed)
{
  mbDir2PinState = true;
  if (speed < 0)
  {
    speed = -speed;  
     mbDir2PinState = !mbDir2PinState; 
  }
  if (speed > 255)  // Max PWM
    speed = 255;
  if (mbFlipM2) 
  {
    digitalWrite(mcDir2Pin, !mbDir2PinState);
  }
  else 
  {
    digitalWrite(mcDir2Pin, mbDir2PinState);
  }
  analogWrite(mcSpeed2Pin,speed); 
}

// Set speed for motors 1, 2 separately
void DRV8838MotorShield::setSpeeds(int mi1Speed, int mi2Speed)
{
  setM1Speed(mi1Speed);
  setM2Speed(mi2Speed);
}

//set speeds together. 
void DRV8838MotorShield::setSpeeds(int iSpeed)
{
  setM1Speed(iSpeed);
  setM2Speed(iSpeed);
}



