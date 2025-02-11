#include "Vector.h"

template<typename T>
PF::STL::Vector<T>::Vector(const size_t capacity) :capacity(capacity) { data = new T[capacity]; }

template<typename T>
const size_t PF::STL::Vector<T>::size() const { return _size; };

template<typename T>
void PF::STL::Vector<T>::resize(){
  capacity *= 2;
  T* temp = new T[capacity];
  for(size_t i = 0; i < _size; i++) temp[i] = data[i];
  delete[] data;
  data = temp;
};

template<typename T>
void PF::STL::Vector<T>::push(const T line){
  if(_size >= capacity) resize();
  data[_size] = line;
  _size++;
};

template<typename T>
T PF::STL::Vector<T>::pop(){
  if(_size >= 0){ 
      _size--;
      return data[_size];
    }
  return T();
};

template<typename T>
void PF::STL::Vector<T>::clear(){
  delete[] data;
  data = new T[1];
  capacity = 1;
  _size = 0;
};

template <typename T>
inline T PF::STL::Vector<T>::remove(const size_t index){
  T temp = data[index];
  for(size_t i = index; i < _size - 1; i++) data[i] = data[i + 1];
  _size--;
  return temp;
};

template<typename T>
T &PF::STL::Vector<T>::operator[](const size_t index){ return data[index]; };

template<typename T>
PF::STL::Vector<PF::STL::Vector<std::string>*> PF::STL::Vector<T>::split(const char sep){
  Vector<Vector<std::string>*> result;
  for(int i = 0; i < _size; i++){
    Vector<std::string> *temp = new Vector<std::string>();
    std::string line = data[i];
    std::string word = "";
    for(int j = 0; j < line.size(); j++){
      if(line[j] == sep){
        temp->push(word);
        word = "";
      }else{
        word += line[j];
      };
    };
    temp->push(word);
    result.push(temp);
  };
  return result;
};

template<typename T>
std::string PF::STL::Vector<T>::concat(const char sep){
  std::string result = "";
  for(size_t i = 0; i < _size; i++) result += data[i] + sep;
  return result;
};

template <typename T>
void PF::STL::Vector<T>::sort(bool (*compare)(T, T)) { quickSort(0, _size - 1, compare); };

template <typename T>
void PF::STL::Vector<T>::quickSort(int a, int b, bool (*compare)(T, T)) {
  if(a >= b) return;
  int c = partition(a, b, compare);
  quickSort(a, c - 1, compare);
  quickSort(c + 1, b, compare);
};

template <typename T>
const int PF::STL::Vector<T>::partition(int a, int b, bool (*compare)(T, T)){
  T pivot = data[b];
  int i = a - 1;
  for(unsigned int j = a; j < b; j++){
    if(compare(data[j], pivot)){
      i++;
      std::swap(data[i], data[j]);
    };
  };
  std::swap(data[i + 1], data[b]);
  return i + 1;
};