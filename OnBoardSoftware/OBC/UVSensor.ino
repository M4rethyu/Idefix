String getUVData(){
	sensorValue = analogRead(UV_Pin);
	return(String(sensorValue/1024*3.3 * 0.1)); //*0.1 to get UV-Index 
}
