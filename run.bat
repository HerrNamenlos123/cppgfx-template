@echo off

cls

:: Batch

:: If the file does not exist
if not exist "build/cppgfx.configured" (
    echo [34m[cppgfx] The project was not configured yet, configuring now...[0m

    :: Create build directory
    mkdir build 2> nul

    :: Configure the project
    cmake -S . -B build

    if %errorlevel% neq 0 (
        echo [cppgfx] Configuring failed
        exit /b 1
    )

    :: Create the file
    echo. > "build/cppgfx.configured"

    echo [cppgfx] Configuring done
)

echo [34m[cppgfx] Building the project...[0m

:: Build the project
cmake --build build

if %errorlevel% neq 0 (
    echo [91m[cppgfx] Building failed[0m
    exit /b 1
)

echo [34m[cppgfx] Building done[0m

:: Run the project

echo [34m[cppgfx] Running the project...[0m

call build/run
