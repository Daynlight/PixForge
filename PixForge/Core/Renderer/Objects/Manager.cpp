#include "Manager.h"

PF::Core::Renderer::Objects::Manager* PF::Core::Renderer::Objects::Manager::manager = nullptr;

void PF::Core::Renderer::Objects::Manager::init(const std::string &object_path, const std::string &texture_path, Window *window) { 
  if(!manager) {
    manager = new Manager(object_path); 
    manager->textures = new Texture(texture_path, window);
  };
};

void PF::Core::Renderer::Objects::Manager::dealloc() { delete manager; };

PF::Core::Renderer::Objects::Manager::Manager(const std::string &object_path) : file(object_path) {};

PF::Core::Renderer::Objects::Manager::~Manager(){
  for(unsigned int i = 0; i < objects.size(); i++) delete objects[i];
  delete textures;
};

void PF::Core::Renderer::Objects::Manager::addColourBox(const STL::Vec<int, 5> &position, const STL::Vec<char, 4> &colour) { 
  objects.push(new ColourBox(position, colour)); 
};

void PF::Core::Renderer::Objects::Manager::addSprite(const STL::Vec<int, 5> &position, const unsigned int &texture_index) { 
  objects.push(new Sprite(textures, position, texture_index)); 
};

void PF::Core::Renderer::Objects::Manager::load() {
  textures->load();
  file.read();
  STL::Vector<STL::Vector<std::string>*> records = file.split(';');
  for(unsigned int i = 0; i < file.size(); i++) {
    STL::Vector<std::string>* record = records[i];
    iObject::Type type = static_cast<iObject::Type>(std::stoul((*record)[0]));
    switch (type){
      case iObject::Type::SPRITE: objects.push(new Sprite(textures, (*record))); break;
      case iObject::Type::COLOUR_BOX: objects.push(new Objects::ColourBox(*record)); break;
    };
    delete record;
  };
};

void PF::Core::Renderer::Objects::Manager::save() {
  textures->save();
  if(file.notExist()) file.createFile();
  file.clear();
  for(unsigned int i = 0; i < objects.size(); i++) file.push(objects[i]->save());
  file.save();
};
