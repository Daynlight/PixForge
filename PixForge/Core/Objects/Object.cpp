#include "Object.h"

PF::ObjectManager::~ObjectManager(){ 
  for(size_t i = 0; i < objects.size(); i++) delete objects[i]; 
};

void PF::ObjectManager::load(File *file){
  file->read();
  if(!file->notExist()){
    for(size_t i = 0; i < file->size(); i++) {
      std::string record = (*file)[i];
      Object::Type type = static_cast<Object::Type>(record[0]);

      if(type == Object::Type::SPRITE) objects.push(new Sprite());
      if(type == Object::Type::COLOUR_BOX) { objects.push(new ColourBox(record)); };
    };
  };
};

void PF::ObjectManager::save(File *file){
  if(file->notExist()) file->createFile();

  file->clear();
  for(size_t i = 0; i < objects.size(); i++)
    file->push(objects[i]->save());

  file->save();
};
