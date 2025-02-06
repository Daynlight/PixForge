#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), sandbox(&window, &objects), ui(&objects), gui(&window, &ui){
  Log::inf("Forge Created");

  {
    Folder assets_folder = Folder("assets/");
    if(!assets_folder.exist()){
      assets_folder.createFolder();
      Log::war("Assets folder created");
    }
    assets_folder.fetchList();
  }
  
  if(!texture_folder.exist()){
    texture_folder.createFolder();
    Log::war("Texture folder created");
  }
  texture_folder.fetchList();
  
  loadGuiWindow();
};

PF::Forge::~Forge(){
  saveGuiWindow();
  Log::inf("Forge Destroyed");
};

void PF::Forge::run(){
  while (window.isRunning()){
    Renderer::background(&window, backgroundColour);

    sandbox.run();

    gui.renderGui();
    events();
    SDL_RenderPresent(window.getRenderer());
  };
};

inline void PF::Forge::loadGuiWindow(){
  if(!gui_window.isEmpty()){
    gui_window.read();
    ui.load(&gui_window);
  };
};

inline void PF::Forge::saveGuiWindow(){
  if(gui_window.isEmpty()) {
    gui_window.createFile();
    Log::war("gui_window file Created");
  };
  gui_window.clear();
  ui.save(&gui_window);
  gui_window.save();
};

inline void PF::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) Builder::buildGame();
      if(event.key.keysym.sym == SDLK_F6) Builder::runGame();
    }

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};