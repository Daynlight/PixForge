#pragma once

#ifdef OPENGLRENDERER
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Renderer {
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
};
#endif