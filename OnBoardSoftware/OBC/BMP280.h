/*
Project: IDEFIX
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
/*
SPI connections
#define MOSI 11
#define MISO 12
#define SCK 13
#define CS_BMP 10

Adafruit_BMP280 bmp(CS_BMP, MOSI, MISO, SCK);
*/

Adafruit_BMP280 bmp;

#define BMP280_I2C_ADDRESS 0x76

bool initializeBMP280();

String getBMP280Pressure();

String getBMP280Temperature();

String getBMP280Altitude(float pressureAtSeaLevelhPa);
