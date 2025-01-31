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
    private:
      void resize();
    public:
      Vector(const size_t capacity = 1);
      T& operator[](const size_t index);
      void push(const T line);
      T pop();
      void clear();
      T remove(const size_t index);
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
  };
};

#include "STL.hpp"