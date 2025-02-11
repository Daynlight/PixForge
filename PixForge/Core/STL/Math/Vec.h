#pragma once
#include "Mat.h"

namespace PF::STL{
template<typename T, unsigned int S>
class Vec{
public:
  T data[S];
public:
  Vec(T value){ for(unsigned int i = 0; i < S; i++) data[i] = value; };
  Vec(std::initializer_list<T> value) { auto it = value.begin(); for(unsigned int i = 0; i < S; i++, ++it) data[i] = *it; };
  Vec(const Vec<T, S> &second){ for(unsigned int i = 0; i < S; i++) data[i] = second.data[i]; };
public:
  void operator=(Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] = second[i]; };
  void operator+(Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] += second[i]; };
  void operator-(Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] -= second[i]; };
  void operator*(T &value) { for(unsigned int i = 0; i < S; i++) data[i] *= value; };
  void operator/(T &value) { for(unsigned int i = 0; i < S; i++) data[i] /= value; };
  void operator%(T &value) { for(unsigned int i = 0; i < S; i++) data[i] %= value; };
  void operator+=(T &value) { for(unsigned int i = 0; i < S; i++) data[i] += value; };
  void operator-=(T &value) { for(unsigned int i = 0; i < S; i++) data[i] -= value; };
  void operator*=(T &value) { for(unsigned int i = 0; i < S; i++) data[i] *= value; };
  void operator/=(T &value) { for(unsigned int i = 0; i < S; i++) data[i] /= value; };
  void operator%=(T &value) { for(unsigned int i = 0; i < S; i++) data[i] %= value; };
public:
  void operator*(Mat<T, S, S> &matrix);
  T& operator[](const unsigned int &index) { return data[index]; };
  const T& operator[](const unsigned int &index) const { return data[index]; };
}; // class Vec
}; // namespace PF::STL

#include "Vec.hpp"