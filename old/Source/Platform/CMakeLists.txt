cmake_minimum_required(VERSION 3.15)

find_package(OpenGL REQUIRED)

add_library(Platform 
    Window.cpp
)

target_link_libraries(Platform glfw)

target_include_directories(Platform PUBLIC ${CMAKE_SOURCE_DIR}/Source)
