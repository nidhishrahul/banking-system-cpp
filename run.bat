@echo off
echo Compiling...

g++ src\*.cpp -o bank.exe

if errorlevel 1 (
    echo Compilation failed.
) else (
    echo Compilation successful. Running program...
    bank.exe
)

pause