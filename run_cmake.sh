#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

echo "[1/4] Configuring CMake..."
cmake -S . -B build

echo "[2/4] Building the project..."
cmake --build build

echo "[3/4] Changing to the build directory..."
cd build

echo "[4/4] Starting the application..."
./cmake_exec


