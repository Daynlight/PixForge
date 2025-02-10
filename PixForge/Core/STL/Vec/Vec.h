#pragma once
#include <stdio.h>

namespace PF::STL{
template<typename T, size_t S>
class Vec{
public:
  T data[S];
public:
  Vec(){};
  Vec(std::initializer_list<T> value){
    auto it = value.begin();
    for(size_t i = 0; i < S; i++, ++it) data[i] = *it;
  };
  Vec(T *data){ for(size_t i = 0; i < S; i++) this->data[i] = data[i]; };
  Vec(const Vec<T, S> &vec){ for(size_t i = 0; i < S; i++) data[i] = vec.data[i]; };
  void operator%(T value){ for(size_t i = 0; i < S; i++) data[i] %= value; };
  void operator/=(T value) { for(size_t i = 0; i < S; i++) data[i] /= value; };
  void operator=(Vec<T, S> value) { for(size_t i = 0; i < S; i++) data[i] = value[i]; };
  T& operator[](size_t i){ return data[i]; }
  const T& operator[](size_t i) const { return data[i]; }
  ~Vec(){};
};
}; // namespace PF::STL