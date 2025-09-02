#include "Engine.h"

void PF::ENGINE::Engine::Init(const std::string &window_title, int width, int height){
  renderer->createWindow(window_title, width, height);
  renderer->createRenderer();
}

void PF::ENGINE::Engine::InitForEditor(const std::string &window_title, int width, int height) {
  //  renderer->createRenderer();
};

PF::ENGINE::Engine::~Engine() {
  delete renderer;
};

PF::UTILITIES::Vector<std::string> PF::ENGINE::Engine::getRenderers() {
  PF::UTILITIES::Vector<std::string> dlls;
  for (auto& p : std::filesystem::directory_iterator("renderers/")) {
      if (p.path().extension() == ".dll") { 
          dlls.push(p.path().string());
      }
  }
  return dlls;
}

void PF::ENGINE::Engine::loadRenderer(const std::string& dllPath) {
  #ifdef _WIN32
    HMODULE handle = LoadLibraryA(dllPath.c_str());
    if (!handle) return;
    auto createFunc = (PF::PLATFORM::iRenderer* (*)())GetProcAddress(handle, "CreateRenderer");
    if (!createFunc) return;
    renderer = createFunc();
  #else
    void* handle = dlopen(dllPath.c_str(), RTLD_LAZY);
    if (!handle) return;
    auto createFunc = (PF::PLATFORM::iRenderer* (*)())dlsym(handle, "CreateRenderer");
    if (!createFunc) return;
    renderer = createFunc();
  #endif
};

void PF::ENGINE::Engine::run(std::function<void()> func) {
  renderer->events();
  func();
};

void PF::ENGINE::Engine::events() {
  renderer->events();
};

void PF::ENGINE::Engine::render(){
  renderer->render();
};

PF::ENGINE::Texture* PF::ENGINE::Engine::renderToTexture(){
  return renderer->renderToTexture();
};

void PF::ENGINE::Engine::generateFrame(){
  renderer->renderBackground({50, 50, 50, 255});

  renderer->renderColourBox({200, 300, 0.9, 200, 200}, {0, 255, 0, 255});
  renderer->renderColourBox({200, 200, 0.6, 200, 200}, {200, 0, 0, 255});
};
