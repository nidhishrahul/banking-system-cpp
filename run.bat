@echo off
echo Compiling...

g++ -Iinclude src/main.cpp src/Account.cpp src/Bank.cpp -o bank.exe

if errorlevel 1 (
    echo Compilation failed.
) else (
    echo Compilation successful. Running program...
    bank.exe
)

pause