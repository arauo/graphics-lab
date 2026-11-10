@echo off
if not exist build mkdir build
if "%~1"=="" (
    echo Usage: build.bat src\filename.c
    exit /b 1
)
gcc -Wall -Wextra -g -fexec-charset=GBK "%~1" -o "build\%~n1.exe"
if errorlevel 1 exit /b 1
echo Build OK: build\%~n1.exe

