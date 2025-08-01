#pragma once
#include <string>
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "STL/File/File.h" 
#include "Engine/Events.h"
#include "Engine/Shader.h"

namespace PF::PLATFORM{
class iRenderer{
public:
  virtual void createWindow(const std::string &title, int width, int height) = 0;
  virtual void createRenderer() = 0;
  virtual bool isRunning() = 0;
  virtual STL::Vec<int, 4> getWindowRect() = 0;
  virtual void pullEventsAndProccessWindowEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) = 0;
public:
  virtual void render() = 0;
  virtual void renderBackground(STL::Vec<float, 4> colour) = 0;
  virtual void renderColourBox(STL::Vec<float, 5> position, STL::Vec<float, 4> colour) = 0;
  virtual void renderTexture() = 0;
public:
  virtual void bindVertexShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindFragmentShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindDefaultColourBoxShader() = 0;
  virtual void bindDefaultTextureShader() = 0;
  virtual void compileShader() = 0;
};
}; // namespace PF::PLATFORM