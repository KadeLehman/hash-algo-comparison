cmake_minimum_required(VERSION 3.10)
project(HASH-ALGO-COMPARISON)
set (EXE_NAME HashCompare)

set(CMAKE_CXX_FLAGS "-Wall")

# set (input01 "ControlFile.txt")
# set (input02 "GraphMaker-For-AlgoPA03/graph_10.kml")
# set (input03 "GraphMaker-For-AlgoPA03/graph_20.kml")
# set (input04 "GraphMaker-For-AlgoPA03/graph_40.kml")
# set (input05 "GraphMaker-For-AlgoPA03/graph_80.kml")
# set (input06 "GraphMaker-For-AlgoPA03/graph_160.kml")

# Copy data files to build dir
# foreach(file IN LISTS input01 input02 input03 input04 input05 input06)
#     configure_file(${file} ${file} COPYONLY)
# endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME} main.cpp Program.h Program.cpp)
