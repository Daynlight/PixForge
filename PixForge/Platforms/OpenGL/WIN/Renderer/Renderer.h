#pragma once

#include "Platforms/Interfaces/iRenderer.h"
#include <string>
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
    void pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events);
    void proccessEvent(const PF::ENGINE::EventsCodes event);
}; // class Renderer
}; // namespace PF::PLATFORMS