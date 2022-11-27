/*
 *
Project: IDEFIX
27.11.2022
*
*/

float getAverage(float* data, int size){
  float sum = 0.0f;

  for(int i = 0; i < size; i++){
    sum += data[i];
  }

  return sum/(float)size;
}
