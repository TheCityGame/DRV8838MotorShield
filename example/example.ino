#include <DRV8838MotorShield.h>
/*  this example uses the DRV8838MotorShield class. I wanted a simpler class than 
 *  the one that Pololu wrote and give the user the ability to define the pins in the 
 *  declaration. I used both SLP pins. There are ways around this if pins are at a premium.
 *  This is probably overly commented. 
 */

DRV8838MotorShield motors(8, 7, 9, 10, 11, 12); //set the pins to whatever you want. 

void setup(){
  motors.init(); //this sets the pins. 
  motors.flipM1();  //flip direction. e.g. if wired opposite, or whatever
  //motors.flipM2();  //uncomment to flip.  
}

void loop(){

  motors.setM1Speed(120); //spin one wheel forward
  delay(1000);
  motors.setM2Speed(120); //spin the other forward
  delay(1000);
  motors.setSpeeds(-255, -255); //spin them both backwards. 
  delay(1000); 
  motors.setSpeeds(-20);
  delay(1000);
  motors.sleep();  //put the unit to sleep 
  delay(1000);
  //motors.wake(); //wake the motors if you want to keep looping. Or better, just comment the sleep line. 
}

