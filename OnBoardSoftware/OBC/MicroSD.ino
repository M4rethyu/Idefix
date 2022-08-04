#include "MicroSD.h"

bool initializeMicroSD(){
	return SD.begin(CS_SD);
}
