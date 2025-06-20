#pragma once
#include <string>
#include "Platforms/Interfaces/iRenderer.h"
#include "STL/Math/Vec.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORMS{
class Renderer : public iRenderer {
private:
    GLFWwindow *window;
    bool running = true;
public:
    bool isRunning() { return running; };
    void createWindow(const std::string &title);
    void createRenderer();
    void pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events);
    void proccessEvent(const PF::ENGINE::EventsCodes event);
public:
    void render();
    void renderBackground(STL::Vec<float, 4> colour);
    void renderColourBox(STL::Vec<int, 3> position, STL::Vec<float, 4> colour);
    void renderTexture();
}; // class Renderer
}; // namespace PF::PLATFORMS