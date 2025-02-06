#pragma once
#include <stdio.h>

namespace PF{
  template<typename T, size_t S>
  class Vec{
    private:
      T data[S];
    public:
      Vec(){};
      Vec(std::initializer_list<T> value){
        for(size_t i = 0; i < S; i++) data[i] = value[i];
      };
      Vec(T *data){
        for(size_t i = 0; i < S; i++) this->data[i] = data[i];
      };
      Vec(const Vec<T, S> &vec){
        for(size_t i = 0; i < S; i++) data[i] = vec.data[i];
      };
      SDL_Rect getRect(){
        SDL_Rect rect = { data[0], data[1], data[2], data[3] };
        return rect;
      };
      ~Vec(){};
  };
};