#pragma once

namespace PF::UTILITIES{
template<typename T, unsigned int S>
class Vec{
private:
  T data[S];
public:
  Vec();
  Vec(const T &value);
  Vec(const std::initializer_list<T> &value);
  Vec(const Vec<T, S> &second);
  void operator=(Vec<T, S> &second);
  Vec<T, S> operator+(const Vec<T, S> &second) const;
  void operator+=(const Vec<T, S> &second);
  Vec<T, S> operator-(const Vec<T, S> &second) const;
  void operator-=(const Vec<T, S> &second);
  Vec<T, S> operator+(const T &value) const;
  void operator+=(const T &value);
  Vec<T, S> operator-(const T &value) const;
  void operator-=(const T &value);
  Vec<T, S> operator*(const T &value) const;
  void operator*=(const T &value);
  Vec<T, S> operator/(const T &value) const;
  void operator/=(const T &value);
  Vec<T, S> operator%(const T &value) const;
  void operator%=(const T &value);
  const T& operator[](const unsigned int &index) const;
  T& operator[](const unsigned int &index);
};
// class Vec
}; // namespace PF::UTILITIES

#include "Vec.hpp"