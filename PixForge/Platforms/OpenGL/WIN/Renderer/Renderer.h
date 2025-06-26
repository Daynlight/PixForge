#pragma once
#include <string>
#include "Platforms/Interfaces/iRenderer.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "STL/File/File.h"
#include "Engine/Events.h"
#include "Engine/Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORM {
class Renderer : public iRenderer {
private:
    const char* defaultColourBoxVertexShader = R"(
    #version 330 core
    layout (location = 0) in vec2 aPos;
    uniform vec3 uPos;
    uniform vec2 uSize;
    void main() {
        vec3 scaled = vec3(aPos * uSize, 0.0) + uPos;
        gl_Position = vec4(scaled, 1.0);
    }
    )";
    const char* defaultColourBoxFragmentShader = R"(
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
    ENGINE::Shader vertexShader = ENGINE::Shader(defaultColourBoxVertexShader, "");
    ENGINE::Shader fragmentShader = ENGINE::Shader(defaultColourBoxFragmentShader, "");
    int x, y, width, height;
    GLuint boxVAO = 0;
    GLuint boxVBO = 0;
    GLuint compiledShader;
    void createBox();
public:
    ~Renderer();
    GLFWwindow* getWindow() { return window; };
    bool isRunning() { return running; };
    void createWindow(const std::string &title, int width, int height);
    void createRenderer();
    void pullEventsAndProccessWindowEvents(STL::Vector<PF::ENGINE::EventsCodes> &events);
    STL::Vec<int, 4> getWindowRect() { return {x, y, width, height}; };
public:
    void render();
    void renderBackground(STL::Vec<float, 4> colour);
    void renderColourBox(STL::Vec<float, 5> position, STL::Vec<float, 4> colour);
    void renderTexture();
    void bindVertexShader(PF::ENGINE::Shader shader);
    void bindFragmentShader(PF::ENGINE::Shader shader);
    void bindDefaultColourBoxShader();
    void bindDefaultTextureShader();
    void compileShader();
private:
    void bindDefaultColourBoxVertexShader();
    void bindDefaultColourBoxFragmentShader();
}; // class Renderer
}; // namespace PF::PLATFORMS