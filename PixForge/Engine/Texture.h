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
    // Default constructor
    Texture() : width(64), height(64) {}

    // Construct with dimensions (empty texture)
    Texture(unsigned int w, unsigned int h)
        : width(w), height(h), data(w * h * 4, 0) // RGBA format
    {}

    // Construct with raw data
    Texture(unsigned int w, unsigned int h, const unsigned char* rawData)
        : width(w), height(h), data(w * h * 4)
    {
        std::memcpy(data.data(), rawData, data.size());
    }

    // Getters
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

    // Pixel access
    void setPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) {
        if (x >= width || y >= height)
            throw std::out_of_range("Texture::setPixel out of bounds");

        size_t index = (y * width + x) * 4;
        data[index + 0] = r;
        data[index + 1] = g;
        data[index + 2] = b;
        data[index + 3] = a;
    }

    void getPixel(unsigned int x, unsigned int y, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a) const {
        if (x >= width || y >= height)
            throw std::out_of_range("Texture::getPixel out of bounds");

        size_t index = (y * width + x) * 4;
        r = data[index + 0];
        g = data[index + 1];
        b = data[index + 2];
        a = data[index + 3];
    }

    // Resize texture (clears existing data)
    void resize(unsigned int w, unsigned int h) {
        width = w;
        height = h;
        data.assign(w * h * 4, 0);
    }

    // Clear texture to color
    void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) {
        for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                setPixel(x, y, r, g, b, a);
            }
        }
    }
};

} // namespace PF::ENGINE
