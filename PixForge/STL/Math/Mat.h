#pragma once

namespace PF::STL{
template<typename T, unsigned int S, unsigned int R>
class Mat{
public:
  T data[S][R];
public:
  Mat(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = value; };
  Mat(const std::initializer_list<T> &value) { auto it = value.begin(); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++, ++it) data[i][j] = *it; };
  Mat(const Mat<T, S, R> &second){ for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = second.data[i][j]; };
public:
  void operator=(const Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] = second.data[i][j]; };
  Mat<T, S, R> operator+(const Mat<T, S, R> &second) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] += second.data[i][j]; return temp; };
  void operator+=(const Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] += second.data[i][j]; };
  Mat<T, S, R> operator-(const Mat<T, S, R> &second) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] -= second.data[i][j]; return temp; };
  void operator-=(const Mat<T, S, R> &second) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] -= second.data[i][j]; };
public:
  Mat<T, S, R> operator+(const T &value) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] += value; return temp; };
  void operator+=(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] += value; };
  Mat<T, S, R> operator-(const T &value) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] -= value; return temp; };
  void operator-=(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] -= value; };
  Mat<T, S, R> operator*(const T &value) const  { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] *= value; return temp; };
  void operator*=(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] *= value; };
  Mat<T, S, R> operator/(const T &value) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] /= value; return temp; };
  void operator/=(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] /= value; };
  Mat<T, S, R> operator%(const T &value) const { Mat<T, S, R> temp(*this); for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) temp.data[i][j] %= value; return temp; };
  void operator%=(const T &value) { for(unsigned int i = 0; i < S; i++) for(unsigned int j = 0; j < R; j++) data[i][j] %= value; };
public:
  Mat<T, R, S> operator*(const Mat<T, S, R> &second) const;
  void operator*=(const Mat<T, S, R> &second);
public:
  T& operator()(const unsigned int &row, const unsigned int &col) { return data[row][col]; };
  const T& operator()(const unsigned int &row, const unsigned int &col) const { return data[row][col]; };
};// class Mat
}; // namespace PF::STL

#include "Mat.hpp"