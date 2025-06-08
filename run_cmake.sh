#!/bin/bash
set -e

echo "[1/5] Removing old build directory..."
rm -rf build

echo "[2/5] Creating new build directory..."
mkdir build
cd build

echo "[3/5] Configuring CMake..."
cmake ..

echo "[4/5] Building the project..."
make

echo "[5/5] Starting the application..."
./cmake_exec
