@echo off
setlocal


if exist "%cd%\build\" (
    rmdir /s /q build
)

mkdir build
cd build

where cmake >nul 2>&1
if errorlevel 1 (
    echo Error: cmake not found in PATH!
    echo fail >> result.txt
    exit /b 1
)

cmake ..


if errorlevel 1 (
    echo Error: CMake configuration failed!
    echo fail >> result.txt
    exit /b 1
)

echo CMake succeeded.
echo success >> result.txt
exit /b 0