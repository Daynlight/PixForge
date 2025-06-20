#pragma once

#include "Interfaces/iRenderer.h"
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace PF::PLATFORMS{
class Renderer : public iRenderer {
public:
    Renderer();
    ~Renderer();

    bool Init();
    void Clear(float r, float g, float b, float a);
    void Draw();
    void Shutdown();

private:
    GLuint VAO, VBO;
    GLuint shaderProgram;

    bool CreateShaders();
    GLuint CompileShader(GLenum type, const std::string& source);
}; // class Renderer
}; // namespace PF::PLATFORMS