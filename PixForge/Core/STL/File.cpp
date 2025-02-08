#include "File.h"

void PF::File::read()
{
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
};

void PF::File::save(){
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
};