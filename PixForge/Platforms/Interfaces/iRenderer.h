#pragma once
#include <string>
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "Engine/Events.h"
#include "Engine/Shader.h"

namespace PF::PLATFORMS{
class iRenderer{
public:
  virtual void createWindow(const std::string &title) = 0;
  virtual void createRenderer() = 0;
  virtual bool isRunning() = 0;
  virtual void pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) = 0;
  virtual void proccessEvent(const PF::ENGINE::EventsCodes) = 0;
public:
  virtual void render() = 0;
  virtual void renderBackground(STL::Vec<float, 4> colour) = 0;
  virtual void renderColourBox(STL::Vec<int, 5> position, STL::Vec<float, 4> colour) = 0;
  virtual void renderTexture() = 0;
  virtual void bindVertexShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindFragmentShader(PF::ENGINE::Shader shader) = 0;
  virtual void bindDefaultVertexShader() = 0;
  virtual void compileShader() = 0;
};
}; // namespace PF::PLATFORM