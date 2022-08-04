#include "MPU6050.h"

void initializeMPU6050(){
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // wake up!
  Wire.endTransmission(true);
}	

String getMPU6050Data(){
	Wire.beginTransmission(MPU6050_ADDR);
  
	Wire.write(0x3B); 							            //starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false); 				        //keep connection active to request data from the sensor						   
	Wire.requestFrom(MPU6050_ADDR, 14, true); 	//request a total of 7*2=14 registers
	
	accX = Wire.read() << 8 | Wire.read(); 	// reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
	accY = Wire.read() << 8 | Wire.read(); 	// reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
	accZ = Wire.read() << 8 | Wire.read(); 	// reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
	tRaw = Wire.read() << 8 | Wire.read(); 	// reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
	gyroX = Wire.read() << 8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
	gyroY = Wire.read() << 8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
	gyroZ = Wire.read() << 8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

  String str = String(String(accX) + "," + String(accY) + "," + String(accZ) + "," + String((tRaw + 12412.0) / 340.0) + "," + String(gyroX) + "," + String(gyroY) + "," + String(gyroZ)); 
  
	return str;
}
