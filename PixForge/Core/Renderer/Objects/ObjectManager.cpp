#include "ObjectManager.h"

void PF::ObjectManager::load(){
  file.read();
  if(!file.notExist()){
    for(size_t i = 0; i < file.size(); i++) {
      std::string record = file[i];
      iObject::Type type = static_cast<iObject::Type>(record[0]);

      // if(type == iObject::Type::SPRITE) objects.push(new Sprite(texture));
      if(type == iObject::Type::COLOUR_BOX) { objects.push(new ColourBox(record)); };
    };
  };
};

void PF::ObjectManager::save(){
  if(file.notExist()) file.createFile();

  file.clear();
  for(size_t i = 0; i < objects.size(); i++)
    file.push(objects[i]->save());

  file.save();
};
