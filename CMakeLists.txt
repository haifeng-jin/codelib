cmake_minimum_required(VERSION 3.10)

# Define the project name
project(CodeLib)

set(CMAKE_CXX_STANDARD 17)

# Enable testing for the project
enable_testing()

# Include subdirectories
add_subdirectory(src)
add_subdirectory(tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)