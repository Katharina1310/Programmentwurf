@echo off
REM Build and run the C++ application with CMake

echo [1/4] Starting CMake configuration...
cmake -S . -B build
if %errorlevel% neq 0 (
    echo Error during CMake configuration.
    exit /b %errorlevel%
)

echo [2/4] Building the project...
cmake --build build
if %errorlevel% neq 0 (
    echo Error while building the project.
    exit /b %errorlevel%
)

echo [3/4] Changing to the build directory...
cd build

echo [4/4] Starting the application...
.\main_app.exe
