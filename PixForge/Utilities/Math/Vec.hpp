#include "Vec.h"

template<typename T, unsigned int S>
template<typename U>
PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator*(const Mat<U, S, S>& matrix) const {
    PF::UTILITIES::Vec<T, S> result;
    for (unsigned int i = 0; i < S; i++) {
        U temp = 0;
        for (unsigned int j = 0; j < S; j++) {
            temp += matrix(i, j) * data[j];
        };
        result[i] = static_cast<T>(temp);
    };
    return result;
};

template <typename T, unsigned int S>
template <typename U>
inline void PF::UTILITIES::Vec<T, S>::operator*=(const Mat<U, S, S> &matrix) {
    for (unsigned int i = 0; i < S; i++) {
        U temp = 0;
        for (unsigned int j = 0; j < S; j++) {
            temp += matrix(i, j) * data[j];
        };
        data[i] = static_cast<T>(temp);
    };
};
