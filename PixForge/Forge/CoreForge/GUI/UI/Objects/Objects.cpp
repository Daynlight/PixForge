#include "Objects.h"

inline void PF::Forge::Ui::Objects::renderObjectsList(){
  for(size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++){
    ImGui::Text(Core::Renderer::Objects::Manager::at(i).getRefName().c_str());
    if(ImGui::BeginPopupContextItem(("Object" + std::to_string(i)).c_str())){
      if(ImGui::MenuItem("Delete")){
        delete &Core::Renderer::Objects::Manager::at(i);
        Core::Renderer::Objects::Manager::remove(i);
        Utilities::Log::log("Object Deleted");
      };
      if(ImGui::MenuItem("Properties")){
        show_properties = true;
        properties_index = i;
        Utilities::Log::log("Object Properties");
      };
      ImGui::EndPopup();
    };
  };
};

inline void PF::Forge::Ui::Objects::renderAddColourBox() {
  ImGui::Begin("Add Object", nullptr, ImGuiWindowFlags_MenuBar);

  ImGui::BeginMenuBar();
  if(ImGui::Button("exit")) {add_colour_box = false; Utilities::Log::log("Add Colour Box Window Closed");}
  ImGui::EndMenuBar();
  
  ImGui::InputInt("X: ", &position[0]);
  ImGui::InputInt("Y: ", &position[1]);
  ImGui::InputInt("Width: ", &position[2]);
  ImGui::InputInt("Height: ", &position[3]);
  if(position[2] < 0) position[2] = 0;
  if(position[3] < 0) position[3] = 0;

  ImGui::ColorPicker4("##picker", colour.data);

  if(ImGui::Button("Add Object")){
    STL::Vec<char, 4> colourTemp(0);
    for (size_t i = 0; i < 4; i++) 
      colourTemp[i] = static_cast<char>(colour[i] * 255);

      Core::Renderer::Objects::Manager::push(new Core::Renderer::Objects::ColourBox(position, colourTemp));
    Utilities::Log::inf("Colour Box Added: " + std::to_string((uint8_t)colourTemp[0]) + " " + std::to_string((uint8_t)colourTemp[1]) + " " + std::to_string((uint8_t)colourTemp[2]) + " " + std::to_string((uint8_t)colourTemp[3]));
  };

  ImGui::End();
};

inline void PF::Forge::Ui::Objects::renderAddSprite(){
  ImGui::Begin("Add Object", nullptr, ImGuiWindowFlags_MenuBar);

  ImGui::BeginMenuBar();
  if(ImGui::Button("exit")) {add_sprite = false; Utilities::Log::log("Add Sprite Window Closed");}
  ImGui::EndMenuBar();

  ImGui::InputInt("X: ", &position[0]);
  ImGui::InputInt("Y: ", &position[1]);
  ImGui::InputInt("Width: ", &position[2]);
  ImGui::InputInt("Height: ", &position[3]);
  if(position[2] < 0) position[2] = 0;
  if(position[3] < 0) position[3] = 0;

  ImGui::InputInt("texture: ", &texture_index);

  if(ImGui::Button("Add Object")){
    Core::Renderer::Objects::Manager::addSprite(position, texture_index);
    Utilities::Log::inf("Sprite Added");
  };

  ImGui::End();
};

inline void PF::Forge::Ui::Objects::renderProperties(){
  if(show_properties){
    if(Core::Renderer::Objects::Manager::at(properties_index).getType() == Core::Renderer::Objects::iObject::Type::COLOUR_BOX) renderColourBoxProperties();
    else if(Core::Renderer::Objects::Manager::at(properties_index).getType() == Core::Renderer::Objects::iObject::Type::SPRITE) renderSpriteProperties();
  }
};

inline void PF::Forge::Ui::Objects::renderColourBoxProperties(){
  ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_MenuBar);

  ImGui::BeginMenuBar();
  if(ImGui::Button("exit")) { show_properties = false; Utilities::Log::log("Properties Window Closed");}
  ImGui::EndMenuBar();

  if(Core::Renderer::Objects::Manager::at(properties_index).getType() == Core::Renderer::Objects::iObject::Type::COLOUR_BOX){
    ImGui::Text(Core::Renderer::Objects::Manager::at(properties_index).getRefName().c_str());

    STL::Vec<int, 4> *pos = &static_cast<Core::Renderer::Objects::ColourBox*>(&Core::Renderer::Objects::Manager::at(properties_index))->getRefPosition();
    int *zIndex = &Core::Renderer::Objects::Manager::at(properties_index).getRefZIndex();

    int last_z_index = *zIndex;

    ImGui::InputInt("X: ", &(*pos)[0]);
    ImGui::InputInt("Y: ", &(*pos)[1]);
    ImGui::InputInt("Z: ", zIndex);
    ImGui::InputInt("Width: ", &(*pos)[2]);
    ImGui::InputInt("Height: ", &(*pos)[3]);
    if((*pos)[2] < 0) (*pos)[2] = 0;
    if((*pos)[3] < 0) (*pos)[3] = 0;

    ImGui::ColorPicker4("##picker", colour.data);

    if(ImGui::Button("Apply")){
      STL::Vec<char, 4> colourTemp(0);
      for (size_t i = 0; i < 4; i++) 
        colourTemp[i] = static_cast<char>(colour[i] * 255);          
      static_cast<Core::Renderer::Objects::ColourBox*>(&Core::Renderer::Objects::Manager::at(properties_index))->getRefColour() = colourTemp;
      Utilities::Log::inf("Colour Box Colour Applied: " + std::to_string((uint8_t)colourTemp[0]) + " " + std::to_string((uint8_t)colourTemp[1]) + " " + std::to_string((uint8_t)colourTemp[2]) + " " + std::to_string((uint8_t)colourTemp[3]));
    };

    if(*zIndex != last_z_index) {
      Core::Renderer::Objects::Manager::updateZIndex();
      show_properties = false;
      Utilities::Log::inf("ZIndex Updated");
    };
  };

  ImGui::End();
};

inline void PF::Forge::Ui::Objects::renderSpriteProperties(){
  ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_MenuBar);

  ImGui::BeginMenuBar();
  if(ImGui::Button("exit")) { show_properties = false; Utilities::Log::log("Properties Window Closed");}
  ImGui::EndMenuBar();

  if(Core::Renderer::Objects::Manager::at(properties_index).getType() == Core::Renderer::Objects::iObject::Type::SPRITE){
    ImGui::Text(Core::Renderer::Objects::Manager::at(properties_index).getRefName().c_str());

    ImGui::InputText("path to texture", path_to_texture, IM_ARRAYSIZE(path_to_texture));
    if(ImGui::Button("add texture")) { 
      if(!std::filesystem::exists(path_to_texture)) Utilities::Log::err("Texture didn't exists");
      else{
        addTextureFromFile(path_to_texture);
        path_to_texture[0] = '\0';
        Utilities::Log::inf("Texture added"); 
      };
    };

    STL::Vec<int, 4> *pos = &static_cast<Core::Renderer::Objects::Sprite*>(&Core::Renderer::Objects::Manager::at(properties_index))->getRefPosition();

    int last_z_index = Core::Renderer::Objects::Manager::at(properties_index).getRefZIndex();

    ImGui::InputInt("X: ", &(*pos)[0]);
    ImGui::InputInt("Y: ", &(*pos)[1]);
    ImGui::InputInt("Z: ", &Core::Renderer::Objects::Manager::at(properties_index).getRefZIndex());
    ImGui::InputInt("Width: ", &(*pos)[2]);
    ImGui::InputInt("Height: ", &(*pos)[3]);
    if((*pos)[2] < 0) (*pos)[3] = 0;
    if((*pos)[3] < 0) (*pos)[3] = 0;

    ImGui::InputInt("texture: ", reinterpret_cast<int*>(&static_cast<Core::Renderer::Objects::Sprite*>(&Core::Renderer::Objects::Manager::at(properties_index))->getRefTextureIndex()));
    
    if(last_z_index != Core::Renderer::Objects::Manager::at(properties_index).getRefZIndex()) {
      Core::Renderer::Objects::Manager::updateZIndex();
      show_properties = false;
      Utilities::Log::inf("ZIndex Updated");
    };
  };

  ImGui::End();
};

void PF::Forge::Ui::Objects::render(){
  ImGui::Begin(("Objects (" + std::to_string(id) + ")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if (ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")) {open = false; Utilities::Log::log("Objects UI Window Closed");}
    if(ImGui::BeginMenu("Add")){
      if(ImGui::MenuItem("ColourBox")) add_colour_box = !add_colour_box;
      if(ImGui::MenuItem("Sprite")) add_sprite = !add_sprite;
      ImGui::EndMenu();
    };
    ImGui::EndMenuBar();
  };


  ImGui::Text("Objects:");
  renderObjectsList();
  
  ImGui::End();

  if(add_colour_box) renderAddColourBox();
  else if(add_sprite) renderAddSprite();
  else if(show_properties) renderProperties();
};
