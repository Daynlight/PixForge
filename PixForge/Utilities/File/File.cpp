#include "File.h"

PF::UTILITIES::File::File(const std::string &path)
: path(path) { std::filesystem::create_directory(path); file.open(path, std::ios::in | std::ios::out); }

PF::UTILITIES::File::~File()
{ file.close(); };

const bool PF::UTILITIES::File::exist() const
{ return std::filesystem::exists(path); };

void PF::UTILITIES::File::create(){
  std::string temp = "";
  for(unsigned int i = 0; i < path.size(); i++){
    if(path[i] == '/'){
      std::filesystem::create_directory(temp);
    }
    temp += path[i];
  };
  file.open(path, std::ios::out);
}

void PF::UTILITIES::File::remove()
{ std::filesystem::remove(path); }

void PF::UTILITIES::File::push(const std::string &line)
{ data.push(line); };

std::string PF::UTILITIES::File::pop()
{ if(data.size() < 1) return ""; return data.pop(); };

const unsigned int PF::UTILITIES::File::size() const
{ return data.size(); };

void PF::UTILITIES::File::clear()
{ while(size() > 0) pop(); };

const std::string PF::UTILITIES::File::getPath() const
{ return path; };

void PF::UTILITIES::File::setPath(const std::string &new_path)
{ file.close(); path = new_path; file.open(path, std::ios::in | std::ios::out); };

const std::string& PF::UTILITIES::File::operator[](const unsigned int &index) const
{ if(index >= data.size()) std::out_of_range("index out of range"); return data[index]; };

std::string& PF::UTILITIES::File::operator[](const unsigned int &index)
{ if(index >= data.size()) throw std::out_of_range("index out of range"); return data[index]; }

PF::UTILITIES::File &PF::UTILITIES::File::operator=(const File &second)
{ data = second.data; path = second.path; return *this; }

PF::UTILITIES::Vector<PF::UTILITIES::Vector<std::string>*> PF::UTILITIES::File::split(const char &sep)
{ return data.split(sep); }

std::string PF::UTILITIES::File::concat(const char &sep)
{ return data.concat(sep); };

void PF::UTILITIES::File::read(){
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
};

void PF::UTILITIES::File::save() {
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(unsigned int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
};