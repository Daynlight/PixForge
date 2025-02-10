#pragma once
#include "STL/Vector/Vector.h"
#include "STL/File/File.h"
#include <filesystem>

namespace PF::STL{
class Folder{
private:
  std::string path;
private:
  Vector<std::pair<char, std::string>> files;
public:
  Folder(const std::string &path) :path(path){};
  std::pair<char, std::string> &operator[](const size_t &index){ return files[index]; };
  bool exist() { return std::filesystem::exists(path); };
  void createFolder(){ std::filesystem::create_directory(path); };
  File openFile(const std::string &file) { return File(path + file); };
  void remove(const std::string &file) { std::filesystem::remove_all(path + file); };
  std::string getPath() { return path; };
  Folder openFolder(const std::string &folder) { return Folder(path + folder); };
  std::pair<char, std::string> &operator[](const int index) { return files[index]; };
  size_t size() { return files.size(); };
public:
  void fetchList();
  Folder back();
};
}; // namespace PF::STL