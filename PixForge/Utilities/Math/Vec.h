#pragma once
#include "Mat.h"

namespace PF::UTILITIES{
template<typename T, unsigned int S>
class Vec{
public:
  T data[S];
public:
  Vec() { for(unsigned int i = 0; i < S; i++) data[i] = 0; };
  Vec(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] = value; };
  Vec(const std::initializer_list<T> &value) { auto it = value.begin(); for(unsigned int i = 0; i < S; i++, ++it) data[i] = *it; };
  Vec(const Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] = second.data[i]; };
public:
  void operator=(Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] = second[i]; };
  Vec<T, S> operator+(const Vec<T, S> &second) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] += second[i]; return temp; };
  void operator+=(const Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] += second[i]; };
  Vec<T, S> operator-(const Vec<T, S> &second) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] -= second[i]; return temp; };
  void operator-=(const Vec<T, S> &second) { for(unsigned int i = 0; i < S; i++) data[i] -= second[i]; };
public:
  Vec<T, S> operator+(const T &value) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] += value; return temp; };
  void operator+=(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] += value; };
  Vec<T, S> operator-(const T &value) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] -= value; return temp; };
  void operator-=(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] -= value; };
  Vec<T, S> operator*(const T &value) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] *= value; return temp; };
  void operator*=(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] *= value; };
  Vec<T, S> operator/(const T &value) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] /= value; return temp; };
  void operator/=(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] /= value; };
  Vec<T, S> operator%(const T &value) const { Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] %= value; return temp; };
  void operator%=(const T &value) { for(unsigned int i = 0; i < S; i++) data[i] %= value; };
public:
  template<typename U>
  Vec<T, S> operator*(const Mat<U, S, S> &matrix) const;
  template<typename U>
  void operator*=(const Mat<U, S, S> &matrix);
public:
  T& operator[](const unsigned int &index) { return data[index]; };
  const T& operator[](const unsigned int &index) const { return data[index]; };
}; // class Vec
}; // namespace PF::STL

#include "Vec.hpp"