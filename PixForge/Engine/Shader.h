#pragma once
#include <string>
#include "Utilities/File/File.h"

namespace PF::ENGINE{
class Shader{
private:
  std::string data;
  UTILITIES::File file;
public:
  Shader(const std::string &path) : file(path) {};
  Shader(const Shader &second) : data(second.data), file(second.file.getPath()) {};
  Shader(std::string data, const std::string &path) : data(data), file(path) {};
  void save() { file.save(); };
  void read() { file.read(); };
  const char* getData() { return data.c_str(); };
public:
  Shader& operator=(const Shader &second) { data = second.data; file = second.file; return *this; }
}; // class Shader
}; // namespace PF::ENGINE