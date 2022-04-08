/*
Project: IDEFIX
Device under test: DEBO MICROSD2 (MicroSD Card Adapter)
https://www.reichelt.de/be/en/developer-boards-breakout-board-for-microsd-cards-debo-microsd-2-p266045.html?&trstct=pos_1&nbc=1
Tested with: Arduino Nano ATmega328p (Old Bootloader)
08.04.2022

MicroSD Module - Arduino
GND  - GND
VCC  - 5V
MISO - D11
MOSI - D12
SCK  - D13
CS   - D9
*/

#include <SPI.h>
#include <SD.h>

#define SD_CS 9

File textdoc;
void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Initialize MicroSD Card:");   

  if (!SD.begin(SD_CS)) {
    Serial.println("Failed!");
    return;
  }
  Serial.println("Successful");

  //--- Status ----
  textdoc = SD.open("status.txt");
  if (textdoc) 
  {                                            
    Serial.println("status.txt:");
    while (textdoc.available())
    {                          
      Serial.write(textdoc.read());
    }
    textdoc.close();

    if(SD.exists("status.txt")){
      Serial.println("Deleting...");
      SD.remove("status.txt");
      Serial.println("Done");
    }
  } 
  else                                                             
  {
    Serial.println("Couldn't open status.txt! The file doesn't seem to exist!");
  }
  Serial.println();
  

  //--- Data ----
  textdoc = SD.open("data.txt");
  if (textdoc) 
  {                                            
    Serial.println("data.txt:");
    while (textdoc.available())
    {                          
      Serial.write(textdoc.read());
    }
    textdoc.close();

    if(SD.exists("data.txt")){
      Serial.println("Deleting...");
      SD.remove("data.txt");
      Serial.println("Done");
    }
  } 
  else                                                             
  {
    Serial.println("Couldn't open data.txt! The file doesn't seem to exist!");
  }

  Serial.println("Done");
}

void loop()
{ 
}
