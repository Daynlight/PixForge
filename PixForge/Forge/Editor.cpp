#include "Editor.h"

PE::Editor::Editor(){
  Log::inf("Editor Created");
}

PE::Editor::~Editor(){
  Log::inf("Editor Destroyed");
}

void PE::Editor::run(){
  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);

    sandbox.run();

    gui.renderGui();
    editorEvent();
    SDL_RenderPresent(window.getRenderer());
  };
};

void PE::Editor::editorEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) Builder::buildGame();
      if(event.key.keysym.sym == SDLK_F6) Builder::runGame();
    }

    sandbox.gameEvent(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};