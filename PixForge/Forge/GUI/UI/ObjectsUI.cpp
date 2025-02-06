#include "ObjectsUI.h"

bool PF::ObjectsUI::render(){
   ImGui::Begin(("Objects ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
    if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

    ImGui::InputInt("X: ", &position[0]);
    ImGui::InputInt("Y: ", &position[1]);
    ImGui::InputInt("Width: ", &position[2]);
    ImGui::InputInt("Height: ", &position[3]);

    ImGui::InputInt("Red", &colour[0]);
    ImGui::InputInt("Green", &colour[1]);
    ImGui::InputInt("Blue", &colour[2]); 
    ImGui::InputInt("Alpha", &colour[3]);
    colour % 256;

    if(ImGui::Button("Add Object")){
      Vec<char, 4> colourTemp;
      for (size_t i = 0; i < 4; ++i) 
        colourTemp[i] = static_cast<char>(colour[i]);
      objects->push(new ColourBox(position, colourTemp));
    };
    ImGui::End();
  return true;
};
