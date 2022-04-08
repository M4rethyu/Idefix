/*
Project: Idefix
File: OBC (Main)
*/

#include <SPI.h>
#include <Servo.h>
#include "BMP280.h"
#include "MPU6050.h"
#include "UVSensor.h"
#include "MicroSD.h"
#include "ErrorCodes.h"

#define Button 6
#define Servo_Pin 8

Servo servo;
int btn_state = 0;
float pressureAtSeaLevelhPa = 1013.2;

void setup() {
  //SetUp BMP280
  if(!initializeBMP280()){
    sendErrorCode(1);
    while(1);
  }

  //SetUp MicroSD
  if(!initializeMicroSD()){
    sendErrorCode(2);
    while(1);
  }
  
  //SetUp MPU6050
  initializeMPU6050();

  //SetUp Servo
  servo.attach(Servo_Pin);
  delay(100);
  servo.write(0);

  //Indicate ReadyForFlight
  digitalWrite(LED, HIGH);
  file = SD.open("data.txt", FILE_WRITE);
  
  btn_state = digitalRead(Button);
  while(btn_state == 0){
    btn_state = digitalRead(Button);
  }
  
  digitalWrite(LED, LOW);
  delay(2000);
}

int counter = 0;

void loop() {
  String t = String(millis());
  String temp = getBMP280Temperature();
  String pressure = getBMP280Pressure();
  String alt = getBMP280Altitude(pressureAtSeaLevelhPa);
  delay(10);
  String mpu = getMPU6050Data();
  delay(10);
  String uv = getUVData();

  String str = t + "," + pressure + "," + temp + "," + alt + "," + mpu + "," + uv;
  file.println(str);
  
  btn_state = digitalRead(Button);
  if(btn_state == HIGH){
    file.close();
    while(1){
      sendErrorCode(-1);
    }
  }

  counter++;

  if(counter % 20 == 0){
    delay(5);
    servo.write(180);
    delay(5);
  }
  else if(counter % 20 == 10){
    delay(5);
    servo.write(0);
    delay(5);
  }

  delay(60);
}
