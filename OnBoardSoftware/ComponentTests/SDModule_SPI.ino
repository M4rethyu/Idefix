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
  //Init
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Initialize MicroSD Card:");   

  if (!SD.begin(SD_CS)) {
    Serial.println("Failed!");
    return;
  }
  Serial.println("Successful");


  //Write
  textdoc = SD.open("status.txt", FILE_WRITE); //create file
  if (textdoc) 
  {                                       
    Serial.println("Write to status.txt...");
    textdoc.println("Ich bin eine Textdatei!");
    textdoc.close();
    Serial.println("Done");
  } 
  else 
  {
    Serial.println("Couldn't open and write to status.txt!");
  }


  //Read
  textdoc = SD.open("status.txt");
  if (textdoc) 
  {                                            
    Serial.println("Reading test.txt:");
    while (textdoc.available())
    {                          
      Serial.write(textdoc.read());
    }
    textdoc.close();
    Serial.println("Done");
  } 
  else                                                             
  {
    Serial.println("Couldn't open and read from status.txt!");
  }

  if(SD.exists("status.txt")){
    Serial.println("Deleting status.txt...");
    SD.remove("status.txt");
    Serial.println("Done");
  }

  Serial.println("Done");
    
}

void loop()
{ 
}
