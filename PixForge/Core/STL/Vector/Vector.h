#pragma once
#include <string>

namespace PF::STL{
template<typename T>
class Vector{
private:
  T* data;
  unsigned int _size = 0;
  unsigned int capacity = 1;
private:
  void resize();
public:
  Vector(const unsigned int &capacity = 1);
  ~Vector(){ if(data) delete[] data; };
public:
  void push(const T &line);
  T pop();
  T remove(const unsigned int &index);
  const unsigned int size() const;
  void clear();
public:
  T& operator[](const unsigned int &index) { return data[index]; };
  const T& operator[](const unsigned int &index) const { return data[index]; };
public:
  Vector<Vector<std::string>*> split(const char &sep) const;
  std::string concat(const char &sep) const;
public:
  void sort(bool (*compare)(T, T));
private:
  void quickSort(int a, int b, bool (*compare)(T, T));
  const int partition(int a, int b, bool (*compare)(T, T));
};
}; // namespace PF::STL

#include "Vector.hpp"