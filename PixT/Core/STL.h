#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

namespace PC{
  class File{
    private:
      std::vector<std::string> data;
      std::string path;
      std::fstream file;
    public:
      File(const std::string path);
      ~File();
      std::string& operator[](const size_t index);
      bool isEmpty();
      void createFile();
      void push(const std::string line);
      void clear();
      size_t size();
      void read();
      void save();
  };
  class Folder{
    private:
      std::string path;
    public:
      Folder(const std::string path);
      bool exist();
      void createFolder();
  };
};