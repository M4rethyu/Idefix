/*
Project: IDEFIX
08.04.2022

MPU6050 - Arduino Nano
VCC - 3,3V
GND - GND
SDA - A4
SCL - A5
AD0 - GND
other pins unconnected
*/

#include "Wire.h" 
#define MPU6050_ADDR 0x68 // Alternatively set AD0 to HIGH  --> Address = 0x69

int16_t accX, accY, accZ, gyroX, gyroY, gyroZ, tRaw;	//Register

void initializeMPU6050();								//Initialize I²C connection

String getMPU6050Data();								//Read data from sensor
