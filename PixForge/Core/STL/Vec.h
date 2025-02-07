#pragma once
#include <stdio.h>

namespace PF{
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
      Vec(T *data){
        for(size_t i = 0; i < S; i++) this->data[i] = data[i];
      };
      Vec(const Vec<T, S> &vec){
        for(size_t i = 0; i < S; i++) data[i] = vec.data[i];
      };
      void operator%(T value){
        for(size_t i = 0; i < S; i++) data[i] %= value;
      }
      T& operator[](size_t i){ return data[i]; }
      ~Vec(){};
  };
};