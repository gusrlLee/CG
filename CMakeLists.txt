cmake_minimum_required(VERSION 3.15)

project(Rendering_Engine)
set(CMAKE_CXX_STANDARD 17)

message("Runtime file path : ${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Source)

