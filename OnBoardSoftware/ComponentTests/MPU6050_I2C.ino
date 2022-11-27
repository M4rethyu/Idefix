/*
Project: IDEFIX
Device under test: DEBO SENS 3-AXIS MPU6050
https://www.reichelt.de/be/en/developer-boards-acceleration-amp-gyroscope-3-axis-mpu-605-debo-sens-3axis-p253987.html?PROVID=2788&gclid=Cj0KCQjw0PWRBhDKARIsAPKHFGjE9pr-Rn-On4U8vLCTOjR9nR6h6SNWmVn4N5A0JD7yDVEm5DMcyN0aAtd7EALw_wcB&&r=1
Script based on: https://wolles-elektronikkiste.de/mpu6050-beschleunigungssensor-und-gyroskop
Tested with: Arduino Nano ATmega328P (Old Bootloader)
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

int16_t accX, accY, accZ, gyroX, gyroY, gyroZ, tRaw; // Raw register values (accelaration, gyroscope, temperature)

void setup() {
 /* //Debugging
  Serial.begin(9600);
  while (!Serial) {;}

  //init MPU6050
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // wake up!
  Wire.endTransmission(true);
  */

 pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  Serial.print("test1");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  Serial.print("test2");
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
  Serial.print("test3");
/*  Wire.beginTransmission(MPU6050_ADDR);
  
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)

  //keep connection active
  Wire.endTransmission(false);
                               
  //request a total of 7*2=14 registers
  Wire.requestFrom(MPU6050_ADDR, 14, true); 
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same int16_t variable
  accX = Wire.read() << 8 | Wire.read(); //reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accY = Wire.read()<<8 | Wire.read();   //reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accZ = Wire.read()<<8 | Wire.read();   //reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  tRaw = Wire.read()<<8 | Wire.read();   //reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyroX = Wire.read()<<8 | Wire.read();  //reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyroY = Wire.read()<<8 | Wire.read();  //reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyroZ = Wire.read()<<8 | Wire.read();  //reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

  
  Serial.print("AcX = "); Serial.print(accX);
  Serial.print(" | AcY = "); Serial.print(accY);
  Serial.print(" | AcZ = "); Serial.print(accZ);
  Serial.print(" | tmp = "); Serial.print((tRaw + 12412.0) / 340.0); //temp. conversion from data sheet
  Serial.print(" | GyX = "); Serial.print(gyroX);
  Serial.print(" | GyY = "); Serial.print(gyroY);
  Serial.print(" | GyZ = "); Serial.print(gyroZ);
  Serial.println();
  delay(1000);
  */
}
