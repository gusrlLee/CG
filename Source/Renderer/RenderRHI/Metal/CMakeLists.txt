cmake_minimum_required(VERSION 3.15)


add_library(Metal_Renderer
    Metal_Renderer.mm
)

target_link_libraries(Metal_Renderer METAL_CPP)
# target_include_directories(Renderer PUBLIC ${ROOT_PATH})