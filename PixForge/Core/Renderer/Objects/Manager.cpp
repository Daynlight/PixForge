#include "Manager.h"

PF::Core::Renderer::Objects::Manager* PF::Core::Renderer::Objects::Manager::manager = nullptr;

const void PF::Core::Renderer::Objects::Manager::load(){
  textures->load();
  file.read();
  STL::Vector<STL::Vector<std::string>> records = file.split(';');
  for(unsigned int i = 0; i < file.size(); i++) {
    STL::Vector<std::string> record = records[i];
    iObject::Type type = static_cast<iObject::Type>(std::stoul(record[0]));
    switch (type){
      case iObject::Type::SPRITE: objects.push(new Sprite(textures, record)); break;
      case iObject::Type::COLOUR_BOX: objects.push(new Objects::ColourBox(record)); break;
    };
  };
};

const void PF::Core::Renderer::Objects::Manager::save(){
  textures->save();
  if(file.notExist()) file.createFile();
  file.clear();
  for(unsigned int i = 0; i < objects.size(); i++) file.push(objects[i]->save());
  file.save();
};
