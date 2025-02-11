#pragma once

namespace PF::STL{
template<typename T, unsigned int S, unsigned int R>
class Mat{
public:
  T data[S][R];
public:
  Mat(T value){ for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = value; };
  Mat(std::initializer_list<T> value) { auto it = value.begin(); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++, ++it) data[i][j] = *it; };
  Mat(const Mat<T, S, R> &second){ for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = second.data[i][j]; };
public:
  void operator=(Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = second[i][j]; };
  void operator+(Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] += second[i][j]; };
  void operator-(Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] -= second[i][j]; };
  void operator*(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] *= value; };
  void operator/(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] /= value; };
  void operator%(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] %= value; };
  void operator+=(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] += value; };
  void operator-=(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] -= value; };
  void operator*=(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] *= value; };
  void operator/=(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] /= value; };
  void operator%=(T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] %= value; };
public:
  void operator*(Mat<T, S, R> &second);
public:
  T& operator()(const unsigned int &row, const unsigned int &col) { return data[row][col]; };
  const T& operator()(const unsigned int &row, const unsigned int &col) const { return data[row][col]; };
};// class Mat
}; // namespace PF::STL

#include "Mat.hpp"