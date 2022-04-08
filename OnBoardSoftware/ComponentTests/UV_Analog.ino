/*
Project: IDEFIX
Device under test: GUVA S12SD Breakout Board
Tested with: Arduino Nano ATmega328P (Old Bootloader)
08.04.2022

GUVA-S12SD - Arduino
VCC - 3,3V
GND - GND
SIG - A0
*/

#define UV_Pin A0

void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
  float sensorVoltage; 
  float sensorValue;
 
  sensorValue = analogRead(UV_Pin);
  sensorVoltage = sensorValue/1024*3.3;
  
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  
  Serial.print("    ");
  
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  
  delay(1000);
}
