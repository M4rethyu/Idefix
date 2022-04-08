/*
Project: IDEFIX
Device under test: Bosch BMP280 Pressure and Temperature Sensor
Bus: I²C [Address 0x76 (SDO on GND) or 0x77 (SDO on VCC)]
Tested with: Arduino Nano ATmega328P (Old Bootloader)
08.04.2022

BMP280 - Arduino
VCC - 3.3V
GND - GND
SCL - A5
SDA - A4
CSB - unconnected
SDO - GND
*/

#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

#define BMP280_I2C_ADDRESS 0x76

void setup() {
  Serial.begin(9600);
  
  //Debugging
  while (!Serial) {;}

  if (!bmp.begin(BMP280_I2C_ADDRESS)){
    Serial.println("Failed to initialize BMP280!");
    while(true);
  }

  Serial.println("Okeeeeeeey, let's go!");
}

void loop() {
  Serial.print("Pressure: ");
  Serial.println(bmp.readPressure());
  Serial.print("Temperature: ");
  Serial.println(bmp.readTemperature());
  
  delay(100);
}
