#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>   // for memcpy

namespace PF::ENGINE {
class Texture {
private:
    unsigned int width;
    unsigned int height;
    std::vector<unsigned char> data;

public:
    Texture() : width(64), height(64) {}
    Texture(unsigned int w, unsigned int h) : width(w), height(h), data(w * h * 4, 0) {}
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }
    const unsigned char* getData() const { return data.data(); }
    unsigned char* getData() { return data.data(); }
    void setData(const unsigned char* src, size_t size) {
        if (size != data.size()) {
            throw std::runtime_error("Texture::setData - size mismatch");
        }
        std::memcpy(data.data(), src, size);
    }
    void resize(unsigned int w, unsigned int h) {
        width = w;
        height = h;
        data.assign(w * h * 4, 0);
    }
};
} // namespace PF::ENGINE
