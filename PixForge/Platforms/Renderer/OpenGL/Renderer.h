#pragma once
#include <string>
#include "Platforms/Interfaces/iRenderer.h"
#include "Utilities/Vector/Vector.h"
#include "Utilities/Math/Vec.h"
#include "Utilities/File/File.h"
#include "Engine/Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORM {
class OpenGLRenderer : public iRenderer {
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
    ENGINE::Shader vertexShader = ENGINE::Shader(defaultColourBoxVertexShader, "vertex.shader");
    ENGINE::Shader fragmentShader = ENGINE::Shader(defaultColourBoxFragmentShader, "fragment.shader");
    int x, y, width, height;
    GLuint boxVAO = 0;
    GLuint boxVBO = 0;
    GLuint compiledShader;
    void createBox();
public:
    ~OpenGLRenderer();
    GLFWwindow* getWindow() { return window; };
    bool isRunning() { return running; };
    void createWindow(const std::string &title, int width, int height, bool for_editor = false);
    void createRenderer();
    void events();
    UTILITIES::Vec<int, 4> getWindowRect() { return {x, y, width, height}; };
public:
    void render();
    GLuint* renderEditorWindow();
    void renderBackground(UTILITIES::Vec<float, 4> colour);
    void renderColourBox(UTILITIES::Vec<float, 5> position, UTILITIES::Vec<float, 4> colour);
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