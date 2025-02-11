#pragma once
#include "STL/Vector/Vector.h"
#include "STL/File/File.h"
#include <filesystem>

namespace PF::STL{
class Folder{
private:
  Vector<std::pair<char, std::string>> data;
  std::string path;
public:
  Folder(const std::string &path) : path(path) {};
public:
  const bool exist() const { return std::filesystem::exists(path); };
  void create();
  void remove(const std::string &folder) { std::filesystem::remove_all(path + folder); };
public:
  void fetchList();
  const unsigned int size() const { return data.size(); };
  File openFile(const std::string &file) { return File(path + file); };
  Folder openFolder(const std::string &folder) const { return Folder(path + folder); };
  Folder backFolder() const;
public:
  std::string getPath() { return path; };
  std::pair<char, std::string> &operator[](const unsigned int &index) { return data[index]; };
  const std::pair<char, std::string> &operator[](const unsigned int &index) const { return data[index]; };
};
}; // namespace PF::STL