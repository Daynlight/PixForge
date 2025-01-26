#include "STL.h"

PC::File::File(const std::string path)
  :path(path){
  file.open(path, std::ios::in | std::ios::out);
}

PC::File::~File(){
  file.close();
}

std::string& PC::File::operator[](const size_t index){ return data[index]; };

bool PC::File::isEmpty(){ return file.peek() == std::ifstream::traits_type::eof(); }

void PC::File::createFile(){ file.open(path, std::ios::out); }

void PC::File::read(){
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
}

void PC::File::push(const std::string line){
  data.push(line);
}

void PC::File::clear(){
  while(data.size() > 0) data.pop();
}

size_t PC::File::size(){ return data.size(); }

void PC::File::save(){
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
}

PC::Folder::Folder(const std::string path) :path(path){}

bool PC::Folder::exist(){ return std::filesystem::exists(path); };

void PC::Folder::createFolder(){ std::filesystem::create_directory(path); };