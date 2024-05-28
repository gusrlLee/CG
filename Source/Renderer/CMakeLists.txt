cmake_minimum_required(VERSION 3.15)

add_subdirectory(RenderRHI/Metal)

add_library(Renderer 
    Renderer.cpp
)

target_link_libraries(Renderer Metal_Renderer)
target_include_directories(Renderer PUBLIC ${CMAKE_SOURCE_DIR}/Source)
# target_include_directories(Renderer PUBLIC ${ROOT_PATH})