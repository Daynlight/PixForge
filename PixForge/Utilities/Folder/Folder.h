#pragma once
#include "Utilities/Vector/Vector.h"
#include "Utilities/File/File.h"
#include <filesystem>

namespace PF::UTILITIES{
class Folder{
private:
  Vector<std::pair<char, std::string>> data;
  std::string path;
public:
  Folder(const std::string &path);
  const bool exist() const;
  void create();
  void remove(const std::string &folder);
  void fetchList();
  const unsigned int size() const;
  File openFile(const std::string &file);
  Folder openFolder(const std::string &folder) const;
  Folder backFolder() const;
  std::string getPath();
  const std::pair<char, std::string> &operator[](const unsigned int &index) const;
  std::pair<char, std::string> &operator[](const unsigned int &index);
}; // class Folder
}; // namespace PF::STL