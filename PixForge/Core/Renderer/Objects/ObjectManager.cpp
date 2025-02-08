#include "ObjectManager.h"

void PF::ObjectManager::load(){
  file.read();
  if(!file.notExist()){
    Vector<Vector<std::string>> records = file.split(';');
    for(size_t i = 0; i < file.size(); i++) {
      Vector<std::string> record = records[i];
      iObject::Type type = static_cast<iObject::Type>(std::stoi(record[0]));

      if(type == iObject::Type::SPRITE) objects.push(new Sprite(texture, record, null_texture));
      else
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
