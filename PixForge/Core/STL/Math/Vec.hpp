#include "Vec.h"

template<typename T, unsigned int S>
template<typename U>
PF::STL::Vec<T, S> PF::STL::Vec<T, S>::operator*(const Mat<U, S, S>& matrix) const {
    PF::STL::Vec<T, S> result;
    for (unsigned int i = 0; i < S; i++) {
        U temp = 0;
        for (unsigned int j = 0; j < S; j++) {
            temp += matrix(i, j) * data[j];
        };
        result[i] = static_cast<T>(temp);
    };
    return result;
};
