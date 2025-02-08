#pragma once
#include <string>

namespace PF{
template<typename T>
class Vector{
private:
  T* data;
  size_t _size = 0;
  size_t capacity = 1;
private:
  void resize();
public:
  Vector(const size_t capacity = 1);
  size_t size();
  void push(const T line);
  T pop();
  T remove(const size_t index);
  void clear();
  T& operator[](const size_t index);
  Vector<Vector<std::string>> split(const char sep);
  std::string concat(const char sep);
};
}; // namespace PF

#include "Vector.hpp"