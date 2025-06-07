## \brief CMake configuration file for project setup.
## \author Konstantin Growitsch and Katharina Benedikt
## \06.06.2025

# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)
# define the project name
project(DeveloperProject LANGUAGES CXX)

# define the cxx standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic)

# include directory for header files
include_directories(include)

# add a macro for the logo path
add_compile_definitions(LOGO_PATH=\"../logos/\")

# build the library from implementation files
add_library(developer_lib src/developer.cpp src/junior_developer.cpp src/senior_developer.cpp)

# make sure the macro is visible to the library target as well
target_compile_definitions(developer_lib PRIVATE LOGO_PATH=\"../logos/\")

# build the main application executable
add_executable(cmake_exec src/main.cpp)
target_link_libraries(cmake_exec PRIVATE developer_lib)
target_compile_definitions(cmake_exec PRIVATE LOGO_PATH=\"../logos/\")

# GoogleTest 
# enable the testing
enable_testing()
# check if we have gtest
find_package (GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)

# JuniorDeveloper tests
add_executable(junior_tests test/test_junior_developer.cpp)
target_link_libraries(junior_tests PRIVATE GTest::GTest GTest::Main developer_lib)
target_include_directories(junior_tests PUBLIC include)
gtest_discover_tests(junior_tests)

# SeniorDeveloper Tests
add_executable(senior_tests test/test_senior_developer.cpp)
target_link_libraries(senior_tests PRIVATE GTest::GTest GTest::Main developer_lib)
target_include_directories(senior_tests PUBLIC include)
gtest_discover_tests(senior_tests)

# After building the test executables, copy the logo files into the appropriate directory.
# This ensures that the tests can always find the logos, regardless of the current working directory.
add_custom_command(TARGET junior_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/logos $<TARGET_FILE_DIR:junior_tests>/../logos
)
add_custom_command(TARGET senior_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/logos $<TARGET_FILE_DIR:senior_tests>/../logos
)