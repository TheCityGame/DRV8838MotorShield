# DRV8838MotorShield

This is a library for the 8838 motor driver which was tested on the 3543 power/motor board from Pololu. 
https://www.pololu.com/product/3543

I used some ideas from the pololu library here
https://github.com/pololu/drv8835-motor-shield

I didn't liek that library. I don't think it allowed the user to set their own pins and seemed overly complicated to me. For instance, speeds were allowed between -400 amd 400 and then converted to 0-255. This might be because it was written for other boards that had other clock speeds. I'm not sure. I liked their idea of have a boolean to controlling flipping the motor direction in one place. 

I also used some ideas from the simpler library
https://github.com/SeeingInGreen/drv8838

Mine should allow a user to set speeds between -255 and 255. 

It allows the user to set speeds for each motor individually with separate calls, with a single call, or set the same speed for both motors. I added a sleep function, which is nice for testing. It allows the user to run through several sequences in loop() and then set the motors to sleep, so when testing, one doesn't have to keep unplugging or turning off the board. See the example. 
