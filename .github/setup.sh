#!/bin/bash
set -e  # Exit on error

echo "====================="
echo "Installing Conan dependencies"
echo "====================="

# Create Conan output folders
mkdir -p build/conan_debug build/conan_release

# Install Debug dependencies
echo "Installing Debug dependencies..."
conan install . \
    -s build_type=Debug \
    --output-folder=build/conan_debug \
    --build=missing

# Install Release dependencies
echo "Installing Release dependencies..."
conan install . \
    -s build_type=Release \
    --output-folder=build/conan_release \
    --build=missing

echo "====================="
echo "Configuring CMake using presets"
echo "====================="

# Configure Debug build preset
cmake --preset debug

# Configure Release build preset
cmake --preset release

echo "====================="
echo "Setup completed. You can now
