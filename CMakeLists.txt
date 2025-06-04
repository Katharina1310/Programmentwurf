# Minimum required CMake version
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(developer VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++14 and require it
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings and extra warnings
add_compile_options(-Wall -Wextra -pedantic)

# Include testing module and enable testing
include(CTest)
enable_testing()

# Add executable target and specify source files
add_executable(group_p_cpp
    src/developer.cpp
    src/main.cpp
)

# Add include directories
target_include_directories(group_p_cpp PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Define macro for logo path
target_compile_definitions(group_p_cpp PRIVATE LOGO_PATH=\"./\")
