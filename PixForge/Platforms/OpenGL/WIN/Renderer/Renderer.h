#pragma once
#include <string>
#include "Platforms/Interfaces/iRenderer.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "Engine/Events.h"
#include "Engine/Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORMS{
class Renderer : public iRenderer {
private:
    const char* defaultVertexShader = R"(
    #version 330 core
    layout (location = 0) in vec2 aPos;
    uniform vec3 uPos;
    uniform vec2 uSize;
    void main() {
        vec3 scaled = vec3(aPos * uSize, 0.0) + uPos;
        gl_Position = vec4(scaled, 1.0);
    }
    )";
    const char* defaultFragmentShader = R"(
    #version 330 core
    out vec4 FragColor;
    uniform vec4 uColor;
    void main() {
        FragColor = uColor;
    }
    )";
private:
    GLFWwindow *window;
    bool running = true;
    ENGINE::Shader vertexShader = ENGINE::Shader(defaultVertexShader, "");
    ENGINE::Shader fragmentShader = ENGINE::Shader(defaultFragmentShader, "");
    int width, height;
    GLuint boxVAO = 0;
    GLuint boxVBO = 0;
    GLuint compiledShader;
    void createBox();
public:
    bool isRunning() { return running; };
    void createWindow(const std::string &title);
    void createRenderer();
    void pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events);
    void proccessEvent(const PF::ENGINE::EventsCodes event);
public:
    void render();
    void renderBackground(STL::Vec<float, 4> colour);
    void renderColourBox(STL::Vec<float, 5> position, STL::Vec<float, 4> colour);
    void renderTexture();
    void bindVertexShader(PF::ENGINE::Shader shader);
    void bindFragmentShader(PF::ENGINE::Shader shader);
    void bindDefaultVertexShader();
    void bindDefaultFragmentShader();
    void compileShader();
}; // class Renderer
}; // namespace PF::PLATFORMS