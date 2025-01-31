#include "STL.h"

template<typename T>
PF::Vector<T>::Vector(const size_t capacity) :capacity(capacity) { data = new T[capacity]; }

template<typename T>
void PF::Vector<T>::resize(){
  capacity *= 2;
  T* temp = new T[capacity];
  for(size_t i = 0; i < _size; i++) temp[i] = data[i];
  delete[] data;
  data = temp;
}

template<typename T>
T &PF::Vector<T>::operator[](const size_t index) { return data[index]; }

template<typename T>
void PF::Vector<T>::push(const T line){
  if(_size >= capacity) resize();
  data[_size] = line;
  _size++;
}

template<typename T>
T PF::Vector<T>::pop(){
  if(_size >= 0){ 
      _size--;
      return data[_size];
    }
  return T();
}

template<typename T>
void PF::Vector<T>::clear(){
  delete[] data;
  data = new T[1];
  capacity = 1;
  _size = 0;
}

template <typename T>
inline T PF::Vector<T>::remove(const size_t index){
  T temp = data[index];
  for(size_t i = index; i < _size - 1; i++) data[i] = data[i + 1];
  _size--;
  return temp;
}

template<typename T>
size_t PF::Vector<T>::size() { return _size; }
