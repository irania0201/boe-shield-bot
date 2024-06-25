/* Name: Irania Mazariegos
   Date: May 4, 2024
   Description: Maze Maneuvers
*/

#include <Servo.h>    // include servo library

Servo servoLeft;      // declare left and right servos
Servo servoRight;

void setup() {
  tone(4, 3000, 1000);  // play tone for 1 second
  delay(1000);          // delay to finish tone

  servoLeft.attach(13);   // attach left signal to pin 13
  servoRight.attach(12);  // attach right signal to pin 12

  maneuver(190, 167, 6350);     // forward 7 
  stop();
  maneuver(120, -100, 560);     // right
  stop();
  maneuver(190, 167, 3500);     // forward 3 seconds
  stop();
  maneuver(-100, 100, 560);     // left
  stop();
  maneuver(190, 167, 3700);     // forward 4 seconds
  stop();
  maneuver(100, -100, 560);     // right
  stop();
  maneuver(200, 157, 1750);     // forward 2 seconds
  stop();
  maneuver(-100, 100, 560);     // left
  stop();
  maneuver(200, 157, 800);      // forward 1 second
  stop();
  maneuver(100, -100, 560);     // right
  stop();
  maneuver(190, 167, 5900);     // forward 6 seconds
  stop();
  maneuver(100, -100, 560);     // right
  stop();
  maneuver(180, 173, 7250);     // forward 8 seconds
  stop();
  maneuver(100, -100, 560);     // right
  stop();
  maneuver(200, 157, 5000);     // forward 5 seconds
  stop();
  maneuver(-100, 100, 560);     // left
  stop();
  maneuver(200, 157, 3500);     // forward 4 seconds
  stop();
  maneuver(100, -100, 540);     // right
  stop();
  maneuver(200, 157, 6000);     // forward 6 seconds 
  maneuver(0, 0, -1);           // disable servos
} 

void loop() {
  // put your main code here, to run repeatedly:

}

void maneuver(int speedLeft, int speedRight, int msTime)
{
  // speedLeft, speedRight ranges: Backward Linear Stop Linear Forward
  //                                   -200   -100    0    100     200
  servoLeft.writeMicroseconds(1500 + speedLeft);    // left servo speed
  servoRight.writeMicroseconds(1500 - speedRight);  // right servo speed
  
  if(msTime==-1) // if msTime = -1 
  {
    servoLeft.detach(); // stop servo signals
    servoRight.detach();
  }

  delay(msTime); // delay for msTime
} 

void stop() {
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(250);
}
