#include "Object.h"

PF::ObjectManager::~ObjectManager(){
  for(size_t i = 0; i < objects.size(); i++) delete objects[i];
}

void PF::ObjectManager::load(File *file){
  for(size_t i = 0; i < file->size(); i++) {
  std::string record = (*file)[i];
  Object::Type type = static_cast<Object::Type>(record[0]);
  if(type == Object::Type::SPRITE) objects.push(new Sprite());
  if(type == Object::Type::COLOUR_BOX) {
    ColourBox *object = new ColourBox();
    object->load(record);
    objects.push(object);
    }
  };
};

void PF::ObjectManager::save(File *file){
  for(size_t i = 0; i < objects.size(); i++)
    file->push(objects[i]->save());
};
