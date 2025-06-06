@echo off
REM Build und Ausführen der C++ Anwendung mit CMake

echo [1/4] CMake Konfiguration starten...
cmake -S . -B build
if %errorlevel% neq 0 (
    echo Fehler bei der CMake-Konfiguration.
    exit /b %errorlevel%
)

echo [2/4] Projekt bauen...
cmake --build build
if %errorlevel% neq 0 (
    echo Fehler beim Bauen des Projekts.
    exit /b %errorlevel%
)

echo [3/4] Wechsle in das Build-Verzeichnis...
cd build

echo [4/4] Starte Anwendung...
.\main_app.exe
