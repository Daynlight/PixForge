#include "Vec.h"

template <typename T, unsigned int S>
void PF::STL::Vec<T, S>::operator*(Mat<T, S, S> &matrix){
  Vec<T, S> temp(0);
  for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < S; j++) temp[i] += data[j] * matrix[j][i];
  *this = temp;
};