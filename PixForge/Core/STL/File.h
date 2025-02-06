#pragma once
#include "Vector.h"
#include <string>
#include <fstream>

namespace PF{
    class File{
    private:
      Vector<std::string> data;
      std::string path;
      std::fstream file;
    public:
      File(const std::string path);
      ~File();
      std::string& operator[](const size_t index);
      bool isEmpty();
      bool notExist();
      void createFile();
      void push(const std::string line);
      void clear();
      size_t size();
      void read();
      void save();
  };
}