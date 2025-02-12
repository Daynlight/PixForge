#include "Mat.h"

template <typename T, unsigned int S, unsigned int R>
inline PF::STL::Mat<T, R, S> PF::STL::Mat<T, S, R>::operator*(const PF::STL::Mat<T, S, R> &second) const {
  PF::STL::Mat<T, S, R> temp(0);
  for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) for(unsigned int k = 0; k < S; k++) temp[i][j] += data[i][k] * second[k][j];
  return temp;
};