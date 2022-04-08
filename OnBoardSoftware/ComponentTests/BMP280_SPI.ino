/*
Project: IDEFIX
Device under test: Bosch BMP280 Pressure and Temperature Sensor
https://www.reichelt.de/be/en/developer-boards-temperature-and-pressure-sensor-bmp280-debo-bmp280-p266034.html?&trstct=pos_0&nbc=1
Bus: SPI
Tested with: Arduino Nano ATmega 328P (Old Bootloader)
08.04.2022

BMP280 - Arduino
VCC - 3.3V
GND - GND
SCL - D13
SDA - D11
CSB - D10
SDO - D12
*/

#include <SPI.h>
#include <Adafruit_BMP280.h>

#define MOSI 11
#define MISO 12
#define SCK 13
#define CS 10

Adafruit_BMP280 bmp(CS, MOSI, MISO, SCK);

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}

  //Init
  if (!bmp.begin()){
    Serial.println("check wiring...");
    while(true);
  }

  Serial.println("Okeeeeeeey, let's go!");
}

void loop() {
  Serial.print("Pressure: ");
  Serial.println(bmp.readPressure());
  Serial.print("Temperature: ");
  Serial.println(bmp.readTemperature());
  Serial.print("Altitude: ");
  Serial.println(bmp.readAltitude(1013.2));
  
  delay(500);
}
