#include "Vec.h"

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S>::Vec() 
{ for(unsigned int i = 0; i < S; i++) data[i] = 0; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S>::Vec(const T &value) 
{ for(unsigned int i = 0; i < S; i++) data[i] = value; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S>::Vec(const std::initializer_list<T> &value) 
{ auto it = value.begin(); for(unsigned int i = 0; i < S; i++, ++it) data[i] = *it; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S>::Vec(const Vec<T, S> &second)
{ for(unsigned int i = 0; i < S; i++) data[i] = second.data[i]; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator=(Vec<T, S> &second)
{ for(unsigned int i = 0; i < S; i++) data[i] = second[i]; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator+=(const Vec<T, S> &second) 
{ for(unsigned int i = 0; i < S; i++) data[i] += second[i]; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator+=(const T &value) 
{ for(unsigned int i = 0; i < S; i++) data[i] += value; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator+(const Vec<T, S> &second) const
{ Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] += second[i]; return temp; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator+(const T &value) const
{ Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] += value; return temp; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator-=(const Vec<T, S> &second) 
{ for(unsigned int i = 0; i < S; i++) data[i] -= second[i]; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator-=(const T &value) 
{ for(unsigned int i = 0; i < S; i++) data[i] -= value; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator-(const Vec<T, S> &second) const
{ Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] -= second[i]; return temp; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator-(const T &value) const
{ Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] -= value; return temp; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator*(const T &value) const
{ Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] *= value; return temp; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator*=(const T &value) 
{ for(unsigned int i = 0; i < S; i++) data[i] *= value; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator/(const T &value) const
{ if(value == 0) throw std::runtime_error("Division by zero"); Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] /= value; return temp; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator/=(const T &value)
{ if(value == 0) throw std::runtime_error("Division by zero"); for(unsigned int i = 0; i < S; i++) data[i] /= value; }

template <typename T, unsigned int S>
inline PF::UTILITIES::Vec<T, S> PF::UTILITIES::Vec<T, S>::operator%(const T &value) const
{ if(value == 0) throw std::runtime_error("Division by zero"); Vec<T, S> temp(*this); for(unsigned int i = 0; i < S; i++) temp[i] %= value; return temp; }

template <typename T, unsigned int S>
inline void PF::UTILITIES::Vec<T, S>::operator%=(const T &value) 
{ if(value == 0) throw std::runtime_error("Division by zero"); for(unsigned int i = 0; i < S; i++) data[i] %= value; };

template <typename T, unsigned int S>
inline const T& PF::UTILITIES::Vec<T, S>::operator[](const unsigned int &index) const 
{ if(index >= S) throw std::out_of_range("index out of range"); return data[index]; };

template <typename T, unsigned int S>
inline T& PF::UTILITIES::Vec<T, S>::operator[](const unsigned int &index) 
{ if(index >= S) throw std::out_of_range("index out of range"); return data[index]; };
