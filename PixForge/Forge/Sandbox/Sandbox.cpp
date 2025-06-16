#include "Sandbox.h"

PF::Sandbox::Sandbox(CoreForge::Window *window) 
  : forgeWindow(window) {
  Utilities::Log::log("Sandbox Created");
  // Core::Renderer::Assets::init(&window);
  // Core::Renderer::Objects::Manager::init("objects.bin", "textures.bin", &window);
  // Core::Renderer::Objects::Manager::load();
  // SDL_Renderer* renderer = window.getRenderer();
  // int width = window.getWindowSizesAndPosition().w;
  // int height = window.getWindowSizesAndPosition().h;

  // renderTexture = SDL_CreateTexture(
  //   renderer,
  //   SDL_PIXELFORMAT_RGBA8888,
  //   SDL_TEXTUREACCESS_TARGET,
  //   width, height
  // );

  // if (!renderTexture) {
  //   Utilities::Log::err("Failed to create sandbox render texture: " + std::string(SDL_GetError()));
  // } else {
  //   Utilities::Log::log("Sandbox render texture created: " + std::to_string(width) + "x" + std::to_string(height));
  // }
};

PF::Sandbox::~Sandbox() {
  if (renderTexture) SDL_DestroyTexture(renderTexture);
};

SDL_Texture* PF::Sandbox::getViewportTexture() {
    // SDL_Renderer* renderer = window.getRenderer();

    // // Save previous render target
    // SDL_Texture* previousTarget = SDL_GetRenderTarget(renderer);

    // // Set render target to your offscreen texture
    // if (SDL_SetRenderTarget(renderer, renderTexture) != 0) {
    //     Utilities::Log::err("Failed to set render target: " + std::string(SDL_GetError()));
    //     return nullptr;
    // }

    // // Render background and objects to offscreen texture
    // Core::Renderer::Assets::background(backgroundColour);

    // for (size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++) {
    //     Core::Renderer::Objects::Manager::at(i).render(&window);
    // }

    // // Reset render target back to window
    // SDL_SetRenderTarget(renderer, previousTarget);

    // // Present the window renderer so it shows on screen
    // SDL_RenderPresent(renderer);

    // return renderTexture;
    return nullptr;
}


void PF::Sandbox::event(){
  // Event handling implementation here (currently empty)
}
