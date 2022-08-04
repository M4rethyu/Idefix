#include "BMP280.h"

bool initializeBMP280(){
	return bmp.begin(BMP280_I2C_ADDRESS);
}

String getBMP280Pressure(){
	return String(bmp.readPressure());
}

String getBMP280Temperature(){
	return String(bmp.readTemperature());
}

String getBMP280Altitude(float pressureAtSeaLevelhPa){
  return String(bmp.readAltitude(pressureAtSeaLevelhPa));  
}
