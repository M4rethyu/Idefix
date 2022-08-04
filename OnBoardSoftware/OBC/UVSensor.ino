#include "UVSensor.h"

String getUVData(){
	sensorValue = analogRead(UV_Pin);
	return(String(sensorValue/1024*3.3));
}
