#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Configure the project with CMake
cmake ..

# Build the project
cmake --build .
