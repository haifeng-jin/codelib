#!/bin/bash

# Navigate to build directory
cd build

# Run tests with CTest
ctest --output-on-failure
