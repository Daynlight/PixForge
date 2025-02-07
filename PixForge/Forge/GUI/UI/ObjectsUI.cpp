#include "ObjectsUI.h"

inline void PF::ObjectsUI::renderObjectsList(){
  for(size_t i = 0; i < objects->objects.size(); i++){
    ImGui::Text(objects->objects[i]->getName());
    if(ImGui::BeginPopupContextItem(("Object" + std::to_string(i)).c_str())){
      if(ImGui::MenuItem("Delete")){
        delete objects->objects[i];
        objects->objects.remove(i);
      };
      ImGui::EndPopup();
    };
  };
};

inline void PF::ObjectsUI::renderAddColourBox() {
  ImGui::Begin("Add Object");

  ImGui::InputInt("X: ", &position[0]);
  ImGui::InputInt("Y: ", &position[1]);
  ImGui::InputInt("Width: ", &position[2]);
  ImGui::InputInt("Height: ", &position[3]);
  if(position[2] < 0) position[2] = 0;
  if(position[3] < 0) position[3] = 0;

  ImGui::ColorPicker4("##picker", colour.data);

  if(ImGui::Button("Add Object")){
    Vec<char, 4> colourTemp;
    for (size_t i = 0; i < 4; ++i) 
      colourTemp[i] = static_cast<char>(colour[i] * 255);

    objects->objects.push(new ColourBox(position, colourTemp));
  };

  ImGui::End();
};

void PF::ObjectsUI::render(){
  ImGui::Begin(("Objects (" + std::to_string(ID) + ")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if (ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")) open = false;
    if(ImGui::BeginMenu("Add")){
      if(ImGui::MenuItem("ColourBox")) addColourBox = !addColourBox;
      ImGui::EndMenu();
    };
    ImGui::EndMenuBar();
  };


  ImGui::Text("Objects:");
  renderObjectsList();
  
  ImGui::End();

  if(addColourBox) renderAddColourBox();
};
