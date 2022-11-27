/*
Project: IDEFIX
08.04.2022

MicroSD Module - Arduino
GND  - GND
VCC  - 5V
MISO - D11
MOSI - D12
SCK  - D13
CS   - D9
*/

#include <SD.h>

#define CS_SD 9

File file;

bool initializeMicroSD();
