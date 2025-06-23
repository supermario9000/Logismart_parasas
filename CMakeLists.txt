cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Logismart_paraso_generatorius VERSION 1)

# Target Windows platform
set(CMAKE_SYSTEM_NAME Windows)

# Set the MinGW cross-compilers
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Static linking for Windows
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++ -Wall -Wextra -O2")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    main.cpp
)

# Define the executable with .exe extension
add_executable(Logismart_paraso_generatorius.exe ${SOURCES})
