#include "Editor.h"

void PE::Editor::run(){
  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);
    
    gui.renderGui();
    editorEvent();
    SDL_RenderPresent(window.getRenderer());
  }
}

void PE::Editor::editorEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) Builder::buildGame();
      if(event.key.keysym.sym == SDLK_F6) Builder::runGame();
    }

    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  }
}
