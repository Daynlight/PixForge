#pragma once
#include "Vector.h"
#include "File.h"
#include <filesystem>

namespace PF{
  class Folder{
    private:
      std::string path;
    public:
      Vector<std::pair<char, std::string>> files;
    public:
      Folder(const std::string path);
      std::pair<char, std::string>& operator[](const size_t index);
      bool exist();
      void createFolder();
      File openFile(const std::string file);
      void remove(const std::string file);
      void fetchList();
      std::string getPath();
      Folder openFolder(const std::string folder);
      Folder back();
  };
};