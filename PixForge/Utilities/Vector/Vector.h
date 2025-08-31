#pragma once
#include <string>
#include <stdexcept>

namespace PF::UTILITIES{
template<typename T>
class Vector{
private:
  T* data;
  unsigned int _size = 0;
  unsigned int capacity = 1;
public:
    Vector(const unsigned int &capacity = 1);
    ~Vector();
public:
  void push(const T &line);
  T pop();
  T remove(const unsigned int &index);
  const unsigned int size() const;
  void resize();
  void clear();
  T& operator[](const unsigned int &index);
  const T& operator[](const unsigned int &index) const;
  Vector<Vector<std::string>*> split(const char &sep) const;
  std::string concat(const char &sep) const;
  void sort(bool (*compare)(T, T));
  void quickSort(int a, int b, bool (*compare)(T, T));
  const int partition(int a, int b, bool (*compare)(T, T));
};
}; // namespace PF::UTILITIES

#include "Vector.hpp"