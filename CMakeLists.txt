cmake_minimum_required(VERSION 3.10)
project(HASH-ALGO-COMPARISON)
set (EXE_NAME HashCompare)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set (input01 "ControlFile.txt")
set (input02 "intList.txt")

# Copy data files to build dir
foreach(file IN LISTS input01 input02)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME} main.cpp Program.h Program.cpp HashTable.h HashTable.cpp)
