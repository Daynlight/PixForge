#include "Manager.h"

const void PF::Core::Renderer::Objects::Manager::load(){
  file.read();

  // [NOTE] This is temporary solution to time that i rework STL
  // [WARNING] This convert std::string Vector to const char* vector
  STL::Vector<STL::Vector<std::string>> file_data = file.split(';');
  STL::Vector<STL::Vector<const char*>> records;
  for(unsigned int i = 0; i < file_data.size(); i++){
    STL::Vector<std::string> data = file_data[i];
    STL::Vector<const char*> temp;
    for(unsigned int j = 0; j < data.size(); j++) temp.push(data[j].c_str());
    records.push(temp);
  }
  // [NOTE] This is temporary solution to time that i rework STL

  for(unsigned int i = 0; i < file.size(); i++) {
    STL::Vector<const char*> record = records[i];
    iObject::Type type = static_cast<iObject::Type>(STL::Convert::CharUint(record[0]));

    switch (type){
      case iObject::Type::SPRITE: objects.push(new Sprite(record)); break;
      case iObject::Type::COLOUR_BOX: objects.push(new Objects::ColourBox(record)); break;
    };
  };
};

const void PF::Core::Renderer::Objects::Manager::save(){
  if(file.notExist()) file.createFile();
  file.clear();
  for(unsigned int i = 0; i < objects.size(); i++) file.push(objects[i]->save());
  file.save();
};
