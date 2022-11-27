/*
Project: IDEFIX
Device under test: MicroServo 9g SG90
Tested with: Arduino Nano ATmega328P (Old Bootloader)
08.04.2022

Servo - Arduino
VCC - 5V
GND - GND
Signal - D8
*/

#include <Servo.h> 

#define ServoPin 8

Servo servo;

void setup()
{
  servo.attach(ServoPin); 
}
 
void loop()
{ 
  servo.write(90);
  delay(500);
  servo.write(180);   
  delay(500);
}
