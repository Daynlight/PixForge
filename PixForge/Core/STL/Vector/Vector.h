#pragma once
#include <string>

namespace PF::STL{
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
  ~Vector(){ if(data) delete[] data; };
public:
  void push(const T line);
  T pop();
  T remove(const size_t index);
  const size_t size() const;
  void clear();
public:
  T& operator[](const size_t index);
  const T& operator[](const size_t index) const { return data[index]; };
public:
  Vector<Vector<std::string>*> split(const char sep);
  std::string concat(const char sep);
public:
  void sort(bool (*compare)(T, T));
private:
  void quickSort(int a, int b, bool (*compare)(T, T));
  const int partition(int a, int b, bool (*compare)(T, T));
};
}; // namespace PF::STL

#include "Vector.hpp"