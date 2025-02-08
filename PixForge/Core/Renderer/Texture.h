#pragma once
#include "../STL/Vector.h"
#include "SDL2/SDL.h"
#include "../STL/File.h"
#include "Window/Window.h"

namespace PF{
class Texture{
private:
  Vector<SDL_Texture*> textures;
  File file;
  Window* window;
public:
  Texture(const std::string& path, Window* window) : file(path), window(window) {};
  ~Texture(){ while(textures.size()) SDL_DestroyTexture(textures.pop()); };
  void add(SDL_Texture* texture) { textures.push(texture); };
  void addTextureFromFile(const std::string &path){
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTexture(window->getRenderer(), SDL_PIXELFORMAT_RGBA32,
      SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);
    SDL_SetRenderTarget(window->getRenderer(), texture);
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
    SDL_SetRenderTarget(window->getRenderer(), NULL);
    SDL_FreeSurface(surface);
  };
  SDL_Texture* operator[](int index) { return textures[index]; };
  void clear() { textures.clear(); };
  int size() { return textures.size(); };
  void save() { 
    if(file.notExist()) file.createFile();
    file.clear();
    size_t size = textures.size();
    for(int i = 0; i < size; i++){
      int width, height;
      SDL_QueryTexture(textures[i], NULL, NULL, &width, &height);

      Uint32* pixels = new Uint32[width * height];
      SDL_Rect rect =  SDL_Rect({0,0,width,height});
      int pitch = width * sizeof(Uint32);

      SDL_SetRenderTarget(window->getRenderer(), textures[i]);
      SDL_RenderReadPixels(window->getRenderer(), &rect, SDL_PIXELFORMAT_RGBA32, pixels, pitch);
      SDL_SetRenderTarget(window->getRenderer(), NULL);

      std::string record = "";
      record += std::to_string(width) + " " + std::to_string(height) + " ";
      record += std::to_string(pitch) + " ";
      for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
          Uint32 pixel = pixels[y * width + x];
          record += std::to_string(pixel) + " ";
        };
      };
      file.push(record);
      delete[] pixels;
    };
    file.save();
   };

  void load() { 
    file.read();
    for(size_t i = 0; i < file.size(); i++){
      std::string record = file[i];
      std::string width = "";
      std::string height = "";
      std::string pitch = "";
      std::string pixels = "";
      size_t state = 0;
      std::string line = "";
      for(size_t j = 0; j < record.size(); j++){
        if(record[j] == ' '){
          if(state == 0) width = line;
          if(state == 1) height = line;
          if(state == 2) { pitch = line; state = j + 1; break; }
          state++;
          line = "";
        }
        else line += record[j];
      };
      line = "";
      int w = std::stoi(width);
      int h = std::stoi(height);
      int p = std::stoi(pitch);
      Uint32* pixel = new Uint32[w * h];
      size_t pixelIndex = 0;
      for(size_t j = state; j < record.size(); j++){
        if(record[j] == ' '){
          Uint32 pixelValue = std::stoul(line);
          pixel[pixelIndex] = pixelValue;
          pixelIndex++;
          line = "";
        }
        else line += record[j];
      };

      SDL_Surface* surface = IMG_Load("texture.png");
      SDL_Texture* texture = SDL_CreateTexture(window->getRenderer(), SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);
      SDL_SetRenderTarget(window->getRenderer(), texture);
      SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
      SDL_SetRenderTarget(window->getRenderer(), NULL);
      textures.push(texture);
      SDL_FreeSurface(surface);
      delete[] pixel;
    };
  };
};
}; // namespace PF