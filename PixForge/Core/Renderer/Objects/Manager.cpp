#include "Manager.h"

PF::Core::Renderer::Objects::Manager* PF::Core::Renderer::Objects::Manager::instance = nullptr;

void PF::Core::Renderer::Objects::Manager::init(const std::string &object_path, const std::string &texture_path, Window *window) { 
  if(!instance) {
    instance = new Manager(object_path); 
    instance->textures = new Texture(texture_path, window);
  };
};

void PF::Core::Renderer::Objects::Manager::dealloc() { delete instance; };

PF::Core::Renderer::Objects::Manager::Manager(const std::string &object_path) : file(object_path) {};

PF::Core::Renderer::Objects::Manager::~Manager(){
  for(unsigned int i = 0; i < objects.size(); i++) delete objects[i];
  delete textures;
};

void PF::Core::Renderer::Objects::Manager::addColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour) { 
  get().objects.push(new ColourBox(position, colour)); 
};

void PF::Core::Renderer::Objects::Manager::addSprite(const STL::Vec<int, 4> &position, const unsigned int &texture_index) { 
  get().objects.push(new Sprite(get().textures, position, texture_index)); 
};

void PF::Core::Renderer::Objects::Manager::load() {
  get().textures->load();
  get().file.read();
  STL::Vector<STL::Vector<std::string>*> records = get().file.split(';');
  for(unsigned int i = 0; i < get().file.size(); i++) {
    STL::Vector<std::string>* record = records[i];
    iObject::Type type = static_cast<iObject::Type>(std::stoul((*record)[0]));
    switch (type){
      case iObject::Type::SPRITE: get().objects.push(new Sprite(get().textures, (*record))); break;
      case iObject::Type::COLOUR_BOX: get().objects.push(new Objects::ColourBox(*record)); break;
    };
    delete record;
  };
};

void PF::Core::Renderer::Objects::Manager::save() {
  get().textures->save();
  if(!get().file.exist()) get().file.create();
  get().file.clear();
  for(unsigned int i = 0; i < get().objects.size(); i++) get().file.push(get().objects[i]->save());
  get().file.save();
};
