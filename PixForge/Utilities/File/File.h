#pragma once
#include "Utilities/Vector/Vector.h"
#include <string>
#include <fstream>
#include <filesystem>

namespace PF::UTILITIES{
class File{
private:
  Vector<std::string> data;
  std::string path;
  std::fstream file;
public:
  File(const std::string &path);
  ~File();
  const bool exist() const;
  void create();
  void remove();
  void push(const std::string &line);
  std::string pop();
  const unsigned int size() const;
  void clear();
  const std::string getPath() const;
  void setPath(const std::string &new_path);
  const std::string& operator[](const unsigned int &index) const;
  std::string& operator[](const unsigned int &index);
  File& operator=(const File &second);
  Vector<Vector<std::string>*> split(const char &sep);
  std::string concat(const char &sep);
  void read();
  void save();
}; // class File
}; // namespace PF::STL