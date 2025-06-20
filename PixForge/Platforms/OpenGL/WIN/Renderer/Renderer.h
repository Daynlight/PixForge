#pragma once

#include "Platforms/Interfaces/iRenderer.h"
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORMS{
class Renderer : public iRenderer {
private:
GLFWwindow *window;
public:
    Renderer();
    ~Renderer();
}; // class Renderer
}; // namespace PF::PLATFORMS