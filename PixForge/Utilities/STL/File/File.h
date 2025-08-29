#pragma once
#include "Utilities/STL/Vector/Vector.h"
#include <string>
#include <fstream>
#include <filesystem>

namespace PF::STL{
class File{
private:
  Vector<std::string> data;
  std::string path;
  std::fstream file;
public:
  File(const std::string &path) : path(path) { file.open(path, std::ios::in | std::ios::out); };
  ~File() { file.close(); };
public:
  const bool exist() const { return std::filesystem::exists(path); };
  void create();
  void remove() { std::filesystem::remove(path); };
public:
  void push(const std::string &line) { data.push(line); };
  std::string pop() { return data.pop(); };
  const unsigned int size() const { return data.size(); };
  void clear() { while(size() > 0) pop(); };
public:
  const std::string getPath() const { return path; };
  void setPath(const std::string &new_path) { file.close(); path = new_path; file.open(path, std::ios::in | std::ios::out); };
  std::string& operator[](const unsigned int &index) { return data[index]; };
  const std::string& operator[](const unsigned int &index) const { return data[index]; };
  File& operator=(const File &second) { data = second.data; path = second.path; return *this; };
public:
  Vector<Vector<std::string>*> split(const char &sep) { return data.split(sep); };
  std::string concat(const char &sep) { return data.concat(sep); };
public:
  void read();
  void save();
}; // class File
}; // namespace PF::STL