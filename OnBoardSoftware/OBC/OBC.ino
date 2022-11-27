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
#include "Utils.h"

#define Button 6
#define Servo_Pin 8

Servo servo;
int btn_state = 0;
float pressureAtSeaLevelhPa = 1013.2;
int counter = 0;

float deploymentAlt_par = 107.75; //Height in m at which the servo will act and deploy the parachute
float deploymentAlt_pay = 107.40;//Height in m at which the servo will act and deploy the payload
bool hasDeployedPar = 0;
bool hasDeployedPay = 0;

double startTime = 0.0;

void setup(){
  Serial.begin(9600);

  startTime = millis(); //starting time

  pinMode(LED, OUTPUT);
  
  //SetUp BMP280
  if(!initializeBMP280()){
    sendErrorCode(1);
    while(1);
  }

  /* MicroSD broken atm.
  //SetUp MicroSD
  if(!initializeMicroSD()){
    sendErrorCode(2);
    while(1);
  }
  */

  //SetUp MPU6050
  initializeMPU6050();

  //SetUp Servo
  servo.attach(Servo_Pin);
  delay(5);
  servo.write(0);
  delay(5);
  

  
  //Indicate ReadyForFlight
  digitalWrite(LED, HIGH);

  btn_state = digitalRead(Button);
  while(btn_state == 0){
    btn_state = digitalRead(Button);
  }

  Serial.print("Button-GO.\n");
  digitalWrite(LED, LOW);

  
}

void loop(){


  String temp = getBMP280Temperature();
  String pres = getBMP280Pressure();
  String alt = getBMP280Altitude(pressureAtSeaLevelhPa);
  String uv = getUVData();
  delay(10);
  String mpu = getMPU6050Data();
  delay(10);
  String str;
  
  
  if(counter % 10 == 0){  
    str = temp + "deg, " + pres + "hPa, " + alt + "m, " + uv + " uv-index" +  "\t|counter: " + counter + "\t|MPU: " + mpu + "\n";   
  } 
  
  Serial.print(str);

  counter++;

  if(alt.toFloat() < deploymentAlt_par && !hasDeployedPar){
    servo.write(180);
    hasDeployedPar = 1;
    float deltaT = (millis() - startTime)/1000;
    String s = "Deployed parachute at "+ alt + "m at " + deltaT + "s \n";
    Serial.print(s);
    delay(5);
  }

  if(alt.toFloat() < deploymentAlt_pay && !hasDeployedPay){
    servo.write(360);
    hasDeployedPay = 1;
    float deltaT = (millis() - startTime)/1000;
    String s = "Deployed payload at "+ alt + "m at " + deltaT + "s \n";
    Serial.print(s);
    delay(5);
  }
    

  
  delay(100);
}
