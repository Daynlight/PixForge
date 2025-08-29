#include "File.h"

void PF::STL::File::create(){
  std::string temp = "";
  for(unsigned int i = 0; i < path.size(); i++){
    if(path[i] == '/'){
      std::filesystem::create_directory(temp);
    }
    temp += path[i];
  };
  file.open(path, std::ios::out);
};

void PF::STL::File::read(){
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
};

void PF::STL::File::save(){
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(unsigned int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
};