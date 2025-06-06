#!/bin/bash

# Beende bei Fehler
set -e

echo "[1/4] CMake konfigurieren..."
cmake -S . -B build

echo "[2/4] Projekt bauen..."
cmake --build build

echo "[3/4] In Build-Verzeichnis wechseln..."
cd build

echo "[4/4] Anwendung starten..."
./main_app
