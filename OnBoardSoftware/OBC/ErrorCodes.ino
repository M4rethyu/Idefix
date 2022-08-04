#include "ErrorCodes.h"

void sendErrorCode(int num){
	switch(num){
    case 1:
      setLED(1, 100, 0, 500, 1, 100, 0, 500, 1, 100, 0);
      break;
		default:
			setLED(1, 50, 0, 50, 1, 50, 0, 50, 1, 50, 0);
			break;
	}
}

void setLED(int s1, int d1, int s2, int d2, int s3, int d3, int s4, int d4, int s5, int d5, int s6){
  for(int i = 0; i < 5; i++){
    digitalWrite(LED, s1);
    delay(d1);
    digitalWrite(LED, s2);
    delay(d2);
    digitalWrite(LED, s3);
    delay(d3);
    digitalWrite(LED, s4);
    delay(d4);
    digitalWrite(LED, s5);
    delay(d5);
    digitalWrite(LED, s6);
    delay(2000);
  }
}
