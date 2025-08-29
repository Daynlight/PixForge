#include "Vector.h"

template<typename T>
PF::UTILITIES::Vector<T>::Vector(const unsigned int &capacity) :capacity(capacity) { data = new T[capacity]; }

template<typename T>
const unsigned int PF::UTILITIES::Vector<T>::size() const { return _size; };

template<typename T>
void PF::UTILITIES::Vector<T>::resize(){
  capacity *= 2;
  T* temp = new T[capacity];
  for(unsigned int i = 0; i < _size; i++) temp[i] = data[i];
  delete[] data;
  data = temp;
};

template<typename T>
void PF::UTILITIES::Vector<T>::push(const T &line){
  if(_size >= capacity) resize();
  data[_size] = line;
  _size++;
};

template<typename T>
T PF::UTILITIES::Vector<T>::pop(){
  if(_size >= 0){ 
      _size--;
      return data[_size];
    }
  return T();
};

template<typename T>
void PF::UTILITIES::Vector<T>::clear(){
  delete[] data;
  data = new T[1];
  capacity = 1;
  _size = 0;
};

template <typename T>
inline T PF::UTILITIES::Vector<T>::remove(const unsigned int &index){
  T temp = data[index];
  for(unsigned int i = index; i < _size - 1; i++) data[i] = data[i + 1];
  _size--;
  return temp;
};

template<typename T>
PF::UTILITIES::Vector<PF::UTILITIES::Vector<std::string>*> PF::UTILITIES::Vector<T>::split(const char &sep) const {
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
std::string PF::UTILITIES::Vector<T>::concat(const char &sep) const {
  std::string result = "";
  for(unsigned int i = 0; i < _size; i++) result += data[i] + sep;
  return result;
};

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