cmake_minimum_required(VERSION 3.20)

project(DeveloperProject LANGUAGES CXX)

# Use C++14 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings
add_compile_options(-Wall -Wextra -pedantic)

# Include headers directory
include_directories(include)

# Define absolute path to logos directory
set(LOGO_PATH_ABS "${CMAKE_SOURCE_DIR}/logos/")
add_compile_definitions(LOGO_PATH="${LOGO_PATH_ABS}")

# Build library from source files
add_library(developer_lib
    src/developer.cpp
    src/junior_developer.cpp
    src/senior_developer.cpp
)

# Make LOGO_PATH visible to the library
target_compile_definitions(developer_lib PRIVATE LOGO_PATH="${LOGO_PATH_ABS}")

# Build main executable
add_executable(cmake_exec src/main.cpp)
target_link_libraries(cmake_exec PRIVATE developer_lib)
target_compile_definitions(cmake_exec PRIVATE LOGO_PATH="${LOGO_PATH_ABS}")

# Enable testing
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# JuniorDeveloper tests
add_executable(junior_tests test/test_junior_developer.cpp)
target_link_libraries(junior_tests PRIVATE GTest::GTest GTest::Main developer_lib)
target_include_directories(junior_tests PUBLIC include)
target_compile_definitions(junior_tests PRIVATE LOGO_PATH="${LOGO_PATH_ABS}")
# Set working directory for tests discovered by gtest_discover_tests
gtest_discover_tests(junior_tests PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# SeniorDeveloper tests
add_executable(senior_tests test/test_senior_developer.cpp)
target_link_libraries(senior_tests PRIVATE GTest::GTest GTest::Main developer_lib)
target_include_directories(senior_tests PUBLIC include)
target_compile_definitions(senior_tests PRIVATE LOGO_PATH="${LOGO_PATH_ABS}")
gtest_discover_tests(senior_tests PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

