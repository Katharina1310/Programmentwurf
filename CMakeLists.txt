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

# Define macro LOGO_PATH as a string (adjust path as needed)
add_compile_definitions(LOGO_PATH=\"../logos/\")

# Build the library from implementation files
add_library(developer_lib
    src/Developer.cpp
    src/JuniorDeveloper.cpp
    src/SeniorDeveloper.cpp
)


# Make sure the macro is visible to the library target as well
target_compile_definitions(developer_lib PRIVATE LOGO_PATH=\"../logos/\")

# Build the main application executable
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE developer_lib)
target_compile_definitions(main_app PRIVATE LOGO_PATH=\"../logos/\")

# GoogleTest holen und einbinden
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable bauen
add_executable(tests
    tests/test_developer.cpp
)

target_link_libraries(tests developer_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
