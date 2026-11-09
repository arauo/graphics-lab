@echo off
if not exist build mkdir build
gcc -Wall -Wextra -g src\hello.c -o build\hello.exe
if errorlevel 1 exit /b 1
echo Build OK: build\hello.exe
