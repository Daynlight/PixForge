#include "Gui.h"

PF::CoreForge::Gui::Gui(const std::string &path, CoreForge::Window *window, Sandbox *sandbox) 
  :window(window), imGui(path, window), sandbox(sandbox){
  Utilities::Log::log("Gui Created");
  Utilities::Log::log("ImGui Initialized");
};

PF::CoreForge::Gui::~Gui(){
  Utilities::Log::inf("ImGui Destroyed");
  Utilities::Log::inf("Gui Destroyed");
};

inline void PF::CoreForge::Gui::renderDock() {
  imGui.dock([this](){  this->renderTopBar(); });
};

inline void PF::CoreForge::Gui::renderTopBar(){
  imGui.topBar([](){
    // if (ImGui::MenuItem("Log")) ui.addWindow(Ui::iUi::Type::LOG);
    // if (ImGui::MenuItem("File Explorer [assets]")) ui.addWindow(Ui::iUi::Type::FILE_EXPLORER);
    // if (ImGui::MenuItem("Text Editor")) ui.addWindow(Ui::iUi::Type::TEXT_EDITOR);
    // if (ImGui::MenuItem("Objects")) ui.addWindow(Ui::iUi::Type::OBJECTS_UI);
    // if (ImGui::MenuItem("Sandbox")) ui.addWindow(Ui::iUi::Type::SANDBOX);
    
  });
};

void PF::CoreForge::Gui::render(){
  imGui.render([this](){
    this->renderTopBar();
    // for(size_t i = 0; i < ui.windows.size(); i++) {
    //   ui.windows[i]->render();
    //   if(!ui.windows[i]->isOpen()) { delete ui.windows.remove(i); };
    // };
  });
};

void PF::CoreForge::Gui::guiEvent(SDL_Event event){
  imGui.events(event);
};