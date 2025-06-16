#include "Sandbox.h"

PF::Sandbox::Sandbox()
  : window("Sandbox") {
  Utilities::Log::log("Sandbox Created");
  Core::Renderer::Assets::init(&window);
  Core::Renderer::Objects::Manager::init("objects.bin", "textures.bin", &window);
  Core::Renderer::Objects::Manager::load();
  SDL_Renderer* renderer = window.getRenderer();
  int width = window.getWindowSizesAndPosition().w;
  int height = window.getWindowSizesAndPosition().h;

  renderTexture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    width, height
  );

  if (!renderTexture) {
    Utilities::Log::err("Failed to create sandbox render texture: " + std::string(SDL_GetError()));
  } else {
    Utilities::Log::log("Sandbox render texture created: " + std::to_string(width) + "x" + std::to_string(height));
  }
};

PF::Sandbox::~Sandbox() {
  if (renderTexture) SDL_DestroyTexture(renderTexture);
};

SDL_Texture* PF::Sandbox::render() {
    SDL_Renderer* renderer = window.getRenderer();

    // Save previous render target
    SDL_Texture* previousTarget = SDL_GetRenderTarget(renderer);

    // Set render target to your offscreen texture
    if (SDL_SetRenderTarget(renderer, renderTexture) != 0) {
        Utilities::Log::err("Failed to set render target: " + std::string(SDL_GetError()));
        return nullptr;
    }

    // Clear the render target before drawing (important!)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render background and objects to offscreen texture
    Core::Renderer::Assets::background(backgroundColour);

    for (size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++) {
        Core::Renderer::Objects::Manager::at(i).render(&window);
    }

    // Reset render target back to window
    SDL_SetRenderTarget(renderer, previousTarget);

    // Clear the window renderer (optional but recommended)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Copy the offscreen texture to the window renderer
    auto sizeData = window.getWindowSizesAndPosition();
    SDL_Rect destRect{ 0, 0, sizeData.w, sizeData.h };
    if (SDL_RenderCopy(renderer, renderTexture, nullptr, &destRect) != 0) {
        Utilities::Log::err("Failed to render texture to window: " + std::string(SDL_GetError()));
    }

    // Present the window renderer so it shows on screen
    SDL_RenderPresent(renderer);

    return renderTexture;
}


void PF::Sandbox::event(){
  // Event handling implementation here (currently empty)
}
