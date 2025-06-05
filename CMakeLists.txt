cmake_minimum_required(VERSION 3.20)
project(DeveloperProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Include directory for header files
include_directories(include)

# Define macro LOGO_PATH as a string (with escaped quotes)
# Adjust the path as needed depending on where the executable runs
add_compile_definitions(LOGO_PATH=\"../logos/\")

# Build the library from implementation files
add_library(developer_lib
    src/Developer.cpp
    src/JuniorDeveloper.cpp
    src/SeniorDeveloper.cpp
)

# Build the main application
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE developer_lib)

# Ensure the macro is visible to both targets
target_compile_definitions(developer_lib PRIVATE LOGO_PATH=\"../logos/\")
target_compile_definitions(main_app PRIVATE LOGO_PATH=\"../logos/\")
