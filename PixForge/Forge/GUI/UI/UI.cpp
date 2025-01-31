#include "UI.h"

uint8_t PF::UI::generateUniqueID(Vector<UI*> *UIs){
  uint8_t ID = 0;
  for(size_t i = 0; i < UIs->size(); i++) if((*UIs)[i]->getID() == ID) ID++;
  return ID;
};