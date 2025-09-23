#include "File.h"

PF::UTILITIES::File::File(const std::string &path, const unsigned int size) 
: path(path), data(size) {
  auto parent = std::filesystem::path(path).parent_path();
  if (!parent.empty()) std::filesystem::create_directories(parent);

  file.open(path, std::ios::in | std::ios::out | std::ios::app);
  file.close();
  file.open(path, std::ios::in | std::ios::out);
}

PF::UTILITIES::File::~File()
{ if(file.is_open() && path != "") file.close(); };

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
{ if(data.size() < 1) throw std::out_of_range("File is empty"); return data.pop(); };

const unsigned int PF::UTILITIES::File::size() const
{ return data.size(); };

void PF::UTILITIES::File::clear()
{ while(size() > 0) pop(); };

const std::string PF::UTILITIES::File::getPath() const
{ return path; };

void PF::UTILITIES::File::setPath(const std::string &new_path)
{ file.close(); path = new_path; file.open(path, std::ios::in | std::ios::out); };

const std::string& PF::UTILITIES::File::operator[](const unsigned int &index) const
{ if(index >= data.size()) throw std::out_of_range("index out of range"); return data[index]; };

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
std::ofstream out(path, std::ios::out | std::ios::trunc);
  if(!out.is_open()) throw std::runtime_error("Failed to open file for saving");

  for(unsigned int i = 0; i < data.size(); i++)
      out << data[i] << std::endl;
  out.close();
  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
  if(!file.is_open()) throw std::runtime_error("Failed to reopen file after saving");
};