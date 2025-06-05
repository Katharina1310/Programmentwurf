cmake_minimum_required(VERSION 3.20)
project(DeveloperProject VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler-Warnungen
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Logo-Pfad definieren (relativ vom Executable aus)
add_compile_definitions(LOGO_PATH="./logos/")

# Include-Verzeichnis
include_directories(include)

# Bibliothek mit allen Klassendateien
add_library(developer_lib
    src/Developer.cpp
    src/JuniorDeveloper.cpp
    src/SeniorDeveloper.cpp
)

# Hauptprogramm erstellen
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE developer_lib)

# Optionale Tests (wenn du sie später hinzufügen willst)
include(CTest)
enable_testing()
