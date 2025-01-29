#pragma once
#include <string>
#include <fstream>
#include <filesystem>

namespace PF{
  template<typename T>
  class Vector{
    private:
      T* data;
      size_t _size = 0;
      size_t capacity = 1;
      void resize();
    public:
      Vector(const size_t capacity = 1);
      T& operator[](const size_t index);
      void push(const T line);
      T pop();
      void clear();
      size_t size();
  };
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

#include "STL.hpp"