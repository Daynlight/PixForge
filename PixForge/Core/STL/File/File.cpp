#include "File.h"

PF::STL::File::File(const std::string &path) 
  : path(path){ 
  file.open(path, std::ios::in | std::ios::out); 
};
  
PF::STL::File::~File() { file.close(); };

void PF::STL::File::read() {
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
};

void PF::STL::File::save(){
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
};