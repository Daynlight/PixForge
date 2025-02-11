#include "Vec.h"

template<typename T, unsigned int S>
template<typename U, unsigned int R>
PF::STL::Vec<U, R> PF::STL::Vec<T, S>::operator*(const Mat<U, R, R>& matrix) const {
    PF::STL::Vec<U, R> result(0);
    for (unsigned int i = 0; i < R; i++) {
        for (unsigned int j = 0; j < S; j++) {
            result[i] += data[j] * matrix(i, j);
        }
    }
    return result;
}
