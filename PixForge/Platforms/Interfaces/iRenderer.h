#pragma once
#include <string>
#include "Utilities/Vector/Vector.h"
#include "Utilities/Math/Vec.h"
#include "Utilities/File/File.h" 
#include "Engine/Shader.h"

namespace PF::PLATFORM{
class iRenderer{
public:
  virtual void createWindow(const std::string &title, int width, int height, bool for_editor) = 0;
  virtual void createRenderer() = 0;
  virtual bool isRunning() = 0;
  virtual UTILITIES::Vec<int, 4> getWindowRect() = 0;
public:
  virtual void render() = 0;
  virtual void events() = 0;
  virtual void renderBackground(UTILITIES::Vec<float, 4> colour) = 0;
  virtual void renderColourBox(UTILITIES::Vec<float, 5> position, UTILITIES::Vec<float, 4> colour) = 0;
  virtual void renderTexture() = 0;
public:
  virtual void bindVertexShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindFragmentShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindDefaultColourBoxShader() = 0;
  virtual void bindDefaultTextureShader() = 0;
  virtual void compileShader() = 0;
};
}; // namespace PF::PLATFORM

extern "C" PF::PLATFORM::iRenderer* CreateRenderer();