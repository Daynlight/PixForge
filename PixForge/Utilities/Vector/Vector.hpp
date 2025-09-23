#include "Vector.h"

template<typename T>
PF::UTILITIES::Vector<T>::Vector(const unsigned int &capacity) :capacity(capacity < 1 ? 1 : capacity) { data = new T[this->capacity]; }

template <typename T>
inline PF::UTILITIES::Vector<T>::~Vector() { if(data) delete[] data; };
template<>
inline PF::UTILITIES::Vector<PF::UTILITIES::Vector<std::string>*>::~Vector() {
    if (data) {
        for (unsigned int i = 0; i < _size; ++i) {
            delete data[i]; // free each heap object
        }
        delete[] data;
    }
}

template<typename T>
const unsigned int PF::UTILITIES::Vector<T>::size() const { return _size; };

template<typename T>
void PF::UTILITIES::Vector<T>::resize(){
  if(capacity < 2) capacity = 2;
  unsigned int new_capacity = capacity + capacity / 2;
  if(new_capacity <= capacity) new_capacity = capacity + 1;
  T* temp = new T[new_capacity];
  for(unsigned int i = 0; i < _size; i++) temp[i] = data[i];
  if(data) delete[] data;
  data = temp;
  capacity = new_capacity;
};

template <typename T>
inline void PF::UTILITIES::Vector<T>::reserve(const unsigned int size) {
  if(data) delete[] data;
  data = new T[size];
  capacity = size;
  _size = 0;
};

template<typename T>
void PF::UTILITIES::Vector<T>::push(const T &line) {
  if(_size >= capacity) resize();
  data[_size] = line;
  _size++;
};

template<typename T>
T PF::UTILITIES::Vector<T>::pop(){
  if(_size < 1) throw std::runtime_error("Vector is empty"); 
  _size--;
  return data[_size];
};

template<typename T>
void PF::UTILITIES::Vector<T>::clear(){
  if(data) delete[] data;
  data = new T[1];
  capacity = 1;
  _size = 0;
};

template <typename T>
inline T PF::UTILITIES::Vector<T>::remove(const unsigned int &index) {
  if(index >= _size) throw std::runtime_error("Index >= size");
  T temp = data[index];
  for(unsigned int i = index; i < _size - 1; i++) data[i] = data[i + 1];
  _size--;
  return temp;
};

template<>
inline PF::UTILITIES::Vector<PF::UTILITIES::Vector<std::string>*> PF::UTILITIES::Vector<std::string>::split(const char &sep) const {
  Vector<Vector<std::string>*> result;
  for(int i = 0; i < _size; i++){
    Vector<std::string> *temp = new Vector<std::string>();
    std::string line = data[i];
    std::string word = "";
    for(unsigned int j = 0; j < line.size(); j++){
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

template<>
inline std::string PF::UTILITIES::Vector<std::string>::concat(const char &sep) const {
  std::string result = "";
  for(unsigned int i = 0; i < _size; i++) result += data[i] + sep;
  return result;
};

template<typename T>
T& PF::UTILITIES::Vector<T>::operator[](const unsigned int &index) 
{ if(index >= _size) throw std::out_of_range("index out of range"); return data[index]; };

template<typename T>
const T& PF::UTILITIES::Vector<T>::operator[](const unsigned int &index) const 
{ if(index >= _size) throw std::out_of_range("index out of range"); return data[index]; };

template <typename T>
void PF::UTILITIES::Vector<T>::sort(bool (*compare)(T, T)) { quickSort(0, _size - 1, compare); };

template <typename T>
void PF::UTILITIES::Vector<T>::quickSort(int a, int b, bool (*compare)(T, T)) {
  if(a >= b) return;
  int c = partition(a, b, compare);
  quickSort(a, c - 1, compare);
  quickSort(c + 1, b, compare);
};

template <typename T>
const int PF::UTILITIES::Vector<T>::partition(int a, int b, bool (*compare)(T, T)){
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