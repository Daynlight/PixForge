#include "Mat.h"

template <typename T, unsigned int S, unsigned int R>
void PF::STL::Mat<T, S, R>::operator*(Mat<T, S, R> &second) { 
  Mat<T, S, R> temp(0);
  for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) for(unsigned int k = 0; k < S; k++) temp[i][j] += data[i][k] * second[k][j];
  *this = temp;
};