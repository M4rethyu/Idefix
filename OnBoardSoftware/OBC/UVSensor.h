/*
Project: IDEFIX
08.04.2022Nano

GUVA-S12SD - Arduino
VCC - 3,3V
GND - GND
SIG - A0
*/

#ifndef UVSENSOR_H_
#define UVSENSOR_H_

#define UV_Pin A0

float sensorValue;

String getUVData();

#endif
