@echo off
if not exist build mkdir build
gcc -Wall -Wextra -g -fexec-charset=GBK src\swap.c -o build\swap.exe
if errorlevel 1 exit /b 1
echo Build OK: build\swap.exe
