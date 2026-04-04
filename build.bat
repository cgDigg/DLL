@echo off
setlocal


cmake --build build/Release --config Release
if %errorlevel% neq 0 (
    echo fail
    exit /b 1
)


if exist result rmdir /s /q result

mkdir result

xcopy /e /i build\Release\Release result\Release >nul


cd result\Release

del *.exp >nul 2>&1


mkdir dll
mkdir lib


move *.dll dll\ >nul 2>&1
move *.lib lib\ >nul 2>&1

